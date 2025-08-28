/**
 * @file
 * @brief Calculates root of square equation
 */

#ifndef SS_SOLVE_H
#define SS_SOLVE_H


/**
 * @param [in] b second coefficient of the linear equation
 * @param [in] c third coefficient of the linear equation
 * @param [out] x return root of linear equation
 * @returns number of found solves: \n
    INF_ROOTS = -1, \n
    ZERO_ROOTS = 0, \n
    ONE_ROOT = 1, \n
 */
int SolveLinear(double b, double c, double *x);

/**
 * @param [in] a first coefficient of the quadratic equation
 * @param [in] b second coefficient of the quadratic equation
 * @param [in] c third coefficient of the quadratic equation
 * @param [out] answers return x1 and x2 if found and must be at least 2 doubles size
 * @returns number of found solves: \n
    INF_ROOTS = -1, \n
    ZERO_ROOTS = 0, \n
    ONE_ROOT = 1, \n
    TWO_ROOTS = 2 \n
 */
int SolveSquare(double a, double b, double c, double *x1, double *x2);


#endif // SS_SOLVE_H