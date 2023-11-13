#include "funcs.h"


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Uso: %s <nome_do_arquivo>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        perror("Erro ao abrir o arquivo");
        return EXIT_FAILURE;
    }

    Buffer *buffer = allocate_buffer();
    Lexeme data;
    data.lexeme = (char *)malloc(MAX_S * sizeof(char));


    // Continua lendo até que não haja mais caracteres para processar
    while (fill_buffer(buffer, file, data)!=EOF)
    {
        fill_buffer(buffer, file, data);
    }

    fclose(file);
    deallocate_buffer(buffer);

    return EXIT_SUCCESS;
}
