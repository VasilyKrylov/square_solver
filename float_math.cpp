#include <stdio.h>
#include <math.h>

#include "float_math.h"

const float EPS = 1e-9f;

int isEqual(float a, float b) {
    return abs(a - b) <= EPS;
}
int isZero(float a) {
    return isEqual(a, 0);
}