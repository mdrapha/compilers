#include "funcs.h"
#include "lex.h"
#include "parse_tree.h"
#include "parser.tab.h"
#include "symbTable.h"

#define BUFFER_SIZE 256
#define MAX_ID_STACK_SIZE 256
#define MAX_LEXEME_SIZE 64

/*Variable to manage the file*/
extern FILE *file;

/*Variable to manage the buffer*/
extern Buffer *buffer;

/*Variable to manage the lexeme*/
extern lexeme *lex;

/*Variable to manage the parse tree*/
extern TreeNode *parseTree;

/*Variable to manage the file name*/
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

/*Variable to manage the next scope*/
extern char *nextScope;

/*Variable to manage the identifiers stack index*/
extern int idStackIndex;

/*Variable to manage the numbers stack index*/
extern int numStackIndex;

/*Variable to manage the identifiers stack*/
extern char **idStack;

/*Variable to manage the numbers stack*/
extern int **numStack;

/*Variable to manage the scope counter*/
extern int scopeCounter;

void initGlobals();

void CompilerInit(int argc, char *argv[]);
