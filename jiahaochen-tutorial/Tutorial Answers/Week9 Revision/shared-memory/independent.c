/*

    • We have two techniques of communicating between processes, what are the pros and cons
    between both processes?
        + pipes the synchronization is simple and built into the pipe mechanism itself.(read and write block)
        + With shared memory, it is easier to work asynchronously.

        + pipe accessible between independent processes ?


    • Why must we use shm_open when sharing with unrelated processes?
        + MAP_ANONYMOUS|MAP_SHARED mapped memory can only be accessed by the process which does that mmap() call or its child processes. 
          There is no way for another process to map the same memory because that memory can not be referred to from elsewhere since it is anonymous.

        + Using shm_open() call it is possible to create named shared memory which can be referred to and mapped by unrelated processes.


    • What problems do we face with processes reading and writing to the same space of memory?
    How could we solve this?
        + race condition. lock

        file1 i = 1
        process1        process2
        for(100) i++    for(100) i++         ==> i++ = i = i + 1 (read i, write i)
        read i = 1      read i = 1
        write i = 2     write i = 2


    • What would happen if we tried to mmap a file that is larger than physical memory?
        + So if you run out of physical memory (that is, the actual RAM chips that you have on your motherboard), that's fine. 
          The operating system will just page out whichever parts of the file it thinks you're not going to use. If it guesses wrong, you'll have poor performance, but you won't crash or anything.

    + shm_open vs open
    
    + the file shm_open operates must be in the /dev/shm. So the file name in shm_open does not contain path. if you want to add a path, 
    create a directory in /dev/shm firslty


*/
