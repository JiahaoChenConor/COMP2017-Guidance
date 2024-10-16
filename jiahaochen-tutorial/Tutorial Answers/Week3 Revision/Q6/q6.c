#include <stdio.h>
#include <math.h>

// #define PI 3.1415

int main () {
    // const float PI = 3.1415;
    float r = 0;

    printf("Specify the radius of the sphere: ");
    scanf("%f", &r);
    

    // do not 4/3 => 1       int/int => int   at least one of them should be float
    printf("Volume is: %f\n", 4/3.0 * M_PI * pow(r, 3));

}