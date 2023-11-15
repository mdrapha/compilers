#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_S 64
#define ID 0
#define IF 1
#define FOR 2
#define WHILE 3
#define TYPE 4
#define DO 5
#define SWITCH 6
#define RETURN 8
#define STRUCT 9
#define BUFFER_SIZE 256

typedef struct Node
{
    char character;
    struct Node *next;
} Node;

typedef struct Buffer
{
    Node *start;
    Node *current;
    int currentPosition;
    int currentLine;
    int isFilled;
} Buffer;

typedef struct lexeme
{
    int lin;
    char *lexeme;
    int token;
} Lexeme;

Buffer *allocate_buffer();
void deallocate_buffer(Buffer *buffer);
int fill_buffer(Buffer *buffer, FILE *file, Lexeme data);
void get_next_token(Lexeme data);
