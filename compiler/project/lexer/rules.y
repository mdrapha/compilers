%{

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funcs.h"

int yylex();
int yyparse();
void yyerror(char *s);

%}

%token ID NUM
%token INT VOID
%token IF ELSE WHILE RETURN
%token PLUS MINUS TIMES DIVIDE ASSIGN
%token EQUAL NEQUAL LT GT LTE GTE
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET SEMI COMMA

%start programa

%%

programa
    : declaracao_lista
    ;

declaracao_lista
    : declaracao_lista declaracao
    | declaracao
    ;

declaracao
    : var_declaracao
    | fun_declaracao
    ;

var_declaracao
    : tipo_especificador ID SEMI
    | tipo_especificador ID LBRACKET NUM RBRACKET SEMI
    ;

tipo_especificador
    : INT
    | VOID
    ;

fun_declaracao
    : tipo_especificador ID LPAREN params RPAREN composto_decl
    ;

params
    : param_lista
    | VOID
    ;

param_lista
    : param_lista COMMA param
    | param
    ;

param
    : tipo_especificador ID
    | tipo_especificador ID LBRACKET RBRACKET
    ;

composto_decl
    : LBRACE local_declaracoes statement_lista RBRACE
    ;

local_declaracoes
    : local_declaracoes var_declaracao
    | /* empty */
    ;

statement_lista
    : statement_lista statement
    | /* empty */
    ;

statement
    : expressao_decl
    | composto_decl
    | selecao_decl
    | iteracao_decl
    | retorno_decl
    ;

expressao_decl
    : expressao SEMI
    | SEMI
    ;

selecao_decl
    : IF LPAREN expressao RPAREN statement
    | IF LPAREN expressao RPAREN statement ELSE statement
    ;

iteracao_decl
    : WHILE LPAREN expressao RPAREN statement
    ;

retorno_decl
    : RETURN SEMI
    | RETURN expressao SEMI
    ;

expressao
    : var ASSIGN expressao
    | simples_expressao
    ;

var
    : ID
    | ID LBRACKET expressao RBRACKET
    ;

simples_expressao
    : soma_expressao relacional soma_expressao
    | soma_expressao
    ;

relacional
    : LT
    | LTE
    | GT
    | GTE
    | EQUAL
    | NEQUAL
    ;

soma_expressao
    : soma_expressao PLUS termo
    | soma_expressao MINUS termo
    | termo
    ;

termo
    : termo TIMES fator
    | termo DIVIDE fator
    | fator
    ;

fator
    : LPAREN expressao RPAREN
    | var
    | ativacao
    | NUM
    ;

ativacao
    : ID LPAREN args RPAREN
    ;

args
    : arg_lista
    | /* empty */
    ;

arg_lista
    : arg_lista COMMA expressao
    | expressao
    ;

%%
void yyerror(char *s){
    fprintf(stderr, "Error: Semantical Problem on: %s\n", s);
}

int yylex(){
    int token;
    Analysis *info = createAnalyser(&lex, buffer, file);
    Analysis *temp = info;

        temp = analyser(info);
        token= *temp->lex->token;
        strcpy(lexema,*temp->lex->name);
        actualLine=*temp->lex->line;
        info = temp;
    
    return token;
}

%%