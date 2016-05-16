#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "headers/globals.h"
#include "headers/scan.h"

int main(int argc, char* argv[]) { 

    int LINENO = 0;
    int ECHO_SOURCE = TRUE;
    if (argv[1]) {
        FILE* SOURCE = fopen(argv[1], "r");
        printf("Reading from file: '%s'\n", argv[1]);
    } else {
        puts("tiny: No input file specified");
        exit(EXIT_FAILURE);
    }
    FILE* LISTING;
    FILE* CODE;
    return 0;
}
