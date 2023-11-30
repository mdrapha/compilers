#include "globals.h"
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 101


SymbolTableEntry *hashTable[HASH_TABLE_SIZE]; // Hash table for the symbol table

/*Function to calculate the hash value of a string*/ 
unsigned int hash(char *str) {
    unsigned int hashValue = 0;
    for (char *p = str; *p != '\0'; p++) {
        hashValue = *p + 31 * hashValue;
    }
    return hashValue % HASH_TABLE_SIZE;
}

/*Function to insert a symbol in the symbol table*/
void insertSymbol(TreeNode *Node, int scopeLevel) {
    unsigned int index = hash(Node->lexeme);
    SymbolTableEntry *entry = (SymbolTableEntry *)malloc(sizeof(SymbolTableEntry));
    strcpy(entry->identifier, Node->lexeme);
    entry->type = Node->type;
    entry->scopeLevel = scopeLevel;
    entry->linesUsed = malloc(sizeof(int)); 
    entry->nLinesUsed = 0;
    entry->linesUsed[entry->nLinesUsed] = -1; // End marker for lines used
    entry->isFunction = Node->isFunction;
    entry->isArray = Node->isArray;
    entry->value = 0;

    if(hashTable[index] == NULL){
        if (!Node->isDecl) {
            entry->lineDecl = -1;
        } else {
            entry->lineDecl = Node->lineNumber;
        }
    }else if(hashTable[index]->lineDecl == -1 && Node->isDecl==1){
        entry->lineDecl = Node->lineNumber;
    }

    if (Node->isFunction == 1) {
        entry->scope = malloc(sizeof(char) * MAX_LEXEME_SIZE);
        strcpy(entry->scope, Node->lexeme);
        currentScope = malloc(sizeof(char) * MAX_LEXEME_SIZE);
        strcpy(currentScope, Node->lexeme);
    } else {
        entry->scope = malloc(sizeof(char) * MAX_LEXEME_SIZE);
        strcpy(entry->scope, currentScope);
    }

    // Add the new entry to the beginning of the linked list
    entry->next = hashTable[index];
    hashTable[index] = entry;
}

/*Function to check if a symbol exists in the symbol table*/
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
    printf("createSymbolTable: %s %s\n", node->lexeme, get_token_name(node->type));


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

char *get_type_name(int nodeType) {
    if (nodeType == T_INT) {
        return "int";
    } else {
        return "void";
    }
    
}




/*Function to print the symbol table*/
void printSymbolTable() {
    printf("Symbol Table:\n");
    printf("---------------------------------------------------------------------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s | %-10s | %-10s | %-3s | %-24s |\n", "Name", "Decl Line", "Scope", "Func/Var", "Is Array?", "Value", "Lines Usage");
    printf("---------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        SymbolTableEntry *entry = hashTable[i];
        while (entry != NULL) {
            printf("| %-20s | %-10d | %-10s | %-10s | %-10d | %-5d | ", entry->identifier, entry->lineDecl, entry->scope, func_or_var(entry->isFunction), entry->isArray, entry->value);
            
            // Print lines used
            int j = 0;
            while (entry->linesUsed[j] != -1) {
                if (j > 0) {
                    printf(", ");
                }
                printf("%d", entry->linesUsed[j]);
                j++;
            }
            printf("\n");
            printf("---------------------------------------------------------------------------------------------------------------\n");

            entry = entry->next;
        }
    }
}

void checkDeclarations() {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        SymbolTableEntry *entry = hashTable[i];
        while (entry != NULL) {
            if (entry->lineDecl == -1 || entry->nLinesUsed == 0 || verify_linesDecl(entry->lineDecl, entry->linesUsed)) {
                printf("Erro: Símbolo '%s' usado mas não declarado corretamente.\n", entry->identifier);
                //exit(1);
            }
            entry = entry->next;
        }
    }
}

int verify_linesDecl(int lineDecl, int *linesUsed) {
    int i = 0;
    while (linesUsed[i] != -1) {
        if (linesUsed[i] >= lineDecl) {
            continue;
        }else{
            return 1;
        }
        i++;
    }
    return 0;
}