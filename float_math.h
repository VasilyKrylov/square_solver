#ifndef SS_FLOAT_MATH_H
#define SS_FLOAT_MATH_H

int IsNan(double a);
int IsInf(double a);
int IsEqual(double a, double b);
int IsZero(double a);
void normalizeZero(double *a);

#endif // SS_FLOAT_MATH_H