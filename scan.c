#include <stdio.h>
#include <string.h>

#include "headers/scan.h"
#include "headers/globals.h"

#define MAXRESERVED 8
#define BUFLEN      256

extern char token_string[MAXTOKENLEN + 1];

typedef enum {
    START,
    INASSIGN,
    INCOMMENT,
    INNUM,
    INID,
    DONE
} state_type;

/* reserved words lookup table */
static struct {
    char*      str;
    token_type tok;
} reserved_words[MAXRESERVED + 1] = {
    {"if",     IF},
    {"then",   THEN},
    {"else",   ELSE},
    {"end",    END},
    {"repeat", REPEAT},
    {"until",  UNTIL},
    {"read",   READ},
    {"write",  WRITE}
};

/* Linear search through reserved_words, and return 
   cooresponding identifier */
static token_type reserved_lookup(char* s) {
    int i;
    for (i = 0; i < MAXRESERVED; i++) {
        if (strcmp(s, reserved_words[i].str) == 0) {
            return reserved_words[i].tok;
        }
    }
    return ID;
}

static char line_buf[BUFLEN]; /* current line */
static int  linepos = 0;      /* current position of linebuf */
static int  bufsize = 0;      /* current size of buffer string */

static char get_next_char(void) {
    if ( !(linepos < bufsize) ) { // then read next line
        LINENO++;
        if (fgets(line_buf, BUFLEN-1, SOURCE)) {
            if (ECHO_SOURCE) { // if reading from source file
                fprintf(LISTING, "%4d: %s", LINENO, line_buf);
                bufsize = strlen(line_buf);
                linepos = 0;
                return line_buf[linepos++];
            }
        } else {
            return EOF;
        }
    } else {
        return line_buf[linepos++];
    }
}

token_type get_token(void) {
    /* TODO: pg 513, line 674 */
    int token_string_index = 0;

    token_type current_token;

    state_type state = START;

    /* flag to indicate save to token_string */
    int save;

    while (state != DONE) {
        char c = get_next_char();
        save   = TRUE;

        switch (state) {
        }
    }
}
