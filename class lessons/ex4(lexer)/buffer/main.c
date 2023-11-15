#include "funcs.h"

int main(int argc, char *argv[]) {
    struct Buffer buffer;
    struct lexeme lex;
    FILE *file;
    char filename[MAX_S];

    if (argc > 1) {
        strcpy(filename, argv[1]);
    } else {
        printf("Enter the filename: ");
        scanf("%s", filename);
    }

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    printf("File opened\n");

    initBuffer(&buffer);

    while (!buffer.eof) {
        lex = get_next_token(&buffer, file);
        print_lexeme(&lex);
    }

    free_lexeme(&lex);
    free_buffer(&buffer);
    fclose(file);
    return 0;
}
