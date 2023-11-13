#include "funcs.h"

// Function to print a lexical error
void print_perror(int currentLine, int currentPosition, char *message) {
    printf("Lexical error at line %d position %d: %s\n",currentLine , currentPosition, message);// Print the error
}

// Function to print the list of lexical errors
void print_error_list(LexError *errorList) {
    LexError *current = errorList;
    while (current != NULL) { // While there are errors in the list
        print_perror(current->line, current->pos, current->error); // Print the error
        current = current->next; // Go to the next error
    }
}


