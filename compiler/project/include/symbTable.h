
#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H


#define MAX_LEXEME_SIZE 64
#define HASH_TABLE_SIZE 101

typedef struct SymbolTableEntry {
    char identifier[MAX_LEXEME_SIZE]; // Identifier name
    NodeType type; // The type of the node
    int scopeLevel; // Scope level of the identifier
    int lineDecl; // Line where the identifier was declared
    int *linesUsed; // Array of lines where the identifier was used
    int nLinesUsed; // Number of lines where the identifier was used
    int isFunction; // Flag to indicate if the identifier is a function
    int isArray; // Flag to indicate if the identifier is an array
    int value; // Identifier value
    char *scope; // Scope name
    struct SymbolTableEntry *next; // Next entry in the hash table
} SymbolTableEntry;

// Function declarations

// Function to create a new entry in the hash table
unsigned int hash(char *str);

// Function to get the type of a function or variable
char *func_or_var(int isFunction);

// Function to insert a symbol in the symbol table without specifying its type
void insertSymbol(TreeNode *Node, int scopeLevel);

//  Function to search for an entry in the hash table
bool symbolExistsInScope(TreeNode *aux, int scopeLevel, int lineNumber);

// Function to create the symbol table
void createSymbolTable(TreeNode *node, int scopeLevel);

// Function to start the creation of the symbol table
void startSymbolTableCreation(TreeNode *root);

// Function to free the symbol table
void freeSymbolTable();

// Function to print the symbol table
void printSymbolTable();

// Function to check if a declaration is valid
int checkDeclarations();

// Function to verify if a variable is declared
int verify_linesDecl(int lineDecl, int *linesUsed);

// Function to verify a variable declaration
int verifyVariableDeclaration(TreeNode *variableNode);

// Function to convert an integer to a string
char *tostring_1(int num);


#endif // SYMBOL_TABLE_H
