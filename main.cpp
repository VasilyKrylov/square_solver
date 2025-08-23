#include <stdio.h>
#include <math.h>
#include <cassert>

#include "float_math.h"
#include "input.h"
#include "solve.h"



int printAnswer(const float answers[], int numberOfAnswers);






int printAnswer(const float answers[], const int numberOfAnswers) {
    if (numberOfAnswers == -1) {
        printf("Found infinite number of answers - ∞\n");
        return 0;
    }
    printf("Found %d number of answers\n", numberOfAnswers);
    for (int answerIndex = 0; answerIndex < numberOfAnswers; ++answerIndex) {
        printf("x%d = %f\n", answerIndex, answers[answerIndex]);
    }
    printf("\n");
    return 0;
}

int main() {
    float a = 0, b = 0, c = 0;
    int numberOfAnswers = 0;
    float answers[2] = {0};

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
            check float valids
            Book - 1.6
            doxygen
    */
    return 0;
}

