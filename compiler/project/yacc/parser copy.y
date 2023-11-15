%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "globals.h"

TreeNode *root = NULL;

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
    : tipo_especificador T_ID T_SEMI { $$ = createNode(nVarDeclaracao, $1, NULL, NULL, strdup($<string>2)); }
    | tipo_especificador T_ID T_LSQBRA T_NUM T_RSQBRA T_SEMI { $$ = createNode(nVarDeclaracao, $1, NULL, NULL, strdup($<string>2)); }
    ;

tipo_especificador
    : T_INT { $$ = createNode(nTipoEspecificador, NULL, NULL, NULL, "int"); }
    | T_VOID { $$ = createNode(nTipoEspecificador, NULL, NULL, NULL, "void"); }
    ;

fun_declaracao
    : tipo_especificador T_ID T_LPAREN params T_RPAREN composto_decl {
        $$ = createNode(nFunDeclaracao, $1, $4, $6, strdup($<string>2));
    }
    ;

params
    : param_lista {
        $$ = $1;
    }
    | T_VOID {
        $$ = createNode(nParams, NULL, NULL, NULL, "void");
    }
    ;

param_lista
    : param_lista T_COMMA param {
        $$ = createNode(nParamLista, $1, $3, NULL, NULL);
    }
    | param {
        $$ = createNode(nParamLista, $1, NULL, NULL, NULL);
    }
    ;

param
    : tipo_especificador T_ID { $$ = createNode(nParam, $1, NULL, NULL, strdup($<string>2)); }
    | tipo_especificador T_ID T_LSQBRA T_RSQBRA { $$ = createNode(nParam, $1, NULL, NULL, strdup($<string>2)); }
    ;

composto_decl
    : T_LBRACE local_declaracoes statement_lista T_RBRACE {
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
    : expressao T_SEMI {
        $$ = createNode(nExpressaoDecl, $1, NULL, NULL, NULL);
    }
    | T_SEMI {
        $$ = createNode(nExpressaoDecl, NULL, NULL, NULL, NULL);
    }
    ;

selecao_decl
    : T_IF T_LPAREN expressao T_RPAREN statement %prec LOWER_THAN_ELSE {
        $$ = createNode(nSelecaoDecl, $3, $5, NULL, "if");
    }
    | T_IF T_LPAREN expressao T_RPAREN statement T_ELSE statement {
        $$ = createNode(nSelecaoDecl, $3, $5, $7, "if-else");
    }
    ;

iteracao_decl
    : T_WHILE T_LPAREN expressao T_RPAREN statement {
        $$ = createNode(nIteracaoDecl, $3, $5, NULL, "while");
    }
    ;

retorno_decl
    : T_RETURN T_SEMI {
        $$ = createNode(nRetornoDecl, NULL, NULL, NULL, "return");
    }
    | T_RETURN expressao T_SEMI {
        $$ = createNode(nRetornoDecl, $2, NULL, NULL, "return");
    }
    ;

expressao
    : var T_ATRB expressao {
        $$ = createNode(nExpressao, $1, $3, NULL, "=");
    }
    | simples_expressao {
        $$ = $1;
    }
    ;

var
    : T_ID { $$ = createNode(nVar, NULL, NULL, NULL, strdup($<string>1)); }
    | T_ID T_LSQBRA expressao T_RSQBRA { $$ = createNode(nVar, NULL, $3, NULL, strdup($<string>1)); }
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
    : T_LT {
        $$ = createNode(nRelacional, NULL, NULL, NULL, "<");
    }
    | T_LTE {
        $$ = createNode(nRelacional, NULL, NULL, NULL, "<=");
    }
    | T_GT {
        $$ = createNode(nRelacional, NULL, NULL, NULL, ">");
    }
    | T_GTE {
        $$ = createNode(nRelacional, NULL, NULL, NULL, ">=");
    }
    | T_EQ {
        $$ = createNode(nRelacional, NULL, NULL, NULL, "==");
    }
    | T_NEQ {
        $$ = createNode(nRelacional, NULL, NULL, NULL, "!=");
    }
    ;

soma_expressao
    : soma_expressao T_PLUS termo {
        $$ = createNode(nSomaExpressao, $1, $3, NULL, "+");
    }
    | soma_expressao T_MINUS termo {
        $$ = createNode(nSomaExpressao, $1, $3, NULL, "-");
    }
    | termo {
        $$ = $1;
    }
    ;

termo
    : termo T_MULT fator {
        $$ = createNode(nTermo, $1, $3, NULL, "*");
    }
    | termo T_DIV fator {
        $$ = createNode(nTermo, $1, $3, NULL, "/");
    }
    | fator {
        $$ = $1;
    }
    ;

fator
    : T_LPAREN expressao T_RPAREN { $$ = createNode(nFator, $2, NULL, NULL, NULL); }
    | var { $$ = $1; }
    | ativacao { $$ = $1; }
    | T_NUM { $$ = createNode(nFator, NULL, NULL, NULL, strdup($<string>1)); }
    ;

ativacao
    : T_ID T_LPAREN args T_RPAREN { $$ = createNode(nAtivacao, NULL, NULL, NULL, strdup($<string>1)); }
    ;

args
    : arg_lista { $$ = $1; }
    | /* empty */ { $$ = createNode(nArgs, NULL, NULL, NULL, NULL); }
    ;

arg_lista
    : arg_lista T_COMMA expressao { $$ = createNode(nArgLista, $1, $3, NULL, NULL); }
    | expressao { $$ = createNode(nArgLista, $1, NULL, NULL, NULL); }
    ;


%%
void yyerror(char *s){
    fprintf(stderr, "Error: Semantical Problem on '%s' at line %d\n", s, currentTokenLine);
}

int yylex(){
    int token;
    Analysis *info = createGNT(&lex, buffer, file);
    Analysis *temp = info;

    temp = get_next_token(info);
    token = temp->lex->token;
    
    // Configurar yylval com base no token reconhecido
    switch(token) {
        case T_NUM:
            yylval.num = atoi(temp->lex->name); // supondo que T_NUM seja um número inteiro
            break;
        case T_ID:
            yylval.string = strdup(temp->lex->name); // você precisará liberar essa memória mais tarde
            break;
        // Adicionar cases para outros tokens que carregam valores
    }

    // Atualizar informações de linha do token, se o Bison precisar delas
    currentTokenLine = temp->lex->line;
    
    info = temp;

    return token;
}

%%