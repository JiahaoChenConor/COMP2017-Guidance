## HIGH LEVEL DESIGN - Select 3

OLD

1. What structs did you have in your code? Why did you decide to use them?
2. **Identify one data structure you used. Why did you decide to use it?**
3. **Did you use function pointers in your code? (if they used fptrs) Why did you decide to use function pointers here? /(if they didn't) Is there anywhere in your code you believe function pointers might be useful?**
4. Are there any functions that were implemented similarly? How did you avoid repetition of code in implementing them?
5. Suppose you had to extend your program to manage multiple databases at once. How would you do this?
6. Suppose you needed to export your database into a file, which can then be imported when restarting the program, how would you implement such import / export functionality?

NEW

1. **Did you use unions in your implementation? (YES) Why did you use a union here instead of a struct? (NO) Is there anywhere in your code where you believe unions might be useful?**
2. Suppose your computer loses power and shuts down when running your database, what happens to the data in the database? Can you think of a way to avoid losing data in the case of power loss?
3. Are there any operations on data structures that have similarities? How did you avoid repetition of code in implementing them?
4. **Suppose we add a new command DIFF which takes two snapshots and prints out their differences. How would you do this?**
5. Suppose we add a new command MERGE which takes two snapshots and combines them. How would you do this?

High level design
1. **Did you use recursion in your implementation? (YES) Why did you decide to use recursion here? (NO) Is there anywhere you believe recursion might be useful?**
2. Did you use a const pointer in your implementation? (YES) Why did you decide to use one here? (NO) Is there anywhere you believe const pointers might be helpful?
3. **Did you use a void pointer in your implementation? (YES) Why did you decide to use one here? (NO) Is there anywhere you believe void pointers might be helpful?**
4. Suppose we add a new command called REWIND which undos the last command to the database. How would you implement this?
5. **Suppose we add a new command called COMPRESS which removes values that are duplicated between any entries in a snapshot? How would you implement this?**



## PROGRAM FUNCTIONALITY - Select 2

OLD

1. How did you implement the PURGE command?
2. How did you implement the FORWARD and BACKWARD commands?
3. How does your code achieve the snapshot functionality?
4. How does your code process user inputs?
5. **How did you write test cases? What type of test cases did you write and how do you ensure good code coverage?**

NEW

1. How did you implement the REV command?
2. How did you implement the UNIQ command?
3. **How did you implement the ROLLBACK functionality?**
4. How did you generate the expected output for your test cases? How do you know that your test cases are correct?
5. Can a program with 100% test coverage still have bugs? Besides optimising for test coverage, how did you prevent bugs in your implementation?

Program Functionality
7. How did you implement the PLUCK command?

8. **How did you implement the PUSH command?**

9. **How did you implement the POP command?**

10. What are the advantages of writing tests? Did you find them helpful during your implementation?

11. **We told you to assume that malloc()/realloc() never return NULL. What if they did? How would you handle the case where you fail to allocate memory?**

    Maybe free some memory unused



## MEMORY MANAGEMENT - Select 2

OLD

1. How does your code organise and manage the stack memory and the heap memory for function calls?
2. What is the difference between malloc, calloc and realloc? Which did you use and why?
3. Did you use the memcpy and/or memmove functions? What for? Why did you choose them? What are the necessary conditions to use them safely, and how did you ensure you met them?
4. **How did you ensure all memory references are correctly copied for snapshots?**
5. (find a double pointer in their code) Why is this variable a double pointer? Can you use a single pointer instead?

NEW

1. **What data did you store on the stack in your implementation? Why did you choose to store this on the stack instead of the heap?**
2. **How did you ensure that changes made in functions would persist after the function exits? (Ai ke se ci)**
3. Explain the ownership of memory in your implementation. How do you decide when to deallocate each piece of memory?
4. **What data structure did you use to store your entries? (If dynamic array) Does a dynamic array use more or less memory than storing them in a linked list? (If linked list) Does a linked list use more or less memory than storing them in a dynamic array?**
5. What is the purpose of freeing all memory leaks if the memory is freed when the program exits anyway?

Memory Management
7. (Find a struct) How much memory does this struct occupy? Is there a way that you could reduce the size of this struct?
8. If you had to implement this assignment without dynamic memory but still had to support an arbitrary number of entries, how would you do this?
9. Is there a way to reuse memory between snapshots? What are the advantages and disadvantages of this approach?
10. **Does calling free() set your pointer to NULL? Why would you NULL a pointer after it’s been freed?**
11. Identify a piece of memory that is not on the stack or the heap in your implementation. Why is it not on the stack or the heap?

## PROGRAMMING PRACTICES - Select 3

OLD

1. Discuss the advantages and disadvantages of implementing the database in C, rather than some other language.
2. Identify one place in your program where you encountered a time-space tradeoff. Explain what you decided and why.

NEW

1. **When your program has a  ((sai ge)) fault, how do you debug it?** 
2. (Find the min or max command) How do you know this will always produce the minimum/maximum value?
3. Would a user be able to notice **the difference between a database written in C and a database written in Python/Java?**
4. Identify one edge case that you didn’t handle. Why did you choose not to handle this case? What changes would make to ensure correctness in this scenario?
5. Did you rewrite parts of your implementation from scratch? What caused you to do this and is there anything you could have done to avoid rewrites in your implementation?



7. What flags did you compile your program with? Can you catch all memory leaks just by adding compiler flags?

8. Did you draw memory diagrams before or during the assignment? (YES) Did it help? (NO) How do you think this would help during the implementation?

9. **Did you test your program on multiple machines? What sort of bugs do you think you could catch by testing on different machines?**

10. **Did you check pointers for NULL at the start of each function? Why might this help during implementation?**

    

## Mark deductions (-5 mark for any of the below)

- program has memory leaks
- excessive memory is used, e.g preallocation or over allocation of what is required
- program avoids malloc family of C functions to instantiate memory dynamically
- uses unjustifiable magic numbers
- uses files, or mapped memory