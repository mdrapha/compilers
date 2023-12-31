%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "globals.h"

*parseTree = NULL;
int scopeCounter = 0; // Counter for the current scope
void yyerror(char *s);

extern int yylex();
%}

%union {
    TreeNode *node;
    char *string;
    int line;
    int num;
}

%token <string> T_ID
%token <num> T_NUM
%token <string> T_INT T_VOID T_IF T_ELSE T_WHILE T_RETURN
%token <string> T_PLUS T_MINUS T_MULT T_DIV T_ATRB
%token <string> T_EQ T_NEQ T_LT T_GT T_LTE T_GTE
%token <string> T_LPAREN T_RPAREN T_LBRACE T_RBRACE T_LSQBRA T_RSQBRA T_SEMI T_COMMA

%nonassoc LOWER_THAN_ELSE
%nonassoc T_ELSE


%type <node> programa declaracao_lista declaracao var_declaracao tipo_especificador
%type <node> fun_declaracao fun_id params param_lista param composto_decl local_declaracoes
%type <node> statement_lista statement expressao_decl selecao_decl iteracao_decl
%type <node> retorno_decl expressao var simples_expressao relacional soma_expressao
%type <node> termo fator ativacao args arg_lista

%start programa

%%

programa
    : declaracao_lista {
        parseTree = $1;
        symbolTable = createSymbolTable();
    }
    ;

declaracao_lista
    : declaracao_lista declaracao {
        if ($1 != NULL) {
            addNode(&$1, $2, -1); // Add as sibling            
            $$ = $1;

        } else {
            $$ = $2;
        }
    }
    | declaracao {
        $$ = $1;
    }
    ;

declaracao
    : var_declaracao {
        $$ = $1;
    }
    | fun_declaracao {
        $$ = $1;
    }
    ;

var_declaracao
    : tipo_especificador T_ID T_SEMI {
        $$ = $1;
        $$->type = T_ID; // Defining the type as an identifier
        $$->nodeType = nVarDeclaracao; // Defining the node type as a variable declaration
        $$->lineNumber = currentTokenLine;

        TreeNode *aux = newNode();
        strcpy(aux->lexeme, currentTokenValue);
        addNode(&$$, aux, 0); // Adiciona aux como o primeiro filho

        // Adiciona a variável à tabela de símbolos
        addSymbol(symbolTable, aux->lexeme, $$->type, aux->lineNumber, currentScope, 0); 
    }
    | tipo_especificador T_ID T_LSQBRA T_NUM T_RSQBRA T_SEMI {
        $$ = $1;
        $$->type = T_ID; // Assume que T_ID representa uma declaração de vetor
        $$->lineNumber = currentTokenLine;

        TreeNode *aux = newNode();
        strcpy(aux->lexeme, currentTokenValue); // Assume que armazena o nome da variável
        addNode(&$$, aux, 0); // Adiciona aux como o primeiro filho

        TreeNode *aux2 = newNode();
        aux2->type = T_NUM;
        strcpy(aux2->lexeme, yylval.string); // Assume que armazena o tamanho do vetor
        aux2->lineNumber = currentTokenLine;
        addNode(&$$, aux2, 1); // Adiciona aux2 como o segundo filho

        // Adiciona o vetor à tabela de símbolos
        addSymbol(symbolTable, aux->lexeme, $$->type, aux->lineNumber, currentScope, atoi(aux2->lexeme));
    }

tipo_especificador
    : T_INT {
        $$ = newNode();
        $$->type = T_INT; // Assuming T_INT is the token type for "int"
        strcpy($$->lexeme, "int");
        $$->lineNumber = currentTokenLine;

    }
    | T_VOID {
        $$ = newNode();
        $$->type = T_VOID; // Assuming T_VOID is the token type for "void"
        strcpy($$->lexeme, "void");
        $$->lineNumber = currentTokenLine;
    }


fun_declaracao
    : tipo_especificador fun_id T_LPAREN params T_RPAREN composto_decl {
        char *previousScope = strdup(currentScope); // Salva o escopo atual
        currentScope = strdup($2->lexeme); // Entra no escopo da função

        $$ = $1; // O especificador de tipo torna-se o nó raiz para a declaração da função
        
        addNode(&$$, $2, 0); // Adiciona identificador da função como o primeiro filho
        addNode(&$$, $4, 1); // Adiciona parâmetros como o segundo filho
        addNode(&$2, $6, 0); // Adiciona declaração composta como filho do identificador da função

        $$->type = T_FUN; // Assume que T_FUN é o tipo de token para declarações de função
        $$->lineNumber = currentTokenLine; // Define o número da linha
        $$->nodeType = nFunDeclaracao; // Define o tipo do nó como declaração de função

        // Adiciona a função à tabela de símbolos (implemente getParamTypes para obter tipos de parâmetros)
        addFunctionSymbol(symbolTable, $2->lexeme, $1->type, $2->lineNumber, getParamTypes($4), $4->nParams);

        free(currentScope); // Libera o escopo da função
        currentScope = previousScope; // Restaura o escopo anterior
    }
    ;

fun_id
    : T_ID {
        $$ = newNode();
        $$->type = T_ID; // Assume que T_ID é o tipo de token para identificadores
        strncpy($$->lexeme, currentTokenValue); // Copia o lexema do identificador
        $$->lexeme[MAX_LEXEME_SIZE - 1] = '\0'; // Garante terminação nula
        $$->lineNumber = currentTokenLine;
    }
    ;


params
    : param_lista {
        $$ = $1; // Directly use the parameter list node
        $$->nodeType = nParams;
    }
    | T_VOID {
        $$ = newNode();
        $$->type = T_VOID; // Assuming T_VOID is the token type for "void"
        strncpy($$->lexeme, "VOID", MAX_LEXEME_SIZE - 1); // Set lexeme to "void"
        $$->lexeme[MAX_LEXEME_SIZE - 1] = '\0'; // Ensure null termination
        $$->lineNumber = currentTokenLine;
        $$->nodeType = nParams;
    }
    ;


param_lista
    : param_lista T_COMMA param {
        if ($1 != NULL) {
            addNode(&$1, $3, -1); // Add $3 as a sibling to $1
            $$ = $1; // The first parameter list node is the root of the list
        } else {
            $$ = $3; // If $1 is NULL, use $3 as the start of the list
        }
    }
    | param {
        $$ = $1; // For a single parameter, just use the parameter node
    }
    ;


param
    : tipo_especificador T_ID {
        $$ = newNode();
        $$->type = T_ID; // Defining the type as an identifier
        $$->lineNumber = currentTokenLine;

        TreeNode *aux = newNode();
        strncpy(aux->lexeme, currentTokenValue, MAX_LEXEME_SIZE - 1); // Copy the identifier's lexeme
        aux->lexeme[MAX_LEXEME_SIZE - 1] = '\0'; // Ensure null termination
        aux->lineNumber = currentTokenLine;
        aux->type = T_ID; // Set type for the identifier

        addNode(&$$, aux, 0); // Add aux as the first child
        addSymbol(symbolTable, aux->lexeme, $$->type, aux->lineNumber, currentScope, 0); // Add parameter symbol to symbol table
    }

    | tipo_especificador T_ID T_LSQBRA T_RSQBRA {
        $$ = newNode();
        $$->type = T_ID; // Defining the type as an array
        $$->lineNumber = currentTokenLine;

        TreeNode *aux = newNode();
        strncpy(aux->lexeme, currentTokenValue, MAX_LEXEME_SIZE - 1); // Copy the array identifier's lexeme
        aux->lexeme[MAX_LEXEME_SIZE - 1] = '\0'; // Ensure null termination
        aux->lineNumber = currentTokenLine;
        aux->type = T_ID; // Set type for the array identifier

        addNode(&$$, aux, 0); // Add aux as the first child
        addSymbol(symbolTable, aux->lexeme, $$->type, aux->lineNumber, currentScope, 0); // Add array parameter symbol to symbol table
    }



composto_decl
    : T_LBRACE local_declaracoes statement_lista T_RBRACE {
        char* previousScope = currentScope; // Save the current scope
        currentScope = generateNewScopeName(); // Generate a new scope name
        $$ = newNode(); // Create a new node for the compound declaration
        $$->type = T_LBRACE; // Assuming T_LBRACE represents a compound declaration
        $$->lineNumber = currentTokenLine; // Set the line number
        $$->nodeType = nCompostoDecl; 

        if ($2 != NULL) {
            addNode(&$$, $2, 0); // Add local declarations as the first child
        }
        if ($3 != NULL) {
            addNode(&$$, $3, 1); // Add statement list as the second child
        }
        exitScope(); // Exit the compound declaration's scope
        currentScope = previousScope; // Restore the previous scope
    }
    ;

local_declaracoes
    : local_declaracoes var_declaracao {
        if ($1 != NULL) {
            addNode(&$1, $2, -1); // Add $2 as a sibling to $1
            $$ = $1; // The first local declarations node remains the root
        } else {
            $$ = $2; // If $1 is NULL, use $2 as the start of the list
        }
    }
    | /* empty */ {
        $$ = NULL; // For an empty production, set $$ to NULL
    }
    ;


statement_lista
    : statement_lista statement {
        if ($1 != NULL) {
            addNode(&$1, $2, -1); // Add $2 as a sibling to $1
            $$ = $1; // The first statement list node remains the root
        } else {
            $$ = $2; // If $1 is NULL, use $2 as the start of the list
        }
    }
    | /* empty */ {
        $$ = NULL; // For an empty production, set $$ to NULL
    }
    ;


statement
    : expressao_decl {
        $$ = $1;
    }
    | composto_decl {
        $$ = $1;
    }
    | selecao_decl {
        $$ = $1;
    }
    | iteracao_decl {
        $$ = $1;
    }
    | retorno_decl {
        $$ = $1;
    }
    ;


expressao_decl
    : expressao T_SEMI {
        $$ = $1; // The result is the expression's subtree
    }

    | T_SEMI {
        $$ = NULL; // Representing an empty statement with NULL
    }
    ;


selecao_decl
    : T_IF T_LPAREN expressao T_RPAREN statement %prec LOWER_THAN_ELSE {
        $$ = newNode();
        $$->type = T_IF; // Defining the type as an if statement
        strcpy($$->lexeme, "IF");
        $$->lineNumber = currentTokenLine;
        $$->nodeType = nSelecaoDecl;

        addNode(&$$, $3, 0); // Add the expression as the first child
        addNode(&$$, $5, 1); // Add the statement as the second child
    }
    | T_IF T_LPAREN expressao T_RPAREN statement T_ELSE statement {
        $$ = newNode();
        $$->type = T_IF; // Defining the type as an if statement
        strcpy($$->lexeme, "IF");
        $$->lineNumber = currentTokenLine;
        $$->nodeType = nSelecaoDecl;

        addNode(&$$, $3, 0); // Add the expression as the first child
        addNode(&$$, $5, 1); // Add the statement as the second child
        addNode(&$$, $7, 2); // Add the else part as the third child
    }
    ;


iteracao_decl
    : T_WHILE T_LPAREN expressao T_RPAREN statement {
        $$ = newNode();
        $$->type = T_WHILE; // Assuming T_WHILE is the token type for "while" loops
        strncpy($$->lexeme, "WHILE", MAX_LEXEME_SIZE - 1); // Set lexeme to "WHILE"
        $$->lexeme[MAX_LEXEME_SIZE - 1] = '\0'; // Ensure null termination
        $$->lineNumber = currentTokenLine;
        $$->nodeType = nIteracaoDecl;

        addNode(&$$, $3, 0); // Add the expression as the first child
        addNode(&$$, $5, 1); // Add the statement as the second child
    }
    ;



retorno_decl
    : T_RETURN T_SEMI {
        $$ = newNode();
        $$->type = T_RETURN; // Assuming T_RETURN is the token type for "return"
        strncpy($$->lexeme, "ReturnVOID", MAX_LEXEME_SIZE - 1); // Set lexeme to "ReturnVOID"
        $$->lexeme[MAX_LEXEME_SIZE - 1] = '\0'; // Ensure null termination
        $$->lineNumber = currentTokenLine;
        $$->nodeType = nRetornoDecl;

    }

    | T_RETURN expressao T_SEMI {
        $$ = newNode();
        $$->type = T_RETURN; // Assuming T_RETURN is the token type for "return"
        strncpy($$->lexeme, "ReturnINT", MAX_LEXEME_SIZE - 1); // Set lexeme to "ReturnINT"
        $$->lexeme[MAX_LEXEME_SIZE - 1] = '\0'; // Ensure null termination
        $$->lineNumber = currentTokenLine;
        $$->nodeType = nRetornoDecl;

        addNode(&$$, $2, 0); // Add the expression as the first child

    }
    ;

expressao
    : var T_ATRB expressao {
        $$ = newNode();
        $$->type = T_ATRB; // Assuming T_ATRB is the token type for assignment operator
        strncpy($$->lexeme, "=", MAX_LEXEME_SIZE - 1); // Set lexeme to "="
        $$->lexeme[MAX_LEXEME_SIZE - 1] = '\0'; // Ensure null termination
        $$->lineNumber = currentTokenLine;
        $$->nodeType = nExpressao;

        addNode(&$$, $1, 0); // Add the variable as the first child
        addNode(&$$, $3, 1); // Add the expression as the second child
    }

    | simples_expressao {
        $$ = $1;
        $$->nodeType = nExpressao;
    }
    ;

var
    : T_ID {
        $$ = newNode();
        $$->type = T_ID; // Assuming T_ID is the token type for identifiers
        strncpy($$->lexeme, currentTokenValue, MAX_LEXEME SIZE - 1); // Copy the identifier's lexeme
        $$->lexeme[MAX_LEXEME SIZE - 1] = '\0'; // Ensure null termination
        $$->lineNumber = currentTokenLine;
        $$->nodeType = nVar;
    }

    | T_ID T_LSQBRA expressao T_RSQBRA {
        $$ = newNode();
        $$->type = T_ID; // Assuming T_ID is used for array identifiers as well
        strncpy($$->lexeme, currentTokenValue, MAX_LEXEME SIZE - 1); // Copy the identifier's lexeme
        $$->lexeme[MAX_LEXEME SIZE - 1] = '\0'; // Ensure null termination
        $$->lineNumber = currentTokenLine;
        $$->nodeType = nVar; 

        addNode(&$$, $3, 0); // Add the index expression as the first child

    }



simples_expressao
    : soma_expressao relacional soma_expressao {
        $$ = $2; // Use the relational operator's node as the base
        $$->nodeType = nSimplesExpressao;
        addNode(&$$, $1, 0); // Add the first expression as the first child
        addNode(&$$, $3, 1); // Add the second expression as the second child
    }
    | soma_expressao {
        $$ = $1;
        $$->nodeType = nSimplesExpressao;
    }
    ;

relacional
    : T_LT {
        $$ = newNode();
        $$->type = T_LT; // Defining the type as a less than operator
        $$->lineNumber = currentTokenLine;
        strcpy($$->lexeme, "<"); // Set lexeme to "<"

    }
    | T_LTE {
        $$ = newNode();
        $$->type = T_LTE; // Defining the type as a less than or equal operator
        $$->lineNumber = currentTokenLine;
        strcpy($$->lexeme, "<="); // Set lexeme to "<="
    }
    | T_GT {
        $$ = newNode();
        $$->type = T_GT; // Defining the type as a greater than operator
        $$->lineNumber = currentTokenLine;
        strcpy($$->lexeme, ">"); // Set lexeme to ">"
    }
    | T_GTE {
        $$ = newNode();
        $$->type = T_GTE; // Defining the type as a greater than or equal operator
        $$->lineNumber = currentTokenLine;
        strcpy($$->lexeme, ">="); // Set lexeme to ">="
    }
    | T_EQ {
        $$ = newNode();
        $$->type = T_EQ; // Defining the type as an equal operator
        $$->lineNumber = currentTokenLine;
        strcpy($$->lexeme, "=="); // Set lexeme to "=="
    }
    | T_NEQ {
        $$ = newNode();
        $$->type = T_NEQ; // Defining the type as a not equal operator
        $$->lineNumber = currentTokenLine;
        strcpy($$->lexeme, "!="); // Set lexeme to "!="
    }
    ;


soma_expressao
    : soma_expressao T_PLUS termo {
        $$ = newNode();
        $$->type = T_PLUS; // Defining the type as an addition operator
        strcpy($$->lexeme, "+"); // Defining the lexeme as "+"
        $$->lineNumber = currentTokenLine;

        addNode(&$$, $1, 0); // Add the first expression as the first child
        addNode(&$$, $3, 1); // Add the term as the second child
    }
    | soma_expressao T_MINUS termo {
        $$ = newNode();
        $$->type = T_MINUS; // Defining the type as a subtraction operator
        strcpy($$->lexeme, "-"); // Defining the lexeme as "-"
        $$->lineNumber = currentTokenLine;

        addNode(&$$, $1, 0); // Add the first expression as the first child
        addNode(&$$, $3, 1); // Add the term as the second child
    }
    | termo {
        $$ = $1; // The result is the term's subtree
    }
    ;


termo
    : termo T_MULT fator {
        $$ = newNode();
        $$->type = T_MULT; // Defining the type as an operator of multiplication
        strcpy($$->lexeme, "*"); // Defining the lexeme as "*"
        $$->lineNumber = currentTokenLine;

    }
    | termo T_DIV fator {
        $$ = newNode();
        $$->type = T_DIV; // Defining the type as an operator of division
        strcpy($$->lexeme, "/"); // Defining the lexeme as "/"
        $$->lineNumber = currentTokenLine;

    }
    | fator {
        $$ = $1;
    }
    ;

fator
    : T_LPAREN expressao T_RPAREN {
        $$ = newNode();
        $$->nodeType = nFator;
        $$->type = T_LPAREN; // Defining the type as a left parenthesis
        addNode(&$$, $2, 0); // Add the expression as the first child
        $$->lineNumber = currentTokenLine;
    }
    | var {
        $$ = $1; // The result is the variable's subtree
    }
    | ativacao {
        $$ = $1; // The result is the function call's subtree
    }
    | T_NUM {
        $$ = newNode();
        $$->type = T_NUM; // Defining the type as a number
        strcpy($$->lexeme, currentTokenValue); // Defining the lexeme as the number's value
        $$->lineNumber = currentTokenLine;
    }
    ;


ativacao
    : fun_id T_LPAREN args T_RPAREN {
        $$ = newNode();
        $$->nodeType = nAtivacao; 
        $$->type = T_LPAREN; // Defining the type as an opening parenthesis
        strncpy($$->lexeme, $1->lexeme, MAX_LEXEME_SIZE - 1); // Copying the function identifier's lexeme
        $$->lexeme[MAX_LEXEME_SIZE - 1] = '\0'; // Ensure null termination
        $$->lineNumber = qntLinhas; // Defining the line number as the current line

        addNode(&$$, $3, 0); // Add the arguments as the first child
    }
    ;

args
    : arg_lista {
        $$ = $1; // The result is the argument list's subtree
        $$->nodeType = nArgs;
    }
    | /* empty */ {
        $$ = NULL; // Representing an empty argument list with NULL
    }
    ;

arg_lista
    : arg_lista T_COMMA expressao {
        if ($1 != NULL) {
            $$ = $1; // Keep the first argument list node as the root
            $$->nodeType = nArgLista;
            addNode(&$$, $3, -1); // Add the expression as a sibling to the first argument list node
        } else {
            $$ = $3; // If $1 is NULL, use $3 as the start of the list
        }
    }
    | expressao {
        $$ = $1; // For a single argument, just use the expression's subtree
        $$->nodeType = nArgLista;
    }
    ;




%%
void yyerror(char *s){
    fprintf(stderr, "Error: Syntax Problem at line %d\n", currentTokenLine);
    printf("token: %d\n", currentToken);
    switch (currentToken)
    {
    case T_ID:
        fprintf(stderr, "Unexpected ID %s\n", s);
        break;

    case T_NUM:
        fprintf(stderr, "Unexpected NUM %s\n", s);
        break;

    case T_PLUS:
        fprintf(stderr, "Unexpected '+'\n");
        break;

    case T_MINUS:
        fprintf(stderr, "Unexpected '-'\n");
        break;

    case T_MULT:
        fprintf(stderr, "Unexpected '*'\n");
        break;

    case T_DIV:
        fprintf(stderr, "Unexpected '/'\n");
        break;

    case T_IF:
        fprintf(stderr, "Unexpected 'if'\n");
        break;

    case T_ELSE:
        fprintf(stderr, "Unexpected 'else'\n");
        break;
    
    case T_WHILE:
        fprintf(stderr, "Unexpected 'while'\n");
        break;

    case T_RETURN:
        fprintf(stderr, "Unexpected 'return'\n");
        break;

    case T_LT:
        fprintf(stderr, "Unexpected '<'\n");
        break;

    case T_LTE:
        fprintf(stderr, "Unexpected '<='\n");
        break;

    case T_GT:
        fprintf(stderr, "Unexpected '>'\n");
        break;

    case T_GTE:
        fprintf(stderr, "Unexpected '>='\n");
        break;

    case T_EQ:
        fprintf(stderr, "Unexpected '=='\n");
        break;

    case T_NEQ: 
        fprintf(stderr, "Unexpected '!='\n");
        break;

    case T_ATRB:
        fprintf(stderr, "Unexpected '='\n");
        break;

    case T_LPAREN:
        fprintf(stderr, "Unexpected '('\n");
        break;

    case T_RPAREN:
        fprintf(stderr, "Unexpected ')'\n");
        break;

    case T_LBRACE:
        fprintf(stderr, "Unexpected '{'\n");
        break;

    case T_RBRACE:  
        fprintf(stderr, "Unexpected '}'\n");
        break;

    case T_LSQBRA:
        fprintf(stderr, "Unexpected '['\n");
        break;

    case T_RSQBRA:
        fprintf(stderr, "Unexpected ']'\n");
        break;

    case T_SEMI:
        fprintf(stderr, "Unexpected ';'\n");
        break;

    case T_COMMA:
        fprintf(stderr, "Unexpected ','\n");
        break;

    case T_VOID:
        fprintf(stderr, "Unexpected 'void'\n");
        break;

    case T_INT:
        fprintf(stderr, "Unexpected 'int'\n");
        break;

    case T_EOF:
        fprintf(stderr, "Unexpected end\n");
        break;

    

    default:
        fprintf(stderr, "Unexpected token %s\n", s);
      break;
    }
}

int yylex() {
    int token;
    Analysis *info = createGNT(&lex, buffer, file);
    Analysis *temp = info;

    temp = get_next_token(info);
    token = temp->lex->token;

    // Configuração do yylval union
    switch (token) {
        case T_NUM:
            yylval.num = atoi(temp->lex->name); // Se o token for um número, converte para inteiro
            break;
        case T_ID:
            yylval.string = strdup(temp->lex->name); // Se o token for um identificador, copia seu lexema
            break;
    }

    currentTokenLine = temp->lex->line;
    currentTokenValue = temp->lex->name;
    currentToken = temp->lex->token;
    info = temp;
    if(token==T_EOF) {
        free(info);
        return 0;
    }

    return token;
}

