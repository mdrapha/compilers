#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "globals.h"

int main(int argc, char *argv[])
{
    file_name = argv[1];

    if (argc < 2)
    {
        printf("Usage: ./lexer <file_name>\n");
        exit(1);
    }
    file = fopen(file_name, "r");

    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    printf("\033[1;32m"); // Set text to the color green
    printf("Begin C- Compiler\n");
    printf("\033[0m"); // Reset text to default color

    initGlobals(); // Initialize global variables

    Analysis *info = createGNT(lex, buffer, file);

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
        
        int result = yyparse();
        printf("result: %d\n", result);
        
        if(result == 0){
            if (parseTree != NULL) {
                printTree(parseTree, 0, TRUE); // Print the parse tree
                freeTree(parseTree); // Free memory allocated for the tree
            }
        }
    }

    if (opFlags[2] == TRUE) // Symbol Table
    {
        printf("\033[1;32mSymbol Table:\n\033[0m");
        
        // Add logic to print the symbol table
    }


    free_buffer(buffer);
    fclose(file);

    printf("\033[1;32mEnd of compiling\n\n\033[0m");
    return 0;
}
