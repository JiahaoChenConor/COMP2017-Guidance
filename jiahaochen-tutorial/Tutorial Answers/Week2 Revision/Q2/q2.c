#include <stdio.h>

int main(int argc, char** argv) {
	if(argc >= 2) {
        char name[256];
        /*
            reads  in at most one less than size characters from stream and stores them into the buffer pointed to by s.  Reading stops after an EOF or a newline.  If a newline
            is read, it is stored into the buffer.  A terminating null byte ('\0') is stored after the last character in the buffer.
       */ 
        printf("What's your name ? ");
        fgets(name, 256, stdin);
        printf("%s %s", argv[1], name);
  }
	return 0;
}

// int main(int argc, char** argv) {
// 	if(argc >= 2) {
//         char name[256];
//         printf("What is your name ? ");
//         // scanf will end when encountering space
//         scanf("%s", name);
//         printf("%s %s\n", argv[1], name);
//   }
// 	return 0;
// }

