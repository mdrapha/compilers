#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum tokens_tiny {
    IF = 1, THEN, ELSE, END, REPEAT, UNTIL, READ, WRITE, eof, 
    ID, NUM, ATRB, OPERATOR, PLUS, MINUS, MULT, DIV, OPEN_PAR, CLOSE_PAR, LESS, EQUAL, ERROR,
    SEMICOLON
};

#define BUFFER_SIZE 256
#define MAX_S 64
#define BUFFER_SIZE 256

struct Buffer {
    char *buffer;
    int eof;
    int isFilled;
    int currentLine;
    int currentPosition;
};

struct lexeme {
    char *name;
    int token;
    int line;
};

extern int currentLine;

void fill_buffer(struct Buffer *buffer, FILE *file);
void initBuffer(struct Buffer *buffer);
void free_buffer(struct Buffer *buffer);
char get_next_char(struct Buffer *buffer, FILE *file);
void initLexeme(struct lexeme *lex);
void free_lexeme(struct lexeme *lex);
void print_lexeme(const struct lexeme *lex);
void print_error(struct Buffer *buffer, char *message);
struct lexeme get_next_token(struct Buffer *buffer, FILE *file);