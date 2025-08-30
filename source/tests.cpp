#include "tests.h"

#include "float_math.h"
#include "io.h"
#include "solve.h"
#include "status_codes.h"
#include "structures.h"
#include "utils.h"

#include <assert.h>
#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Check excepted answer and real result
 * @param [in] test Test sample from file (correct answer to compare with)
 * @param [in] x1 Calculated x1 by current program
 * @param [in] x2 Calculated x2 by current program
 * @param [in] nRoots number of roots calculated by current program
 *
 */
bool TestAnswer(Test test, double *x1, double *x2, int nRoots);

/**
 * @brief run test on SolveSquare with given tests
 * @param [in] tests array of tests
 * @param [out] length length of tests array
 */
int enumerateThrowTestSet(Test *tests, size_t length);

/**
 * @brief Gives array and it's size
 * @param [out] testsFromFile Array of tests
 * @param [out] testsFromFile Len of numberOfTests
 *
 * Format of tests in file:
 * First line = number of tests
 * next lines = a, b, c, d, x1, x2, numberOfRoots separated by \\t
 * @returns number of test sets which contain errors
 */
int ReadTestsFromFile(const char *filename, Test **testsFromFilePointer, size_t *numberOfTests);

/**
 * @brief check excepted number of roots and real one
 */
bool TestNumberOfRoots(const Test *tests, int nRoots);

// --------------------------------------------------------------------------------------------

bool TestAnswer(Test test, double *x1, double *x2, int nRoots) {
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    switch (nRoots)
    {
        case INF_ROOTS:
        case ZERO_ROOTS:
            return IsNan(test.x1) && IsNan(test.x2) && IsNan(*x1) && IsNan(*x2);

        case ONE_ROOT:
            return IsEqual(test.x1, *x1) && IsNan(test.x2) && IsNan(*x2);

        case TWO_ROOTS:
        {
            // Pseudo sort here:)
            if (*x1 > *x2) {
                swap(x1, x2);
            }
            if (test.x1 > test.x2) {
                swap(&test.x1, &test.x2);
            }

            return IsEqual(test.x1, *x1) && IsEqual(test.x2, *x2);
        }

        default:
            ERROR("%s: %s:%d: [ERROR]: Uknown number of roots.\n", __func__, __FILE__, __LINE__);
            abort();
    }
}

bool TestNumberOfRoots(const Test *tests, int nRoots) {
    return tests->nRoots == nRoots;
}

int ReadTestsFromFile(const char *filename, Test **testsFromFilePointer, size_t *numberOfTests) {
    FILE *testsFile = fopen(filename, "r");

    if (testsFile == NULL) {
        ERROR("[ERROR] opening file \"%s\" with tests: %s\n", filename, strerror(errno));
        abort();
    }

    *numberOfTests = 0;
    size_t bufferSize = 10;
    fscanf(testsFile, "%lu\n", numberOfTests);
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11
    // DELELE numberOfTests and use realloc()

    Test *testsFromFile = (Test *)(calloc(*numberOfTests, sizeof(Test)));

    if (testsFromFile == NULL) {
        ERROR("[ERROR] opening file \"%s\" with tests: %s\n", filename, strerror(errno));
        abort();
    }

    int incorrectLines = 0;

    for (size_t i = 0; i < *numberOfTests; ++i) {

        int ReadTestLineStatus = ReadTestLine(testsFile, &testsFromFile[i]);
        switch (ReadTestLineStatus)
        {
            case STATUS_OK:
                // *numberOfTests++;
                // if (*numberOfTests % 10 == 0) {
                //     realloc(testsFromFile, *numberOfTests + bufferSize);
                // }
                break;

            case STATUS_INF:
                incorrectLines++;
                printf("[ERROR]: %s contains incorrect test. INF value on line %lu. \n", filename, i + 2);
                break;
            case STATUS_NAN:
                incorrectLines++;
                printf("[ERROR]: %s contains incorrect test. NAN value on line %lu. \n", filename, i + 2);
                break;
            case STATUS_NOT_DOUBLE:
                incorrectLines++;
                printf("[ERROR]: %s contains incorrect test. No double on line %lu. \n", filename, i + 2);
                break;
            case STATUS_WITH_TRASH:
                incorrectLines++;
                printf("[ERROR]: %s contains incorrect test. Trash symbols on line %lu. \n", filename, i + 2);
                break;

            default:
                ERROR("%s: %s:%d: [ERROR]: Uknown status of number.\n", __func__, __FILE__, __LINE__);
                abort();
                break;
        }
        // fscanf(
        //     testsFile,
        //     "%lg\t%lg\t%lg\t%lg\t%lg\t%d",
        //     &testsFromFile[i].a, &testsFromFile[i].b, &testsFromFile[i].c,
        //     &testsFromFile[i].x1, &testsFromFile[i].x2,
        //     &testsFromFile[i].nRoots
        // );

        // printf("[DEBUG]:%lg\t%lg\t%lg\t%lg\t%lg\t%d\n",
        //     testsFromFile[i].a, testsFromFile[i].b, testsFromFile[i].c,
        //     testsFromFile[i].x1, testsFromFile[i].x2,
        //     testsFromFile[i].nRoots
        // );
    }

    *testsFromFilePointer = testsFromFile;

    fclose(testsFile);

    return incorrectLines;
}


int enumerateThrowTestSet(Test *tests, size_t length) {
    int failedTests = 0;

    for (size_t i = 0; i < length; i++) {
        Answer answer = {.x1 = 0, .x2 = 0, .nRoots = 0};

        answer.nRoots = SolveSquare(tests[i].a, tests[i].b, tests[i].c, &answer.x1, &answer.x2);

        // log.txt
        // print good

        if (!TestAnswer(tests[i], &answer.x1, &answer.x2, answer.nRoots)) {
            printf(
                "FAILED(on test number %lu):\n"
                "\tSolveSquare(%lf, %lf, %lf) -> x1=%lf, x2=%lf.\n"
                "\tShould be x1=%lf, x2=%lf.\n\n",
                i + 1,
                tests[i].a, tests[i].b, tests[i].c,
                answer.x1, answer.x2,
                tests[i].x1, tests[i].x2
            );

            failedTests++;
        }

        if (!TestNumberOfRoots(&tests[i], answer.nRoots)) {
            printf(
                "FAILED(on test number %lu):\n"
                "\tSolveSquare(%lf, %lf, %lf) -> %d number of roots.\n"
                "\tShould be %d number of roots.\n\n",
                i,
                tests[i].a, tests[i].b, tests[i].c,
                answer.nRoots, tests[i].nRoots
            );

            failedTests++;
        }
    }

    return failedTests;
}

int TestSolveSquare() {
    Test testsHardcoded[] = {
        //-------------------------------------------------------------------------------------+
        //a     b       c       x1                          x2                          nRoots//
        {23,    8,  -2006,      -9.5145574029986317299,     9.1667313160421084461,      TWO_ROOTS},
        {0,     0,      0,      NAN,                        NAN,                        INF_ROOTS},
        {1,     0,      0,      0,                          NAN,                        ONE_ROOT},
        {0,     1,      0,      0,                          NAN,                        ONE_ROOT},
        {0,     0,      1,      NAN,                        NAN,                        ZERO_ROOTS},
        {1,     -5,     6,      2,                          3,                          TWO_ROOTS},
        {1,     4,      4,      -2,                         NAN,                        ONE_ROOT}
        //-------------------------------------------------------------------------------------+
    };

    // fprintf(stdout, "%s:%d:%s [DEBUG]: Code works\n", __FILE__, __LINE__, __func__);

    int totalFailedTests = 0;
    Test* testSetFromFile = NULL;
    size_t numberOfTests = 0;

    int incorrectLines = ReadTestsFromFile("tests.txt", &testSetFromFile, &numberOfTests);

    if (incorrectLines == 0) {
        totalFailedTests += enumerateThrowTestSet(testSetFromFile, numberOfTests);
    }
    else {
        ERROR("%s: %s:%d: [ERROR]: %d lines of file with tests contain errors.\n", __func__, __FILE__, __LINE__, incorrectLines);
        abort();
    }

    free(testSetFromFile);

    // fprintf(stdout, "%s:%d:%s [DEBUG]: local tests from testsHardcoded[]\n\n", __FILE__, __LINE__, __func__);
    totalFailedTests += enumerateThrowTestSet(
        testsHardcoded,
        sizeof(testsHardcoded)/sizeof(testsHardcoded[0])
    );

    return totalFailedTests;
}
