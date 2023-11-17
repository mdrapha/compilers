#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "globals.h"

int main(int argc, char *argv[])
{
    file_name = argv[1];

    if (argc != 2)
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
    printf("\033[1;32mBegin \033[1;0m%s\033[1;32m Compiling\n", file_name);
    printf("\033[0m"); // Reset text to default color

    initGlobals(); // Initialize global variables

    Analysis *info = createGNT(lex, buffer, file);

    printf("parser\n");
    printf("result: %d\n", yyparse());
    if (parseTree != NULL) {
        printTree(parseTree, 0, TRUE); // Imprime a árvore de análise
        freeTree(parseTree); // Libera a memória alocada para a árvore
    }
    free_buffer(buffer);
    fclose(file);

    printf("\033[1;32m"); // Set text to the color green
    printf("End of compiling\n\n");
    printf("\033[0m"); // Reset text to default color
    return 0;
}