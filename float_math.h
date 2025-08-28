/**
 * @file
 * @brief Functions for comparison double values \n 
 *        Uses EPS to most of operations
 */

#ifndef SS_FLOAT_MATH_H
#define SS_FLOAT_MATH_H

/**
 * @brief Is number equals to NaN
 * @param [in] a number to compare with
 * @returns 1 = a is NaN, \n
            0 = a isn't Nan
 */
bool IsNan(double a);

/**
 * @brief Is number equals to INF
 * @param [in] a number to compare with
 * @returns 1 = a is INF, \n
            0 = a isn't INF
 */
bool IsInf(double a);

/**
 * @brief Is number equals to each other
 * @param [in] a first float to compare 
 * @param [in] b second float to compare 
 * @returns 1 = a and b are the same, \n
            0 = Good
 */
bool IsEqual(double a, double b);

/**
 * @brief Is number similar to 0.0
 * @param [in] a double to compare with zero
 * @returns 1 = number is similiar to 0.0, \n
            0 = number isn't similiar to 0.0
 */
bool IsZero(double a);

/**
 * @brief Identifies if a number is finite.
 * @param [in] a double to analyze
 * @returns 1 = safe to use(number is finite)
 *          0 = isn't safe to use(number isn't finite)
 */
bool IsFinite(double a);

/**
 * @brief Check is number similiar to 0.0 \n 
 *        If yes, a is set to 0.0 \n 
 *        Also fix -0
 * @param [in] a double to normalizes
 * 
 */
void normalizeZero(double *a);

#endif // SS_FLOAT_MATH_H
