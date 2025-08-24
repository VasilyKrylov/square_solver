/**
 * @file
 * @brief Input-output system with input sanitazion
 */

#include "io.h"
#include "float_math.h"

#include <stdio.h>

const int MAX_ATTEMPTS = 5;

enum status {
    STATUS_OK = 0,
    STATUS_INF = 1,
    STATUS_NAN = 2,
    STATUS_NOT_DOUBLE = 3,
    STATUS_WITH_TRASH = 4
};

//--------------------------------------------------------------------------------------
// INPUT
//--------------------------------------------------------------------------------------

void SoberUp() {
    printf("User, looks you feels bad...\n"
           "Sober up and return later)\n");
}

// return 0 = ok
// return 1 = bad
bool CheckBuffer() {
    int countChars = 0;
    int trash = '\0';

    while (trash != '\n' && trash != EOF) {
        trash = getchar();
        ++countChars;
    }

    return countChars != 1;
}

/**
 * @param [in] a pointer to double to read
 * @returns OK if input clear
 *          one of enums if not
 *          see errors and errorMessages
 */
int ReadDouble(double *a) {
    int readArguments = scanf("%lf", a);
    printf("\n");

    if (IsInf(*a)) {
        return STATUS_INF;
    }
    if (IsNan(*a)) {
        return STATUS_NAN;
    }

    if (readArguments != 1) {
        CheckBuffer();
        return STATUS_NOT_DOUBLE;
    }
    if (CheckBuffer()) {
        return STATUS_WITH_TRASH;
    }

    return STATUS_OK;
}

int InputDouble(const char *greeting, double *a) {
    int attempts = MAX_ATTEMPTS;
    // printf("%s", greeting);


    while (1) {
        --attempts;

        if (!attempts) {
            SoberUp();
            return -1;
        } else {
            printf("%s", greeting);
        }
        
        
        int statusCode = ReadDouble(a);
        
        switch (statusCode)
        {
            case STATUS_OK:
                return 0;
                break;
            case STATUS_INF:
                printf("ERROR: You entered INF\n");
                break;
            case STATUS_NAN:
                printf("ERROR: You entered NAN\n");
                break;
            case STATUS_NOT_DOUBLE:
                printf("ERROR: You don't enter double\n");
                break;
            case STATUS_WITH_TRASH:
                printf("ERROR: You entered number with trash symbols\n");
                break;
            default:
                printf("ERROR: internal crush\n");
                break;

        }
    }
    
    return -1;
}

int InputCoefficients(double *a, double *b, double *c) {
    if (InputDouble("Input first coefficient in double format(0.5 for example):\n", a) != 0) {
        return -1;
    }
    if (InputDouble("Input second coefficient in double format(0.5 for example):\n", b) != 0) {
        return -1;
    }
    if (InputDouble("Input third coefficient in double format(0.5 for example):\n", c) != 0) {
        return -1;
    }

    printf("\nYour quadratic equation is :\n\t%lf*x^2 + %lf*x + %lf = 0\n", *a, *b, *c);

    return 0;
}
//--------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------
// OUTPUT
//--------------------------------------------------------------------------------------

int PrintAnswer(const double answers[], const int numberOfAnswers) {
    if (numberOfAnswers == -1) {
        printf("Found infinite number of answers - ∞\n");
        return 0;
    }

    printf("Found %d number of answers\n", numberOfAnswers);
    for (int answerIndex = 0; answerIndex < numberOfAnswers; ++answerIndex) {
        printf("\tx%d = %.20lg\n", answerIndex, answers[answerIndex]);
    }
    printf("\n");

    return 0;
}
//--------------------------------------------------------------------------------------