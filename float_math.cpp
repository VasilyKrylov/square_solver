/**
 * @file
 * @brief Function for comparison double values
 */
#include "float_math.h"

#include <stdio.h>
#include <math.h>
#include <limits.h>

const double EPS = 1.11e-16; // https://en.wikipedia.org/wiki/Machine_epsilon

int IsNan(double a) {
    return isnan(a);
}

int IsInf(double a) {
    return !isnan(a) && isnan(a - a);
} 

int IsEqual(double a, double b) {
    return abs(a - b) <= EPS;
    isfinite(a);
}

int IsZero(double a) {
    return IsEqual(a, 0);
}

void normalizeZero(double *a) {
    if (IsZero(*a)) {
        *a = 0;
    }
    return;
}