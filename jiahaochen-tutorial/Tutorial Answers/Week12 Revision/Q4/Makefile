CC=gcc
CFLAGS=-fsanitize=address -Wall -Werror -std=gnu11 -g -lm

tests: q4.c thread_pool.c thread_pool.h
	$(CC) $(CFLAGS) $^ -o $@

