#include "float_math.h"
#include "io.h"
#include "solve.h"
#include "tests.h"

#include <stdio.h>
#include <math.h>
#include <cassert>
#include <float.h>


const char *greeting = "The quadratic equation solver\n"
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
    printf("%s", greeting);

    fprintf(stdin, "%s:%d:%s [DEBUG]: Code works\n", __FILE__, __LINE__, __func__);
    int testsStatus = TestSolveSquare();
    fprintf(stdin, "%s:%d:%s [DEBUG]: Code works\n", __FILE__, __LINE__, __func__);

    if (testsStatus == -1) {
        printf("[ERROR] TestSolveSquare() failed. Please contact with developer\n");
        return 0;
    }
    if (testsStatus) {
        printf("[ERROR] %d tests failed. Please contact with developer\n", testsStatus);
        return 0;
    }
    fprintf(stdin, "%s:%d:%s [DEBUG]: Code works\n", __FILE__, __LINE__, __func__);


    double a = 0, b = 0, c = 0;
    double answers[2] = {0};

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
    FIRST:
        ReadTestLine
    HARD:
        Make input of a, b, c in one file(and make it safe)
        CRITICAL:
            MAKE SAFE INPUT in tests.cpp

    tests from file
    what is assert
    doxygen continue
    add more tests
    ctl + shift +h - camelCase to PascalCase
*/