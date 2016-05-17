#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "globals.h"
#include "scan.h"

int main(int argc, char* argv[]) { 

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
