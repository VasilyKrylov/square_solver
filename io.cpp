#include "io.h"

#include "float_math.h"
#include "objects.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

const int MAX_ATTEMPTS = 5;

//--------------------------------------------------------------------------------------
// FILE INPUT
//--------------------------------------------------------------------------------------

/**
 * @brief check for trash chars in file buffer after fscanf() call
 * @param [in] file to check
 * @returns 0 if buffer clear\n
 *          1 if not
 */
bool FileCheckBuffer(FILE **file) { // make one start lol *******************
    int countChars = 0;
    int trash = '\0';

    while (trash != '\n' && trash != EOF) {
        trash = fgetc(*file);
        ++countChars;
    }

    return countChars != 1;
}

/**
 * @brief sanitize input from tests file
 * @param [in] file to read tests from
 * @returns enum Status
 */
int ReadTestLine(FILE **file, Test *test) {
    assert(test != NULL);

    int readArguments = fscanf(
        *file,
        "%lf %lf %lf %lf %lf %d",
        &test->a, &test->b, &test->c,
        &test->x1, &test->x2, &test->nRoots
    );

    if (readArguments != 6) {
        FileCheckBuffer(file);
        return STATUS_NOT_DOUBLE;
    }
    if (FileCheckBuffer(file)) {
        return STATUS_WITH_TRASH;
    }

    double doubleArguments[] = {
        test->a, test->b, test->c, test->x1, test->x2
    };

    for (size_t i = 0; i < sizeof(doubleArguments)/sizeof(doubleArguments[0]); ++i) {
        if (IsInf(doubleArguments[i])) {
            return STATUS_INF;
        }
        if (IsNan(doubleArguments[i])) {
            return STATUS_NAN;
        }
    }

    return STATUS_OK;
}

//--------------------------------------------------------------------------------------
// STDIN INPUT
//--------------------------------------------------------------------------------------

void SoberUp() {
    printf("User, looks you feels bad...\n"
           "Sober up and return later)\n");
}

/**
 * @brief check for trash chars in stdin buffer after scanf() call
 * @returns 0 if buffer clear\n
 *          1 if not
 */
bool CheckBuffer() {
    int countChars = 0;
    int trash = '\0';
    
    while (trash != '\n' && trash != EOF) {
        trash = getchar();
        ++countChars;
    }
    
    return countChars != 1;
    // return FileCheckBuffer(stdin);
}


/**
 * @brief Check if input is correct(without trash symbols, without nan and inf)
 * @param [in] a pointer to double to read
 * @returns enum STATUS_[something]\n
 *          InputDouble() processes this return codes
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

    // also clears buffer
    bool hasTrash = CheckBuffer();
    if (readArguments != 1) {
        return STATUS_NOT_DOUBLE;
    }
    if (hasTrash) {
        return STATUS_WITH_TRASH;
    }

    return STATUS_OK;
}

/**
 * @brief request user to input double until correct attempt
 * @param [in] a pointer to double to read
 * Check if input is correct(without trash symbols, without nan and inf) \n
 * @returns enum Status \n
 *          InputDouble() processes this return codes
 */
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
            case STATUS_INF:
                printf("You entered INF\n");
                break;
            case STATUS_NAN:
                printf("You entered NAN\n");
                break;
            case STATUS_NOT_DOUBLE:
                printf("You don't enter double\n");
                break;
            case STATUS_WITH_TRASH:
                printf("You entered number with trash symbols\n");
                break;
            default:
                assert(0 && "[ERROR]: Unknown status from user");
                break;

        }
    }

    return -1;
}

/**
 * @brief request for coefficients of quadratic equation and shows user input
 * @param [in] a pointer to first coefficient
 * @param [in] b pointer to second coefficient
 * @param [in] c pointer to third coefficient
 * @returns enum STATUS_[something] \n
 *          InputDouble() processes this return codes
 */
int InputCoefficients(double *a, double *b, double *c) {
    if (InputDouble("Input coefficient as float number (0.5 for example):\n", a) != 0) {
        return -1;
    }
    if (InputDouble("Input second coefficient as float number (0.5 for example):\n", b) != 0) {
        return -1;
    }
    if (InputDouble("Input third coefficient as float number (0.5 for example):\n", c) != 0) {
        return -1;
    }

    printf("\nYour quadratic equation is :\n\t%lf*x^2 + %lf*x + %lf = 0\n", *a, *b, *c);

    return 0;
}

//--------------------------------------------------------------------------------------
// OUTPUT
//--------------------------------------------------------------------------------------

/**
 * @brief Print answers to stdout
 * @param [in] answers values to print
 * @param [in] numberOfAnswers how many answers found
 */
void PrintAnswer(const double answers[], const int numberOfAnswers) {
    if (numberOfAnswers == -1) { // ADD ENUM HERE !!!!!!
        printf("Found infinite number of answers - ∞\n");
    }

    printf("Found %d number of answers\n", numberOfAnswers);
    for (int answerIndex = 0; answerIndex < numberOfAnswers; ++answerIndex) {
        printf("\tx%d = %.20lg\n", answerIndex, answers[answerIndex]);
    }
    printf("\n");
}
//--------------------------------------------------------------------------------------
