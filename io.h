/**
 * @file
 * @brief Input-output system with input sanitation
 */

#ifndef SS_IO_H
#define SS_IO_H

#include "objects.h"

#include <stdio.h>

// INPUT FILE 
// MOVE TO tests.h
int ReadTestLine(FILE **file, Test *test);
bool FileCheckBuffer(FILE **file);


// INPUT TERMINAL
void SoberUp();
bool CheckBuffer();
int ReadDouble(double *a);
int InputDouble(const char *greeting, double *a); // move to .cpp
int InputCoefficients(double *a, double *b, double *c);

// OUTPUT TERMINAL
void PrintAnswer(const double answers[], int numberOfAnswers);

#endif // SS_IO_H
