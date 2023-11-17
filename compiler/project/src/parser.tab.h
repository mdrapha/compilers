/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_ID = 258,                    /* T_ID  */
    T_NUM = 259,                   /* T_NUM  */
    T_INT = 260,                   /* T_INT  */
    T_VOID = 261,                  /* T_VOID  */
    T_IF = 262,                    /* T_IF  */
    T_ELSE = 263,                  /* T_ELSE  */
    T_WHILE = 264,                 /* T_WHILE  */
    T_RETURN = 265,                /* T_RETURN  */
    T_PLUS = 266,                  /* T_PLUS  */
    T_MINUS = 267,                 /* T_MINUS  */
    T_MULT = 268,                  /* T_MULT  */
    T_DIV = 269,                   /* T_DIV  */
    T_ATRB = 270,                  /* T_ATRB  */
    T_EQ = 271,                    /* T_EQ  */
    T_NEQ = 272,                   /* T_NEQ  */
    T_LT = 273,                    /* T_LT  */
    T_GT = 274,                    /* T_GT  */
    T_LTE = 275,                   /* T_LTE  */
    T_GTE = 276,                   /* T_GTE  */
    T_LPAREN = 277,                /* T_LPAREN  */
    T_RPAREN = 278,                /* T_RPAREN  */
    T_LBRACE = 279,                /* T_LBRACE  */
    T_RBRACE = 280,                /* T_RBRACE  */
    T_LSQBRA = 281,                /* T_LSQBRA  */
    T_RSQBRA = 282,                /* T_RSQBRA  */
    T_SEMI = 283,                  /* T_SEMI  */
    T_COMMA = 284,                 /* T_COMMA  */
    LOWER_THAN_ELSE = 285          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "parser.y"

    TreeNode *node;
    char *string;
    int line;
    int num;

#line 101 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
