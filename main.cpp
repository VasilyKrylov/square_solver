#include <stdio.h>
#include <math.h>
#include <cassert>

#include "float_math.h"
#include "io.h"
#include "solve.h"






int main() {
    double a = 0, b = 0, c = 0;
    int numberOfAnswers = 0;
    double answers[2] = {0};

    printf("The quadratic equation solver\n");
    printf("Vasily Krylov 2025\n\n");

    while (true) {
        if (inputCoefficients(&a, &b, &c) == -1) {
            return 0;
        }
        solveSquare(a, b, c, &numberOfAnswers, answers);
        printAnswer(answers, numberOfAnswers);
    }

    /*
        TODO:
            what is assert
            check double valids
            Book - 1.6
            doxygen
            replace double to double
    */
    return 0;
}

