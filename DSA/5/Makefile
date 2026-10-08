CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2

all: step1 step2

step1: step1.c clist.c josephus.c clist.h josephus.h
	$(CC) $(CFLAGS) -o step1 step1.c clist.c josephus.c

step2: step2.c clist.c josephus.c clist.h josephus.h
	$(CC) $(CFLAGS) -o step2 step2.c clist.c josephus.c

clean:
	rm -f step1 step2

.PHONY: all clean
