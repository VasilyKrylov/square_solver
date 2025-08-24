#ifndef SS_TESTS_H
#define SS_TESTS_H

struct test {
    double a, b, c;
    double x1, x2;
    int nRoots;
};

bool TestAnswer(test tests, const double *result);
bool TestNumberOfRoots(test tests, int nRoots);
int TestSolveSquare();

#endif // SS_TESTS_H