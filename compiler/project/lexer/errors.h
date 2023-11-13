/*
    Defining a structure for a list of lexical errors
*/

#ifndef LEXERROR_H
#define LEXERROR_H
#define MAX_ERROR_LIST_SIZE 64
#include "lex.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
    Structure for a lexical error
*/
typedef struct LexError
{
    int line;
    int pos;
    char *error;
    struct LexError *next;
}LexError;


void print_perror(int currentLine, int currentPosition, char *message); // Function to print a lexical error
void print_error_list(LexError *errorList); // Function to print the list of lexical errors
LexError *initLexErrorList(); // Function to initialize a list of lexical errors
LexError *addLexError(LexError *list, int line, int pos, const char *error); // Function to add a new error to the list
void freeLexErrorList(LexError *list); // Function to free the list of lexical errors


#endif // LEXERROR_H

// Path: compiler/project/lexer/lexer.h