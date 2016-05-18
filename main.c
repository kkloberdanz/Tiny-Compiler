#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "globals.h"
#include "scan.h"
#include "util.h"

FILE* LISTING;
FILE* CODE;
FILE* SOURCE;

int main(int argc, char* argv[]) { 

    /* TEST */
    /*
    char user_input = 'a';
    while (user_input != 'q') {
        inc_global();
        printf("%d\n", global_var); 
        user_input = getchar();
    }
    */

    if (argv[1]) {
        SOURCE = fopen(argv[1], "r");
        LISTING = fopen("listing", "w");
        /*LISTING = stdout;*/
        if (SOURCE) {
            printf("Reading from file: '%s'\n", argv[1]); 
            while(get_token() != ENDFILE);
        } else {
            printf("Could not open file: '%s', exiting\n", argv[1]);
            exit(EXIT_FAILURE);
        }
    } else {
        puts("tiny: No input file specified");
        exit(EXIT_FAILURE);
    }
    return 0;
}
