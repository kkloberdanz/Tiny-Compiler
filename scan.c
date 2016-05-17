#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "scan.h"
#include "globals.h"

#define MAXRESERVED 8
#define BUFLEN      256

int LINENO = 0;
/*int ECHO_SOURCE;*/
FILE *SOURCE, *LISTING, *CODE;

char token_string[MAXTOKENLEN + 1];

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
    int token_string_index = 0; /* index for storing token */
    token_type current_token;   /* Holds token that will be returned */
    state_type state = START;   /* current state begins at START */
    int save;                   /* flag to indicate save to token_string */

    while (state != DONE) {
        char c = get_next_char();
        save   = TRUE;

        switch (state) {
            case START:
                if (isdigit(c)) {
                    state = INNUM;          /* in number */
                } else if (isalpha(c)) {
                    state = INID;           /* in identifier */
                } else if (c == ':') {
                    state = INASSIGN;       /* in assignment */
                } else if ((c == ' ') || (c == '\t') || (c == '\n')) {
                    save = FALSE;           /* ignore whitespace/newlines */
                } else if (c == '{') {
                    save = FALSE;           /* { and } denote comments */
                    state = INCOMMENT;
                } else {
                    state = DONE;
                }
                switch(c) {

                    case EOF:
                        save = FALSE;
                        current_token = ENDFILE;
                        break; 

                    case '<':
                        current_token = LESS_THAN;
                        break;

                    case '+':
                        current_token = PLUS;
                        break;

                    case '-':
                        current_token = MINUS;
                        break;

                    case '*':
                        current_token = MULT;
                        break;

                    case '/':
                        current_token = DIV;
                        break;

                    case '(':
                        current_token = OPEN_PAREN;
                        break;

                    case ')':
                        current_token = CLOSE_PAREN;
                        break; 

                    case ';':
                        current_token = SEMI_COLON;
                        break;

                    default:
                        current_token = ERROR;
                        break;
                } /* end switch */
                break; /* outer switch */

            case INCOMMENT:
                save = FALSE;
                if (c == '}') {
                    state = START;
                }
                break;

            case INASSIGN:
                state = DONE;
                if (c == '=') {
                    current_token = ASSIGN;
                } else {
                    unget_next_char(); /* backup in the input */
                    save = FALSE;
                    current_token = ERROR;
                }
                break;

            case INNUM:
                if (!isdigit(c)) {
                    unget_next_char();
                    save = FALSE;
                    state = DONE;
                    current_token = NUM;
                }
                break; 

            case INID:
                if (!isalpha(c)) {
                    unget_next_char();
                    save = FALSE;
                    state = DONE;
                    current_token = ID;
                }
                break;
                
            case DONE:
            default: /* should never happen */
                fprintf(LISTING, "Scanner Bug: state = %d\n", state);
                state = DONE;
                current_token = ERROR;
                break; 
        } /* end switch */
        if (save && (token_string_index <= MAXTOKENLEN)) {
            token_string[token_string_index++] = c;
        }

        if (state == DONE) {
            token_string[token_string_index] = '\0'; 
            if (current_token == ID) {
                current_token = reserved_lookup(token_string);
            }
        } 
    } /* end while */
    /*
    if (TRACE_SCAN) {
        fprintf(LISTING, "\t%d: ", LINENO);
        print_token(current_token, token_string);
    }
    */
    return current_token;
} /* end get_token */

static void unget_next_char(void) {
    linepos--;
}
