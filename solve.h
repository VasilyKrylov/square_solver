#ifndef SS_SOLVE_H
#define SS_SOLVE_H

enum nRoots {
    INF = -1,
    ZERO = 0,
    ONE = 1,
    TWO = 2
}; // move to io.h

int SolveLinear(double b, double c, double *answers);
int SolveSquare(double a, double b, double c, double *answers);

#endif // SS_SOLVE_H