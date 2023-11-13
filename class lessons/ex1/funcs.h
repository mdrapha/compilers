struct Buffer {
    char *data;     // Vetor para o buffer
    int size;       // Tamanho do buffer
};

// Declaração das funções
struct Buffer allocate_buffer(int size);
void deallocate_buffer(struct Buffer *buffer);
void replace_print(struct Buffer *buffer, const char *filename);
