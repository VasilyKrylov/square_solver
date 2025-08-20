#include <stdio.h>
#include <math.h>

const float EPS = 1e-9f;

void input(float *a, float *b, float *c);
void solve(float a, float b, float c);
void printAnswer(float answers[], int numberOfAnswers);

void input(float *a, float *b, float *c) {
    printf("Input first coefficient:\n");
    scanf("%f", a);
    printf("Input second coefficient:\n");
    scanf("%f", b);
    printf("Input second coefficient:\n");
    scanf("%f", c);
}

void solve(float a, float b, float c) {
    float discriminant = b * b - 4 * a * c;
    float answers[2];
    if (discriminant < 0) {
        printAnswer(answers, 0);
    }
    else if (abs(discriminant) <= EPS) {
        answers[0] = -b / (2 * a);
        printAnswer(answers, 1);
    }
    else {
        answers[0] = (-b - sqrt(discriminant)) / (2 * a);
        answers[1] = (-b + sqrt(discriminant)) / (2 * a);
        printAnswer(answers, 2);
    }
        
}
void printAnswer(float answers[], int numberOfAnswers) {
    printf("Founded %d number of answers\n", numberOfAnswers);
    for (int answerIndex = 0; answerIndex < numberOfAnswers; ++answerIndex) {
        printf("x%d = %f\n", answerIndex, answers[answerIndex]);
    }
}
int main() {
    float a, b, c;
    input(&a, &b, &c);   
    solve(a, b, c);
    return 0;
}

