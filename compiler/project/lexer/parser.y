%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { 
    nPrograma, 
    nDeclaracaoLista, 
    nDeclaracao, 
    nVarDeclaracao, 
    nTipoEspecificador, 
    nFunDeclaracao, 
    nParams, 
    nParamLista, 
    nParam, 
    nCompostoDecl, 
    nLocalDeclaracoes, 
    nStatementLista, 
    nStatement, 
    nExpressaoDecl, 
    nSelecaoDecl, 
    nIteracaoDecl, 
    nRetornoDecl, 
    nExpressao, 
    nVar, 
    nSimplesExpressao, 
    nRelacional, 
    nSomaExpressao, 
    nTermo, 
    nFator, 
    nAtivacao, 
    nArgs, 
    nArgLista, 
} NodeType;


typedef struct treeNode {
    NodeType nodeType;
    struct treeNode *children[3]; // Ajuste conforme necessário
    char *lexeme;
} TreeNode;

TreeNode *createNode(NodeType type, TreeNode *child1, TreeNode *child2, TreeNode *child3, char *lexeme) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->nodeType = type;
    node->children[0] = child1;
    node->children[1] = child2;
    node->children[2] = child3;
    node->lexeme = lexeme ? strdup(lexeme) : NULL;
    return node;
}

void freeNode(TreeNode *node) {
    if (node == NULL) return;
    free(node->lexeme);
    for (int i = 0; i < 3; ++i) {
        if (node->children[i]) {
            freeNode(node->children[i]);
        }
    }
    free(node);
}

void printNode(TreeNode *node, int level) {
    if (node == NULL) return;
    for (int i = 0; i < level; ++i) printf("  ");
    switch (node->nodeType) {
        case nPrograma: printf("Programa\n"); break;
        case nDeclaracaoLista: printf("Lista de Declaração\n"); break;
        case nVarDeclaracao: printf("Declaração de Variável\n"); break;
        case nTipoEspecificador: printf("Especificador de Tipo: %s\n", node->lexeme); break;
        // ... outros tipos de nós
    }
    for (int i = 0; i < 3; ++i) {
        printNode(node->children[i], level + 1);
    }
}

void yyerror(const char *s) {
    fprintf(stderr, "Erro: %s\n", s);
}

extern int yylex();
%}

%union {
    TreeNode *node;
    char *string;
}

%token <string> ID NUM
%token <string> INT VOID
%token <string> IF ELSE WHILE RETURN
%token <string> PLUS MINUS TIMES DIVIDE ASSIGN
%token <string> EQUAL NEQUAL LT GT LTE GTE
%token <string> LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET SEMI COMMA

%type <node> programa declaracao_lista declaracao var_declaracao tipo_especificador
%type <node> fun_declaracao params param_lista param composto_decl local_declaracoes
%type <node> statement_lista statement expressao_decl selecao_decl iteracao_decl
%type <node> retorno_decl expressao var simples_expressao relacional soma_expressao
%type <node> termo fator ativacao args arg_lista

%start programa

%%

programa
    : declaracao_lista { $$ = createNode(nPrograma, $1, NULL, NULL, NULL); }
    ;

declaracao_lista
    : declaracao_lista declaracao { $$ = createNode(nDeclaracaoLista, $1, $2, NULL, NULL); }
    | declaracao { $$ = createNode(nDeclaracaoLista, $1, NULL, NULL, NULL); }
    ;

declaracao
    : var_declaracao { $$ = $1; }
    | fun_declaracao { $$ = $1; }
    ;

var_declaracao
    : tipo_especificador ID SEMI { $$ = createNode(nVarDeclaracao, $1, NULL, NULL, $2); }
    | tipo_especificador ID LBRACKET NUM RBRACKET SEMI { $$ = createNode(nVarDeclaracao, $1, NULL, NULL, $2); }
    ;

tipo_especificador
    : INT { $$ = createNode(nTipoEspecificador, NULL, NULL, NULL, "int"); }
    | VOID { $$ = createNode(nTipoEspecificador, NULL, NULL, NULL, "void"); }
    ;

fun_declaracao
    : tipo_especificador ID LPAREN params RPAREN composto_decl {
        $$ = createNode(nFunDeclaracao, $1, $4, $6, $2);
    }
    ;

params
    : param_lista {
        $$ = $1;
    }
    | VOID {
        $$ = createNode(nParams, NULL, NULL, NULL, "void");
    }
    ;

param_lista
    : param_lista COMMA param {
        $$ = createNode(nParamLista, $1, $3, NULL, NULL);
    }
    | param {
        $$ = createNode(nParamLista, $1, NULL, NULL, NULL);
    }
    ;

param
    : tipo_especificador ID {
        $$ = createNode(nParam, $1, NULL, NULL, $2);
    }
    | tipo_especificador ID LBRACKET RBRACKET {
        $$ = createNode(nParam, $1, NULL, NULL, $2); // You might want to distinguish arrays in your node
    }
    ;

composto_decl
    : LBRACE local_declaracoes statement_lista RBRACE {
        $$ = createNode(nCompostoDecl, $2, $3, NULL, NULL);
    }
    ;

local_declaracoes
    : local_declaracoes var_declaracao {
        $$ = createNode(nLocalDeclaracoes, $1, $2, NULL, NULL);
    }
    | /* empty */ {
        $$ = createNode(nLocalDeclaracoes, NULL, NULL, NULL, NULL);
    }
    ;

statement_lista
    : statement_lista statement {
        $$ = createNode(nStatementLista, $1, $2, NULL, NULL);
    }
    | /* empty */ {
        $$ = createNode(nStatementLista, NULL, NULL, NULL, NULL);
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
    : expressao SEMI {
        $$ = createNode(nExpressaoDecl, $1, NULL, NULL, NULL);
    }
    | SEMI {
        $$ = createNode(nExpressaoDecl, NULL, NULL, NULL, NULL);
    }
    ;

selecao_decl
    : IF LPAREN expressao RPAREN statement {
        $$ = createNode(nSelecaoDecl, $3, $5, NULL, "if");
    }
    | IF LPAREN expressao RPAREN statement ELSE statement {
        $$ = createNode(nSelecaoDecl, $3, $5, $7, "if-else");
    }
    ;

iteracao_decl
    : WHILE LPAREN expressao RPAREN statement {
        $$ = createNode(nIteracaoDecl, $3, $5, NULL, "while");
    }
    ;

retorno_decl
    : RETURN SEMI {
        $$ = createNode(nRetornoDecl, NULL, NULL, NULL, "return");
    }
    | RETURN expressao SEMI {
        $$ = createNode(nRetornoDecl, $2, NULL, NULL, "return");
    }
    ;

expressao
    : var ASSIGN expressao {
        $$ = createNode(nExpressao, $1, $3, NULL, "=");
    }
    | simples_expressao {
        $$ = $1;
    }
    ;

var
    : ID {
        $$ = createNode(nVar, NULL, NULL, NULL, $1);
    }
    | ID LBRACKET expressao RBRACKET {
        $$ = createNode(nVar, NULL, $3, NULL, $1); // Array access
    }
    ;

simples_expressao
    : soma_expressao relacional soma_expressao {
        $$ = createNode(nSimplesExpressao, $1, $3, NULL, $2);
    }
    | soma_expressao {
        $$ = $1;
    }
    ;

relacional
    : LT {
        $$ = createNode(nRelacional, NULL, NULL, NULL, "<");
    }
    | LTE {
        $$ = createNode(nRelacional, NULL, NULL, NULL, "<=");
    }
    | GT {
        $$ = createNode(nRelacional, NULL, NULL, NULL, ">");
    }
    | GTE {
        $$ = createNode(nRelacional, NULL, NULL, NULL, ">=");
    }
    | EQUAL {
        $$ = createNode(nRelacional, NULL, NULL, NULL, "==");
    }
    | NEQUAL {
        $$ = createNode(nRelacional, NULL, NULL, NULL, "!=");
    }
    ;

soma_expressao
    : soma_expressao PLUS termo {
        $$ = createNode(nSomaExpressao, $1, $3, NULL, "+");
    }
    | soma_expressao MINUS termo {
        $$ = createNode(nSomaExpressao, $1, $3, NULL, "-");
    }
    | termo {
        $$ = $1;
    }
    ;

termo
    : termo TIMES fator {
        $$ = createNode(nTermo, $1, $3, NULL, "*");
    }
    | termo DIVIDE fator {
        $$ = createNode(nTermo, $1, $3, NULL, "/");
    }
    | fator {
        $$ = $1;
    }
    ;

fator
    : LPAREN expressao RPAREN {
        $$ = createNode(nFator, $2, NULL, NULL, NULL);
    }
    | var {
        $$ = $1;
    }
    | ativacao {
        $$ = $1;
    }
    | NUM {
        $$ = createNode(nFator, NULL, NULL, NULL, $1);
    }
    ;

ativacao
    : ID LPAREN args RPAREN {
        $$ = createNode(nAtivacao, NULL, NULL, NULL, $1); // Func call, args are handled separately
    }
    ;

args
    : arg_lista {
        $$ = $1;
    }
    | /* empty */ {
        $$ = createNode(nArgs, NULL, NULL, NULL, NULL);
    }
    ;

arg_lista
    : arg_lista COMMA expressao {
        $$ = createNode(nArgLista, $1, $3, NULL, NULL);
    }
    | expressao {
        $$ = createNode(nArgLista, $1, NULL, NULL, NULL);
    }
    ;


%%


