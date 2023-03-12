#include "primesMT.h"


static BitBlock_t  *prime_arr = NULL;
//static int arr_size = MAX_UPPER_PRIME/32 + 1;
static  int max_prime_number = MAX_UPPER_PRIME;
static int num_threads = 1;



BitBlock_t
*alloc_primes_blocks(void){
    int arr_size = max_prime_number/32 + 1;
    BitBlock_t *block_arr = malloc(arr_size * sizeof(BitBlock_t));
    return  block_arr;
}

void
init(BitBlock_t * block_arr)
{
    int arr_size = max_prime_number/32 + 1;
    for(int i= 0; i < arr_size; i ++)
    {
        block_arr[i].bits = 0;
		//block_arr[i].mutex = PTHREAD_MUTEX_INITIALIZER;
		pthread_mutex_init( &(block_arr[i].mutex), NULL);

    }
}

int
check_prime(int value)
{
    int i, flag = 0;
    if (value == 0 || value == 1)
        flag = 1;

    for (i = 2; i <= value / 2; ++i) {

        // if n is divisible by i, then n is not prime
        // change flag to 1 for non-prime number
        if (value % i == 0) {
            flag = 1;
            break;
        }
    }

    // flag is 0 for prime numbers
    if (flag == 0)
        return  1;
    else
        return 0;
}
/*
void
*set_prime_block(void *vid){
    int arr_size = max_prime_number/32 + 1;
    int arr_poss, numb_check, new_num = 0;
	int i = -1;
	int j = -1;
    // check if max_prime < 32.
	for(i = get_next_row(); i < arr_size; i = get_next_row()){
        arr_poss = 32 * i;
        for(j = 1; j < 32 ; j ++)
        {
            numb_check = arr_poss + j;
            if(check_prime(numb_check))
            {
               // printf("%d  : ",numb_check);
                new_num = (1 << j ) | prime_arr[i].bits;
               // printf("New number is : %d \n", new_num);

                prime_arr[i].bits = new_num;

            }
        }
    }
	pthread_exit(EXIT_SUCCESS);
}
*/

void
*set_prime_block(void *arg){
    //int arr_size = max_prime_number/32 + 1;
   // int arr_poss, numb_check, new_num = 0;
	//int i = -1;
	//int j = -1;
    // check if max_prime < 32.
	long ub =((long) max_prime_number);
	uint32_t new_num = 0;
	long start_paws = ((long) arg);
	//uint32_t numb_check =0;
	
	//printf("\n inside setprimeblock function: start_paws = %ld ub = %ld : numthread = %d", start_paws,ub, num_threads);
	for(long candy_date = start_paws; candy_date < ( sqrt(ub) + 1 ); candy_date += (num_threads * 2)){
		for(long j = (candy_date); j <= ub; j += (num_threads * 2)){
			int bb_index = j/32;
			int bb_bit = j%32;
			// do turn on  bit.
			uint32_t mask = 0x1 << bb_bit;
			//numb_check = bb_index * 32 + bb_bit;
			pthread_mutex_lock(&prime_arr[bb_index].mutex);
			
            if(check_prime(j))
            {
				//printf("\ncurrent  number prime set is : %ld", j);
               // printf("%ld  : ",candy_date);
                new_num = mask | prime_arr[bb_index].bits;
               // printf("New number is : %d \n", new_num);

                prime_arr[bb_index].bits = new_num;

            }
			pthread_mutex_unlock(&prime_arr[bb_index].mutex);
        }
    }
	pthread_exit(EXIT_SUCCESS);
}


void op_mat(void)
{
    FILE *op = NULL;
    int i = -1;
    int j = -1;
    int arr_size = max_prime_number/32 + 1;
    int bit_status, bit_th, curr_num;

#define FILE_NAME "primesMT.txt"
    op = fopen(FILE_NAME, "w");
    if(op == NULL) {
        perror("could not open file: " FILE_NAME);
        exit(17);
    }
    //printf("\n Check output count : ");
    for (i = 0; i < arr_size ; i++){
        bit_th = 32 * i;
        for (j = 0; j < 32; j++){
            curr_num = bit_th + j;
            if(curr_num > max_prime_number)
                break;
           // printf("  %d:  ",curr_num);
            bit_status = (prime_arr[i].bits >> j) & 1;
            if(bit_status)
              // fprintf(op, "%d\n", curr_num);
				printf("%d\n",curr_num);
		    
        }
        //fprintf(op, "\n");
    }
    //fclose(op);
}

void free_primes_block(BitBlock_t *arr)
{
    free(arr);
}

double
elapse_time(struct timeval *t0, struct timeval *t1)
{
    double et = (((double) (t1->tv_usec - t0->tv_usec )) / MICROSECONDS_PER_SECOND)
                + ((double) (t1->tv_sec - t0->tv_sec));
    return et;

}
int
get_next_row(void)
{
	static int next_row = 0;
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	int cur_row = 0;
	pthread_mutex_lock(&lock);
	cur_row = next_row++;
	pthread_mutex_unlock(&lock);
	
	return cur_row;
}


int main(int argc, char * argv[]){
    //printf("Hello, World!\n");

    struct timeval et0;
    struct timeval et1;
    struct timeval et2;
    struct timeval et3;
    struct timeval et4;
    struct timeval et5;
    pthread_t *threads = NULL;
//    long tid = 0;
    {

        int opt = -1;
        while((opt = getopt(argc, argv, "t:u:h")) != -1){
            switch (opt) {
                case 't':
                    num_threads = atoi(optarg);

                    break;
                case 'u':
                    max_prime_number = atoi(optarg);
                    // need check for lower case < 2.
                    break;
                case 'h':
                    printf("%s: -t # -u #\n", argv[0]);
                    printf("\t-t #: number of threads\n");
                    printf("\t-u #: size of maxtrix\n");
                    exit(0);
                    break;
                default: /* '?' */
                    exit(EXIT_FAILURE);
                    break;
            }
        }
    }
    gettimeofday(&et0, NULL);
    prime_arr = alloc_primes_blocks();
	threads = malloc(num_threads * sizeof(pthread_t));

    gettimeofday(&et1, NULL);

    init(prime_arr);

    gettimeofday(&et2, NULL);
	
    //set_prime_block();
	/*for( tid = 0; tid < num_threads; tid++){
		pthread_create(&threads[tid], NULL, set_prime_block, (void *) tid);		
	}
	for(tid = 0; tid < num_threads; tid++){
		pthread_join(threads[tid], NULL);
	}		
	*/
	for(long i = 0, start_paws = 3; i < num_threads; i++, start_paws += 2){
		//printf("call setprimeblock function");
		pthread_create(&threads[i], NULL, set_prime_block, (void *) start_paws);
	}
	
	for(long i = 0; i < num_threads; i ++){
		pthread_join(threads[i], NULL);
	}

    gettimeofday(&et3, NULL);
    op_mat();

    gettimeofday(&et4, NULL);
    free_primes_block(prime_arr);
    gettimeofday(&et5, NULL);
    {
        double total_time = elapse_time(&et0, &et5);
        double alloc_time = elapse_time(&et0, &et1);
        double init_time = elapse_time(&et1, &et2);
        double comp_time = elapse_time(&et2, &et3);
        double op_time = elapse_time(&et3,&et4);
        double td_time = elapse_time(&et4, &et5);
	/*	
        printf("Total time: %8.2lf\n", total_time);
        printf("Alloc time: %8.2lf\n", alloc_time);
        printf("Init time: %8.2lf\n", init_time);
        printf("Comp time: %8.2lf\n", comp_time);
        printf("O/P time: %8.2lf\n", op_time);
        printf("T/D time: %8.2lf\n", td_time);
		*/
    }

    return EXIT_SUCCESS;
}
