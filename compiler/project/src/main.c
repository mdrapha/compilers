/**
 * @file main.c
 * How to run:
 * 1. make
 * 2. ./lexer <file_name> -l -p -s
 *      -l: Print the lexeme list
 *      -p: Print the parse tree
 *      -s: Print the symbol table
 */

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
    printf("Begin C- Compiler\n", file_name);
    printf("\033[0m"); // Reset text to default color

    initGlobals(); // Initialize global variables

    Analysis *info = createGNT(lex, buffer, file);

    int opFlags[3] = {FALSE, FALSE, FALSE};

    /*Verifing the argv diretives*/
    //Verifica se no argv tem a diretiva -l ou -p ou -s
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

    if (opFlags[0] == TRUE)
    {   

        printf("\033[1;32m"); // Set text to the color green
        printf("Lexeme List:\n");
        printf("\033[0m"); // Reset text to default color
        
        while(!buffer->eof){
            print_lexeme((get_next_token(info))->lex);
        }
        printf("\n");
        return 0;
    }

    if (opFlags[1] == TRUE)
    {        
        printf("\033[1;32m"); // Set text to the color green
        printf("Parser Tree:\n");
        int result = yyparse();
        printf("result: %d\n", result);
        printf("\033[0m"); // Reset text to default color
        if(result==0){
            if (parseTree != NULL) {
                printTree(parseTree, 0, TRUE); // Imprime a árvore de análise
                freeTree(parseTree); // Libera a memória alocada para a árvore
            }
        }
    }

    // if(opFlags[2] == TRUE){


        printf("\033[1;32m"); // Set text to the color green
        printf("Parser Tree:\n");
        int result = yyparse();
        printf("result: %d\n", result);
        printf("\033[0m"); // Reset text to default color
        if(result==0){
            if (parseTree != NULL) {
                printTree(parseTree, 0, TRUE); // Imprime a árvore de análise
                freeTree(parseTree); // Libera a memória alocada para a árvore
            }
        }

        

    // }

    // printf("parser\n");
    // printf("result: %d\n", yyparse());
    // if (parseTree != NULL) {
    //     printTree(parseTree, 0, TRUE); // Imprime a árvore de análise
    //     freeTree(parseTree); // Libera a memória alocada para a árvore
    // }
    freeGNT(info);
    free_buffer(buffer);
    fclose(file);
    

    printf("\033[1;32m"); // Set text to the color green
    printf("End of compiling\n\n");
    printf("\033[0m"); // Reset text to default color
    return 0;
}