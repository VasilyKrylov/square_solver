#include <stdio.h>
#include <math.h>

#include "float_math.h"

const double EPS = 1e-9f;

int isEqual(double a, double b) {
    return abs(a - b) <= EPS;
}
int isZero(double a) {
    return isEqual(a, 0);
}