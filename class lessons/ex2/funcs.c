#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"

char *global_input_buffer = NULL;

Buffer *allocate_buffer()
{
    Buffer *buffer = (Buffer *)malloc(64*sizeof(Buffer));
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
    free(global_input_buffer); // Free the allocated input buffer
}

void fill_buffer(Buffer *buffer, FILE *file)
{
    if (buffer->isFilled)
    {
        return;
    }

    if (global_input_buffer == NULL)
    {
        global_input_buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
        if (global_input_buffer == NULL)
        {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
    }

    if (fgets(global_input_buffer, BUFFER_SIZE, file) == NULL)
    {
        buffer->isFilled = 1;
        return;
    }

    for (int i = 0; global_input_buffer[i] != '\0'; i++)
    {
        char character = global_input_buffer[i];
        appendCharacter(buffer, character);

        if (character == '\n')
        {
            buffer->currentLine++;
            buffer->currentPosition = 0;
        }
    }
}

char get_next_char(Buffer *buffer)
{
    if (buffer->current == NULL)
    {
        fill_buffer(buffer, stdin);
        if (buffer->start == NULL)
        {
            return '\0';
        }
    }

    char character = buffer->current->character;
    buffer->current = buffer->current->next;

    return character;
}
