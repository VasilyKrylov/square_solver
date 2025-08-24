/**
 * @file
 * @brief main file 
 */

#include "float_math.h"
#include "io.h"
#include "solve.h"
#include "tests.h"

#include <stdio.h>
#include <math.h>
#include <cassert>


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


/**
 * Entry point of the program
 */
int main(int argc, char **argv, char **envp) {
    printf("%s", greeting);
        
    if (TestSolveSquare() != 0) {
        printf("Internal test failed. Please contact with developer");
        return 0;
    }
        
    double a = 0, b = 0, c = 0;
    double answers[2] = {0};

    while (true) {
        if (InputCoefficients(&a, &b, &c) == -1) {
            return 0;
        }
        int nRoots = SolveSquare(a, b, c, answers);
        PrintAnswer(answers, nRoots);
    }

    /*
        TODO:
            tests from file
            fix nan and inf input
            what is assert
            doxygen continue
            EOF - echo "121qwe" | ./main 
            add more tests
            ctl + shift +h - camelCase to PascalCase
    */
    return 0;
}

