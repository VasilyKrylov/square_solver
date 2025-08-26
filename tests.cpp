#include "tests.h"

#include "float_math.h"
#include "io.h"
#include "solve.h"
#include "status_codes.h"

#include <stdio.h>
#include <stdlib.h>


/**
 * @brief check excepted answer and real result
 */
bool TestAnswer(Test test, const double *result) { //result1, result2
    bool firstPermutation = IsEqual(test.x1, result[0]) && IsEqual(test.x2, result[1]);
    bool secondPermutation = IsEqual(test.x1, result[1]) && IsEqual(test.x2, result[0]);

    return (firstPermutation || secondPermutation);
}

/**
 * @brief check excepted number of roots and real one
 */
bool TestNumberOfRoots(const Test *tests, int nRoots) {
    return tests->nRoots == nRoots;
}

/**
 * @brief gives array and it's size
 * @param [out] testsFromFile array of tests
 * @param [out] testsFromFile len of numberOfTests
 *
 * Format of tests in file:
 * First line = number of tests
 * next lines = a, b, c, d, x1, x2, numberOfRoots separated by \\t
 * @returns number of test sets which contain errors
 */
int ReadTestsFromFile(const char *filename, Test **testsFromFilePointer, size_t *numberOfTests) {
    FILE *testsFile = fopen(filename, "r");
    if (testsFile == NULL) {
        // !!!!!!!!
        // Divide no right to read and no file to read
        printf("Error opening file \"%s\" with tests!\n", filename);

       return -1;
    }

    *numberOfTests = 0;
    fscanf(testsFile, "%lu\n", numberOfTests);
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11
    // DELELE numberOfTests and use realloc()

    // CHECK FOR NULL 
    // VERY IMPORTANT !!!!!!
    Test *testsFromFile = (Test *)(calloc(*numberOfTests, sizeof(Test)));

    for (size_t i = 0; i < *numberOfTests; ++i) {

        int ReadTestLineStatus = ReadTestLine(testsFile, &testsFromFile[i]);
        switch (ReadTestLineStatus)
        {
            case STATUS_OK:
                break;
            case STATUS_INF:
                printf("[ERROR]: %s contains incorrect test. INF value on line %lu. \n", filename, i + 2);
                break;
            case STATUS_NAN:
                printf("[ERROR]: %s contains incorrect test. NAN value on line %lu. \n", filename, i + 2);
                break;
            case STATUS_NOT_DOUBLE:
                printf("[ERROR]: %s contains incorrect test. No double on line %lu. \n", filename, i + 2);
                break;
            case STATUS_WITH_TRASH:
                printf("[ERROR]: %s contains incorrect test. Trash symbols on line %lu. \n", filename, i + 2);
                break;
            default:
                // assert(0 && "%s:%d:%s [ERROR]: internal crush - \n", __FILE__, __LINE__, __func__);
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

    return 0;
}

/**
 * @brief run test on SolveSquare with given tests
 * @param [in] tests array of tests
 * @param [out] length length of tests array
 */
int enumerateThrowTestSet(Test *tests, size_t length) {
    int failedTests = 0;

    for (size_t i = 0; i < length; i++) {
        double results[2] = {0, 0};
        int nRoots = SolveSquare(tests[i].a, tests[i].b, tests[i].c, &results[0]);

        // log.txt
        // print good

        if (!TestAnswer(tests[i], results)) {
            printf(
                "FAILED(on test number %lu):\n"
                "\tSolveSquare(%lf, %lf, %lf) -> x1=%lf, x2=%lf.\n"
                "\tShould be x1=%lf, x2=%lf.\n\n",
                i + 1,
                tests[i].a, tests[i].b, tests[i].c,
                results[0], results[1],
                tests[i].x1, tests[i].x2
            );

            failedTests++;
        }

        if (!TestNumberOfRoots(&tests[i], nRoots)) {
            printf(
                "FAILED(on test number %lu):\n"
                "\tSolveSquare(%lf, %lf, %lf) -> %d number of roots.\n"
                "\tShould be %d number of roots.\n\n",
                i,
                tests[i].a, tests[i].b, tests[i].c,
                nRoots, tests[i].nRoots
            );

            failedTests++;
        }
    }

    return failedTests;
}

/**
 * @brief get test sets and run enumerateThrowTestCase()
 *
 * @returns number of failed tests and -1 if error appeared in function // do failed/total
 */
int TestSolveSquare() {
    Test testsHardcoded[] = {
        //-------------------------------------------------------------------------------------+
        //a     b       c       x1                          x2                          nRoots//
        {23,    8,  -2006,      -9.5145574029986317299,     9.1667313160421084461,      TWO},
        {0,     0,      0,      0,                          0,                          INF},
        {1,     0,      0,      0,                          0,                          ONE},
        {0,     1,      0,      0,                          0,                          ONE},
        {0,     0,      1,      0,                          0,                          ZERO},
        {1,     -5,     6,      2,                          3,                          TWO},
        {1,     4,      4,      -2,                         0,                          ONE}
        //-------------------------------------------------------------------------------------+
    };

    // fprintf(stdout, "%s:%d:%s [DEBUG]: Code works\n", __FILE__, __LINE__, __func__);

    int totalFailedTests = 0;
    Test* testSetFromFile = NULL;
    size_t numberOfTests = 0;

    if (ReadTestsFromFile("tests.txt", &testSetFromFile, &numberOfTests) == 0) {
        totalFailedTests += enumerateThrowTestSet(testSetFromFile, numberOfTests);
    } else {
        return -1;
    }
    free(testSetFromFile);
    
    // fprintf(stdout, "%s:%d:%s [DEBUG]: local tests from testsHardcoded[]\n\n", __FILE__, __LINE__, __func__);
    totalFailedTests += enumerateThrowTestSet(
        testsHardcoded,
        sizeof(testsHardcoded)/sizeof(testsHardcoded[0])
    );
    
    return totalFailedTests;
}
