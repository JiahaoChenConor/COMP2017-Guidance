#include <stdio.h>
#include <unistd.h>

int main() {
	write(STDOUT_FILENO, "Hello World!\n", sizeof("Hello World!\n")); // Using the file descriptor and sys call
}
