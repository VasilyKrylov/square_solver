#include "solve.h"

#include "float_math.h"

#include <stdio.h>
#include <math.h>

int SolveLinear(const double b, const double c,
                double *answers) {
    if (IsZero(b)) {
        return (IsZero(c) ? INF : ZERO);
    } else {
        if (IsZero(c)) {
            answers[0] = 0;
        } else {
            answers[0] = -c / b;
        }
        return ONE;
    }

    return ERROR;
}

/**
 * @param [in] a first coefficient of the quadratic equation
 * @param [in] b second coefficient of the quadratic equation
 * @param [in] c third coefficient of the quadratic equation
 * @param [out] answers return x1 and x2 if found
 * @returns number of found solves 
 */
int SolveSquare(const double a, const double b, const double c, 
                double *answers) {
    // assert(std::isfinite (a));
    // assert(std::isfinite (b));
    // assert(std::isfinite (c));

    if (IsZero(a)) {
        return SolveLinear(b, c, answers);
    }

    double discriminant = b * b - 4 * a * c;
    double sqrtDiscriminant = sqrt(discriminant);
    if (IsZero(discriminant)) {
        if (IsZero(b)) {
            answers[0] = 0;
        } else {
            answers[0] = -b / (2 * a);
        }
        return ONE;
    }
    if (discriminant < 0) {
        return ZERO;
    }

    answers[0] = (-b - sqrtDiscriminant) / (2 * a);
    answers[1] = (-b + sqrtDiscriminant) / (2 * a);
    normalizeZero(&answers[0]);
    normalizeZero(&answers[1]);
    return TWO;
}