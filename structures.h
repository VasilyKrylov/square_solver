/**
 * @file 
 * @brief For global structures
 */

#ifndef SS_STRUCTURES_H
#define SS_STRUCTURES_H

 
/*! \struct Test structures.h "structures.h"
 *  \brief Structure for tests
 */
struct Test {
    double a, b, c; ///< Сoefficients of the quadratic equation
    double x1, x2;  ///< Answers of the quadratic equation
    int nRoots;     ///< Number of roots of the quadratic equation
};

/*! \struct Coefficients structures.h "structures.h"
 *  \brief Сoefficients of the quadratic equation
 */
struct Coefficients {
    double a, b, c;
};

/*! \struct Answer structures.h "structures.h"
 *  \brief 
 */
struct Answer {
    double x1, x2; ///< Roots of the quadratic equation
    int nRoots;     ///< Number of roots
};

#endif // SS_STRUCTURES_H