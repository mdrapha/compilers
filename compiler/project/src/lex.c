#include "../include/globals.h"

int transition_table[28][22] = {
    {S_ID, S_NUM, S_PLUS, S_MINUS, S_MULT, S_DIV, S_LT, S_GT, S_ATRB, S_SEMI, S_COMMA, S_LPAREN, S_RPAREN, S_LBRACE, S_RBRACE, S_LSQBRA, S_RSQBRA, S_EXCLAMATION, S_SPACE, S_ENTER, S_EOF, S_ERROR},
    {S_ID, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S_EOF, S_ERROR},
    {S0, S_NUM, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S_EOF, S_ERROR},
    {S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S_EOF, S_ERROR},
    {S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S_EOF, S_ERROR},
    {S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S_EOF, S_ERROR},
    {S0, S0, S0, S0, S_BCOMMENT, S0 , S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S_EOF, S_ERROR},
    {S0, S0, S0, S0, S0, S0, S0, S0, S_LTE, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S_EOF, S_ERROR},
    {S0, S0, S0, S0, S0, S0, S0, S0, S_GTE, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S_EOF, S_ERROR},
    {S0, S0, S0, S0, S0, S0, S0, S0, S_EQ, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S_EOF, S_ERROR},
    {S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S_EOF, S_ERROR},
    {S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S_EOF, S_ERROR},
    {S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S_EOF, S_ERROR},
    {S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S_EOF, S_ERROR},
    {S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S_EOF, S_ERROR},
    {S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S_EOF, S_ERROR},
    {S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S_EOF, S_ERROR},
    {S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S_EOF, S_ERROR},
    {S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S_EOF, S_ERROR},
    {S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S_EOF, S_ERROR},
    {S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S_EOF, S_ERROR},
    {S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S_EOF, S_ERROR},
    {S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S_EOF, S_ERROR},
    {S_BCOMMENT, S_BCOMMENT, S_BCOMMENT, S_BCOMMENT, S_ECOMMENT, S_BCOMMENT, S_BCOMMENT , S_BCOMMENT, S_BCOMMENT, S_BCOMMENT, S_BCOMMENT, S_BCOMMENT, S_BCOMMENT, S_BCOMMENT, S_BCOMMENT, S_BCOMMENT, S_BCOMMENT, S_BCOMMENT, S_BCOMMENT, S_BCOMMENT, S_EOF, S_BCOMMENT},
    {S_BCOMMENT, S_BCOMMENT, S_BCOMMENT, S_BCOMMENT, S_BCOMMENT, S0, S_BCOMMENT, S_BCOMMENT, S_BCOMMENT, S_BCOMMENT, S_BCOMMENT, S_BCOMMENT, S_BCOMMENT, S_BCOMMENT, S_BCOMMENT, S_BCOMMENT, S_BCOMMENT, S_BCOMMENT, S_BCOMMENT, S_BCOMMENT, S_EOF, S_BCOMMENT},
    {S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S_EOF, S_ERROR},
    {S0, S0, S0, S0, S0, S0, S0, S0, S_DIFF, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S0, S_EOF, S_ERROR},
    {S_ERROR, S_ERROR, S_ERROR, S_ERROR, S_ERROR, S_ERROR, S_ERROR, S_ERROR, S_ERROR, S_ERROR, S_ERROR, S_ERROR, S_ERROR, S_ERROR, S_ERROR, S_ERROR, S_ERROR, S_ERROR, S_ERROR, S_ERROR, S_ERROR, S_ERROR},
};

int progress_table[28][22] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Function to convert a string to a numerical hash
unsigned long int hasher(const char *word) {
    unsigned int hash = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        hash = (hash * 31) + word[i];
    }
    return hash;
}

// Function to convert a string to a numerical token
int char_to_token(char c)
{
    if(isalpha(c)){
        return LETTER;
    }else if(isdigit(c)){
        return DIGIT;
    }else{
        switch (c)
        {
        case '+':
            return PLUS;
            break;

        case '-':
            return MINUS;
            break;            

        case '*':
            return MULT;
            break;
        
        case '/':
            return DIV;
            break;

        case '<':
            return LT;
            break;
        
        case '>':
            return GT;
            break;

        case '=':
            return ATRB;
            break;
        
        case ';':
            return SEMI;
            break;
        
        case ',':
            return COMMA;
            break;

        case '(':
            return LPAREN;
            break;
        
        case ')':
            return RPAREN;
            break;

        case '{':
            return LBRACE;
            break;

        case '}':
            return RBRACE;
            break;

        case '[':
            return LSQBRA;
            break;
        
        case ']':   
            return RSQBRA;
            break;

        case '!':
            return EXCLA;
            break;

        case ' ':
            return SPACE;
            break;

        case '\n':
            return ENTER;
            break;

        case EOF:
            return ENDFILE;
            break;

        default:
            return OTHER;
            break;
        }
    }
}

// Function to convert a token to a string
char *get_char_pretoken_name(int token)
{
    switch (token)
    {
    case LETTER:
        return "LETTER";
        break;
    
    case DIGIT:
        return "DIGIT";
        break;

    case PLUS:
        return "PLUS";
        break;

    case MINUS:
        return "MINUS";
        break;
    
    case MULT:
        return "MULT";
        break;

    case DIV:
        return "DIV";
        break;

    case LT:
        return "LT";
        break;

    case GT:
        return "GT";
        break;

    case ATRB:
        return "ATRB";
        break;

    case SEMI:
        return "SEMI";
        break;

    case LPAREN:
        return "LPAREN";
        break;

    case RPAREN:
        return "RPAREN";
        break;

    case LBRACE:
        return "LBRACE";
        break;

    case RBRACE:
        return "RBRACE";
        break;

    case LSQBRA:
        return "LSQBRA";
        break;

    case RSQBRA:
        return "RSQBRA";
        break;

    case EXCLA:
        return "EXCLA";
        break;

    case SPACE:
        return "SPACE";
        break;

    case ENTER:
        return "ENTER";
        break;

    case ENDFILE:
        return "ENDFILE";
        break;

    case OTHER:
        return "OTHER";
        break;

    default:
        return "ERROR";
        break;
    }
}

// Function to verify if a token is a reserved word
int get_id_token(char *name){
    long int hash = hasher(name);
    switch (hash)
    {
        case 104431 : // int
            return T_INT;
            break;
        
        case 3625364 : // void
            return T_VOID;
            break;

        case 3357 : // if
            return T_IF;
            break;
        
        case 3116345 : // else
            return T_ELSE;
            break;

        case 113101617 : // while
            return T_WHILE;
            break;
        
        case 3360570672 : // return
            return T_RETURN;
            break;

        default:
            return T_ID;
            break;
    }
}

// Function to get the next state
int get_next_state(int state, int token)
{

    return transition_table[state][token];
}

// Function to get the progress
int get_progress(int state, int token)
{
    return progress_table[state][token];
}