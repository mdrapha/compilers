#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

int main(int argc, char *argv[]) {

    const char *filename;
    int buffer_size;

    filename = argv[1];
    buffer_size = atoi(argv[2]);
    
    if (argc != 3) {
        fprintf(stderr, "Erro: Número incorreto de argumentos.\n");
        fprintf(stderr, "Uso: %s <nome_do_arquivo> <tamanho_do_buffer>\n", argv[0]);
        exit(1);
    }

    if (fopen(filename, "r") == NULL) {
        fprintf(stderr, "Erro: Não foi possível abrir o arquivo.\n");
        exit(1);
    }


    struct Buffer buffer = allocate_buffer(buffer_size);

    replace_print(&buffer, filename);

    deallocate_buffer(&buffer);

    return 0;


}
