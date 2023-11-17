#include "funcs.h"
#include "lex.h"
#include "parse_tree.h"
#include "parser.tab.h"


#define BUFFER_SIZE 256


extern FILE *file;
extern Buffer *buffer;
extern lexeme *lex;
extern SymbolTable *symbolTable;
extern TreeNode *parseTree;

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

