#ifndef SS_TESTS_H
#define SS_TESTS_H

#include "structures.h"

#include <stdlib.h>


// MOVE SOME FUNCTIONS TO .cpp
// sructure Test MUST BE HERE 
bool TestAnswer(Test tests, const double *result);
bool TestNumberOfRoots(const Test *tests, int nRoots);
int ReadTestsFromFile(const char *filename, Test **testsFromFilePointer, size_t *numberOfTests);
int enumerateThrowTestSet(Test *tests, size_t length);
int ReadTests();
int TestSolveSquare();

#endif // SS_TESTS_H