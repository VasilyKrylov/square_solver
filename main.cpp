#include "float_math.h"
#include "io.h"
#include "solve.h"
#include "tests.h"

#include <stdio.h>
#include <math.h>
#include <cassert>
#include <float.h>

static const char *greeting = 
    "The quadratic equation solver\n"
    "Vasily Krylov 2025\n"
    " ,_     _\n"
    " |\\_,-~/\n"
    " / _  _ |    ,--.\n"
    "(  @  @ )   / ,-'\n"
    " \\  _T_/-._( (\n"
    " /         `. \\\n"
    "|         _  \\ |\n"
    " \\ \\ ,  /      |\n"
    "  || |-_\\__   /\n"
    " ((_/`(____,-'\n";


int main(/*int argc, char **argv, char **envp*/) {
    printf("%s", greeting); // add another function

    // fprintf(stdout, "%s:%d:%s [DEBUG]: Code works\n", __FILE__, __LINE__, __func__);
    int testsStatus = TestSolveSquare();

    if (testsStatus == -1) {
        printf("[ERROR] TestSolveSquare() failed. Please contact with developer\n");
        return 0;
    }
    if (testsStatus) {
        printf("[ERROR] %d tests failed. Please contact with developer https://t.me/kvas1lek\n", testsStatus);
        return 0;
    }
    // fprintf(stdout, "%s:%d:%s [DEBUG]: Code works\n", __FILE__, __LINE__, __func__);


    double a = 0, b = 0, c = 0;
    double answers[2] = {0}; //make it in structure

    while (true) {
        if (InputCoefficients(&a, &b, &c) == -1) {
            return 0;
        }
        int nRoots = SolveSquare(a, b, c, answers);
        PrintAnswer(answers, nRoots);
    }

    return 0;
}


/*
TODO:
    move docs from cpp to headers
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
    doxygen continue

*/