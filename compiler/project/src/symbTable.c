#include "../include/globals.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define HASH_TABLE_SIZE 101

int doubleDeclaration = 0;
char doubleDeclarationName[MAX_LEXEME_SIZE];

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
    if(strcmp(Node->lexeme, "int")==0 || strcmp(Node->lexeme, "void")==0){
        return;
    }
    unsigned int index = hash(Node->lexeme);
    SymbolTableEntry *current = hashTable[index];

    // Check if the symbol already exists in the current scope
    while (current != NULL) {
        if ((strcmp(current->identifier, Node->lexeme) == 0 && current->scopeLevel == scopeLevel) || (current->isFunction == nVarDeclaracao)) {
            // Update the declaration line if needed
            
            if ((Node->nodeType == nVarArrDecl || Node->nodeType==nVarDeclaracao || Node->nodeType==nFunDeclaracao || Node->nodeType==nParam) && (current->lineDecl == -1)) {
                if(current->lineDecl>0)
                {
                    doubleDeclaration = 1;
                    strcpy(doubleDeclarationName, current->identifier);
                }else
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
    entry->lineDecl = (Node->nodeType == nVarArrDecl || Node->nodeType==nVarDeclaracao || Node->nodeType==nFunDeclaracao || Node->nodeType==nParam) ? Node->lineNumber : -1;
    entry->isFunction = Node->nodeType;
    entry->isArray = Node->isArray;
    entry->value = (Node->nodeType == nVarArrDecl || Node->nodeType==nVarDeclaracao || Node->nodeType==nFunDeclaracao || Node->nodeType==nParam) ? Node->ArraySize : -1;
    if(entry->isFunction == nFunDeclaracao || entry->isFunction == nFunCall){
    entry->type =  Node->varType;
    }
    else{
    entry->type = T_INT;
    }
    

    // Initialize the linesUsed array
    entry->linesUsed = malloc(sizeof(int));
    entry->nLinesUsed = 0;
    entry->linesUsed[entry->nLinesUsed] = -1; // End marker

    if (Node->nodeType == nFunDeclaracao) {
        entry->scope = malloc(sizeof(char) * MAX_LEXEME_SIZE);
        strcpy(entry->scope, "global");
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
    printf("\n\033[1;36m");
    printf(
        "--------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-20s | %-10s | %-15s | %-10s | %-6s | %-5s | %-3s | %-25s |\n", "Name", "Decl Line", "Scope", "Func/Var",
           "Type", "Array?", "Value", "Lines Usage");
    printf(
        "--------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        SymbolTableEntry *entry = hashTable[i];
        while (entry != NULL) {
            printf("\033[1;36m|\033[1m %-20s \033[1;36m|\033[0m %-10d \033[1;36m|\033[0m %-15s \033[1;36m|\033[0m %-10s \033[1;36m|\033[0m %-6s \033[1;36m|\033[0m %-6s \033[1;36m|\033[0m %-5s \033[1;36m|\033[0m ",
                   entry->identifier, entry->lineDecl, entry->scope, (entry->isFunction == nFunDeclaracao || entry->isFunction == nFunCall) ? "Func" : "Var",
                  ( entry->type==T_INT)?"int":"void", (entry->isArray)?"Array":"No", (entry->isArray)?(tostring_1(entry->value)):"-");

            // Print lines used
            if(entry->linesUsed == NULL || entry->linesUsed[0]==-1){
                printf("-\n");
                printf(
                "\033[1;36m--------------------------------------------------------------------------------------------------------------------------\033[0m\n");
                entry = entry->next;
                continue;
            }else{
            int j = 0;
            while (entry->linesUsed[j] != -1) {
                if (j > 0) {
                    printf(",");
                }
                printf("%d", entry->linesUsed[j]);
                j++;
            }
            printf("\n");
            printf(
                "\033[1;36m--------------------------------------------------------------------------------------------------------------------------\033[0m\n");

            entry = entry->next;}
        }
    }
                    printf("\033[0m\n\n");

}

int checkDeclarations() {
    int error = 0;
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        SymbolTableEntry *entry = hashTable[i];
        while (entry != NULL) {
            if (entry->lineDecl == -1 ||
                verify_linesDecl(entry->lineDecl, entry->linesUsed)) {
                printf("\n\033[1;37;41m");
                printf("Error: Symbol '%s' used at line " , entry->identifier);
                int j = 0;
                while (entry->linesUsed[j] != -1) {
                    if (j > 0) {
                        printf(",");
                    }
                    printf("%d", entry->linesUsed[j]);
                    j++;
                }
                printf(" but not declared correctly.");
                printf("\033[0m\n\n");
                error = 1;
            }
            if (doubleDeclaration!=0) {
                printf("\n\033[1;37;41m");
                printf("Error: Some function have been declared more than once.");
                printf("\033[0m\n\n");
                error = 1;
            }

            entry = entry->next;
        }
    }
    return error;
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

char *tostring_1(int num)
{
  char *str = (char *)malloc(sizeof(char) * 10);
  sprintf(str, "%d", num);
  return str;
}