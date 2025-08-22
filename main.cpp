#include <stdio.h>
#include <math.h>
#include <cassert>

const float EPS = 1e-9f;
const int MAX_ATTEMPTS = 5;
static inline int isZero(float number);
int input(float *a, float *b, float *c);
int solve(float a, float b, float c, int *numerOfAnswers, float *answers);
int printAnswer(float answers[], int numberOfAnswers);
bool checkBuffer();
int readFloat(float *a);
void soberUp();

static inline int isZero(float number) {
    return abs(number) <= EPS;
}

void soberUp() {
    printf("User, looks you feels bad...\nSober up and return later)\n");
}
bool checkBuffer() {
    int countChars = 0;
    int trash = '\0';
    while (trash != '\n' && trash != EOF) {
        trash = getchar();
        ++countChars;
    }
    return countChars != 1;
    // return 0 = ok
    // return 1 = bad
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
int input(float *a, float *b, float *c) {
    int attempts = MAX_ATTEMPTS;
    printf("Input first coefficient in float format:\n");
    while (readFloat(a) != 0) {
        --attempts;
        // printf("Input first coefficient in float format:\n");
        if (attempts == 0) {
            soberUp();
            return -1;
        }
    }
    attempts = MAX_ATTEMPTS;
    printf("Input second coefficient in float format:\n");
    while (readFloat(b) != 0) {
        --attempts;
        // printf("Input second coefficient in float format:\n");
        if (attempts == 0) {
            soberUp();
            return -1;
        }
    }
    attempts = MAX_ATTEMPTS;
    printf("Input third coefficient in float format:\n");
    while (readFloat(c) != 0) {
        --attempts;
        // printf("Input third coefficient in float format:\n");
        if (attempts == 0) {
            soberUp();
            return -1;
        }
    }
    return 0;
}

int solve(float a, float b, float c,
            int* numberOfAnswers, float* answers) {
    assert(std::isfinite (a));
    assert(std::isfinite (b));
    assert(std::isfinite (c));

    if (isZero(a)) {
        if (isZero(b)) {
            if (isZero(c)) {
                *numberOfAnswers = -1;
                return 0;
            } else {
                *numberOfAnswers = 0;
                return 0;
            }
        } else {
            *numberOfAnswers = 1;
            if (isZero(c)) {
                answers[0] = 0;
            } else {
                answers[0] = -c / b;
            }
            return 0;
        }
    }
    float discriminant = b * b - 4 * a * c;
    if (isZero(discriminant)) {
        *numberOfAnswers = 1;
        if (isZero(b)) {
            answers[0] = 0;
        } else {
            answers[0] = -b / (2 * a);
        }
        return 0;
    }
    else if (discriminant < 0) {
        *numberOfAnswers = 0;
        return 0;
    }
    else {
        *numberOfAnswers = 2;
        if(isZero(-b - sqrt(discriminant))) {
            answers[0] = 0;
        } else {
            answers[0] = (-b - sqrt(discriminant)) / (2 * a);
        }
        if(isZero(-b + sqrt(discriminant))) {
            answers[1] = 0;
        } else {
            answers[1] = (-b + sqrt(discriminant)) / (2 * a);
        }
        return 0;
    }
    return 0;
}
int printAnswer(float answers[], int numberOfAnswers) {
    if (numberOfAnswers == -1) {
        printf("Found infinite number of answers - ∞");
        return 0;
    }
    printf("Found %d number of answers\n", numberOfAnswers);
    for (int answerIndex = 0; answerIndex < numberOfAnswers; ++answerIndex) {
        printf("x%d = %f\n", answerIndex, answers[answerIndex]);
    }
    return 0;
}
int main() {
    float a = 0, b = 0, c = 0;
    int numberOfAnswers = 0;
    float answers[2] = {0};
    if (input(&a, &b, &c) == -1) {
        return 0;
    }
    solve(a, b, c, &numberOfAnswers, answers);
    printAnswer(answers, numberOfAnswers);

        /*
        TODO:
        what is assert
        Book - 1.6
        doxygen
    */
    return 0;
}
