#ifndef LEX_H
#define LEX_H

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

enum Tokens
{
    T_EXCLA = 512,
    T_SPACE,
    T_EOF,
    T_ENTER,
    T_ENDFILE,
    T_ERROR
};

enum Alphabet
{
    LETTER,
    DIGIT,
    PLUS,
    MINUS,
    MULT,
    DIV,
    LT,
    GT,
    ATRB,
    SEMI,
    COMMA,
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,
    LSQBRA,
    RSQBRA,
    EXCLA,
    SPACE,
    ENTER,
    ENDFILE,
    OTHER
};

enum States
{
    S0,             // Initial state
    S_ID,           // Identifier state
    S_NUM,          // Number state
    S_PLUS,         // Plus state
    S_MULT,         // Mult state 
    S_MINUS,        // Minus state
    S_DIV,          // Div state
    S_LT,           // Less than state
    S_GT,           // Greater than state
    S_ATRB,         // Atribuition state
    S_EQ,           // Equal state
    S_LTE,          // Less than or equal state
    S_GTE,          // Greater than or equal state
    S_DIFF,         // Different state
    S_LPAREN,       // Left parenthesis state
    S_RPAREN,       // Right parenthesis state
    S_LBRACE,       // Left brace state
    S_RBRACE,       // Right brace state
    S_LSQBRA,       // Left square bracket state
    S_RSQBRA,       // Right square bracket state
    S_SPACE,        // Space state
    S_SEMI,         // Semicolon state
    S_COMMA,        // Comma state
    S_BCOMMENT,     // Begin comment state
    S_ECOMMENT,     // End comment state
    S_ENTER,        // Enter state
    S_EXCLAMATION,  // Exclamation state
    S_ERROR,        // Error state
    S_EOF         // End of file state
};


int char_to_token(char c);
unsigned long int hasher(const char *word);
int get_id_token(char *name);
char *get_char_pretoken_name(int token);
int get_next_state(int state, int token);
int get_progress(int state, int token);

#endif