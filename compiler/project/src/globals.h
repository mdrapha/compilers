#include "funcs.h"
#include "lex.h"
#include "parse_tree.h"
#include "parser.tab.h"
#include "symbTable.h"

#define BUFFER_SIZE 256
#define MAX_ID_STACK_SIZE 256
#define MAX_LEXEME_SIZE 64


extern FILE *file;
extern Buffer *buffer;
extern lexeme *lex;
extern TreeNode *parseTree;
extern SymbolTable *symbolTable;

extern const char *file_name;

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

/*Variable to manage the current scope*/
extern char *currentScope;

extern int idStackIndex;

extern int numStackIndex;

extern char **idStack;

extern int **numStack;


void initGlobals();

void CompilerInit(int argc, char *argv[]);
