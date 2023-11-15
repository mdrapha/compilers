#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "globals.h"

int main(int argc, char *argv[])
{
    const char *file_name = argv[1];

    if (argc != 2)
    {
        printf("Usage: ./lexer <file_name>\n");
        exit(1);
    }
    printf("File name: %s\n", file_name);
    file = fopen(file_name, "r");

    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    printf("\033[1;32m"); // Set text to the color green
    printf("Begin C- Compiling\n");
    printf("\033[0m"); // Reset text to default color

    initGlobals(); // Initialize global variables

    Analysis *info = createGNT(lex, buffer, file);
    Analysis *temp = info;
    // while (!buffer->eof)
    // {
    //     yylex();
    // }

    printf("parser\n");
    printf("result: %d\n", yyparse());

    free_buffer(buffer);
    fclose(file);

    printf("\033[1;32m"); // Set text to the color green
    printf("End of compiling\n\n");
    printf("\033[0m"); // Reset text to default color
    return 0;
}