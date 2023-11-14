#include "funcs.h"

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

/*Variable to manage the file*/
FILE *file;

/*Variable to manage the buffer*/
Buffer *buffer;

/*Variable to manage the lexeme*/
lexeme lex;

/*Variable to manage the symbol table*/
SymbolTable *symbolTable;
