#
# Created by hieuv on 11/8/2022.
#


CC = gcc
DEBUG = -g
DEFINES =
#DEFINES += -DCHECK
#DEFINES += -DMIN_SBRK_SIZE=1024
#DEFINES += -DMIN_SBRK_SIZE=4096
#DEFINES += -DCHECK_SPLIT_FIT

CFLAGS = $(DEBUG) -Wall -Wshadow -Wunreachable-code -Wredundant-decls -Wextra \
        -Wmissing-declarations -Wold-style-definition -Wmissing-prototypes \
        -Wdeclaration-after-statement -Wunsafe-loop-optimizations 
PROG1 = primesMT

all: $(PROG1)

$(PROG1): $(PROG1).o
	$(CC) $(CFLAGS) -o $(PROG1).o
	chmod a+rx,g-w $@

$(PROG1).o: $(PROG1).c
	$(CC) $(CFLAGS) -c $ $(PROG1).c

#$(PROG1).o: $(PROG1).c




#$(PROG2): $(PROG2).o $(PROG1).o
#	$(CC) $(CFLAGS) -o $@ $^
#	chmod a+rx,g-w $@

#$(PROG2).o: $(PROG2).c Makefile
#	$(CC) $(CFLAGS) -c $<

opt: clean
	make DEBUG=-O3

tar: clean
	tar cvfz $(PROG1).tar.gz *.[ch] ?akefile

# clean up the compiled files and editor chaff
clean cls:
	rm -f $(PROGS) *.o *.gz *~ \#*

ci:
	if [ ! -d RCS ] ; then mkdir RCS; fi
	ci -t-none -m"lazy-checkin" -l *.[ch] ?akefile *.bash

# if you are in more of a git Boom Boom Pow mood.
# "Gotta git [sic] that"
#   https://www.youtube.com/watch?v=4m48GqaOz90
git get gat:
	if [ ! -d .git ] ; then git init; fi
	git add *.[ch] ?akefile
	git commit -m"Gotta git that"
