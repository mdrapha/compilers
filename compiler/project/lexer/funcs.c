#include "funcs.h"

int currentLine = 1;
int iteration = 0;
int errorListSize = 0;
LexError *lexErrorList = NULL;

// Function to initialize a list of lexical errors
LexError *initLexErrorList()
{
    LexError *lexErrorList = malloc(sizeof(LexError));
    lexErrorList->line = 0;
    lexErrorList->pos = 0;
    lexErrorList->error = NULL;
    lexErrorList->next = NULL;
    return lexErrorList;
}

// Function to add a new error to the list
LexError *addLexError(LexError *list, int line, int pos, const char *error)
{
    LexError *newError = (LexError *)malloc(sizeof(LexError));
    if (newError == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(1);
    }

    newError->line = line;
    newError->pos = pos;
    newError->error = strdup(error); // Copy the error description to the new structure
    newError->next = list;           // The new error becomes the first in the list

    return newError;
}

// Function to create Analyser struct
Analysis *createAnalyser(lexeme *lex, Buffer *buffer, FILE *file)
{
    Analysis *info = malloc(sizeof(Analysis));
    info->lex = lex;
    info->buffer = buffer;
    info->file = file;
    return info;
}

// Function to free the list of lexical errors
void freeLexErrorList(LexError *list)
{
    while (list != NULL)
    {
        LexError *next = list->next;
        free(list->error);
        free(list);
        list = next;
    }
}

// Function to free the buffer
void free_buffer(Buffer *buffer)
{
    free(buffer->buffer);
}

// Function to initialize the buffer
void initBuffer(Buffer *buffer)
{
    buffer->buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
    if (!buffer->buffer)
    {
        perror("Failed to allocate memory for buffer");
        exit(EXIT_FAILURE);
    }
    memset(buffer->buffer, 0, BUFFER_SIZE); // Inicializa o buffer com zeros
    buffer->currentPosition = 0;
    buffer->isFilled = 0;
    buffer->eof = 0;
    buffer->currentLine = 1;
}

// Function to fill the buffer
void fill_buffer(Buffer *buffer, FILE *file)
{
    buffer->currentPosition = 0;                          // Reset the buffer position
    memset(buffer->buffer, 0, BUFFER_SIZE);               // Fill the buffer with zeros
    if (fgets(buffer->buffer, BUFFER_SIZE, file) == NULL) // Fill the buffer with the next line of the file
    {
        if (feof(file)) // If the end of file is reached
        {
            buffer->eof = 1;
        }
        else
        {
            perror("Error reading from file");
            exit(EXIT_FAILURE);
        }
    }
}

// Function to get the next char from the buffer
char get_next_char(Buffer *buffer, FILE *file)
{
    if (buffer->currentPosition >= BUFFER_SIZE || buffer->buffer[buffer->currentPosition] == '\0')
    {                              // If the buffer is full or the end of line is reached
        fill_buffer(buffer, file); // Fill the buffer with the next line of the file
        buffer->currentPosition = 0;
    }

    char character = buffer->buffer[buffer->currentPosition];
    buffer->currentPosition++;
    if (character == EOF)
    {
        buffer->eof = 1;
    }
    if (buffer->eof)
    {
        return EOF;
    }

    if (character == '\n')
    {
        currentLine++;
    }

    return character;
}

// Function to unget a char from the buffer
void unget_char(Buffer *buffer)
{
    if (buffer->currentPosition > 0)
    {
        buffer->currentPosition--;
    }
    // Verify if the currentLine should be decremented
    if (buffer->buffer[buffer->currentPosition] == '\n')
    {
        currentLine--;
    }
}

// Function to initialize the lexeme
void initLexeme(lexeme *lex)
{
    lex->name = (char *)malloc(MAX_LEXEME_SIZE * sizeof(char));
    lex->token = 0;
    memset(lex->name, 0, MAX_LEXEME_SIZE); // Adicione esta linha
}

char *strconcat(char *s1, char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

// Function to free the lexeme
void free_lexeme(lexeme *lex)
{
    // Verify if the lexeme is not NULL
    if (lex != NULL)
    {
        // Free the memory allocated for the lexeme
        free(lex);
    }
}

int isspecial(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '<' || c == '>' || c == '=' || c == '!' || c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']' || c == ';' || c == ',' || c == EOF)
    {
        return 1;
    }
    return 0;
}

void cleanString(char *str)
{
    int i = 0, j = 0;

    while (str[i])
    {
        if (isalnum(str[i]) || isspecial(str[i]))
        {                      // Verifica se o caractere é uma letra
            str[j++] = str[i]; // Copia o caractere para a posição 'j' se for uma letra
        }
        i++;
    }

    str[j] = '\0'; // Encerra a string com o caractere nulo
}

// Function to convert a state to a string
char *get_state_name(int state)
{
    switch (state)
    {
    case S0:
        return "S0";
        break;
    case S_ID:
        return "S_ID";
        break;
    case S_NUM:
        return "S_NUM";
        break;
    case S_PLUS:
        return "S_PLUS";
        break;
    case S_MINUS:
        return "S_MINUS";
        break;
    case S_MULT:
        return "S_MULT";
        break;
    case S_DIV:
        return "S_DIV";
        break;
    case S_LT:
        return "S_LESS";
        break;
    case S_LTE:
        return "S_LESS_EQ";
        break;
    case S_GT:
        return "S_GREATER";
        break;
    case S_GTE:
        return "S_GREATER_EQ";
        break;
    case S_EQ:
        return "S_EQ";
        break;
    case S_DIFF:
        return "S_NEQ";
        break;
    case S_ATRB:
        return "S_ATRB";
        break;
    case S_SEMI:
        return "S_SEMI";
        break;

    case S_COMMA:
        return "S_COMMA";
        break;

    case S_LPAREN:
        return "S_LPAREN";
        break;

    case S_RPAREN:
        return "S_RPAREN";
        break;

    case S_LBRACE:
        return "S_LBRACE";
        break;

    case S_RBRACE:
        return "S_RBRACE";
        break;

    case S_LSQBRA:
        return "S_LSQBRA";
        break;

    case S_RSQBRA:
        return "S_RSQBRA";
        break;

    case S_EXCLAMATION:
        return "S_EXCLA";
        break;

    case S_SPACE:
        return "S_SPACE";
        break;

    case S_ENTER:
        return "S_ENTER";
        break;

    case S_EOF:
        return "S_ENDFILE";
        break;

    case S_BCOMMENT:
        return "S_BCOMMENT";
        break;

    case S_ECOMMENT:
        return "S_ECOMMENT";
        break;

    case S_ERROR:
        return "S_ERROR";
        break;

    default:
        return "S_ERROR";
        break;
    }
}

int state_to_token(int state)
{
    switch (state)
    {    
    case S_ID:
        return T_ID;
        break;

    case S_NUM:
        return T_NUM;
        break;

    case S_PLUS:
        return T_PLUS;
        break;

    case S_MINUS:
        return T_MINUS;
        break;

    case S_MULT:
        return T_MULT;
        break;

    case S_DIV:
        return T_DIV;
        break;

    case S_LT:
        return T_LT;
        break;

    case S_LTE:
        return T_LTE;
        break;

    case S_GT:
        return T_GT;
        break;

    case S_GTE:
        return T_GTE;
        break;

    case S_EQ:
        return T_EQ;
        break;

    case S_DIFF:
        return T_NEQ;
        break;

    case S_ATRB:
        return T_ATRB;
        break;

    case S_SEMI:
        return T_SEMI;
        break;

    case S_COMMA:
        return T_COMMA;
        break;

    case S_LPAREN:
        return T_LPAREN;
        break;

    case S_RPAREN:
        return T_RPAREN;
        break;

    case S_LBRACE:
        return T_LBRACE;
        break;

    case S_RBRACE:
        return T_RBRACE;
        break;

    case S_LSQBRA:
        return T_LSQBRA;
        break;

    case S_RSQBRA:
        return T_RSQBRA;
        break;

    case S_EXCLAMATION:
        return T_EXCLA;
        break;

    case S_SPACE:
        return T_SPACE;
        break;

    case S_ENTER:
        return T_ENTER;
        break;

    case S_EOF:
        return T_EOF;
        break;

    case S_ERROR:
        return T_ERROR;
        break;
    
    case S0:
        return T_EOF;
        break;
    
    default:
        return T_ERROR;
        break;
    }
}

int get_token(lexeme *lex)
{
    switch (lex->token)
    {
    case S_ID:
        cleanString(lex->name);
        return get_id_token(lex->name);
        break;

    default:
        return state_to_token(lex->token);
        break;
    }
}

// Function to convert a token to a string
char *get_token_name(int token)
{
    switch (token)
    {
    case T_ID:
        return "T_ID";
        break;

    case T_NUM:
        return "T_NUM";
        break;

    case T_PLUS:
        return "T_PLUS";
        break;

    case T_MINUS:
        return "T_MINUS";
        break;

    case T_MULT:
        return "T_MULT";
        break;

    case T_DIV:
        return "T_DIV";
        break;

    case T_LT:
        return "T_LT";
        break;

    case T_LTE:
        return "T_LTE";
        break;

    case T_GT:
        return "T_GT";
        break;

    case T_GTE:
        return "T_GTE";
        break;

    case T_EQ:
        return "T_EQ";
        break;

    case T_NEQ:
        return "T_NEQ";
        break;

    case T_ATRB:
        return "T_ATRB";
        break;

    case T_SEMI:
        return "T_SEMI";
        break;

    case T_COMMA:
        return "T_COMMA";
        break;

    case T_LPAREN:
        return "T_LPAREN";
        break;

    case T_RPAREN:
        return "T_RPAREN";
        break;

    case T_LBRACE:
        return "T_LBRACE";
        break;

    case T_RBRACE:
        return "T_RBRACE";
        break;

    case T_LSQBRA:
        return "T_LSQBRA";
        break;

    case T_RSQBRA:
        return "T_RSQBRA";
        break;

    case T_EXCLA:
        return "T_EXCLA";
        break;

    case T_SPACE:
        return "T_SPACE";
        break;

    case T_ENTER:
        return "T_ENTER";
        break;

    case T_ENDFILE:
        return "T_ENDFILE";
        break;

    case T_ERROR:
        return "T_ERROR";
        break;

    case T_IF:
        return "T_IF";
        break;

    case T_ELSE:
        return "T_ELSE";
        break;

    case T_RETURN:
        return "T_RETURN";
        break;

    case T_VOID:
        return "T_VOID";
        break;

    case T_WHILE:
        return "T_WHILE";
        break;

    case T_INT:
        return "T_INT";
        break;

    case T_EOF:
        return "T_EOF";
        break;

    default:
        return "T_ERROR";
        break;
    }
}

// Function to print the lexeme
void print_lexeme(lexeme *lex)
{
    if (lex->token == T_ENTER || lex->token == T_SPACE || lex->token == T_EOF)
    {
        return;
    }
    printf("Lexeme: '%s' \t Token:%s \t Line:%d\n", lex->name, get_token_name(lex->token), lex->line);
}

Analysis *analyser(Analysis *info)
{
    lexeme lex;
    lex.name = (char *)malloc(MAX_LEXEME_SIZE * sizeof(char));
    int state = S0;
    int next_state;
    char c;

    if (lex.name == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(1);
    }

    // Initialize the lexeme token and line
    lex.token = 0;
    lex.line = currentLine;

    // Initialize lexeme name
    c = get_next_char(info->buffer, info->file);
    if (c == ' ' || c == '\n' || c == '\r')
    {
        do
        {
            c = get_next_char(info->buffer, info->file);
        } while (c == ' ' || c == '\n' || c == '\r');
    }

    next_state = get_next_state(state, char_to_token(c));
    if (next_state == S_ERROR)
    {
        fprintf(stderr, "Error: Unknowed Character '%c' at Line: %d Col: %d\n", c, currentLine, info->buffer->currentPosition);
        exit(1);
    }

    while (c != EOF && next_state != S0)
    {

        if (next_state == S_ECOMMENT)
        {
            printf("S_ECOMMENT\n");
        }

        // Check for buffer overflow
        if (strlen(lex.name) >= MAX_LEXEME_SIZE - 1)
        {
            fprintf(stderr, "Error: Lexeme too long\n");
            exit(1);
        }

        lex.name = strconcat(lex.name, &c);
        state = next_state;

        c = get_next_char(info->buffer, info->file);

        next_state = get_next_state(state, char_to_token(c));

        if (next_state == S_ERROR)
        {
            fprintf(stderr, "ErrorA: Unknowed Character '%c' at Line: %d Col: %d\n", c, currentLine, info->buffer->currentPosition);
            exit(1);
        }

        if (next_state == S_BCOMMENT)
        {

            while (next_state != S0)
            {
                // lex.name="\0";
                state = next_state;
                c = get_next_char(info->buffer, info->file);
                next_state = get_next_state(state, char_to_token(c));

                if (c == EOF)
                {
                    fprintf(stderr, "Error: Unclosed Comment\n");
                    exit(1);
                }
                
            }
            
            c = get_next_char(info->buffer, info->file);

            return analyser(info);
        }
    }

    // lex.name[strlen(lex.name)] = '\0'; // Null-terminate the lexeme
    

    if (state == S_ERROR)
    {
        fprintf(stderr, "Error: Unknowed Character '%s' at Line: %d Col: %d\n", lex.name, currentLine, info->buffer->currentPosition);
        exit(1);
    }

    if (state == S_BCOMMENT)
    {
        fprintf(stderr, "Error: Unclosed Comment\n");
        exit(1);
    }

    if (get_progress(state, char_to_token(c)) == 0)
    {
        // printf("unget state:%s char:%c\n", get_state_name(state), c);
        unget_char(info->buffer);
    }

    // Tenta assim:
    // if(strlen(lex.name) > 0){
    
    lex.token = state;
    lex.token = get_token(&lex);
    lex.line = currentLine;    
    info->lex = &lex;
    cleanString(info->lex->name);

    return info;
}