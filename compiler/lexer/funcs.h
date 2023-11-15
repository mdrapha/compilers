#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_S 64

/*Enumarator for C- Language Tokens*/
enum token {
    ID = 1, NUM, IF, ELSE, WHILE, RETURN, INT, VOID, PLUS, MINUS, MULT, DIV, LT, LTE, GT, GTE, EQ, NEQ, ASSIGN, SEMI, COMMA, LPAREN, RPAREN, LBRACK, RBRACK, LBRACE, RBRACE, COMMENT, ERROR, ENDFILE, OPERATOR, QUOTE, ATRB, HASHTAG, SPACE, DOT, ENTER
};

typedef struct lexeme {
    char *lex;
    int type;
    int line;
}Lexemes;

void get_next_token(Lexemes lexeme, char* word, int token_type, int line);
void print_lexeme(Lexemes lexeme);
void initLexeme(Lexemes lexeme);
void free_lexeme(Lexemes lexeme);
char *get_token_name(int token_type);
