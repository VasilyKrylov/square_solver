#include "tests.h"

#include "solve.h"
#include "float_math.h"

#include <stdio.h>

bool TestAnswer(test tests, const double *result) {
    bool firstPermutation = IsEqual(tests.x1, result[0]) && IsEqual(tests.x2, result[1]);
    bool secondPermutation = IsEqual(tests.x1, result[1]) && IsEqual(tests.x2, result[0]);

    return (firstPermutation || secondPermutation);
}

bool TestNumberOfRoots(test tests, int nRoots) {
    return tests.nRoots == nRoots;
}

int TestSolveSquare() {
    test tests[] = {
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

    FILE *testsFile = fopen("tests.txt", "r");
    if (testsFile == NULL) {
       perror("Error opening file");
       return -1;
    }
    
    

    fclose(testsFile);

    
    for (size_t i = 0; i < sizeof(tests)/sizeof(tests[0]); ++i) {
        double results[2] = {0, 0};
        int nRoots = SolveSquare(tests[i].a, tests[i].b, tests[i].c, &results[0]);

        if (!TestAnswer(tests[i], results)) {
            printf(
                "FAILED(on test number %lu):\n"
                "\tSolveSquare(%lf, %lf, %lf) -> x1=%lf, x2=%lf.\n"
                "\tShould be x1=%lf, x2=%lf.\n", 
                i,
                tests[i].a, tests[i].b, tests[i].c,
                results[0], results[1],
                tests[i].x1, tests[i].x2
            );

            return -1;
        }

        if (!TestNumberOfRoots(tests[i], nRoots)) {
            printf(
                "FAILED(on test number %lu):\n"
                "\tSolveSquare(%lf, %lf, %lf) -> %d number of roots.\n"
                "\tShould be %d number of roots.\n", 
                i,
                tests[i].a, tests[i].b, tests[i].c,
                nRoots, tests[i].nRoots
            );

            return -1;
        }
    }

    return 0;
}
