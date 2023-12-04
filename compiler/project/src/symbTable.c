#include "../include/globals.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASH_TABLE_SIZE 101
int globalvars = 0;
int input_func = 0;
int output_func = 0;
int doubleDeclaration = 0;
char doubleDeclarationName[MAX_LEXEME_SIZE];

preTable preTableArray[MAX_TABLE_SIZE];

funcsTable funcsTableArray[1000];
globalID globalIDArray[1000];

SymbolTableEntry *hashTable[HASH_TABLE_SIZE]; // Hash table for the symbol table

void checkPreTable()
{
    int i = 0;
    char *currentScope = "global";
    while (preTableArray[i].lexeme != NULL)
    {
        if (preTableArray[i].isFunction == nFunDeclaracao)
        {
            preTableArray[i].scope = malloc(sizeof(char) * MAX_LEXEME_SIZE);
            strcpy(preTableArray[i].scope, "global");
            currentScope = malloc(sizeof(char) * MAX_LEXEME_SIZE);
            strcpy(currentScope, preTableArray[i].lexeme);
        }
        else
        {
            preTableArray[i].scope = malloc(sizeof(char) * MAX_LEXEME_SIZE);
            strcpy(preTableArray[i].scope, currentScope);
            if (strcmp(currentScope, "global") == 0)
            {
                int alreadyDeclared = 0;
                if (globalvars != 0)
                {
                    for (int j = 0; globalIDArray[j].lexeme != NULL; j++)
                    {
                        // printf("Comparing %s with %s\n",globalIDArray[j].lexeme,preTableArray[i].lexeme);
                        if (strcmp(globalIDArray[j].lexeme, preTableArray[i].lexeme) == 0)
                        {
                            alreadyDeclared = 1;
                            printf("\n\033[1;37;41m");
                            printf("Error: Var/Function '%s' declared more than once, at line %d.", preTableArray[i].lexeme, preTableArray[i].line);
                            printf("\033[0m\n\n");
                            exit(1);

                            break;
                        }
                    }
                }
                // printf("declaring %s\n",preTableArray[i].lexeme);
                strcpy(globalIDArray[i].lexeme, preTableArray[i].lexeme);
                globalIDArray[i].line = preTableArray[i].line;
                globalvars++;
            }
        }
        char *aux = malloc(sizeof(char) * MAX_LEXEME_SIZE * 2);
        strcpy(aux, preTableArray[i].lexeme);
        strcat(aux, "_");
        strcat(aux, preTableArray[i].scope);
        strcpy(preTableArray[i].lexeme2, aux);
        // verificacao se ja foi declarada, caso tenha lineDecl = -1, pega a lineDecl da declaracao inicial, verifica pelas globais
        if(globalvars!=0){
            //printf("entrou\n");
            for (int j = 0; j < globalvars; j++)
            {
                //printf("Comparing %s with %s\n",globalIDArray[j].lexeme,preTableArray[i].lexeme);
                if (strcmp(globalIDArray[j].lexeme, preTableArray[i].lexeme) == 0 && preTableArray[i].lineDecl == -1)
                {
                    preTableArray[i].lineDecl = globalIDArray[j].line;
                    //printf("Found %s at line %d\n",preTableArray[i].lexeme,preTableArray[i].lineDecl);
                }
            }
        }

        i++;
    }

    for (int j = 0; preTableArray[j].lexeme != NULL; j++)
    {
        if (globalvars != 0)
        {
            for (int k = 0; k < globalvars; k++)
            {
                if (strcmp(globalIDArray[k].lexeme, preTableArray[j].lexeme) == 0 && globalIDArray[k].line != preTableArray[j].line && preTableArray[j].line == -1)
                {
                    printf("\n\033[1;37;41m");
                    printf("Error: Var/Function '%s' declared more than once, at line %d.", preTableArray[j].lexeme, preTableArray[j].line);
                    printf("\033[0m\n\n");
                    exit(1);
                    break;
                }
            }
        }
    }
}

/* Function to calculate the hash value of a string */
unsigned int hash(char *str)
{
    unsigned int hashValue = 0;
    for (char *p = str; *p != '\0'; p++)
    {
        hashValue = *p + 31 * hashValue;
    }
    return hashValue % HASH_TABLE_SIZE;
}

/* Function to insert a symbol in the symbol table without specifying its type */
void insertSymbol(preTable entry)
{

    unsigned int index = hash(entry.lexeme2);
    SymbolTableEntry *current = hashTable[index];

    // Verifica se o símbolo já existe
    while (current != NULL)
    {
        if (strcmp(current->lexeme, entry.lexeme2) == 0)
        {
            // Atualiza a linha de declaração e as linhas de uso, se necessário
            if (entry.varType == T_INT || entry.varType == T_VOID)
            {
                // É uma declaração
                current->lineDecl = entry.lineDecl;
            }
            else if (entry.varType == T_ID)
            {
                
                int *temp = realloc(current->linesUsed, sizeof(int) * (current->nLinesUsed + 2));
                if (temp == NULL)
                {
                    printf("Error: Memory allocation failed.\n");
                    exit(1);
                }
                
                current->linesUsed = temp;
                current->linesUsed[current->nLinesUsed++] = entry.line;
                current->linesUsed[current->nLinesUsed] = -1;
            }
            return; // Símbolo já existe e foi atualizado
        }
        current = current->next;
    }
    int foundInFuncsTable = 0;
    int i;

    for (i = 0; funcsTableArray[i].lexeme != NULL; i++)
    {
        if (strcmp(funcsTableArray[i].lexeme, entry.lexeme) == 0)
        {
            // printf("Found in funcsTableArray\n");
            foundInFuncsTable = 1;
            break;
        }
    }

    // Insere um novo símbolo na tabela de símbolos
    SymbolTableEntry *newEntry = (SymbolTableEntry *)malloc(sizeof(SymbolTableEntry));
    if (newEntry == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    strcpy(newEntry->identifier, entry.lexeme);
    strcpy(newEntry->lexeme, entry.lexeme2);
    newEntry->scopeLevel = 0;
    
    if (foundInFuncsTable)
    {
        // Herda atributos da função na funcsTableArray

        newEntry->lineDecl = funcsTableArray[i].line;
        newEntry->type = funcsTableArray[i].type;
        newEntry->isArray = funcsTableArray[i].isArray;
        newEntry->value = funcsTableArray[i].arraySize;
        newEntry->isFunction = 7;
        printf("Found in funcsTableArray\n");

        int *temp2 = realloc(newEntry->linesUsed, sizeof(int) * (newEntry->nLinesUsed + 2));
        if (temp2 == NULL)
        {
            printf("Error: Memory allocation failed.\n");
            exit(1);
        }
        
        newEntry->linesUsed = temp2;
        newEntry->linesUsed[newEntry->nLinesUsed++] = entry.line;
        newEntry->linesUsed[newEntry->nLinesUsed] = -1;

    }
    else
    {
        newEntry->lineDecl =entry.lineDecl;
        newEntry->type = entry.varType;
        newEntry->isArray = entry.isArray;
        newEntry->value = entry.arraySize;
    }

    if(strcmp(entry.lexeme,"input")==0 || strcmp(entry.lexeme,"output")==0){
        newEntry->isFunction = 7;
        newEntry->lineDecl = 0;

        if(input_func == 1 && strcmp(entry.lexeme,"input")==0){
            printf("\n\033[1;37;41m");
            printf("Error: Function '%s' declared more than once.", entry.lexeme);
            printf("\033[0m\n\n");
            exit(1);
        }
        if(output_func == 1 && strcmp(entry.lexeme,"output")==0){
            printf("\n\033[1;37;41m");
            printf("Error: Function '%s' declared more than once.", entry.lexeme);
            printf("\033[0m\n\n");
            exit(1);
        }

        int *temp3 = realloc(newEntry->linesUsed, sizeof(int) * (newEntry->nLinesUsed + 2));
        if (temp3 == NULL)
        {
            printf("Error: Memory allocation failed.\n");
            exit(1);
        }
        
        newEntry->linesUsed = temp3;
        newEntry->linesUsed[newEntry->nLinesUsed++] = entry.line;
        newEntry->linesUsed[newEntry->nLinesUsed] = -1;


        if(strcmp(entry.lexeme,"input")==0){
        newEntry->type = T_INT;
        input_func = 1;
        }else{
        newEntry->type = T_VOID;
        output_func = 1;}

        newEntry->isArray = 0;

       

    }


    if(newEntry->isFunction ==NULL)
    newEntry->isFunction = entry.isFunction;

    newEntry->scope = entry.scope;
    newEntry->value = entry.arraySize;
    newEntry->linesUsed = malloc(sizeof(int));
    
    newEntry->linesUsed[0] = -1;
    newEntry->nLinesUsed = 0;


    // Adiciona o novo símbolo no início da lista no índice hash
    newEntry->next = hashTable[index];
    hashTable[index] = newEntry;
}

// Function to start creating the symbol table
void startSymbolTableCreation(TreeNode *root)
{
    for (int i = 0; preTableArray[i].lexeme != NULL; i++)
    {
        insertSymbol(preTableArray[i]);
    }
}

// Function to free the symbol table
void freeSymbolTable()
{
    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        SymbolTableEntry *entry = hashTable[i];
        while (entry != NULL)
        {
            SymbolTableEntry *temp = entry;
            entry = entry->next;
            free(temp);
        }
    }
}

/* Function to print the symbol table */
void printSymbolTable()
{
    printf("\n\033[1;36m");
    printf(
        "--------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-20s | %-10s | %-15s | %-10s | %-6s | %-5s | %-25s |\n", "Name", "Decl Line", "Scope", "Func/Var",
           "Type", "Array?",  "Lines Usage");
    printf(
        "--------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        SymbolTableEntry *entry = hashTable[i];
        while (entry != NULL)
        {
            printf("\033[1;36m|\033[1m %-20s \033[1;36m|\033[0m %-10d \033[1;36m|\033[0m %-15s \033[1;36m|\033[0m %-10s \033[1;36m|\033[0m %-6s \033[1;36m|\033[0m %-6s \033[1;36m|\033[0m ",
                   entry->identifier, entry->lineDecl, entry->scope, (entry->isFunction == 7) ? "Function" : "Variable",
                   (entry->type == T_INT) ? "int" : "void", (entry->isArray) ? "Array" : "No");

            // Print lines used
            if (entry->linesUsed == NULL || entry->linesUsed[0] == -1)
            {
                printf("-\n");
                printf(
                    "\033[1;36m--------------------------------------------------------------------------------------------------------------------------\033[0m\n");
                entry = entry->next;
                continue;
            }
            else
            {
                int j = 0;
                while (entry->linesUsed[j] != -1)
                {
                    if (j > 0)
                    {
                        printf(",");
                    }
                    printf("%d", entry->linesUsed[j]);
                    j++;
                }
                printf("\n");
                printf(
                    "\033[1;36m--------------------------------------------------------------------------------------------------------------------------\033[0m\n");

                entry = entry->next;
            }
        }
    }
    printf("\033[0m\n\n");
}

int checkDeclarations()
{
    int error = 0;
    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        SymbolTableEntry *entry = hashTable[i];
        while (entry != NULL)
        {
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

            entry = entry->next;
        }
    }
    return error;
}

int verify_linesDecl(int lineDecl, int *linesUsed)
{
    int i = 0;
    while (linesUsed[i] != -1)
    {
        if (linesUsed[i] < lineDecl)
        {
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