#ifndef SS_IO_H
#define SS_IO_H

#include "objects.h"

#include <stdio.h>

// INPUT FILE
int ReadTestLine(FILE **file, Test *test);
bool FileCheckBuffer(FILE **file);


// INPUT TERMINAL
void SoberUp();
bool CheckBuffer();
int ReadDouble(double *a);
int InputDouble(const char *greeting, double *a);
int InputCoefficients(double *a, double *b, double *c);

// OUTPUT TERMINAL
void PrintAnswer(const double answers[], int numberOfAnswers);

#endif // SS_IO_H
