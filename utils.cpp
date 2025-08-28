// #include <stdio.h>
#include "utils.h"

void swap(double *a, double *b) {
    double c = *b;
    *b = *a;
    *a = c;
}

// int main() {
//     double aa = 5;
//     double bb = 10;
    
//     swap(&aa, &bb);

//     printf("%lf %lf", aa, bb);

//     return 0;
// }