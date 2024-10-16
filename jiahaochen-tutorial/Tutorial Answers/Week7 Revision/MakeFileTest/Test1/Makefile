CC=gcc
CFLAGS=-g -std=c11 -Wall -Werror
TARGET=tasks

.PHONY: clean
all: $(TARGET)

clean:
	rm -f $(TARGET)
	rm -f *.o

list.o: list.c
	$(CC) -c $(CFLAGS) $^ -o $@
	echo "recomplie list.c"
	
tasks.o: tasks.c
	$(CC) -c $(CFLAGS) $^ -o $@
	echo "recomplie tasks.c"

tasks: tasks.o list.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
	echo "link tasks.o and list.o"



