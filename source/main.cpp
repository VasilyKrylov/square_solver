/**
 * @file
 */

#include "cli_arguments.h"
#include "float_math.h"
#include "io.h"
#include "solve.h"
#include "status_codes.h"
#include "tests.h"
#include "utils.h"

#include <stdio.h>
#include <math.h>
#include <cassert>
#include <float.h>

int main(int argc, char **argv) {
    ParseArguments(argc, argv);

    PrintHeader();

    int testsStatus = TestSolveSquare();

    if (testsStatus != 0) {
        ERROR("[ERROR] %d tests failed. Please contact with developer https://t.me/kvas1lek.\n", testsStatus);
        return 0;
    }

    Coefficients coeffs = {.a = 0, .b = 0, .c = 0};
    Answer answer = {.x1 = 0, .x2 = 0, .nRoots = 0};

    while (true) {
        if (InputCoefficients(&coeffs.a, &coeffs.b, &coeffs.c) == -1) {
            return 0;
        }

        int nRoots = SolveSquare(coeffs.a, coeffs.b, coeffs.c, &answer.x1, &answer.x2);

        PrintAnswer(answer.x1, answer.x2, nRoots);
    }

    return 0;
}

/*
TODO:
    assert with inserting roots into equation
    sizeof(doubleArguments)/sizeof(doubleArguments[0]) replace to define
    make function statusDescription:
        gets enum status
        return char* error code
    --tests
    --debug
    tests ignore unused answers
    colored output
    makefile


*/
