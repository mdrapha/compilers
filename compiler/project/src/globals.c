#include "globals.h"

// Definitions of global variables
FILE *file;
Buffer *buffer;
lexeme *lex = NULL;
TreeNode *parseTree = NULL;

// Variável global para o escopo atual
char *currentScope;
char *nextScope;



void CompilerInit(int argc, char *argv[]) {
 printf("\n\033[1;32m"); // Set text to the color green
    printf("Begin C- Compiler\n");
    printf("\033[0m\n"); // Reset text to default color

    file_name = argv[1];

    if (argc < 3)
    {   
        // Setting printf color to red
        printf("\033[1;37;41m");
        printf("Usage: ./lexer <file_name> (-l or -p or -s)");
        printf("\033[0m\n");
        exit(1);
    } else if(argc >3){
        printf("\033[1;37;41m");
        printf("----- Only use 1 flag at time!! -----");
        printf("\033[0m\n");
        printf("\033[1;32m\nEnd of compiling\n\n\033[0m");

        exit(1);
    }
    file = fopen(file_name, "r");

    if (file == NULL)
    {
        // Setting printf color to red
        printf("\033[1;37;41m");
        printf("Error opening file\033[0m\n");
        printf("\033[1;32m\nEnd of compiling\n\n\033[0m");

        exit(1);
    }

        int opFlags[3] = {FALSE, FALSE, FALSE};

    /* Verifying the argv directives */
    for (int i = 2; i < argc; i++)
    {
        if (strcmp(argv[i], "-l") == 0)
        {
            opFlags[0] = TRUE;
        }
        else if (strcmp(argv[i], "-p") == 0)
        {
            opFlags[1] = TRUE;
        }
        else if (strcmp(argv[i], "-s") == 0)
        {
            opFlags[2] = TRUE;
        }
    }

    // If no directive is given, exit the program with an error
    if (opFlags[0] == FALSE && opFlags[1] == FALSE && opFlags[2] == FALSE && argc > 2)
    {   
        // Setting printf color to red
        printf("\033[1;37;41m");
        printf("Error: No valid directive given, please use -l, -p or -s!!");
        printf("\033[0m\n");
        printf("\033[1;32m\nEnd of compiling\n\n\033[0m");

        exit(1);
    }else if(opFlags[0] == FALSE && opFlags[1] == FALSE && opFlags[2] == FALSE ){
        
        // Setting printf color to red
        printf("\033[1;37;41m");
        printf("Error: No directive given!!");
        printf("\033[0m\n");
        printf("\033[1;32m\nEnd of compiling\n\n\033[0m");

        exit(1);
    }

    initGlobals(); // Initialize global variables

    Analysis *info = createGNT(lex, buffer, file);

    if (opFlags[0] == TRUE) // Lexeme List
    {   
        printf("\033[1;32mLexeme List:\n\033[0m");
        
        while(!buffer->eof){
            print_lexeme((get_next_token(info))->lex);
        }
        printf("\n");

    }

    if (opFlags[1] == TRUE) // Parse Tree
    {        
        printf("\033[1;32mParser Tree:\n\033[0m");
        printf("\n");
        
        int result = yyparse();
        
        if(result == 0){
            if (parseTree != NULL) {
                setNodeLevels(parseTree, 0); // Set the level of each node
                printTree(parseTree, 0, TRUE); // Print the parse tree
                freeTree(parseTree); // Free memory allocated for the tree
            }
        }
    }

    if (opFlags[2] == TRUE) // Symbol Table
    {
        printf("\033[1;32mSymbol Table:\n\033[0m");
        int result = yyparse();
        if(result == 0){
            if (parseTree != NULL) {
                TreeNode *root = parseTree;
                setNodeLevels(root, 0); // Set the level of each node
                startSymbolTableCreation(root);
                // Trabalhe com a tabela de símbolos aqui
                printSymbolTable();

                freeSymbolTable();
            }
        }
        

    }


    free_buffer(buffer);
    fclose(file);

    printf("\033[1;32m\nEnd of compiling\n\n\033[0m");
}

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

    // Initialize the idStack
    idStack = malloc(sizeof(char *) * MAX_ID_STACK_SIZE);
    if (idStack) {
        for (int i = 0; i < MAX_ID_STACK_SIZE; ++i) {
            idStack[i] = malloc(sizeof(char) * MAX_LEXEME_SIZE);
        }

    } else {
        printf("Error allocating memory for idStack\n");
        exit(1);
    }

    // Initialize numStack
    numStack = malloc(sizeof(int *) * MAX_ID_STACK_SIZE);
    if (numStack) {
        for (int i = 0; i < MAX_ID_STACK_SIZE; ++i) {
            numStack[i] = malloc(sizeof(int));
        }

    } else {
        printf("Error allocating memory for numStack\n");
        exit(1);
    }


    // Initialize symbol table and other variables
    currentLine = 1;
    currentColumn = 0;
    currentToken = 0;
    currentTokenValue = NULL; // Will be allocated later when needed
    currentTokenType = 0;
    currentTokenLine = 0;
    currentScope = "global"; // Assuming it will be initialized later if needed
    idStackIndex = 0;
    numStackIndex = 0;
}


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

char **idStack;

int idStackIndex;

int **numStack;

int numStackIndex;