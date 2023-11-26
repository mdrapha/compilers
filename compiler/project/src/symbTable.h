#define HASH_TABLE_SIZE 997  


typedef struct SymbolTableEntry {
    char *name;          // Symbol name
    int type;            // Type of the symbol
    int lineDecl;      // Symbol declaration line number
    int *linesUsed;     // Array of line numbers where the symbol is used
    int nLinesUsed;     // Number of lines where the symbol is used
    char *stringVal;    // String value of the symbol
    int intVal;         // Integer value of the symbol
    int isVector;       // Flag that indicates if the symbol is a vector
    int vectorSize;     // Vector size
    char *Scope;       // Scope of the symbol
    int isFunction;     // Flag that indicates if the symbol is a function
    int nParams;        // Number of parameters of the function
    int *paramTypes;    // Array of types of the function parameters
    int returnType;     // Return type of the function
    int isDefined;      // Flag that indicates if the function is defined

    struct SymbolTableEntry *next;  // Ponteiro para o próximo símbolo na tabela
} SymbolTableEntry;

typedef struct SymbolTable {
    SymbolTableEntry *first;  // Ponteiro para o primeiro símbolo na tabela
} SymbolTable;



int hash_t(char *str);
SymbolTableEntry *createSymbolTableEntry(char *name, int type, int lineDecl, int isVector, int vectorSize, char *scope, int isFunction, int nParams, int returnType, int isDefined);

void addSymbol(SymbolTable *table, char *name, int type, int lineDecl, int isVector, int vectorSize, char *scope, int isFunction, int nParams, int returnType, int isDefined);

SymbolTableEntry *findSymbol(SymbolTable *table, char *name);

char *generateNewScopeName();

void exitScope();

void enterScope(char *scopeName);