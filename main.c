#include <stdio.h>
#include <math.h>
#include <cassert>

const float EPS = 1e-9f;

static inline int isZero(float number);
int input(float *a, float *b, float *c);
int solve(float a, float b, float c, int *numerOfAnswers, float *answers);
int printAnswer(float answers[], int numberOfAnswers);

static inline int isZero(float number) {
    return abs(number) <= EPS;
}
int input(float *a, float *b, float *c) {
    printf("Input first coefficient(not zero):\n");
    scanf("%f", a);
    printf("Input second coefficient:\n");
    scanf("%f", b);
    printf("Input second coefficient:\n");
    scanf("%f", c);
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
            answers[0] = -c / b;
            return 0;
        }
    }
    float discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        *numberOfAnswers = 0;
        return 0;
    }
    else if (isZero(discriminant)) {
        *numberOfAnswers = 1;
        answers[0] = -b / (2 * a);
        return 0;
    }
    else {
        *numberOfAnswers = 2;
        answers[0] = (-b - sqrt(discriminant)) / (2 * a);
        answers[1] = (-b + sqrt(discriminant)) / (2 * a);
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
    input(&a, &b, &c);   
    solve(a, b, c, &numberOfAnswers, &answers[0]);
    // why this shit doesn't compiles lol? ^-^
    // solve(a, b, c, &numberOfAnswers, &answers);
    printAnswer(answers, numberOfAnswers);
    /*
        TODO:
        a = 0
        infinite number of solves
        no solves
        call printAnswer from main
        Book - 1.5.1
        add asserts
        doxygen
    */
    return 0;
}
