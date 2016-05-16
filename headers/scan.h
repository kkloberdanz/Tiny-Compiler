#ifndef SCANNER_H
#define SCANNER_H 

#include "globals.h"

#define MAXTOKENLEN 40

typedef struct {
    token_type token_val;
    char*      string_val; 
    int        num_val;
} token_record_t;

token_type get_token(void);

static char get_next_char(void);

static token_type reserved_lookup(char* s);

#endif
