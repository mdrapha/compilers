#include "funcs.h"
#include "lex.h"
#include "parse_tree.h"
#include "parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_ID = 258,                    /* T_ID  */
    T_NUM = 259,                   /* T_NUM  */
    T_INT = 260,                   /* T_INT  */
    T_VOID = 261,                  /* T_VOID  */
    T_IF = 262,                    /* T_IF  */
    T_ELSE = 263,                  /* T_ELSE  */
    T_WHILE = 264,                 /* T_WHILE  */
    T_RETURN = 265,                /* T_RETURN  */
    T_PLUS = 266,                  /* T_PLUS  */
    T_MINUS = 267,                 /* T_MINUS  */
    T_MULT = 268,                  /* T_MULT  */
    T_DIV = 269,                   /* T_DIV  */
    T_ATRB = 270,                  /* T_ATRB  */
    T_EQ = 271,                    /* T_EQ  */
    T_NEQ = 272,                   /* T_NEQ  */
    T_LT = 273,                    /* T_LT  */
    T_GT = 274,                    /* T_GT  */
    T_LTE = 275,                   /* T_LTE  */
    T_GTE = 276,                   /* T_GTE  */
    T_LPAREN = 277,                /* T_LPAREN  */
    T_RPAREN = 278,                /* T_RPAREN  */
    T_LBRACE = 279,                /* T_LBRACE  */
    T_RBRACE = 280,                /* T_RBRACE  */
    T_LSQBRA = 281,                /* T_LSQBRA  */
    T_RSQBRA = 282,                /* T_RSQBRA  */
    T_SEMI = 283,                  /* T_SEMI  */
    T_COMMA = 284,                 /* T_COMMA  */
    LOWER_THAN_ELSE = 285          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
extern FILE *file;
extern Buffer *buffer;
extern lexeme *lex;
extern SymbolTable *symbolTable;

/*Variable to manage the current line*/
extern int currentLine;

/*Variable to manage the current column*/
extern int currentColumn;

/*Variable to manage the current token*/
extern int currentToken;

/*Variable to manage the current token value*/
extern char *currentTokenValue;

/*Variable to manage the current token type*/
extern int currentTokenType;

/*Variable to manage the current token line*/
extern int currentTokenLine;

void initGlobals();

