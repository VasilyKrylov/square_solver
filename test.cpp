#include <stdio.h>

// bool checkBuffer();
// int readFloat(float *a);

// bool checkBuffer() {
//     int countChars = 0;
//     int trash = '\0';
//     while (trash != '\n' && trash != EOF) {
//         trash = getchar();
//         ++countChars;
//     }
//     return countChars == 1;
//     // return 1 = ok
//     // return 0 = ploxo
// }

// int readFloat(float *a) {
//     int read_arguments = scanf("%lf", a);
//     printf("DEBUG: %d %lf\n", read_arguments, *a);

//     if (read_arguments != 1) {
//         checkBuffer();
//         printf("Please, input number in decimal format:\n");
//         return 0;
//     }
//     if (!checkBuffer()) {
//         printf("Please, input ONE number in decimal format WITHOUT ANY TRASH:\n");
//         return 0;
//     }
//     return 1;
// }

int main() {
    float a = 0.0;
    // readFloat(&a);
    // while (readFloat(&a) == 0) {
        printf("try again\n");
    // }
    return 0;
}