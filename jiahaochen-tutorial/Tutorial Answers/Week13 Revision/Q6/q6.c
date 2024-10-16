1: sig_atomic_t in c

2: 
1. Mutual exclusion? : a resource can be assigned to at most one thread
2. Hold and wait? 
3. No preemption?
4. Circular wait?

3: 
2 or more threads access and modify the shared data

4:
the is a door only allows one person to enter at one time.
You said after you to your friend

No philopher eats
threads are non-blocking, but not doing anything
try_lock(); <- release the lock that we have already owned
A: lock1 & lock2  
B: lock2 & lock1

5:
some threads are waiting for a lock, <- this lock is holding by some long time running thread

some low priority thread never get the resources

6:
All threads need this resource. Making these programs sequential.

7:
struct x{
    int a;
    int b;
}
struct x xx; <- xx.a & xx.b are laying on the same cache line

A: xx.a
B: xx.b

8:
t = 1;
all these t operations are atomic

wait(); == lock <- t++;

post(); == unlock <- t--;

only the thread which called wait() first, can call post()

9:
//https://github.com/glco/senate_bus/blob/master/senate_bus.c




