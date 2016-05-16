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

extern FILE *SOURCE;  /* source inpug file */
extern FILE *LISTING; /* listing output file */
extern FILE *CODE;    /* object code ouput */

extern int  LINENO;      /* current line number */
extern int  ECHO_SOURCE; /* TRUE if reading from source */ 

#endif
