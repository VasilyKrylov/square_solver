/**
 * @file 
 * @brief For global structures
 */
#ifndef SS_STRUCTURES_H
#define SS_STRUCTURES_H

 
/*! \class Test structures.h "structures.h"
 *  \brief This is a structure for tests
 */
struct Test {
    double a, b, c; ///< Сoefficients of the quadratic equation
    double x1, x2;  ///< Answers of the quadratic equation
    int nRoots;     ///< Number of roots of the quadratic equation
};

#endif // SS_STRUCTURES_H