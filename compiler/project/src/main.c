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
    printf("File opened\n");
    initGlobals(); // Initialize global variables
    printf("Globals initialized\n");
    if (lex != NULL)
    {
        lex->name = malloc(sizeof(char) * MAX_LEXEME_SIZE);
    }
    printf("Lexeme initialized\n");
    Analysis *info = createGNT(lex, buffer, file);
    Analysis *temp = info;
    printf("Analysis created\n");
    while (!buffer->eof)
    {
        temp = get_next_token(info);
        print_lexeme(temp->lex);
        // Reset lex for the next iteration
        resetLexeme(temp->lex);
        info = temp;
    }
    printf("Passed\n");
    // free_lexeme(&lex);
    free_buffer(buffer);
    fclose(file);

    return 0;
}