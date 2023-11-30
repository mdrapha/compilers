// #define HASH_TABLE_SIZE 997  


// typedef struct SymbolTableEntry {
//     char *name;          // Symbol name
//     int type;            // Type of the symbol
//     int lineDecl;      // Symbol declaration line number
//     int *linesUsed;     // Array of line numbers where the symbol is used
//     int nLinesUsed;     // Number of lines where the symbol is used
//     char *stringVal;    // String value of the symbol
//     int intVal;         // Integer value of the symbol
//     int isVector;       // Flag that indicates if the symbol is a vector
//     int vectorSize;     // Vector size
//     char *Scope;       // Scope of the symbol
//     int isFunction;     // Flag that indicates if the symbol is a function
//     int nParams;        // Number of parameters of the function
//     int *paramTypes;    // Array of types of the function parameters
//     int returnType;     // Return type of the function
//     int isDefined;      // Flag that indicates if the function is defined

//     struct SymbolTableEntry *next;  // Ponteiro para o próximo símbolo na tabela
// } SymbolTableEntry;

// typedef struct SymbolTable {
//     SymbolTableEntry *first;  // Ponteiro para o primeiro símbolo na tabela
// } SymbolTable;

// // Function to create a new symbol table
// SymbolTableEntry *createSymbolTableEntry(TreeNode *node, char *currentScope);

// // Function to add a symbol to the symbol table
// void addSymbol(SymbolTable *table, TreeNode *node, char *currentScope);

// // Function to find a symbol in the symbol table
// SymbolTableEntry *findSymbol(SymbolTable *table, char *name, char *currentScope);

// // Function to create a new symbol table
// void buildSymbolTable(TreeNode *node, SymbolTable *symbolTable, char *currentScope);

// // Function to print the symbol table
// void printSymbolTable(SymbolTable *table);

// // Function to create a new symbol table
// void enterScope(char *scopeName);

// // Function to exit the current scope
// void exitScope();

// // Function to generate a new scope name
// char *generateNewScopeName();

// symbol_table.h
#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H


#define MAX_LEXEME_SIZE 64
#define HASH_TABLE_SIZE 101

// Definição da estrutura de entrada da tabela de símbolos
typedef struct SymbolTableEntry {
    char identifier[MAX_LEXEME_SIZE]; // Nome do identificador
    NodeType type; // Tipo do nó (variável, função, etc.)
    int scopeLevel; // Nível de escopo do identificador
    int lineDecl; // Linha onde o identificador foi declarado
    int *linesUsed; // Array de linhas onde o identificador foi usado
    int nLinesUsed; // Número de linhas onde o identificador foi usado
    int isFunction; // Flag que indica se o identificador é uma função
    int isArray; // Flag que indica se o identificador é um vetor
    int value; // Valor do identificador
    char *scope; // Escopo do identificador
    struct SymbolTableEntry *next; // Próximo elemento na lista de colisões
} SymbolTableEntry;

// Função de hash para strings
unsigned int hash(char *str);

char *func_or_var(int isFunction);

// Função para inserir um novo identificador na tabela de símbolos
void insertSymbol(TreeNode *Node, int scopeLevel);

// Função para verificar se um identificador já existe na tabela de símbolos no mesmo escopo
bool symbolExistsInScope(char *identifier, int scopeLevel, int lineNumber);

// Função para criar a tabela de símbolos a partir da árvore sintática
void createSymbolTable(TreeNode *node, int scopeLevel);

// Função para iniciar a criação da tabela de símbolos
void startSymbolTableCreation(TreeNode *root);

// Função para liberar a tabela de símbolos
void freeSymbolTable();

void printSymbolTable();

void checkDeclarations();

int verify_linesDecl(int lineDecl, int *linesUsed);

#endif // SYMBOL_TABLE_H
