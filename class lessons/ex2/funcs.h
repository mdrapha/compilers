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

Buffer *allocate_buffer();
void deallocate_buffer(Buffer *buffer);
void fill_buffer(Buffer *buffer, FILE *file);
char get_next_char(Buffer *buffer);
