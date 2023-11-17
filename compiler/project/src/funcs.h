#ifndef FUNCS_H
#define FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>



#endif

/*Structure for the buffer*/
typedef struct Buffer
{
    char *buffer;
    int eof;
    int isFilled;
    int currentLine;
    int currentPosition;
} Buffer;

/*Structure for the lexeme*/
typedef struct lexeme
{
    char *name;
    int token;
    int line;
} lexeme;

/*Structure for the lexer*/
typedef struct Analysis
{
    Buffer *buffer;
    lexeme *lex;
    FILE *file;
    char lastChar;
} Analysis;



Analysis *createGNT(lexeme *lex, Buffer *buffer, FILE *file); /*Function to analyse lexemes*/
void fill_buffer(Buffer *buffer, FILE *file);                 /*Function to free the buffer*/
void cleanString(char *str);                                  /*Function to clean a string*/
void initBuffer(Buffer *buffer);                              /*Function to initialize the buffer*/
void free_buffer(Buffer *buffer);                             /*Function to free the buffer*/
char get_next_char(Buffer *buffer, FILE *file);               /*Function to get the next char from the buffer*/
void initLexeme(lexeme *lex);                                 /*Function to initialize the lexeme*/
void resetLexeme(lexeme *lex);                                 /*Function to reset the lexeme*/
void free_lexeme(lexeme *lex);                                /*Function to free the lexeme*/
void print_lexeme(lexeme *lex);                               /*Function to print the lexeme*/
char *get_token_name(int token);                              /*Function to convert a token to a string*/
char *get_state_name(int state);                              /*Function to convert a state to a string*/
void unget_char(Buffer *buffer);                              /*Function to unget a char from the buffer*/
Analysis *get_next_token(Analysis *info);                     /*Function to analyse the buffer and return a lexeme*/
int get_token(lexeme *lex);                                   /*Function to get the token from a lexeme*/