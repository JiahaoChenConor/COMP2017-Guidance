#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

#define BUF_SIZE 100

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("not enough arguments\n");
        return 1;
    }

    // strstr: search "=" in argv[1], and return the pointer in that position
    // eg. --cmd="python3 say_hello_100.py", "=", will return the char* starting from "="
    // in linux => echo "if there is some space" treat this as one => ignore ""  => \ escape => echo "\""
    char * cmd = strstr(argv[1], "=") + 1;
    char * out = strstr(argv[2], "=") + 1;
    printf("%s\n", cmd);
    printf("%s\n", out);
    char buf[BUF_SIZE];

    FILE* process = popen(cmd, "r");
    FILE* output = fopen(out, "w");

    printf("Starting command %s\n", cmd);
    printf("Writing output to %s\n", out);
    size_t bytes = 0;
    // read the output and write to the file
    while ((bytes = fread(buf, sizeof(char), BUF_SIZE, process)) > 0) {
        fwrite(buf, sizeof(char), bytes, output);
    }

    fclose(output);
    pclose(process);
}
