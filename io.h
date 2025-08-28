/**
 * @file
 * @brief Input-output system with input sanitation \n 
 *        Works with stdin, stdout, file descriptors
 */

#ifndef SS_IO_H
#define SS_IO_H

#include "structures.h"

#include <stdio.h>

//--------------------------------------------------------------------------------------
// FILE INPUT 
//--------------------------------------------------------------------------------------

/**
 * @brief Sanitize input from tests file
 * @param [in] file to read tests from
 * @returns enum Status
 */
int ReadTestLine(FILE *file, Test *test);

//--------------------------------------------------------------------------------------
// FILE OUTPUT
//--------------------------------------------------------------------------------------

static const char logFile[] = "log.txt";

#define LOG(format, ...) fprintf(logFile format, __VA_ARGS__)

//--------------------------------------------------------------------------------------
// STDIN INPUT
//--------------------------------------------------------------------------------------

#define RED_BOLD_COLOR "\33[1;31m" // Color Start
#define COLOR_END "\33[0m" // To flush out prev colors

/**
 * @brief Make colored output to stderr with \n 
 *        Supports format string
 */
#define ERROR(format, ...) fprintf(stderr, RED_BOLD_COLOR format COLOR_END, __VA_ARGS__)

/**
 * @brief Print information about \n 
 *        * program \n 
 *        * developer \n 
 *        * poltorashka's friend
 */
void PrintHeader();

/**
 * @brief Request user to input double until correct attempt
 * @param [in] a pointer to double to read
 * Check if input is correct(without trash symbols, without nan and inf) \n
 * @returns enum Status \n
 *          InputDouble() processes this return codes
 */
int InputDouble(const char *greeting, double *a);

/**
 * @brief Request for coefficients of quadratic equation and shows user input
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
void PrintAnswer(const double x1, const double x2, const int numberOfAnswers);

#endif // SS_IO_H
