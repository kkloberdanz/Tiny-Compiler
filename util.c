#include <stdio.h>

#include "util.h" 
#include "globals.h" 
#include "scan.h" 

void print_token(token_type token, const char* tokenString ) { 
    switch (token) { 
        case IF:
        case THEN:
        case ELSE:
        case END:
        case REPEAT:
        case UNTIL:
        case READ:
        case WRITE:
            fprintf(LISTING, "reserved word: %s\n",tokenString);
            break;
        case ASSIGN: 
            fprintf(LISTING,":=\n"); 
            break;
        case LESS_THAN: 
            fprintf(LISTING,"<\n"); 
            break;
        case EQUALS: 
            fprintf(LISTING,"=\n"); 
            break;
        case OPEN_PAREN: 
            fprintf(LISTING,"(\n"); 
            break;
        case CLOSE_PAREN: 
            fprintf(LISTING,")\n"); 
            break;
        case SEMI_COLON: 
            fprintf(LISTING,";\n"); 
            break;
        case PLUS: 
            fprintf(LISTING,"+\n"); 
            break;
        case MINUS: 
            fprintf(LISTING,"-\n"); 
            break;
        case MULT: 
            fprintf(LISTING,"*\n"); 
            break;
        case DIV: 
            fprintf(LISTING,"/\n"); 
            break;
        case ENDFILE: 
            fprintf(LISTING,"EOF\n"); 
            break;
        case NUM:
            fprintf(LISTING, "NUM, val= %s\n",tokenString);
            break;
        case ID:
            fprintf(LISTING, "ID, name= %s\n",tokenString);
            break;
        case ERROR:
            fprintf(LISTING, "ERROR: %s\n",tokenString);
            break;
        default: /* should never happen */
            fprintf(LISTING,"Unknown token: %d\n",token);
    } /* end switch */
}
