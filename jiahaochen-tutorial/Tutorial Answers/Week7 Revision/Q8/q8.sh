gcc -c LinkedList.c -o LinkedList.o
gcc -shared -fPIC -o liblinkedlist.so LinkedList.o
gcc test.c -L. -l linkedlist -o test.out # or $gcc test.c -L. liblinkedlist.so -o test.out
                                        # -L . means the .h file is in current directory
                                        # -l  :specify the lib name, cut "lib" and ".o"
                                        
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:~/Week7/Dynamic/   # need to set path for the lib
export LD_LIBRARY_PATH # add path
./test.out

# if we delete liblinkedlist.so, test.out can not execute




# Why is the PIC flag important for shared libraries? Discuss this with your tutors
# + It means that it is compiled into position-independent code. 
#   If this option is not used, the compiled code is position-dependent. 
#   Therefore, during dynamic loading, code copy is used to meet the needs of different processes, 
#   but the purpose of real code segment sharing cannot be achieved. 
#   It is precisely by using this that the dynamic link library does not need to copy the complete code of the library function when compiling, realizing the real dynamic link.



# https://blog.csdn.net/qq_27825451/article/details/105700361    need deleted
