#include "utils.h"

void swap(double *a, double *b) {
    double c = *b;
    *b = *a;
    *a = c;
}
