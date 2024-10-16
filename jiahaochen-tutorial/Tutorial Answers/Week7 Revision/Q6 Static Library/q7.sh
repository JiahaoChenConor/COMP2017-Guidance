gcc -c LinkedList.c -o LinkedList.o    # generate the .o file rename it as LinkedList.o 

# format of .a should start with "lib"
ar rcs libLinkedList.a LinkedList.o    # r:Replace existing target files in the library, or add new target files
                                       # c:Create a library. Regardless of whether the library exists, it will be created
                                       # s:Create a target file index, which can increase speed when creating larger libraries

gcc test.c -I . -L . -l LinkedList -o test.out 
                                         # -I: path of .h file, 
                                         # -L: path of .a file,
                                         # -l: name of lib, if name start with "lib", ignore "lib" and ".a"
                                         

# if we delete libLinkedList.a ? 
# what happens ?
# run test.out still works, since test.out does not depend on libLinkedList.a

# Like copy and paste the lib into test.out


