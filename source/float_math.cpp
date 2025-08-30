#include "float_math.h"

#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <assert.h>

static const double EPS = 1.11e-16; // https://en.wikipedia.org/wiki/Machine_epsilon

bool IsNan(double a) {
    return isnan(a);
}

bool IsInf(double a) {
    // compiler can break "a - a" with O3 or fastmath meow
    return !isnan(a) && isnan(a - a); 
} 

bool IsEqual(double a, double b) {
    assert(IsFinite(a));
    assert(IsFinite(b));

    return abs(a - b) <= EPS;
}

bool IsZero(double a) {
    assert(IsFinite(a));
    return IsEqual(a, 0);
}

bool IsFinite(double a) {
    return !IsInf(a) && !IsNan(a);
}

void normalizeZero(double *a) {
    assert(IsFinite(*a));
    if (IsZero(*a)) {
        *a = 0;
    }
}