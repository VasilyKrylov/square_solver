/**
 * @file 
 * @brief Global return codes
 */

#ifndef SS_STATUS_CODES_H
#define SS_STATUS_CODES_H

/*! \enum Status
 *  Return possible value of double number.
 */
enum Status {
    STATUS_OK         = 0, ///< Normal number
    STATUS_INF        = 1, ///< Number if INF
    STATUS_NAN        = 2, ///< Number if NAN
    STATUS_NOT_DOUBLE = 3, ///< There is no digits in the beginning (example asdf4.5)
    STATUS_WITH_TRASH = 4  ///< There is trash chars after number (example 4.5asdf)
};

/*! \enum Status
 *  Return possible value of double number.
 */
enum nRoots {
    INF_ROOTS   = -1,
    ZERO_ROOTS  = 0,
    ONE_ROOT    = 1,
    TWO_ROOTS   = 2
};

#endif // SS_STATUS_CODES_H