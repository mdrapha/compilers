#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funcs.h"

// Função para alocar o buffer
struct Buffer allocate_buffer(int size) {
    struct Buffer buffer;
    buffer.size = size;
    buffer.data = (char *)malloc(size * sizeof(char));
    if (buffer.data == NULL) {
        fprintf(stderr, "Erro: Não foi possível alocar o buffer.\n");
        exit(1);
    }
    return buffer;
}

// Função para desalocar o buffer
void deallocate_buffer(struct Buffer *buffer) {
    free(buffer->data);
    buffer->data = NULL;
    buffer->size = 0;
}

// Função para substituir e imprimir o buffer
void replace_print(struct Buffer *buffer, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Erro: Não foi possível abrir o arquivo.\n");
        exit(1);
    }

    int i = 0;
    int c;

    while ((c = fgetc(file)) != EOF) { //97-122 minusculo 65-90 maiusculo
        if (i < buffer->size) {
            if(c == 65 || c == 69 || c == 73 || c == 79 || c == 85 || c == 97 || c == 101 || c == 105 || c == 111 || c == 117){
                if (c >= 97 && c <= 122) {
                    buffer->data[i] = c-32;
                } else if (c >= 65 && c <= 90) {
                    buffer->data[i] = c+32;
                }
                
            }else{
                buffer->data[i] = c;
            }
            i++;
        } else {
            // Buffer cheio, imprimir e reiniciar
            buffer->data[i] = '\0';
            printf("%s", buffer->data);
            i = 0;
        }
    }

    if (i > 0) {
        buffer->data[i] = '\0';
        printf("%s", buffer->data);
    }

    fclose(file);
}

