#include <stdio.h>
#include "funcs.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    Buffer *buffer = allocate_buffer();

    while (1)
    {
        char nextChar = get_next_char(buffer);
        if (nextChar == '\0')
        {
            break;
        }
        printf("Char: %c, Line: %d, Position: %d\n", nextChar, buffer->currentLine, buffer->currentPosition);
    }

    deallocate_buffer(buffer);
    fclose(file);

    return 0;
}
