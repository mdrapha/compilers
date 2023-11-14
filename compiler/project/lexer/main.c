#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include "lex.h"
#include "globals.h"


int main(int argc, char *argv[])
{
    const char *file_name = argv[1];

    if(argc != 2){
        printf("Usage: ./lexer <file_name>\n");
        exit(1);
    }   

    file = fopen(file_name, "r");

    if(file == NULL){
        printf("Error opening file\n");
        exit(1);
    }

    buffer = malloc(sizeof(Buffer));
    initBuffer(buffer);
    lex.name = malloc(sizeof(char) * MAX_LEXEME_SIZE);


    Analysis *info = createAnalyser(&lex, buffer, file);
    Analysis *temp = info;

    //free_lexeme(&lex);
    free_buffer(buffer);
    fclose(file);

    return 0;
}