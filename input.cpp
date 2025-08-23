#include <stdio.h>

#include "input.h"

const int MAX_ATTEMPTS = 5;

void soberUp() {
    printf("User, looks you feels bad...\n"
           "Sober up and return later)\n");
}

// return 0 = ok
// return 1 = bad
bool checkBuffer() {
    int countChars = 0;
    int trash = '\0';
    while (trash != '\n' && trash != EOF) {
        trash = getchar();
        ++countChars;
    }
    return countChars != 1;
}

int readDouble(double *a) {
    int readArguments = scanf("%lf", a);

    if (readArguments != 1) {
        checkBuffer();
        printf("Please, input number in double format:\n");
        return -1;
    }
    if (checkBuffer()) {
        printf("Please, input ONE number in double format WITHOUT ANY TRASH:\n");
        return -1;
    }
    return 0;
}
int inputDouble(const char *greeting, double *a) {
    int attempts = MAX_ATTEMPTS;
    printf("%s:\n", greeting);
    while (readDouble(a) != 0) {
        --attempts;
        if (attempts == 0) {
            soberUp();
            return -1;
        }
    }
    return 0;
}

int inputCoefficients(double *a, double *b, double *c) {
    if (inputDouble("Input first coefficient in double format", a) != 0) {
        return -1;
    }
    if (inputDouble("Input second coefficient in double format", b) != 0) {
        return -1;
    }
    if (inputDouble("Input third coefficient in double format", c) != 0) {
        return -1;
    }
    printf("Your quadratic equation is :\n %lf*x^2 + %lf*x + %lf = 0\n", *a, *b, *c);
    return 0;
}
