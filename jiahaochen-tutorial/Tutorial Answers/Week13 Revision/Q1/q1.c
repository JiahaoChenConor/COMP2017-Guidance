1. 
a: random value (garbage)

b: 16 bytes. <- assume no padding, 8+4=12

c: 8 bytes

d: 8 bytes 

e:  16 * 100

f: + 50 * 16

g: - 30 * 16

h: 

arrs:  1st: data + len + 4paddings + 2nd: data + len + 4padding + ..... 50th: data + len + 4padding
   
   
    answer: - 8

2.
Assume a 64 bit system, where the sizeof(int) is 4 bytes, 
and sizeof(float) is also 4 byte


union answer {
    int x; 
    double y; // 4
}


a: 4

b: 
stack:
ptr, x

heap:
the thing that ptr points to (*ptr)

static:
count

c: 
all the var in stack should be died after the g function dies.

heap: whenever they gets freed / the program dies

static: till program dies

