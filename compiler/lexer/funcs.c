#include "funcs.h"

void analyser(Lexemes lexeme, char* word, int token_type, int line) {
    lexeme.lex = (char *)malloc(sizeof(char) * MAX_S);
    strcpy(lexeme.lex, word);
    lexeme.type = token_type;
    lexeme.line = line;

    if(lexeme.type == ID)
    {
        if(strcmp(lexeme.lex, "if") == 0){
            lexeme.type = IF;
        }
        else if(strcmp(lexeme.lex, "else") == 0){
            lexeme.type = ELSE;
        }
        else if(strcmp(lexeme.lex, "while") == 0){
            lexeme.type = WHILE;
        }
        else if(strcmp(lexeme.lex, "return") == 0){
            lexeme.type = RETURN;
        }
        else if(strcmp(lexeme.lex, "int") == 0){
            lexeme.type = INT;
        }
        else if(strcmp(lexeme.lex, "void") == 0){
            lexeme.type = VOID;
        }
    }
    else if(lexeme.type == OPERATOR)
    {
        if(strcmp(lexeme.lex, "+") == 0){
            lexeme.type = PLUS;
        }
        else if(strcmp(lexeme.lex, "-") == 0){
            lexeme.type = MINUS;
        }
        else if(strcmp(lexeme.lex, "*") == 0){
            lexeme.type = MULT;
        }
        else if(strcmp(lexeme.lex, "/") == 0){
            lexeme.type = DIV;
        }
    }
    if(lexeme.type != COMMENT && lexeme.type != SPACE && lexeme.type != ENTER)
        print_lexeme(lexeme);
 }

char* get_token_name(int token_type){
    switch(token_type)
    {
        case ID:
            return "ID";
        case NUM:
            return "NUM";
        case IF:
            return "IF";
        case ELSE:
            return "ELSE";
        case WHILE:
            return "WHILE";
        case RETURN:
            return "RETURN";
        case INT:
            return "INT";
        case VOID:
            return "VOID";
        case PLUS:
            return "PLUS";
        case MINUS:
            return "MINUS";
        case MULT:
            return "MULT";
        case DIV:
            return "DIV";
        case LT:
            return "LT";
        case LTE:
            return "LTE";
        case GT:
            return "GT";
        case GTE:
            return "GTE";
        case EQ:
            return "EQ";
        case NEQ:
            return "NEQ";
        case ASSIGN:
            return "ASSIGN";
        case SEMI:
            return "SEMI";
        case COMMA:
            return "COMMA";
        case LPAREN:
            return "LPAREN";
        case RPAREN:
            return "RPAREN";
        case LBRACK:    
            return "LBRACK";
        case RBRACK:
            return "RBRACK";
        case LBRACE:
            return "LBRACE";
        case RBRACE:
            return "RBRACE";
        case COMMENT:
            return "COMMENT";
        case ERROR:
            return "ERROR";
        case ENDFILE:
            return "ENDFILE";
        case OPERATOR:
            return "OPERATOR";
        case ATRB:
            return "ATRB";
        case HASHTAG:
            return "HASHTAG";
        case SPACE:
            return "SPACE";
        case DOT:
            return "DOT";
        case ENTER:
            return "ENTER";
        case QUOTE:
            return "QUOTE";
        default:
            return "ERROR";
    }
}

void print_lexeme(Lexemes lexeme) {
    printf("Lexeme: %s\t", lexeme.lex);
    printf("Type: %s\t", get_token_name(lexeme.type));
    printf("Line: %d\n", lexeme.line);
}

void initLexeme(Lexemes lexeme) {
    lexeme.lex = (char *)malloc(sizeof(char) * MAX_S);
    lexeme.type = 0;
    lexeme.line = 0;
}

void free_lexeme(Lexemes lexeme) {
    free(lexeme.lex);
}
