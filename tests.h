#ifndef SS_TESTS_H
#define SS_TESTS_H

#include "objects.h"

#include <stdlib.h>


bool TestAnswer(Test tests, const double *result);
bool TestNumberOfRoots(Test tests, int nRoots);
int ReadTestsFromFile(const char *filename, Test **testsFromFilePointer, size_t numberOfTests);
int enumerateThrowTestSet(Test *tests, size_t length);
int ReadTests();
int TestSolveSquare();

#endif // SS_TESTS_H