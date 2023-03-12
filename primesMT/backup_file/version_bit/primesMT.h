//
// Created by hieuv on 11/8/2022.
//
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <pthread.h>
#include <stdint.h>
#include <sys/time.h>


//gcc -g -Wall -o primesMT primesMT.c

#ifndef MAX_UPPER_PRIME
# define MAX_UPPER_PRIME 1000000
#endif // MAX_UPPER_PRIME
#define MICROSECONDS_PER_SECOND 1000000.0
typedef struct BitBlock_s {
    uint32_t bits;
    pthread_mutex_t mutex;
} BitBlock_t;
/*  all functions */

BitBlock_t *alloc_primes_blocks(void);
void free_primes_block(BitBlock_t *);
void init(BitBlock_t *);

/* it is also check if value > 2 ; return 1 is prime; return 0 is not prime */
int check_prime(int);

void *set_prime_block(void *);

void op_mat(void);
int get_prime_bits_index(int);
int get_bit_index(int,int);
double elapse_time(struct timeval *, struct timeval *);
int get_next_row(void);


