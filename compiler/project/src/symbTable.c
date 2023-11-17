#include "globals.h"

int hash_t(char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;  // hash * 33 + c

    return hash % HASH_TABLE_SIZE;
}

SymbolTableEntry *createSymbolTableEntry(char *name, int type, int lineDecl, int isVector, int vectorSize, char *scope, int isFunction, int nParams, int returnType, int isDefined) {
    SymbolTableEntry *newEntry = (SymbolTableEntry *)malloc(sizeof(SymbolTableEntry));
    if (newEntry == NULL) {
        fprintf(stderr, "Symbol Table Allocation error\n");
        exit(1);
    }

    newEntry->name = strdup(name);
    newEntry->type = type;
    newEntry->lineDecl = lineDecl;
    newEntry->linesUsed = NULL;  // Inicialmente nulo, pode ser alocado conforme necessário
    newEntry->nLinesUsed = 0;
    newEntry->stringVal = NULL;  // Alocado e definido conforme necessário
    newEntry->intVal = 0;        // Definido conforme necessário
    newEntry->isVector = isVector;
    newEntry->vectorSize = vectorSize;
    newEntry->Scope = strdup(scope);
    newEntry->isFunction = isFunction;
    newEntry->nParams = nParams;
    newEntry->paramTypes = NULL; // Alocado e definido conforme necessário
    newEntry->returnType = returnType;
    newEntry->isDefined = isDefined;

    newEntry->next = NULL;

    return newEntry;
}


void addSymbol(SymbolTable *table, char *name, int type, int lineDecl, int isVector, int vectorSize, char *scope, int isFunction, int nParams, int returnType, int isDefined) {
    int index = hash(name);
    SymbolTableEntry *existingEntry = table->table[index];

    // Verifique se o símbolo já existe na tabela hash no índice calculado
    while (existingEntry != NULL) {
        if (strcmp(existingEntry->name, name) == 0 && strcmp(existingEntry->Scope, scope) == 0) {
            // Encontrado um símbolo existente com o mesmo nome no mesmo escopo
            fprintf(stderr, "Error: Symbol '%s' already declared at line %d\n", name, existingEntry->lineDecl);
            return;
        }
        existingEntry = existingEntry->next;
    }

    // Crie um novo símbolo e adicione-o à tabela de símbolos
    SymbolTableEntry *newEntry = createSymbolTableEntry(name, type, lineDecl, isVector, vectorSize, scope, isFunction, nParams, returnType, isDefined);
    newEntry->next = table->table[index];
    table->table[index] = newEntry;
}


SymbolTableEntry *findSymbol(SymbolTable *table, char *name) {
    int index = hash_t(name);

    for (SymbolTableEntry *entry = table->table[index]; entry != NULL; entry = entry->next) {
        if (strcmp(entry->name, name) == 0) {
            return entry;56
        }
    }

    return NULL;  // not found
}

void enterScope(char *scopeName) {
    currentScope = strdup(scopeName);
}

void exitScope() {
    free(currentScope);
}

char *generateNewScopeName() {
    char *newScopeName = malloc(sizeof(char) * MAX_LEXEME_SIZE); 
    sprintf(newScopeName, "Scope%d", scopeCounter++);
    return newScopeName;
}