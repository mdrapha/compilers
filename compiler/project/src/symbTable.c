// #include "../include/globals.h"
// #include <stdlib.h>
// #include <string.h>

// #define HASH_TABLE_SIZE 101


// SymbolTableEntry *hashTable[HASH_TABLE_SIZE]; // Hash table for the symbol table

// /*Function to calculate the hash value of a string*/ 
// unsigned int hash(char *str) {
//     unsigned int hashValue = 0;
//     for (char *p = str; *p != '\0'; p++) {
//         hashValue = *p + 31 * hashValue;
//     }
//     return hashValue % HASH_TABLE_SIZE;
// }

// /*Function to insert a symbol in the symbol table*/
// void insertSymbol(TreeNode *Node, int scopeLevel) {
//     unsigned int index = hash(Node->lexeme);
//     SymbolTableEntry *current = hashTable[index];
//         printf("insertSymbol: %s %s %d\n", Node->lexeme, Node->isDecl ? "Decl" : "Usage", Node->lineNumber);


//     // Verifica se o símbolo já existe no escopo atual
//     while (current != NULL) {
//         if (strcmp(current->identifier, Node->lexeme) == 0 && current->scopeLevel == scopeLevel) {
//             // Atualiza a linha de declaração, se for o caso
//             if (Node->isDecl && (current->lineDecl == -1 || current->lineDecl > Node->lineNumber)) {
//                 current->lineDecl = Node->lineNumber;
//             }
//             // Atualiza as linhas de uso
//             if (Node->isUsage) {
//                 int *temp = realloc(current->linesUsed, sizeof(int) * (current->nLinesUsed + 2));
//                 if (temp == NULL) {
//                     printf("Erro: Falha ao alocar memória.\n");
//                     return;
//                 }
//                 current->linesUsed = temp;
//                 current->linesUsed[current->nLinesUsed++] = Node->lineNumber;
//                 current->linesUsed[current->nLinesUsed] = -1;
//             }
//             return; // Símbolo já existe e foi atualizado se necessário
//         }
//         current = current->next;
//     }

//     // Insere novo símbolo se não foi encontrado
//     SymbolTableEntry *entry = (SymbolTableEntry *)malloc(sizeof(SymbolTableEntry));
//     strcpy(entry->identifier, Node->lexeme);
//     entry->type = Node->type;
//     entry->scopeLevel = scopeLevel;
//     entry->lineDecl = Node->isDecl ? Node->lineNumber : -1;
//     entry->isFunction = Node->nodeType;
//     entry->isArray = Node->isArray;
//     entry->value = 0; // ou outro valor inicial, se aplicável

//     // Inicializa o vetor linesUsed
//     entry->linesUsed = malloc(sizeof(int));
//     entry->nLinesUsed = 0;
//     entry->linesUsed[entry->nLinesUsed] = -1; // Marcador de fim

//      if (Node->nodeType == nFunDeclaracao) {
//         entry->scope = malloc(sizeof(char) * MAX_LEXEME_SIZE);
//         strcpy(entry->scope, Node->lexeme);
//         currentScope = malloc(sizeof(char) * MAX_LEXEME_SIZE);
//         strcpy(currentScope, Node->lexeme);
//     } else {
//         entry->scope = malloc(sizeof(char) * MAX_LEXEME_SIZE);
//         strcpy(entry->scope, currentScope);
//     }

//     // Adiciona o novo símbolo ao início da lista no índice hash
//     entry->next = hashTable[index];
//     hashTable[index] = entry;
// }

// bool symbolExistsInScope(TreeNode *aux, int scopeLevel, int lineNumber) {
//     unsigned int index = hash(aux->lexeme);
//     SymbolTableEntry *current = hashTable[index];
//     bool found = false;

//     while (current != NULL) {
//         if (strcmp(current->identifier, aux->lexeme) == 0 && current->scopeLevel == scopeLevel) {
//             // Símbolo encontrado no mesmo escopo
//             found = true;

//             // Atualiza as linhas de uso, se necessário
//             if (aux->isUsage) {
//                 int *temp = realloc(current->linesUsed, sizeof(int) * (current->nLinesUsed + 2)); // +2 para incluir o novo número e o marcador -1
//                 if (temp == NULL) {
//                     printf("Erro: Falha ao alocar memória.\n");
//                     return false;
//                 }
//                 current->linesUsed = temp;
//                 current->linesUsed[current->nLinesUsed++] = lineNumber; // Adiciona a nova linha
//                 current->linesUsed[current->nLinesUsed] = -1; // Atualiza o marcador de fim
//             }
//             break; // Encerra a busca, pois o símbolo foi encontrado
//         }
//         current = current->next;
//     }

//     if (!found) {
//         // Insere o símbolo na tabela de símbolos, se não foi encontrado
//         insertSymbol(aux, scopeLevel);
//     }

//     return found;
// }




// // Função para criar a tabela de símbolos a partir da árvore sintática
// void createSymbolTable(TreeNode *node, int scopeLevel) {
//     if (node == NULL) return;
//         printf("insertSymbol: %s %s %d %s\n", node->lexeme, node->isDecl ? "Decl" : "Usage", node->lineNumber, get_token_name(node->type));


//     // Processa o nó atual
//     if (node->type==T_ID && strcmp(node->lexeme, "")!=0) {
//         TreeNode *aux = node;
//         if (!symbolExistsInScope(aux, scopeLevel, aux->lineNumber) ) {
//             insertSymbol(aux, scopeLevel);
//         }
//     }

//     // Processa os filhos do nó atual
//     for (int i = 0; i < MAX_CHILDREN; i++) {
//         createSymbolTable(node->children[i], scopeLevel + (node->nodeType == nCompostoDecl));
//     }

//     // Processa o irmão do nó atual
//     createSymbolTable(node->sibling, scopeLevel);
// }

// // Função para iniciar a criação da tabela de símbolos
// void startSymbolTableCreation(TreeNode *root) {
//     memset(hashTable, 0, sizeof(hashTable)); // Inicializa a tabela hash
//     createSymbolTable(root, 0); // Inicia com o nível de escopo 0
// }

// // Função para liberar a tabela de símbolos
// void freeSymbolTable() {
//     for (int i = 0; i < HASH_TABLE_SIZE; i++) {
//         SymbolTableEntry *entry = hashTable[i];
//         while (entry != NULL) {
//             SymbolTableEntry *temp = entry;
//             entry = entry->next;
//             free(temp);
//         }
//     }
// }

// char *func_or_var(int isFunction) {
//     if (isFunction == nFunDeclaracao) {
//         return "Func";
//     } else {
//         return "Var";
//     }
    
// }

// char *get_type_name(int nodeType) {
//     if (nodeType == T_INT) {
//         return "int";
//     } else {
//         return "void";
//     }
    
// }




// /*Function to print the symbol table*/
// void printSymbolTable() {
//     printf("Symbol Table:\n");
//     printf("---------------------------------------------------------------------------------------------------------------\n");
//     printf("| %-20s | %-10s | %-10s | %-10s | %-10s | %-3s | %-24s |\n", "Name", "Decl Line", "Scope", "Func/Var", "Is Array?", "Value", "Lines Usage");
//     printf("---------------------------------------------------------------------------------------------------------------\n");

//     for (int i = 0; i < HASH_TABLE_SIZE; i++) {
//         SymbolTableEntry *entry = hashTable[i];
//         while (entry != NULL) {
//             printf("| %-20s | %-10d | %-10s | %-10s | %-10d | %-5d | ", entry->identifier, entry->lineDecl, entry->scope, func_or_var(entry->isFunction), entry->isArray, entry->value);
            
//             // Print lines used
//             int j = 0;
//             while (entry->linesUsed[j] != -1) {
//                 if (j > 0) {
//                     printf(", ");
//                 }
//                 printf("%d", entry->linesUsed[j]);
//                 j++;
//             }
//             printf("\n");
//             printf("---------------------------------------------------------------------------------------------------------------\n");

//             entry = entry->next;
//         }
//     }
// }

// void checkDeclarations() {
//     for (int i = 0; i < HASH_TABLE_SIZE; i++) {
//         SymbolTableEntry *entry = hashTable[i];
//         while (entry != NULL) {
//             if (entry->lineDecl == -1 || entry->nLinesUsed == 0 || verify_linesDecl(entry->lineDecl, entry->linesUsed)) {
//                 printf("Erro: Símbolo '%s' usado mas não declarado corretamente.\n", entry->identifier);
//                 //exit(1);
//             }
//             if(entry->isFunction == 1 && entry->nLinesUsed > 1){
//                 printf("Erro: Função '%s' declarada mais de uma vez.\n", entry->identifier);
//                 //exit(1);
//             }
//             entry = entry->next;
//         }
//     }
// }

// int verify_linesDecl(int lineDecl, int *linesUsed) {
//     int i = 0;
//     while (linesUsed[i] != -1) {
//         if (linesUsed[i] < lineDecl) {
//             return 1; 
//         }
//         i++;
//     }
//     return 0;

// }

// // Function to verify if a variable is declared and determine its type
// int verifyVariableDeclaration(TreeNode *variableNode) {
//     if (variableNode == NULL || variableNode->sibling == NULL) {
//         // Invalid input, or no sibling (type specifier) found
//         return -1; // Not declared
//     }

//     // Get the variable name and type specifier
//     char *variableName = variableNode->lexeme;
//     char *typeSpecifier = variableNode->sibling->lexeme;

//     // Search for the variable in the symbol table
//     unsigned int index = hash(variableName);
//     SymbolTableEntry *current = hashTable[index];

//     while (current != NULL) {
//         if (strcmp(current->identifier, variableName) == 0) {
//             // Variable found in the symbol table
//             if (strcmp(typeSpecifier, "int") == 0) {
//                 // Type specifier is "int"
//                 if (current->type == T_INT) {
//                     // Variable is declared as int
//                     return 0; // Declared as int
//                 }
//             } else if (strcmp(typeSpecifier, "void") == 0) {
//                 // Type specifier is "void"
//                 if (current->type == T_VOID) {
//                     // Variable is declared as void
//                     return 1; // Declared as void
//                 }
//             }
//         }
//         current = current->next;
//     }

//     return -2; // Not declared or type mismatch
// }



#include "../include/globals.h"
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 101

SymbolTableEntry *hashTable[HASH_TABLE_SIZE]; // Hash table for the symbol table

/* Function to calculate the hash value of a string */
unsigned int hash(char *str) {
    unsigned int hashValue = 0;
    for (char *p = str; *p != '\0'; p++) {
        hashValue = *p + 31 * hashValue;
    }
    return hashValue % HASH_TABLE_SIZE;
}

/* Function to insert a symbol in the symbol table without specifying its type */
void insertSymbol(TreeNode *Node, int scopeLevel) {
    unsigned int index = hash(Node->lexeme);
    SymbolTableEntry *current = hashTable[index];

    // Check if the symbol already exists in the current scope
    while (current != NULL) {
        if (strcmp(current->identifier, Node->lexeme) == 0 && current->scopeLevel == scopeLevel) {
            // Update the declaration line if needed
            if (Node->isDecl && (current->lineDecl == -1 || current->lineDecl > Node->lineNumber)) {
                current->lineDecl = Node->lineNumber;
            }
            // Update the usage lines
            if (Node->isUsage) {
                int *temp = realloc(current->linesUsed, sizeof(int) * (current->nLinesUsed + 2));
                if (temp == NULL) {
                    printf("Error: Memory allocation failed.\n");
                    return;
                }
                current->linesUsed = temp;
                current->linesUsed[current->nLinesUsed++] = Node->lineNumber;
                current->linesUsed[current->nLinesUsed] = -1;
            }
            return; // Symbol already exists and has been updated if necessary
        }
        current = current->next;
    }

    // Insert a new symbol if it was not found
    SymbolTableEntry *entry = (SymbolTableEntry *)malloc(sizeof(SymbolTableEntry));
    strcpy(entry->identifier, Node->lexeme);
    entry->scopeLevel = scopeLevel;
    entry->lineDecl = (Node->nodeType == nVarArrDecl || Node->nodeType==nVarDeclaracao || Node->nodeType==nFunDeclaracao) ? Node->lineNumber : -1;
    entry->isFunction = Node->nodeType;
    entry->isArray = Node->isArray;
    entry->value = 0; // or another initial value if applicable
    if(Node->varType){
        entry->type = Node->varType;
    }else{
        entry->type = -1;
    }

    // Initialize the linesUsed array
    entry->linesUsed = malloc(sizeof(int));
    entry->nLinesUsed = 0;
    entry->linesUsed[entry->nLinesUsed] = -1; // End marker

    if (Node->nodeType == nFunDeclaracao) {
        entry->scope = malloc(sizeof(char) * MAX_LEXEME_SIZE);
        strcpy(entry->scope, Node->lexeme);
        currentScope = malloc(sizeof(char) * MAX_LEXEME_SIZE);
        strcpy(currentScope, Node->lexeme);
    } else {
        entry->scope = malloc(sizeof(char) * MAX_LEXEME_SIZE);
        strcpy(entry->scope, currentScope);
    }

    // Add the new symbol to the beginning of the list at the hash index
    entry->next = hashTable[index];
    hashTable[index] = entry;
}

bool symbolExistsInScope(TreeNode *aux, int scopeLevel, int lineNumber) {
    unsigned int index = hash(aux->lexeme);
    SymbolTableEntry *current = hashTable[index];
    bool found = false;

    while (current != NULL) {
        if (strcmp(current->identifier, aux->lexeme) == 0 && current->scopeLevel == scopeLevel) {
            // Symbol found in the same scope
            found = true;

            // Update usage lines if necessary
            if (aux->isUsage) {
                int *temp = realloc(current->linesUsed, sizeof(int) * (current->nLinesUsed + 2)); // +2 to include the new number and the -1 marker
                if (temp == NULL) {
                    printf("Error: Memory allocation failed.\n");
                    return false;
                }
                current->linesUsed = temp;
                current->linesUsed[current->nLinesUsed++] = lineNumber; // Add the new line
                current->linesUsed[current->nLinesUsed] = -1; // Update the end marker
            }
            break; // Stop the search as the symbol has been found
        }
        current = current->next;
    }

    if (!found) {
        // Insert the symbol into the symbol table if not found
        insertSymbol(aux, scopeLevel);
    }

    return found;
}

// Function to create the symbol table from the syntax tree
void createSymbolTable(TreeNode *node, int scopeLevel) {
   // printf("createSymbolTable: %s %s %d %s \n", node->lexeme, node->isDecl ? "Decl" : "Usage", node->lineNumber, get_token_name(node->type) );
    if (node == NULL)
        return;

    // Process the current node
    if (node->type == T_ID && strcmp(node->lexeme, "") != 0) {
        TreeNode *aux = node;
        if (!symbolExistsInScope(aux, scopeLevel, aux->lineNumber)) {
            insertSymbol(aux, scopeLevel);
        }
    }

    // Process the children of the current node
    for (int i = 0; i < MAX_CHILDREN; i++) {
        createSymbolTable(node->children[i], scopeLevel + (node->nodeType == nCompostoDecl));
    }

    // Process the sibling of the current node
    createSymbolTable(node->sibling, scopeLevel);
}

// Function to start creating the symbol table
void startSymbolTableCreation(TreeNode *root) {
    memset(hashTable, 0, sizeof(hashTable)); // Initialize the hash table
    classifyIDNodesInTree(root); // Classify the ID nodes as variables or functions
    createSymbolTable(root, 0); // Start with scope level 0
}

// Function to free the symbol table
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

/* Function to print the symbol table */
void printSymbolTable() {
    printf("Symbol Table:\n");
    printf(
        "--------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s | %-10s | %-10s | %-10s | %-3s | %-24s |\n", "Name", "Decl Line", "Scope", "Func/Var",
           "Type", "Is Array?", "Value", "Lines Usage");
    printf(
        "--------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        SymbolTableEntry *entry = hashTable[i];
        while (entry != NULL) {
            printf("| %-20s | %-10d | %-10s | %-10s | %-10d | %-10d | %-5d | ",
                   entry->identifier, entry->lineDecl, entry->scope, (entry->isFunction == nFunDeclaracao || entry->isFunction == nFunCall) ? "Func" : "Var",
                   entry->type, entry->isArray, entry->value);

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
            printf(
                "--------------------------------------------------------------------------------------------------------------------------\n");

            entry = entry->next;
        }
    }
}

void checkDeclarations() {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        SymbolTableEntry *entry = hashTable[i];
        while (entry != NULL) {
            if (entry->lineDecl == -1 || entry->nLinesUsed == 0 ||
                verify_linesDecl(entry->lineDecl, entry->linesUsed)) {
                printf("Error: Symbol '%s' used but not declared correctly.\n", entry->identifier);
            }
            if (entry->isFunction == nFunDeclaracao && entry->nLinesUsed > 1) {
                printf("Error: Function '%s' declared more than once.\n", entry->identifier);
            }
            entry = entry->next;
        }
    }
}

int verify_linesDecl(int lineDecl, int *linesUsed) {
    int i = 0;
    while (linesUsed[i] != -1) {
        if (linesUsed[i] < lineDecl) {
            return 1;
        }
        i++;
    }
    return 0;
}

void classifyIDNodes(TreeNode *node) {
    if (node == NULL) {
        return;
    }

    // Traverse left child
    classifyIDNodes(node->children[0]);

    // Check if the current node is a T_ID and has a sibling
    if (node->type == T_ID && node->sibling != NULL) {
        TreeNode *sibling = node->sibling;

        // Check if the sibling is a type (T_INT or T_VOID)
        if (sibling->type == T_INT) {
            node->type = T_INT; // Classify as a variable declaration (int)
        } else if (sibling->type == T_VOID) {
            node->type = T_VOID; // Classify as a function declaration (void)
        } else {
            node->type = -1; // Unable to classify, set type to -1
        }
    }

    // Traverse right sibling
    classifyIDNodes(node->sibling);
}

// Call this function with the root of your finished syntax tree
void classifyIDNodesInTree(TreeNode *root) {
    classifyIDNodes(root);
}
