#ifndef GLOBALS_H
#define GLOBALS_H

#ifndef TRUE
#define TRUE        1
#endif

#ifndef FALSE
#define FALSE       0
#endif

#ifndef DEBUG_MODE
#define DEBUG_MODE  0
#endif

#ifndef ECHO_SOURCE
#define ECHO_SOURCE 1
#endif

#ifndef TRACE_SCAN
#define TRACE_SCAN  1
#endif

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

typedef enum {
    PLUS_K,
    MINUS_K,
    TIMES_K 
} op_kind;

typedef enum {
    OP_K,
    CONST_K
} exp_kind;

typedef struct s_tree_node {
    exp_kind kind;
    op_kind  pl;
    struct s_tree_node *lchild, *rchild;
    int val;
} STreeNode;

typedef STreeNode *Syntax_Tree;

extern FILE *SOURCE;  /* source inpug file */
extern FILE *LISTING; /* listing output file */
extern FILE *CODE;    /* object code ouput */

extern int  LINENO;   /* current line number */
extern int  global_var;

//extern int  ECHO_SOURCE = TRUE; [> TRUE if reading from source <] 
//int  TRACE_SCAN  = TRUE;

#endif
