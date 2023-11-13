#include "funcs.h"
int currentLine = 1;

void free_buffer(struct Buffer *buffer)
{
    free(buffer->buffer);
}

void initBuffer(struct Buffer *buffer)
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

void fill_buffer(struct Buffer *buffer, FILE *file)
{
    buffer->currentPosition = 0;
    memset(buffer->buffer, 0, BUFFER_SIZE);
    if (fgets(buffer->buffer, BUFFER_SIZE, file) == NULL)
    {
        if (feof(file))
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

char get_next_char(struct Buffer *buffer, FILE *file)
{
    if (buffer->currentPosition >= BUFFER_SIZE || buffer->buffer[buffer->currentPosition] == '\0')
    {
        fill_buffer(buffer, file);
        buffer->currentPosition = 0;
    }

    if (buffer->eof)
    {
        return EOF;
    }

    char character = buffer->buffer[buffer->currentPosition];
    buffer->currentPosition++;

    if (character == '\n')
    {
        currentLine++;
    }

    return character;
}

void initLexeme(struct lexeme *lex) {
    lex->name = (char *)malloc(MAX_S * sizeof(char));
    lex->token = 0;
    memset(lex->name, 0, MAX_S);  // Adicione esta linha
}


void free_lexeme(struct lexeme *lex)
{
    free(lex->name);
}

char *get_token_name(int token){
    switch (token)
    {
    case IF:
        return "IF";
        break;
    case THEN:
        return "THEN";
        break;
    case ELSE:
        return "ELSE";
        break;
    case END:
        return "END";
        break;
    case REPEAT:
        return "REPEAT";
        break;
    case UNTIL:
        return "UNTIL";
        break;
    case READ:
        return "READ";
        break;
    case WRITE:
        return "WRITE";
        break;
    case eof:
        return "eof";
        break;
    case ID:
        return "ID";
        break;
    case NUM:
        return "NUM";
        break;
    case ATRB:
        return "ATRB";
        break;
    case OPERATOR:
        return "OPERATOR";
        break;
    case PLUS:
        return "PLUS";
        break;
    case MINUS:
        return "MINUS";
        break;
    case MULT:
        return "MULT";
        break;
    case DIV:
        return "DIV";
        break;
    case OPEN_PAR:
        return "OPEN_PAR";
        break;
    case CLOSE_PAR:
        return "CLOSE_PAR";
        break;
    case LESS:
        return "LESS";
        break;
    case EQUAL:
        return "EQUAL";
        break;
    case ERROR:
        return "ERROR";
        break;
    case SEMICOLON:
        return "SEMICOLON";
        break;
    default:
        return "UNKNOWN";
        break;
    }
}

void print_lexeme(const struct lexeme *lex)
{
    printf("Lexeme: %s \t Token:%s \t Line:%d\n", lex->name, get_token_name(lex->token), lex->line);
}

void print_error(struct Buffer *buffer, char *message) {
    printf("Error at position %d: %s\n", buffer->currentPosition, message);
}


struct lexeme analyser(struct Buffer *buffer, FILE *file)
{
    struct lexeme lex;
    initLexeme(&lex);
    char character;
    int i = 0;
    character = get_next_char(buffer, file);
    int state = 0;

    while (state != 6 && state != 5 && character != EOF)
    {
        if (character == EOF)
        {
            lex.token = eof;
            buffer->eof = 1;
            lex.line = currentLine;
            state = 6;
        }
        else if (character == ' ' || character == '\n' || character == '\t')
        {
            character = get_next_char(buffer, file);
            state = 0;
        }
        else if (character == '{')
        {
            state = 3;
        }
        else if (character == ':')
        {
            lex.name[0] = character;
            character = get_next_char(buffer, file);
            if (character == '=')
            {
                lex.name[1] = character;
                lex.name[2] = '\0';
                lex.token = ATRB;
                lex.line = currentLine;
                state = 6;
            }
            else
            {
                lex.token = ERROR;
                lex.line = currentLine;
                state = 5;
            }
        }
        else if (character == '+')
        {
            lex.name[0] = character;
            lex.name[1] = '\0';
            lex.token = PLUS;
            lex.line = currentLine;
            state = 6;
        }
        else if (character == '-')
        {
            lex.name[0] = character;
            lex.name[1] = '\0';
            lex.token = MINUS;
            lex.line = currentLine;
            state = 6;
        }
        else if (character == '*')
        {
            lex.name[0] = character;
            lex.name[1] = '\0';
            lex.token = MULT;
            lex.line = currentLine;
            state = 6;
        }
        else if (character == '/')
        {
            lex.name[0] = character;
            lex.name[1] = '\0';
            lex.token = DIV;
            lex.line = currentLine;
            state = 6;
        }
        else if (character == '(')
        {
            lex.name[0] = character;
            lex.name[1] = '\0';
            lex.token = OPEN_PAR;
            lex.line = currentLine;
            state = 6;
        }
        else if (character == ')')
        {
            lex.name[0] = character;
            lex.name[1] = '\0';
            lex.token = CLOSE_PAR;
            lex.line = currentLine;
            state = 6;
        }
        else if (character == '<')
        {
            lex.name[0] = character;
            lex.name[1] = '\0';
            lex.token = LESS;
            lex.line = currentLine;
            state = 6;
        }
        else if (character == '=')
        {
            lex.name[0] = character;
            lex.name[1] = '\0';
            lex.token = EQUAL;
            lex.line = currentLine;
            state = 6;
        }
        else if (character == ';')
        {
            lex.name[0] = character;
            lex.name[1] = '\0';
            lex.token = SEMICOLON;
            lex.line = currentLine;
            state = 6;
        }
        else if (isdigit(character))
        {
            lex.name[0] = character;
            lex.name[1] = '\0';
            lex.token = NUM;
            lex.line = currentLine;
            state = 2;
        }
        else if (isalpha(character))
        {
            lex.name[0] = character;
            lex.name[1] = '\0';
            lex.token = ID;
            lex.line = currentLine;
            state = 1;
        }
        else
        {
            lex.token = ERROR;
            lex.line = currentLine;
            state = 5;
        }

        switch (state)
        {
        case 1:
            while (isalpha(character))
            {
                lex.name[i] = character;
                character = get_next_char(buffer, file);
                i++;
            }
            lex.name[i] = '\0';

            if(strcmp(lex.name, "if") == 0){
                lex.token = IF;
            } else if(strcmp(lex.name, "then") == 0){
                lex.token = THEN;
            } else if(strcmp(lex.name, "else") == 0){
                lex.token = ELSE;
            } else if(strcmp(lex.name, "end") == 0){
                lex.token = END;
            } else if(strcmp(lex.name, "repeat") == 0){
                lex.token = REPEAT;
            } else if(strcmp(lex.name, "until") == 0){
                lex.token = UNTIL;
            } else if(strcmp(lex.name, "read") == 0){
                lex.token = READ;
            } else if(strcmp(lex.name, "write") == 0){
                lex.token = WRITE;
            } else {
                lex.token = ID;
            }
            i = 0;
            state = 6;
            break;

        case 2:
            while (isdigit(character))
            {
                lex.name[i] = character;
                character = get_next_char(buffer, file);
                i++;
            }
            lex.name[i] = '\0';
            lex.token = NUM;
            i = 0;
            state = 6;
            break;

        case 3:
            while (character != '}' && character != EOF)
            {
                character = get_next_char(buffer, file);
            }
            if (character == EOF)
            {
                lex.token = ERROR;
                state = 5;
            }
            else
            {
                character = get_next_char(buffer, file);
                state = 0;
            }

            break;

        default:
            break;
        }
    }

    return lex;
}
