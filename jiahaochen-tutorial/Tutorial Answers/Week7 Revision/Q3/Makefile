CC=gcc
CFLAGS=-g -std=c11 -Wall -Werror
TARGET=program

.PHONY: clean
all: $(TARGET)

program: main.c stack.c
	$(CC) $(CFLAGS) $^ -o $@

debug: stack.c main.c
	$(CC) $(CFLAGS) -DDEBUG $^ -o $@

stack.o: stack.c
	$(CC $(CFLAGS) -c $^ -o $@

clean:
	rm -f *.o
	rm -f program
	rm -f debug
