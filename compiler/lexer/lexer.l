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
{enter} {current_line++;  analyser(lex, yytext, ENTER, current_line); continue;}
{num} {analyser(lex ,yytext, NUM, current_line);}
{id} {analyser(lex, yytext, ID, current_line);}
<<EOF>> {return 0;}
{comment} {continue;}
{RPAREN} {analyser(lex, yytext, RPAREN, current_line);}
{LPAREN} {analyser(lex, yytext, LPAREN, current_line);}
{LBRACE} {analyser(lex, yytext, LBRACE, current_line);}
{RBRACE} {analyser(lex, yytext, RBRACE, current_line);}
{LBRACK} {analyser(lex, yytext, LBRACK, current_line);}
{OPERATOR} {analyser(lex, yytext, OPERATOR, current_line);}
{SPACE} {analyser(lex, yytext, SPACE, current_line);}
{HASHTAG} {analyser(lex, yytext, HASHTAG, current_line);}
{RBRACK} {analyser(lex, yytext, RBRACK, current_line);}
{SEMI} {analyser(lex, yytext, SEMI, current_line);}
{ATRB} {analyser(lex, yytext, ATRB, current_line);}
{COMMA} {analyser(lex, yytext, COMMA, current_line);}
{DOT} {analyser(lex, yytext, DOT, current_line);}
{LT} {analyser(lex, yytext, LT, current_line);}
{LTE} {analyser(lex, yytext, LTE, current_line);}
{GT} {analyser(lex, yytext, GT, current_line);}
{GTE} {analyser(lex, yytext, GTE, current_line);}
{QUOTE} {analyser(lex, yytext, QUOTE, current_line);}
{EQ} {analyser(lex, yytext, EQ, current_line);}
{NEQ} {analyser(lex, yytext, NEQ, current_line);}


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


