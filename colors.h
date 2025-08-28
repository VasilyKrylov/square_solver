/**
 * @file
 * @brief Make easy to use colored output using defines \n
 *        There is possible solution using functions
 */

#ifndef SS_COLORS_H
#define SS_COLORS_H

#define RED_BOLD_COLOR "\33[1;31m" // Color Start
#define COLOR_END "\33[0m" // To flush out prev colors

/**
 * @brief Make colored output to stderr with \n 
 *        Supports format string
 */
#define ERROR(format, ...) fprintf(stderr, RED_BOLD_COLOR format COLOR_END, __VA_ARGS__)

#endif // SS_COLORS_H