#ifndef SS_INPUT_H
#define SS_INPUT_H

// INPUT
void SoberUp();
bool CheckBuffer();
int ReadDouble(double *a);
int InputDouble(const char *greeting, double *a);
int InputCoefficients(double *a, double *b, double *c);

// OUTPUT
int PrintAnswer(const double answers[], int numberOfAnswers);

#endif // SS_INPUT_H