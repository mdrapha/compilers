#include "globals.h"

// Definitions of global variables
FILE *file;
Buffer *buffer;
lexeme *lex = NULL;
TreeNode *parseTree = NULL;


void initGlobals() {
    // Initialize file-related variables
    buffer = malloc(sizeof(Buffer));
    if (buffer) {
        initBuffer(buffer);
    } else {
        printf("Error allocating memory for buffer\n");
        exit(1);
    }

    // Initialize lex-related variables
    lex = malloc(sizeof(lexeme));
    if (lex) {
        initLexeme(lex);
        if (lex != NULL)
        {
            lex->name = malloc(sizeof(char) * MAX_LEXEME_SIZE);
        }
    } else {
        printf("Error allocating memory for lexeme\n");
        exit(1);
    }

    // Initialize symbol table and other variables
    currentLine = 1;
    currentColumn = 0;
    currentToken = 0;
    currentTokenValue = NULL; // Will be allocated later when needed
    currentTokenType = 0;
    currentTokenLine = 0;
    currentScope = 'global'; // Assuming it will be initialized later if needed
}

SymbolTable *symbolTable;

const char *file_name;

/*Variable to manage the current line*/
int currentLine =1;

/*Variable to manage the current column*/
int currentColumn;

/*Variable to manage the current token*/
int currentToken;

/*Variable to manage the current token value*/
char *currentTokenValue;

/*Variable to manage the current token type*/
int currentTokenType;

/*Variable to manage the current token line*/
int currentTokenLine;

/* Variable to manage the current scope*/
char *currentScope;
