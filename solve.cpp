#include <stdio.h>
#include <math.h>

#include "solve.h"
#include "float_math.h"

int solveLinear(const float b, const float c,
                int* numberOfAnswers, float *answers) {
    if (isZero(b)) {
        if (isZero(c)) {
            *numberOfAnswers = -1;
            return 0;
        } else {
            *numberOfAnswers = 0;
            return 0;
        }
    } else {
        *numberOfAnswers = 1;
        if (isZero(c)) {
            answers[0] = 0;
        } else {
            answers[0] = -c / b;
        }
        return 0;
    }
    return 0;
}

int solveSquare(const float a, const float b, const float c, 
                int *numberOfAnswers, float *answers) {
    // assert(std::isfinite (a));
    // assert(std::isfinite (b));
    // assert(std::isfinite (c));

    if (isZero(a)) {
        solveLinear(b, c, numberOfAnswers, answers);
        return 0;
    }
    float discriminant = b * b - 4 * a * c;
    float sqrtDiscriminant = sqrt(discriminant);
    if (isZero(discriminant)) {
        *numberOfAnswers = 1;
        if (isZero(b)) {
            answers[0] = 0;
        } else {
            answers[0] = -b / (2 * a);
        }
        return 0;
    }
    else if (discriminant < 0) {
        *numberOfAnswers = 0;
        return 0;
    }
    else {
        *numberOfAnswers = 2;
        answers[0] = (-b - sqrtDiscriminant) / (2 * a);
        answers[1] = (-b + sqrtDiscriminant) / (2 * a);
        if (isZero(answers[0])) {
            answers[0] = 0;
        }
        if (isZero(answers[1])) {
            answers[1] = 0;
        }
        return 0;
    }
    return 0;
}