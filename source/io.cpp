/**
 * @file
 * @brief Input-output system. \n
 *        Some function's may be used outside this project. \n
 *        InputDouble() for example. \n
 */

#include "io.h"

#include "float_math.h"
#include "structures.h"
#include "status_codes.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static const int MAX_ATTEMPTS = 5;

/**
 * @brief check for trash chars in file buffer after fscanf() call
 * @param [in] file to check
 * @returns 0 if buffer clear\n
 *          1 if not
 */
bool FileCheckBuffer(FILE *file);

/**
 * @brief Check necessary number of roots for correct input depending on number of roots.
 * @param [out] test to extract roots from
 * @returns enum Status
 */
int checkRoots(Test *test);

/**
 * @brief check for trash chars in stdin buffer after scanf() call
 * @returns 0 if buffer clear\n
 *          1 if not
 */
bool CheckBuffer();

/**
 * @brief print funny message
 */
void SoberUp();

/**
 * @brief Check if input is correct(without trash symbols, without nan and inf)
 * @param [in] a pointer to double to read
 * @returns enum STATUS_[something]\n
 *          InputDouble() processes this return codes
 */
int ReadDouble(double *a);

//--------------------------------------------------------------------------------------
// FILE INPUT
//--------------------------------------------------------------------------------------

bool FileCheckBuffer(FILE *file) {
    int countChars = 0;
    int trash = '\0';

    while (trash != '\n' && trash != EOF) {
        trash = fgetc(file);
        ++countChars;
    }

    return countChars != 1;
}

int checkRoots(Test *test) {
    switch (test->nRoots)
    {
        case INF_ROOTS:
        case ZERO_ROOTS:
            return STATUS_OK;

        case ONE_ROOT:
        {
            if (IsInf(test->a)) {
                return STATUS_INF;
            }
            if (IsNan(test->a)) {
                return STATUS_NAN;
            }

            return STATUS_OK;
        }

        case TWO_ROOTS:
        {
            if (IsInf(test->a)) {
                return STATUS_INF;
            }
            if (IsNan(test->a)) {
                return STATUS_NAN;
            }

            if (IsInf(test->b)) {
                return STATUS_INF;
            }
            if (IsNan(test->b)) {
                return STATUS_NAN;
            }
            return STATUS_OK;
        }

        default:
            ERROR("%s: %s:%d: [ERROR]: Uknown number of roots while checking.\n", __func__, __FILE__, __LINE__);
            abort();
            break;
    }

    ERROR(
          "%s: %s:%d: [ERROR]: Uknown number of roots.\n"
          "Unnecessary error check. \n"
          "You should never see this message.\n",
          __func__, __FILE__, __LINE__
    );
    abort();
}

int ReadTestLine(FILE *file, Test *test) {
    assert(test != NULL);

    int readArguments = fscanf(
        file,
        "%lf %lf %lf %lf %lf %d",
        &test->a, &test->b, &test->c,
        &test->x1, &test->x2, &test->nRoots
    );

    int hasTrash = FileCheckBuffer(file);

    if (readArguments != 6) {
        return STATUS_NOT_DOUBLE;
    }
    if (hasTrash) {
        return STATUS_WITH_TRASH;
    }

    double coefficients[] = {
        test->a, test->b, test->c
    };

    for (size_t i = 0; i < sizeof(coefficients)/sizeof(coefficients[0]); ++i) {
        if (IsInf(coefficients[i])) {
            return STATUS_INF;
        }
        if (IsNan(coefficients[i])) {
            return STATUS_NAN;
        }
    }

    return checkRoots(test);
}

//--------------------------------------------------------------------------------------
// STDIN INPUT
//--------------------------------------------------------------------------------------

static const char *initialInfo =
    "The square equation solver\n"
    "Vasily Krylov 2025\n"
    "https://vasily.su | t.me/kvas1lek\n"
    " ,_     _\n"
    " |\\_,-~/\n"
    " / _  _ |    ,--.\n"
    "(  @  @ )   / ,-'\n"
    " \\  _T_/-._( (\n"
    " /         `. \\\n"
    "|         _  \\ |\n"
    " \\ \\ ,  /      |\n"
    "  || |-_\\__   /\n"
    " ((_/`(____,-'\n";

void PrintHeader() {
    printf("%s", initialInfo);
}

static const char *jokeExit =
    "\n"
    "User, looks you feels bad...\n"
    "Sober up and return later)\n"
    "  ╱▔▏  zzzz\n"
    " ╱◢▅▃\n"
    "▕▔▇ ╯╲╭━━━━━━━━╮\n"
    "▕▕▋╯┛╯▏       ╱┃\n"
    "▕▕╭▔▔▔      ╮╱╱▏\n"
    "▕▕▂▂▂▂▂▂▂▂▂▂▂╱▏▏\n"
    "▕▕╭━╯┃▅╮╭▅┃╭▏▏▏▏\n"
    "▕▕┃╭━┫▅▂▅▅┣╯▏▏▔\n"
    " ▔┃╰╮╰━━━━╯ ▔\n"
    "  ╰╕╕╕\n";

void SoberUp() {
    printf("%s", jokeExit);
}

bool CheckBuffer() {
    return FileCheckBuffer(stdin);
}

int ReadDouble(double *a) {
    int readArguments = scanf("%lf", a);

    // also clears buffer
    bool hasTrash = CheckBuffer();
    if (readArguments != 1) {
        return STATUS_NOT_DOUBLE;
    }
    if (hasTrash) {
        return STATUS_WITH_TRASH;
    }

    if (IsInf(*a)) {
        return STATUS_INF;
    }
    if (IsNan(*a)) {
        return STATUS_NAN;
    }

    return STATUS_OK;
}

int InputDouble(const char *greeting, double *a) {
    int attempts = MAX_ATTEMPTS;

    while (1) {
        --attempts;

        if (!attempts) {
            SoberUp();
            return -1;
        }
        else {
            printf("%s", greeting);
        }

        int statusCode = ReadDouble(a);

        switch (statusCode)
        {
            case STATUS_OK:
                return 0;
            case STATUS_INF:
                printf("You entered INF.\n");
                break;
            case STATUS_NAN:
                printf("You entered NAN.\n");
                break;
            case STATUS_NOT_DOUBLE:
                printf("You don't enter double.\n");
                break;
            case STATUS_WITH_TRASH:
                printf("You entered number with trash symbols.\n");
                break;
            default:
                ERROR("%s: %s:%d: [ERROR]: Uknown type of double.\n", __func__, __FILE__, __LINE__);
                abort();
                break;
        }
    }

    return -1;
}

int InputCoefficients(double *a, double *b, double *c) {
    if (InputDouble("\nInput first coefficient as float number (0.5 for example):\n", a) != 0) {
        return -1;
    }
    if (InputDouble("\nInput second coefficient as float number (0.5 for example):\n", b) != 0) {
        return -1;
    }
    if (InputDouble("\nInput third coefficient as float number (0.5 for example):\n", c) != 0) {
        return -1;
    }

    // printf("\nYour quadratic equation is :\n\t%lf*x^2 + %lf*x + %lf = 0\n", *a, *b, *c);
    printf("\nYour equation is :\n");

    if (!IsZero(*a)) {
        printf("%lg*x^2", *a);

        if (!IsZero(*b)) {
            printf(" + %lg*x", *b);
        }
        if (!IsZero(*c)) {
            printf(" + %lg", *c);
        }
    }

    else {
        if (!IsZero(*b)) {
            printf("%lg*x", *b);

            if (!IsZero(*c)) {
                printf(" + %lg", *c);
            }
        }
        else {
            printf("%lg", *c);
        }
    }

    printf(" = 0\n");

    return 0;
}

//--------------------------------------------------------------------------------------
// STDOUT OUTPUT
//--------------------------------------------------------------------------------------

void PrintAnswer(const double x1, const double x2, const int numberOfAnswers) {
    // yes, array is more scalable solutions
    // with big power comes big responsibility
    // such as index out of range
    // Vadim told me, what array inside struct is safe
    // I should check it by myslef

    if (numberOfAnswers == INF_ROOTS) {
        printf("Found infinite number of answers - ∞\n");
        return;
    }

    if (numberOfAnswers == ZERO_ROOTS) {
        printf("Where is no roots for this \n");
        return;
    }

    if (numberOfAnswers == ONE_ROOT) {
        printf("Found 1 answer:\n");
        printf("\tx = %lg\n", x1);
        return;
    }

    if (numberOfAnswers == TWO_ROOTS) {
        printf("Found 2 answers:\n");
        printf("\tx_1 = %lg\n", x1);
        printf("\tx_2 = %lg\n", x2);
        return;
    }

    ERROR("%s: %s:%d: [ERROR]: Uknown number of roots detected while printing.\n", __func__, __FILE__, __LINE__);
    abort();
}
//--------------------------------------------------------------------------------------
