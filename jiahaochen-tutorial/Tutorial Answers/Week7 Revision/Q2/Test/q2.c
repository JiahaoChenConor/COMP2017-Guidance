

int x = 10;

extern int y;

static int z;

int add(int a, int b);

extern int multiply(int a, int b);
int add(int a, int b) {
    return a + b;
}
static int subtract(int a, int b);
static int subtract(int a, int b) {
    return a - b;
}

int main(void) {
    return 0;
}
