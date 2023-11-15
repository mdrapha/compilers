#include "funcs.h"

char *global_input_buffer = NULL;
int linha=1;

Buffer *allocate_buffer()
{
    Buffer *buffer = (Buffer *)malloc(sizeof(Buffer));
    if (buffer == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    buffer->start = NULL;
    buffer->current = NULL;
    buffer->currentPosition = 0;
    buffer->currentLine = 1;
    buffer->isFilled = 0;

    return buffer;
}

void deallocate_buffer(Buffer *buffer)
{
    Node *currentNode = buffer->start;
    while (currentNode != NULL)
    {
        Node *temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }
    free(buffer);
    free(global_input_buffer);
}

int fill_buffer(Buffer *buffer, FILE *file, Lexeme data)
{

    if (global_input_buffer == NULL)
    {
        global_input_buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
        if (global_input_buffer == NULL)
        {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
    }
    char *lexeme;
    lexeme = (char *)malloc(MAX_S * sizeof(char));

    char *aux;
    char character;
    int size_of_input_buffer;
    data.lexeme = (char *)malloc(MAX_S * sizeof(char));
    aux = fgets(global_input_buffer, BUFFER_SIZE, file);
    int i=0;

    while (aux != NULL)
    {

        size_of_input_buffer = strlen(global_input_buffer);
        int j=0;
        while (i < size_of_input_buffer)
        {
            character = global_input_buffer[i];
            if(character != '\0'){
                if (isalpha(character))
                {
                    lexeme[j] = character;
                    j++;
                }else if(isspace(character) && strlen(lexeme) > 0){
                    j=0;
                    strcpy(data.lexeme, lexeme);
                    data.lin = linha;
                    get_next_token(data);
                    //Limpa o lexema
                    memset(lexeme, 0, sizeof(lexeme));
                }else if(character == '\n' && strlen(lexeme) > 0){
                    j=0;
                    strcpy(data.lexeme, lexeme);
                    data.lin = linha;
                    //get_next_token(data);
                    //Limpa o lexema
                    memset(lexeme, 0, sizeof(lexeme));
                }
                else if(strlen(lexeme) > 0){
                    j=0;
                    strcpy(data.lexeme, lexeme);
                    data.lin = linha;
                    if(lexeme)
                    get_next_token(data);
                    //Limpa o lexema
                    memset(lexeme, 0, sizeof(lexeme));
                }
            }
            i++;
        }
        i=0;
        linha++;
        aux = fgets(global_input_buffer, BUFFER_SIZE, file);
    }
    
    return EOF;

    
}


void get_next_token(Lexeme data)
{
    if (strcmp(data.lexeme, "if") == 0)
    {
        data.token = IF;
        printf("Linha: %d, Lexema: %s, Token: IF", data.lin, data.lexeme);
    }
    else if (strcmp(data.lexeme, "for") == 0)
    {
        data.token = FOR;
        printf("Linha: %d, Lexema: %s, Token: FOR", data.lin, data.lexeme);
    }
    else if (strcmp(data.lexeme, "while") == 0)
    {
        data.token = WHILE;
        printf("Linha: %d, Lexema: %s, Token: WHILE", data.lin, data.lexeme);
    }
    else if (strcmp(data.lexeme, "int") == 0 ||
             strcmp(data.lexeme, "char") == 0 ||
             strcmp(data.lexeme, "float") == 0 ||
             strcmp(data.lexeme, "double") == 0 ||
             strcmp(data.lexeme, "long") == 0 ||
             strcmp(data.lexeme, "short") == 0)
    {

        data.token = TYPE;
        printf("Linha: %d, Lexema: %s, Token: TYPE", data.lin, data.lexeme);
    }
    else if (strcmp(data.lexeme, "do") == 0)
    {
        data.token = DO;
        printf("Linha: %d, Lexema: %s, Token: DO", data.lin, data.lexeme);
    }
    else if (strcmp(data.lexeme, "switch") == 0)
    {
        data.token = SWITCH;
        printf("Linha: %d, Lexema: %s, Token: SWITCH", data.lin, data.lexeme);
    }
    else if (strcmp(data.lexeme, "return") == 0)
    {
        data.token = RETURN;
        printf("Linha: %d, Lexema: %s, Token: RETURN", data.lin, data.lexeme);
    }
    else if (strcmp(data.lexeme, "struct") == 0)
    {
        data.token = STRUCT;
        printf("Linha: %d, Lexema: %s, Token: STRUCT", data.lin, data.lexeme);
    }
    else
    {
        data.token = ID;
        printf("Linha: %d, Lexema: %s, Token: ID", data.lin, data.lexeme);
    }
    printf("\n");
}
