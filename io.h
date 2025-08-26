/**
 * @file
 * @brief Input-output system with input sanitation \n 
 *        Works with stdin, stdout, file descriptors
 */

#ifndef SS_IO_H
#define SS_IO_H

#include "structures.h"

#include <stdio.h>

// INPUT FILE 

/**
 * @brief sanitize input from tests file
 * @param [in] file to read tests from
 * @returns enum Status
 */
int ReadTestLine(FILE *file, Test *test);

//--------------------------------------------------------------------------------------
// STDIN INPUT
//--------------------------------------------------------------------------------------

/**
 * @brief request user to input double until correct attempt
 * @param [in] a pointer to double to read
 * Check if input is correct(without trash symbols, without nan and inf) \n
 * @returns enum Status \n
 *          InputDouble() processes this return codes
 */
int InputDouble(const char *greeting, double *a);

/**
 * @brief request for coefficients of quadratic equation and shows user input
 * @param [in] a pointer to first coefficient
 * @param [in] b pointer to second coefficient
 * @param [in] c pointer to third coefficient
 * @returns enum STATUS_[something] \n
 *          InputDouble() processes this return codes
 */
int InputCoefficients(double *a, double *b, double *c);

//--------------------------------------------------------------------------------------
// STDOUT OUTPUT
//--------------------------------------------------------------------------------------

/**
 * @brief Print answers to stdout
 * @param [in] answers values to print
 * @param [in] numberOfAnswers how many answers found
 */
void PrintAnswer(const double answers[], int numberOfAnswers);

#endif // SS_IO_H
