#include "solve.h"

#include "float_math.h"
#include "status_codes.h"
#include "structures.h"

#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

int SolveLinear(const double b, const double c,
                double *x1) {
    *x1 = NAN;

    if (IsZero(b)) {
        return (IsZero(c) ? INF_ROOTS : ZERO_ROOTS);
    }
    if (IsZero(c)) {
        *x1 = 0;
    }
    else {
        *x1 = -c / b;
    }

    return ONE_ROOT;
}


int SolveSquare(const double a, const double b, const double c,
                double *x1, double *x2) {
    assert(IsFinite(a));
    assert(IsFinite(b));
    assert(IsFinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    *x1 = NAN;
    *x2 = NAN;

    if (IsZero(a)) {
        return SolveLinear(b, c, x1);
    }

    double discriminant = b * b - 4 * a * c;

    if (IsZero(discriminant)) {
        if (IsZero(b)) {
            *x1 = 0;
        }
        else {
            *x1 = -b / (2 * a);
        }

        return ONE_ROOT;
    }

    if (discriminant < 0) {
        return ZERO_ROOTS;
    }

    double sqrtDiscriminant = sqrt(discriminant);

    *x1 = (-b - sqrtDiscriminant) / (2 * a);
    *x2 = (-b + sqrtDiscriminant) / (2 * a);

    normalizeZero(x1);
    normalizeZero(x2);

    return TWO_ROOTS;
}
