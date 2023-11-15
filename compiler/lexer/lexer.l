%{
    #include "funcs.h"

    Lexemes lex;

    int current_line = 1;
    int lexeme_size = 0;
%}

num [0-9]+
id [a-zA-Z][a-zA-Z0-9]*
enter \n
comment \/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+\/
RPAREN \)
LPAREN \(
LBRACE \{
RBRACE \}
LBRACK \[
RBRACK \]
SEMI \;
COMMA \,
OPERATOR \+|\-|\*|\/
HASHTAG \#
SPACE [ \t]+
ATRB =
LT <
LTE <=
GT >
GTE >=
EQ ==
NEQ !=
DOT \.
QUOTE \"


%%
{enter} {current_line++;  get_next_token(lex, yytext, ENTER, current_line); continue;}
{num} {get_next_token(lex ,yytext, NUM, current_line);}
{id} {get_next_token(lex, yytext, ID, current_line);}
<<EOF>> {return 0;}
{comment} {continue;}
{RPAREN} {get_next_token(lex, yytext, RPAREN, current_line);}
{LPAREN} {get_next_token(lex, yytext, LPAREN, current_line);}
{LBRACE} {get_next_token(lex, yytext, LBRACE, current_line);}
{RBRACE} {get_next_token(lex, yytext, RBRACE, current_line);}
{LBRACK} {get_next_token(lex, yytext, LBRACK, current_line);}
{OPERATOR} {get_next_token(lex, yytext, OPERATOR, current_line);}
{SPACE} {get_next_token(lex, yytext, SPACE, current_line);}
{HASHTAG} {get_next_token(lex, yytext, HASHTAG, current_line);}
{RBRACK} {get_next_token(lex, yytext, RBRACK, current_line);}
{SEMI} {get_next_token(lex, yytext, SEMI, current_line);}
{ATRB} {get_next_token(lex, yytext, ATRB, current_line);}
{COMMA} {get_next_token(lex, yytext, COMMA, current_line);}
{DOT} {get_next_token(lex, yytext, DOT, current_line);}
{LT} {get_next_token(lex, yytext, LT, current_line);}
{LTE} {get_next_token(lex, yytext, LTE, current_line);}
{GT} {get_next_token(lex, yytext, GT, current_line);}
{GTE} {get_next_token(lex, yytext, GTE, current_line);}
{QUOTE} {get_next_token(lex, yytext, QUOTE, current_line);}
{EQ} {get_next_token(lex, yytext, EQ, current_line);}
{NEQ} {get_next_token(lex, yytext, NEQ, current_line);}


%%

int main(int argc, char **argv) {
    FILE *fp;
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }
    initLexeme(lex);
    yyin = fp;
    yylex();
    fclose(fp);
    free_lexeme(lex);
    return 0;
}


