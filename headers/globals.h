#ifndef GLOBALS_H
#define GLOBALS_H

#define TRUE  1
#define FALSE 0

typedef enum {
    /* reserved words */
    IF,
    THEN,
    ELSE,
    END,
    REPEAT,
    UNTIL,
    READ,
    WRITE, 

    /* special symbols */
    PLUS,
    MINUS,
    MULT,
    DIV,
    EQUALS,
    LESS_THAN,
    OPEN_PAREN,
    CLOSE_PAREN,
    SEMI_COLON,
    ASSIGN, 

    /* other */
    NUM,            /* one or more digits */
    ID,             /* identifier */

    /* bookkeeping tokens */
    ENDFILE,
    ERROR
} token_type;

FILE *SOURCE;  /* source inpug file */
FILE *LISTING; /* listing output file */
FILE *CODE;    /* object code ouput */

int  LINENO;      /* current line number */
int  ECHO_SOURCE; /* TRUE if reading from source */ 

#endif
