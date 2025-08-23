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

int readFloat(float *a) {
    int readArguments = scanf("%f", a);

    if (readArguments != 1) {
        checkBuffer();
        printf("Please, input number in float format:\n");
        return -1;
    }
    if (checkBuffer()) {
        printf("Please, input ONE number in float format WITHOUT ANY TRASH:\n");
        return -1;
    }
    return 0;
}
int inputFloat(const char *greeting, float *a) {
    int attempts = MAX_ATTEMPTS;
    printf("%s:\n", greeting);
    while (readFloat(a) != 0) {
        --attempts;
        if (attempts == 0) {
            soberUp();
            return -1;
        }
    }
    return 0;
}

int inputCoefficients(float *a, float *b, float *c) {
    if (inputFloat("Input first coefficient in float format", a) != 0) {
        return -1;
    }
    if (inputFloat("Input second coefficient in float format", b) != 0) {
        return -1;
    }
    if (inputFloat("Input third coefficient in float format", c) != 0) {
        return -1;
    }
    printf("Your quadratic equation is :\n %f*x^2 + %f*x + %f = 0\n", *a, *b, *c);
    return 0;
}
