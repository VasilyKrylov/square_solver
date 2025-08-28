/**
 * @file
 */

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

int main(/*int argc, char **argv, char **envp*/) {
    PrintHeader();
    
    int testsStatus = TestSolveSquare();

    if (testsStatus == -1) {
        ERROR("[ERROR] %d tests failed. Please contact with developer https://t.me/kvas1lek.\n", testsStatus);
        return 0;
    }

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
    (i do not care about this now): 
        inconsistency with x1 and x2 in structures and answers (switch to x1, x2)

    DOING: move docs from cpp to headers
    ReadTestsFromFile comment - Divide no right to read and no file to read
    sizeof(doubleArguments)/sizeof(doubleArguments[0]) replace to defines    
    make function statusDescription:
        gets enum status
        return char* error code
FIRST:
        ReadTestLine
    HARD:
        Make input of a, b, c in one file(and make it safe)
        CRITICAL:
            MAKE SAFE INPUT in tests.cpp

    --tests
    --debug
    tests ignore unused answers
    colored output
    makefile


    tests for user incorrect input
*/