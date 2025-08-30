#include "cli_arguments.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char help[] =
    "Usage: main [OPTION]... [FILE]...\n"
    "Solve square equation entered by user\n"
    "-h, --help                  show this help message.\n";


void ParseArguments(int argc, char **argv) {
    if (argc == 1) {
        return;
    }
    if (argc == 2) {
        if (strcmp("-h", argv[1]) == 0 || strcmp("--help", argv[1]) == 0) {
            printf("%s", help);
        }
        exit(0);
    }
}
