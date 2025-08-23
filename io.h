#ifndef INPUT_H
#define INPUT_H

// INPUT
int readDouble(double *a);
int inputDouble(const char *greeting, double *a);
int inputCoefficients(double *a, double *b, double *c);
bool checkBuffer();
void soberUp();

// OUTPUT
int printAnswer(const double answers[], int numberOfAnswers);

#endif