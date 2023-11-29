#include "globals.h"
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 101


SymbolTableEntry *hashTable[HASH_TABLE_SIZE]; // Tabela de hash para símbolos

// Função de hash para strings
unsigned int hash(char *str) {
    unsigned int hashValue = 0;
    for (char *p = str; *p != '\0'; p++) {
        hashValue = *p + 31 * hashValue;
    }
    return hashValue % HASH_TABLE_SIZE;
}

void insertSymbol(TreeNode *Node, int scopeLevel) {
    unsigned int index = hash(Node->lexeme);
    SymbolTableEntry *entry = (SymbolTableEntry *)malloc(sizeof(SymbolTableEntry));
    strcpy(entry->identifier, Node->lexeme);
    entry->type = Node->type;
    entry->scopeLevel = scopeLevel;
    entry->lineDecl = Node->lineNumber;
    entry->linesUsed = malloc(sizeof(int)); // Alocação inicial
    entry->nLinesUsed = 0;
    entry->linesUsed[entry->nLinesUsed] = -1; // Marcador de fim
    entry->isFunction = Node->isFunction;
    entry->isArray = Node->isArray;
    entry->value = 0;


    if (Node->isFunction == 1) {
        entry->scope = malloc(sizeof(char) * MAX_LEXEME_SIZE);
        strcpy(entry->scope, Node->lexeme);
        currentScope = malloc(sizeof(char) * MAX_LEXEME_SIZE);
        strcpy(currentScope, Node->lexeme);
    } else {
        entry->scope = malloc(sizeof(char) * MAX_LEXEME_SIZE);
        strcpy(entry->scope, currentScope);
    }

    // Adiciona a nova entrada no início da lista encadeada no índice hash
    entry->next = hashTable[index];
    hashTable[index] = entry;
}


// bool symbolExistsInScope(char *identifier, int scopeLevel, int lineNumber) {
//     unsigned int index = hash(identifier);
//     SymbolTableEntry *current = hashTable[index];

//     // Percorre a lista encadeada no índice hash para verificar se o identificador já existe no mesmo escopo
//     while (current != NULL) {
//         if (strcmp(current->identifier, identifier) == 0 && current->scopeLevel == scopeLevel) {
//                 current->linesUsed = realloc(current->linesUsed, sizeof(int) * (current->nLinesUsed + 1));
//             current->linesUsed[current->nLinesUsed++] = lineNumber;
//             return true; // Identificador encontrado no mesmo escopo
//         }
//         current = current->next; // Vai para o próximo elemento na lista encadeada
//     }
//     return false; // Identificador não encontrado no mesmo escopo
// }

bool symbolExistsInScope(char *identifier, int scopeLevel, int lineNumber) {
    unsigned int index = hash(identifier);
    SymbolTableEntry *current = hashTable[index];

    while (current != NULL) {
        if (strcmp(current->identifier, identifier) == 0 && current->scopeLevel == scopeLevel) {
            int *temp = realloc(current->linesUsed, sizeof(int) * (current->nLinesUsed + 2)); // +2 para incluir o novo número e o marcador -1
            if (temp == NULL) {
                // Tratamento de erro para falha de realocação
                return false;
            }
            current->linesUsed = temp;
            current->linesUsed[current->nLinesUsed++] = lineNumber; // Adiciona a nova linha
            current->linesUsed[current->nLinesUsed] = -1; // Atualiza o marcador de fim
            return true; // Identificador encontrado no mesmo escopo
        }
        current = current->next;
    }
    return false; // Identificador não encontrado no mesmo escopo
}



// Função para criar a tabela de símbolos a partir da árvore sintática
void createSymbolTable(TreeNode *node, int scopeLevel) {
    if (node == NULL) return;


    // Processa o nó atual
    if (node->type==T_ID && strcmp(node->lexeme, "")!=0) {
        if (!symbolExistsInScope(node->lexeme, scopeLevel, node->lineNumber) ) {
            TreeNode *aux = node;
            insertSymbol(aux, scopeLevel);
        }
    }

    // Processa os filhos do nó atual
    for (int i = 0; i < MAX_CHILDREN; i++) {
        createSymbolTable(node->children[i], scopeLevel + (node->nodeType == nCompostoDecl));
    }

    // Processa o irmão do nó atual
    createSymbolTable(node->sibling, scopeLevel);
}

// Função para iniciar a criação da tabela de símbolos
void startSymbolTableCreation(TreeNode *root) {
    memset(hashTable, 0, sizeof(hashTable)); // Inicializa a tabela hash
    createSymbolTable(root, 0); // Inicia com o nível de escopo 0
}

// Função para liberar a tabela de símbolos
void freeSymbolTable() {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        SymbolTableEntry *entry = hashTable[i];
        while (entry != NULL) {
            SymbolTableEntry *temp = entry;
            entry = entry->next;
            free(temp);
        }
    }
}

char *func_or_var(int isFunction) {
    if (isFunction == 1) {
        return "Func";
    } else {
        return "Var";
    }
    
}


// // Função para imprimir a tabela de símbolos
// void printSymbolTable() {
//     printf("Tabela de Símbolos:\n");
//     printf("----------------------------------------------------------------------------------------------------\n");
//     printf("| %-20s | %-10s | %-10s | %-10s | %-10s | %-15s | %-3s |\n", "Name", "Decl Line", "Scope", "Func/Var", "Is Array?", "Lines Usage","Value");
//     printf("----------------------------------------------------------------------------------------------------\n");

//     for (int i = 0; i < HASH_TABLE_SIZE; i++) {
//         SymbolTableEntry *entry = hashTable[i];
//         while (entry != NULL) {
//             printf("| %-20s | %-10d | %-10s | %-10s | %-10d | %-15d | %-3d |\n", entry->identifier, entry->lineDecl, entry->scope, (func_or_var(entry->isFunction)), entry->isArray, entry->linesUsed, entry->value);
//             printf("----------------------------------------------------------------------------------------------------\n");
//             entry = entry->next;
//         }
//     }
// }

// Função para imprimir a tabela de símbolos
void printSymbolTable() {
    printf("Tabela de Símbolos:\n");
    printf("-------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s | %-10s | %-10s | %-3s | %-29s |\n", "Name", "Decl Line", "Scope", "Func/Var", "Is Array?", "Value", "Lines Usage");
    printf("-------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        SymbolTableEntry *entry = hashTable[i];
        while (entry != NULL) {
            printf("| %-20s | %-10d | %-10s | %-10s | %-10d | %-5d | ", entry->identifier, entry->lineDecl, entry->scope, func_or_var(entry->isFunction), entry->isArray, entry->value);
            
            // Imprime as linhas de uso
            int j = 0;
            while (entry->linesUsed[j] != -1) {
                if (j > 0) {
                    printf(", ");
                }
                printf("%d", entry->linesUsed[j]);
                j++;
            }
            printf("\n");
            printf("-------------------------------------------------------------------------------------------------------------------------\n");

            entry = entry->next;
        }
    }
}
