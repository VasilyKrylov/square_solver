/**
 * @file
 * @brief Functions for comparison double values
 */
#include "float_math.h"

#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <assert.h>

const double EPS = 1.11e-16; // https://en.wikipedia.org/wiki/Machine_epsilon

bool IsNan(double a) {
    return isnan(a);
}

bool IsInf(double a) {
    return !isnan(a) && isnan(a - a); // compiler can break "a - a" with O3 or fastmath idk
} 

bool IsEqual(double a, double b) {
    assert(isfinite(a));
    assert(isfinite(b));

    return abs(a - b) <= EPS;
}

bool IsZero(double a) {
    assert(isfinite(a));
    return IsEqual(a, 0);
}

void normalizeZero(double *a) {
    assert(isfinite(*a));
    if (IsZero(*a)) {
        *a = 0;
    }
}