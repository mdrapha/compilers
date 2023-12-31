/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/globals.h"

int scopeCounter = 0; // Counter for the current scope
void yyerror(char *s);
char *tostring(int num);
extern int yylex();

#line 85 "parser.tab.c"

#ifndef YY_CAST
#ifdef __cplusplus
#define YY_CAST(Type, Val) static_cast<Type>(Val)
#define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type>(Val)
#else
#define YY_CAST(Type, Val) ((Type)(Val))
#define YY_REINTERPRET_CAST(Type, Val) ((Type)(Val))
#endif
#endif
#ifndef YY_NULLPTR
#if defined __cplusplus
#if 201103L <= __cplusplus
#define YY_NULLPTR nullptr
#else
#define YY_NULLPTR 0
#endif
#else
#define YY_NULLPTR ((void *)0)
#endif
#endif

#include "../include/parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,               /* "end of file"  */
  YYSYMBOL_YYerror = 1,             /* error  */
  YYSYMBOL_YYUNDEF = 2,             /* "invalid token"  */
  YYSYMBOL_T_ID = 3,                /* T_ID  */
  YYSYMBOL_T_NUM = 4,               /* T_NUM  */
  YYSYMBOL_T_INT = 5,               /* T_INT  */
  YYSYMBOL_T_VOID = 6,              /* T_VOID  */
  YYSYMBOL_T_IF = 7,                /* T_IF  */
  YYSYMBOL_T_ELSE = 8,              /* T_ELSE  */
  YYSYMBOL_T_WHILE = 9,             /* T_WHILE  */
  YYSYMBOL_T_RETURN = 10,           /* T_RETURN  */
  YYSYMBOL_T_PLUS = 11,             /* T_PLUS  */
  YYSYMBOL_T_MINUS = 12,            /* T_MINUS  */
  YYSYMBOL_T_MULT = 13,             /* T_MULT  */
  YYSYMBOL_T_DIV = 14,              /* T_DIV  */
  YYSYMBOL_T_ATRB = 15,             /* T_ATRB  */
  YYSYMBOL_T_EQ = 16,               /* T_EQ  */
  YYSYMBOL_T_NEQ = 17,              /* T_NEQ  */
  YYSYMBOL_T_LT = 18,               /* T_LT  */
  YYSYMBOL_T_GT = 19,               /* T_GT  */
  YYSYMBOL_T_LTE = 20,              /* T_LTE  */
  YYSYMBOL_T_GTE = 21,              /* T_GTE  */
  YYSYMBOL_T_LPAREN = 22,           /* T_LPAREN  */
  YYSYMBOL_T_RPAREN = 23,           /* T_RPAREN  */
  YYSYMBOL_T_LBRACE = 24,           /* T_LBRACE  */
  YYSYMBOL_T_RBRACE = 25,           /* T_RBRACE  */
  YYSYMBOL_T_LSQBRA = 26,           /* T_LSQBRA  */
  YYSYMBOL_T_RSQBRA = 27,           /* T_RSQBRA  */
  YYSYMBOL_T_SEMI = 28,             /* T_SEMI  */
  YYSYMBOL_T_COMMA = 29,            /* T_COMMA  */
  YYSYMBOL_LOWER_THAN_ELSE = 30,    /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 31,           /* $accept  */
  YYSYMBOL_programa = 32,           /* programa  */
  YYSYMBOL_declaracao_lista = 33,   /* declaracao_lista  */
  YYSYMBOL_declaracao = 34,         /* declaracao  */
  YYSYMBOL_var_declaracao = 35,     /* var_declaracao  */
  YYSYMBOL_tipo_especificador = 36, /* tipo_especificador  */
  YYSYMBOL_fun_declaracao = 37,     /* fun_declaracao  */
  YYSYMBOL_fun_id = 38,             /* fun_id  */
  YYSYMBOL_params = 39,             /* params  */
  YYSYMBOL_param_lista = 40,        /* param_lista  */
  YYSYMBOL_param = 41,              /* param  */
  YYSYMBOL_composto_decl = 42,      /* composto_decl  */
  YYSYMBOL_local_declaracoes = 43,  /* local_declaracoes  */
  YYSYMBOL_statement_lista = 44,    /* statement_lista  */
  YYSYMBOL_statement = 45,          /* statement  */
  YYSYMBOL_expressao_decl = 46,     /* expressao_decl  */
  YYSYMBOL_selecao_decl = 47,       /* selecao_decl  */
  YYSYMBOL_iteracao_decl = 48,      /* iteracao_decl  */
  YYSYMBOL_retorno_decl = 49,       /* retorno_decl  */
  YYSYMBOL_expressao = 50,          /* expressao  */
  YYSYMBOL_var = 51,                /* var  */
  YYSYMBOL_simples_expressao = 52,  /* simples_expressao  */
  YYSYMBOL_relacional = 53,         /* relacional  */
  YYSYMBOL_soma_expressao = 54,     /* soma_expressao  */
  YYSYMBOL_termo = 55,              /* termo  */
  YYSYMBOL_fator = 56,              /* fator  */
  YYSYMBOL_ativacao = 57,           /* ativacao  */
  YYSYMBOL_args = 58,               /* args  */
  YYSYMBOL_arg_lista = 59           /* arg_lista  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;

#ifdef short
#undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
#include <limits.h> /* INFRINGES ON USER NAME SPACE */
#if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#define YY_STDINT_H
#endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
#undef UINT_LEAST8_MAX
#undef UINT_LEAST16_MAX
#define UINT_LEAST8_MAX 255
#define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
#if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#define YYPTRDIFF_T __PTRDIFF_TYPE__
#define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
#elif defined PTRDIFF_MAX
#ifndef ptrdiff_t
#include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#endif
#define YYPTRDIFF_T ptrdiff_t
#define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
#else
#define YYPTRDIFF_T long
#define YYPTRDIFF_MAXIMUM LONG_MAX
#endif
#endif

#ifndef YYSIZE_T
#ifdef __SIZE_TYPE__
#define YYSIZE_T __SIZE_TYPE__
#elif defined size_t
#define YYSIZE_T size_t
#elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#define YYSIZE_T size_t
#else
#define YYSIZE_T unsigned
#endif
#endif

#define YYSIZE_MAXIMUM                               \
  YY_CAST(YYPTRDIFF_T,                               \
          (YYPTRDIFF_MAXIMUM < YY_CAST(YYSIZE_T, -1) \
               ? YYPTRDIFF_MAXIMUM                   \
               : YY_CAST(YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST(YYPTRDIFF_T, sizeof(X))

/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
#if defined YYENABLE_NLS && YYENABLE_NLS
#if ENABLE_NLS
#include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#define YY_(Msgid) dgettext("bison-runtime", Msgid)
#endif
#endif
#ifndef YY_
#define YY_(Msgid) Msgid
#endif
#endif

#ifndef YY_ATTRIBUTE_PURE
#if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#define YY_ATTRIBUTE_PURE __attribute__((__pure__))
#else
#define YY_ATTRIBUTE_PURE
#endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
#if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#define YY_ATTRIBUTE_UNUSED __attribute__((__unused__))
#else
#define YY_ATTRIBUTE_UNUSED
#endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if !defined lint || defined __GNUC__
#define YY_USE(E) ((void)(E))
#else
#define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && !defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
#if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
  _Pragma("GCC diagnostic push")            \
      _Pragma("GCC diagnostic ignored \"-Wuninitialized\"")
#else
#define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                 \
  _Pragma("GCC diagnostic push")                            \
      _Pragma("GCC diagnostic ignored \"-Wuninitialized\"") \
          _Pragma("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
#endif
#define YY_IGNORE_MAYBE_UNINITIALIZED_END \
  _Pragma("GCC diagnostic pop")
#else
#define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
#define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
#define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
#define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && !defined __ICC && 6 <= __GNUC__
#define YY_IGNORE_USELESS_CAST_BEGIN \
  _Pragma("GCC diagnostic push")     \
      _Pragma("GCC diagnostic ignored \"-Wuseless-cast\"")
#define YY_IGNORE_USELESS_CAST_END \
  _Pragma("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
#define YY_IGNORE_USELESS_CAST_BEGIN
#define YY_IGNORE_USELESS_CAST_END
#endif

#define YY_ASSERT(E) ((void)(0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

#ifdef YYSTACK_USE_ALLOCA
#if YYSTACK_USE_ALLOCA
#ifdef __GNUC__
#define YYSTACK_ALLOC __builtin_alloca
#elif defined __BUILTIN_VA_ARG_INCR
#include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#elif defined _AIX
#define YYSTACK_ALLOC __alloca
#elif defined _MSC_VER
#include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#define alloca _alloca
#else
#define YYSTACK_ALLOC alloca
#if !defined _ALLOCA_H && !defined EXIT_SUCCESS
#include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
/* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
#endif
#endif
#endif
#endif

#ifdef YYSTACK_ALLOC
/* Pacify GCC's 'empty if-body' warning.  */
#define YYSTACK_FREE(Ptr) \
  do                      \
  { /* empty */           \
    ;                     \
  } while (0)
#ifndef YYSTACK_ALLOC_MAXIMUM
/* The OS might guarantee only one guard page at the bottom of the stack,
   and a page size can be as small as 4096 bytes.  So we cannot safely
   invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
   to allow for a few compiler-allocated temporary stack slots.  */
#define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#endif
#else
#define YYSTACK_ALLOC YYMALLOC
#define YYSTACK_FREE YYFREE
#ifndef YYSTACK_ALLOC_MAXIMUM
#define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#endif
#if (defined __cplusplus && !defined EXIT_SUCCESS && !((defined YYMALLOC || defined malloc) && (defined YYFREE || defined free)))
#include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
#endif
#ifndef YYMALLOC
#define YYMALLOC malloc
#if !defined malloc && !defined EXIT_SUCCESS
void *malloc(YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#endif
#endif
#ifndef YYFREE
#define YYFREE free
#if !defined free && !defined EXIT_SUCCESS
void free(void *); /* INFRINGES ON USER NAME SPACE */
#endif
#endif
#endif
#endif /* !defined yyoverflow */

#if (!defined yyoverflow && (!defined __cplusplus || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
#define YYSTACK_GAP_MAXIMUM (YYSIZEOF(union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
#define YYSTACK_BYTES(N) \
  ((N) * (YYSIZEOF(yy_state_t) + YYSIZEOF(YYSTYPE)) + YYSTACK_GAP_MAXIMUM)

#define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
#define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
  do                                                                   \
  {                                                                    \
    YYPTRDIFF_T yynewbytes;                                            \
    YYCOPY(&yyptr->Stack_alloc, Stack, yysize);                        \
    Stack = &yyptr->Stack_alloc;                                       \
    yynewbytes = yystacksize * YYSIZEOF(*Stack) + YYSTACK_GAP_MAXIMUM; \
    yyptr += yynewbytes / YYSIZEOF(*yyptr);                            \
  } while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
#ifndef YYCOPY
#if defined __GNUC__ && 1 < __GNUC__
#define YYCOPY(Dst, Src, Count) \
  __builtin_memcpy(Dst, Src, YY_CAST(YYSIZE_T, (Count)) * sizeof(*(Src)))
#else
#define YYCOPY(Dst, Src, Count)         \
  do                                    \
  {                                     \
    YYPTRDIFF_T yyi;                    \
    for (yyi = 0; yyi < (Count); yyi++) \
      (Dst)[yyi] = (Src)[yyi];          \
  } while (0)
#endif
#endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL 9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST 99

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS 31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS 29
/* YYNRULES -- Number of rules.  */
#define YYNRULES 62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES 104

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK 285

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                            \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                 \
       ? YY_CAST(yysymbol_kind_t, yytranslate[YYX]) \
       : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
    {
        0, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 1, 2, 3, 4,
        5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
        15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
        25, 26, 27, 28, 29, 30};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
    {
        0, 44, 44, 51, 60, 66, 69, 75, 88, 108,
        115, 124, 147, 158, 162, 174, 182, 189, 204, 222,
        242, 250, 257, 265, 272, 275, 278, 281, 284, 291,
        295, 302, 312, 327, 343, 353, 367, 379, 386, 395,
        410, 416, 423, 430, 436, 442, 448, 454, 464, 473,
        482, 489, 496, 503, 509, 516, 519, 522, 532, 545,
        549, 555, 564};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST(yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name(yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
    {
        "\"end of file\"", "error", "\"invalid token\"", "T_ID", "T_NUM",
        "T_INT", "T_VOID", "T_IF", "T_ELSE", "T_WHILE", "T_RETURN", "T_PLUS",
        "T_MINUS", "T_MULT", "T_DIV", "T_ATRB", "T_EQ", "T_NEQ", "T_LT", "T_GT",
        "T_LTE", "T_GTE", "T_LPAREN", "T_RPAREN", "T_LBRACE", "T_RBRACE",
        "T_LSQBRA", "T_RSQBRA", "T_SEMI", "T_COMMA", "LOWER_THAN_ELSE",
        "$accept", "programa", "declaracao_lista", "declaracao",
        "var_declaracao", "tipo_especificador", "fun_declaracao", "fun_id",
        "params", "param_lista", "param", "composto_decl", "local_declaracoes",
        "statement_lista", "statement", "expressao_decl", "selecao_decl",
        "iteracao_decl", "retorno_decl", "expressao", "var", "simples_expressao",
        "relacional", "soma_expressao", "termo", "fator", "ativacao", "args",
        "arg_lista", YY_NULLPTR};

static const char *
yysymbol_name(yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-92)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-15)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
    {
        46, -92, -92, 14, 46, -92, -92, 20, -92, -92,
        -92, 15, 22, 13, -92, 53, 45, 19, 70, 51,
        47, -92, 49, 52, 56, 46, -92, 48, -92, -92,
        -92, -92, 46, -92, 76, 3, 15, 27, -92, 59,
        60, 12, -1, -92, -92, 61, -92, -92, -92, -92,
        -92, -92, 57, 69, -92, 44, -5, -92, -92, -1,
        -1, -1, -92, 58, 64, -1, -92, -1, -1, -1,
        -92, -92, -92, -92, -92, -92, -1, -1, -1, 62,
        65, 67, -92, -92, -92, 68, 63, -92, -92, -5,
        -5, 55, -92, -92, -92, 26, 26, -92, -1, 85,
        -92, -92, 26, -92};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
    {
        0, 9, 10, 0, 2, 4, 5, 0, 6, 1,
        3, 12, 0, 0, 7, 0, 0, 10, 0, 0,
        13, 16, 0, 17, 0, 0, 8, 0, 21, 11,
        15, 18, 23, 20, 0, 0, 0, 38, 57, 0,
        0, 0, 0, 19, 30, 0, 25, 22, 24, 26,
        27, 28, 0, 55, 37, 41, 50, 53, 56, 0,
        0, 0, 34, 0, 0, 60, 29, 0, 0, 0,
        46, 47, 42, 44, 43, 45, 0, 0, 0, 0,
        0, 0, 35, 54, 62, 0, 59, 36, 55, 48,
        49, 40, 51, 52, 39, 0, 0, 58, 0, 31,
        33, 61, 0, 32};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
    {
        -92, -92, -92, 90, 66, 7, -92, 88, -92, -92,
        71, 73, -92, -92, -91, -92, -92, -92, -92, -41,
        -31, -92, -92, 23, 0, -7, -92, -92, -92};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
    {
        0, 3, 4, 5, 6, 7, 8, 45, 19, 20,
        21, 46, 32, 35, 47, 48, 49, 50, 51, 52,
        53, 54, 76, 55, 56, 57, 58, 85, 86};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
    {
        63, 64, 37, 38, 99, 100, 37, 38, 77, 78,
        39, 103, 40, 41, 9, 37, 38, 16, 79, 80,
        81, 42, 18, 11, 84, 42, 87, 28, 43, 37,
        38, 44, 18, 39, 42, 40, 41, 88, 88, 34,
        62, 13, -14, 14, 15, 88, 88, 88, 42, -12,
        28, 1, 2, 59, 44, 68, 69, 101, 1, 17,
        70, 71, 72, 73, 74, 75, 68, 69, 89, 90,
        92, 93, 22, 23, 24, 31, 25, 26, 27, 36,
        28, 60, 61, 65, 67, 66, 82, 83, 95, 94,
        96, 97, 98, 102, 10, 12, 30, 29, 33, 91};

static const yytype_int8 yycheck[] =
    {
        41, 42, 3, 4, 95, 96, 3, 4, 13, 14,
        7, 102, 9, 10, 0, 3, 4, 4, 59, 60,
        61, 22, 15, 3, 65, 22, 67, 24, 25, 3,
        4, 28, 25, 7, 22, 9, 10, 68, 69, 32,
        28, 26, 23, 28, 22, 76, 77, 78, 22, 22,
        24, 5, 6, 26, 28, 11, 12, 98, 5, 6,
        16, 17, 18, 19, 20, 21, 11, 12, 68, 69,
        77, 78, 27, 3, 23, 27, 29, 28, 26, 3,
        24, 22, 22, 22, 15, 28, 28, 23, 23, 27,
        23, 23, 29, 8, 4, 7, 25, 24, 32, 76};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
    {
        0, 5, 6, 32, 33, 34, 35, 36, 37, 0,
        34, 3, 38, 26, 28, 22, 4, 6, 36, 39,
        40, 41, 27, 3, 23, 29, 28, 26, 24, 42,
        41, 27, 43, 35, 36, 44, 3, 3, 4, 7,
        9, 10, 22, 25, 28, 38, 42, 45, 46, 47,
        48, 49, 50, 51, 52, 54, 55, 56, 57, 26,
        22, 22, 28, 50, 50, 22, 28, 15, 11, 12,
        16, 17, 18, 19, 20, 21, 53, 13, 14, 50,
        50, 50, 28, 23, 50, 58, 59, 50, 51, 55,
        55, 54, 56, 56, 27, 23, 23, 23, 29, 45,
        45, 50, 8, 45};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
    {
        0, 31, 32, 33, 33, 34, 34, 35, 35, 36,
        36, 37, 38, 39, 39, 40, 40, 41, 41, 42,
        43, 43, 44, 44, 45, 45, 45, 45, 45, 46,
        46, 47, 47, 48, 49, 49, 50, 50, 51, 51,
        52, 52, 53, 53, 53, 53, 53, 53, 54, 54,
        54, 55, 55, 55, 56, 56, 56, 56, 57, 58,
        58, 59, 59};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
    {
        0, 2, 1, 2, 1, 1, 1, 3, 6, 1,
        1, 6, 1, 1, 1, 3, 1, 2, 4, 4,
        2, 0, 2, 0, 1, 1, 1, 1, 1, 2,
        1, 5, 7, 5, 2, 3, 3, 1, 1, 4,
        3, 1, 1, 1, 1, 1, 1, 1, 3, 3,
        1, 3, 3, 1, 3, 1, 1, 1, 4, 1,
        0, 3, 1};

enum
{
  YYENOMEM = -2
};

#define yyerrok (yyerrstatus = 0)
#define yyclearin (yychar = YYEMPTY)

#define YYACCEPT goto yyacceptlab
#define YYABORT goto yyabortlab
#define YYERROR goto yyerrorlab
#define YYNOMEM goto yyexhaustedlab

#define YYRECOVERING() (!!yyerrstatus)

#define YYBACKUP(Token, Value)                      \
  do                                                \
    if (yychar == YYEMPTY)                          \
    {                                               \
      yychar = (Token);                             \
      yylval = (Value);                             \
      YYPOPSTACK(yylen);                            \
      yystate = *yyssp;                             \
      goto yybackup;                                \
    }                                               \
    else                                            \
    {                                               \
      yyerror(YY_("syntax error: cannot back up")); \
      YYERROR;                                      \
    }                                               \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* Enable debugging if requested.  */
#if YYDEBUG

#ifndef YYFPRINTF
#include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#define YYFPRINTF fprintf
#endif

#define YYDPRINTF(Args) \
  do                    \
  {                     \
    if (yydebug)        \
      YYFPRINTF Args;   \
  } while (0)

#define YY_SYMBOL_PRINT(Title, Kind, Value, Location) \
  do                                                  \
  {                                                   \
    if (yydebug)                                      \
    {                                                 \
      YYprintf("%s ", Title);                \
      yy_symbol_print(stderr,                         \
                      Kind, Value);                   \
      YYprintf("\n");                        \
    }                                                 \
  } while (0)

/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print(FILE *yyo,
                      yysymbol_kind_t yykind, YYSTYPE const *const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE(yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE(yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}

/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print(FILE *yyo,
                yysymbol_kind_t yykind, YYSTYPE const *const yyvaluep)
{
  YYFPRINTF(yyo, "%s %s (",
            yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name(yykind));

  yy_symbol_value_print(yyo, yykind, yyvaluep);
  YYFPRINTF(yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print(yy_state_t *yybottom, yy_state_t *yytop)
{
  YYprintf("Stack now");
  for (; yybottom <= yytop; yybottom++)
  {
    int yybot = *yybottom;
    YYprintf(" %d", yybot);
  }
  YYprintf("\n");
}

#define YY_STACK_PRINT(Bottom, Top)    \
  do                                   \
  {                                    \
    if (yydebug)                       \
      yy_stack_print((Bottom), (Top)); \
  } while (0)

/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print(yy_state_t *yyssp, YYSTYPE *yyvsp,
                int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYprintf("Reducing stack by rule %d (line %d):\n",
            yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
  {
    YYprintf("   $%d = ", yyi + 1);
    yy_symbol_print(stderr,
                    YY_ACCESSING_SYMBOL(+yyssp[yyi + 1 - yynrhs]),
                    &yyvsp[(yyi + 1) - (yynrhs)]);
    YYprintf("\n");
  }
}

#define YY_REDUCE_PRINT(Rule)              \
  do                                       \
  {                                        \
    if (yydebug)                           \
      yy_reduce_print(yyssp, yyvsp, Rule); \
  } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
#define YYDPRINTF(Args) ((void)0)
#define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
#define YY_STACK_PRINT(Bottom, Top)
#define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
#define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct(const char *yymsg,
           yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE(yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT(yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE(yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}

/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;

/*----------.
| yyparse.  |
`----------*/

int yyparse(void)
{
  yy_state_fast_t yystate = 0;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus = 0;

  /* Refer to the stacks through separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* Their size.  */
  YYPTRDIFF_T yystacksize = YYINITDEPTH;

  /* The state stack: array, bottom, top.  */
  yy_state_t yyssa[YYINITDEPTH];
  yy_state_t *yyss = yyssa;
  yy_state_t *yyssp = yyss;

  /* The semantic value stack: array, bottom, top.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#define YYPOPSTACK(N) (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF((stderr, "Entering state %d\n", yystate));
  YY_ASSERT(0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST(yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT(yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
  {
    /* Get the current used size of the three stacks, in elements.  */
    YYPTRDIFF_T yysize = yyssp - yyss + 1;

#if defined yyoverflow
    {
      /* Give user a chance to reallocate the stack.  Use copies of
         these so that the &'s don't force the real ones into
         memory.  */
      yy_state_t *yyss1 = yyss;
      YYSTYPE *yyvs1 = yyvs;

      /* Each stack pointer address is followed by the size of the
         data in use in that stack, in bytes.  This used to be a
         conditional around just the two extra args, but that might
         be undefined if yyoverflow is a macro.  */
      yyoverflow(YY_("memory exhausted"),
                 &yyss1, yysize * YYSIZEOF(*yyssp),
                 &yyvs1, yysize * YYSIZEOF(*yyvsp),
                 &yystacksize);
      yyss = yyss1;
      yyvs = yyvs1;
    }
#else /* defined YYSTACK_RELOCATE */
    /* Extend the stack our own way.  */
    if (YYMAXDEPTH <= yystacksize)
      YYNOMEM;
    yystacksize *= 2;
    if (YYMAXDEPTH < yystacksize)
      yystacksize = YYMAXDEPTH;

    {
      yy_state_t *yyss1 = yyss;
      union yyalloc *yyptr =
          YY_CAST(union yyalloc *,
                  YYSTACK_ALLOC(YY_CAST(YYSIZE_T, YYSTACK_BYTES(yystacksize))));
      if (!yyptr)
        YYNOMEM;
      YYSTACK_RELOCATE(yyss_alloc, yyss);
      YYSTACK_RELOCATE(yyvs_alloc, yyvs);
#undef YYSTACK_RELOCATE
      if (yyss1 != yyssa)
        YYSTACK_FREE(yyss1);
    }
#endif

    yyssp = yyss + yysize - 1;
    yyvsp = yyvs + yysize - 1;

    YY_IGNORE_USELESS_CAST_BEGIN
    YYDPRINTF((stderr, "Stack size increased to %ld\n",
               YY_CAST(long, yystacksize)));
    YY_IGNORE_USELESS_CAST_END

    if (yyss + yystacksize - 1 <= yyssp)
      YYABORT;
  }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default(yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
  {
    YYDPRINTF((stderr, "Reading a token\n"));
    yychar = yylex();
  }

  if (yychar <= YYEOF)
  {
    yychar = YYEOF;
    yytoken = YYSYMBOL_YYEOF;
    YYDPRINTF((stderr, "Now at end of input.\n"));
  }
  else if (yychar == YYerror)
  {
    /* The scanner already issued an error message, process directly
       to error recovery.  But do not keep the error token as
       lookahead, it is too special and may lead us to an endless
       loop in error recovery. */
    yychar = YYUNDEF;
    yytoken = YYSYMBOL_YYerror;
    goto yyerrlab1;
  }
  else
  {
    yytoken = YYTRANSLATE(yychar);
    YY_SYMBOL_PRINT("Next token is", yytoken, &yylval, &yylloc);
  }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
  {
    if (yytable_value_is_error(yyn))
      goto yyerrlab;
    yyn = -yyn;
    goto yyreduce;
  }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;

/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;

/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1 - yylen];

  YY_REDUCE_PRINT(yyn);
  switch (yyn)
  {
  case 2: /* programa: declaracao_lista  */
#line 44 "parser.y"
  {
    parseTree = (yyvsp[0].node);
  }
#line 1203 "parser.tab.c"
  break;

  case 3: /* declaracao_lista: declaracao_lista declaracao  */
#line 51 "parser.y"
  {
    if ((yyvsp[-1].node) != NULL)
    {
      (yyval.node) = (yyvsp[-1].node);
      addNode(&(yyvsp[-1].node), (yyvsp[0].node), -1); // Add as sibling
    }
    else
    {
      (yyval.node) = (yyvsp[0].node);
    }
  }
#line 1217 "parser.tab.c"
  break;

  case 4: /* declaracao_lista: declaracao  */
#line 60 "parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1225 "parser.tab.c"
  break;

  case 5: /* declaracao: var_declaracao  */
#line 66 "parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
    (yyval.node)->nodeType = nVarDeclaracao; // Defining the node type as a variable declaration
  }
#line 1233 "parser.tab.c"
  break;

  case 6: /* declaracao: fun_declaracao  */
#line 69 "parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1241 "parser.tab.c"
  break;

  case 7: /* var_declaracao: tipo_especificador T_ID T_SEMI  */
#line 75 "parser.y"
  {
    (yyval.node) = (yyvsp[-2].node);
    (yyval.node)->type = T_ID;               // Defining the type as an identifier
    (yyval.node)->nodeType = nTipoEspecificador; // Defining the node type as a variable declaration
    (yyval.node)->lineNumber = currentTokenLine;
    (yyval.node)->isDecl = 1; // Defining the node type as a variable declaration
    (yyval.node)->isUsage = 0; // Defining the node type as a variable declaration
    (yyval.node)->isFunction = 0; // Defining the node type as a function declaration
    (yyval.node)->isArray = 0; // Defining the node type as a array declaration
    (yyval.node)->isParam = 0; // Defining the node type as a array declaration

    TreeNode *aux = newNode();
    strcpy(aux->lexeme, get_id_from_stack()); // Assuming the identifier is the first child
    aux->type = T_ID;
    aux->lineNumber = currentTokenLine;
    aux->nodeType = nVarDeclaracao; // Defining the node type as a variable declaration
    aux->isDecl = 1; // Defining the node type as a variable declaration
    addNode(&(yyval.node), aux, 0);  // Add aux as the first child
    addNode(&(yyval.node), (yyvsp[0].node), 1); // Add the type specifier as the second child

  }
#line 1259 "parser.tab.c"
  break;

  case 8: /* var_declaracao: tipo_especificador T_ID T_LSQBRA T_NUM T_RSQBRA T_SEMI  */
#line 88 "parser.y"
  {
    (yyval.node) = (yyvsp[-5].node);
    (yyval.node)->lineNumber = currentTokenLine;
    (yyval.node)->nodeType = nTipoEspecificador; // Define o tipo do nó como declaração de variável
    (yyval.node)->isDecl = 1; // Defining the node type as a variable declaration
    (yyval.node)->isUsage = 0; // Defining the node type as a variable declaration
    (yyval.node)->isFunction = 0; // Defining the node type as a function declaration
    (yyval.node)->isArray = 1; // Defining the node type as a array declaration
    (yyval.node)->isParam = 0; // Defining the node type as a array declaration
  

    TreeNode *aux1 = newNode();
    
    strcpy(aux1->lexeme, get_id_from_stack()); // Assume que armazena o nome da variável
    aux1->type = T_ID;
    aux1->lineNumber = currentTokenLine;
    aux1->nodeType = nVarArrDecl; // Defining the node type as a variable declaration
    aux1->isDecl = 1; // Defining the node type as a variable declaration
    aux1->isArray = 1; // Defining the node type as a array declaration

    TreeNode *aux2 = newNode();
    aux2->type = T_NUM;
    strcpy(aux2->lexeme, tostring(get_num_from_stack()));
    aux1->ArraySize=atoi(aux2->lexeme);
    //printf("Array size: %d\n",aux1->ArraySize);
    aux2->nodeType= nValue; // Defining the node type as a variable declaration
    aux2->lineNumber = currentTokenLine;
    addNode(&(yyval.node), aux2, 1); // Adiciona aux2 como o segundo filho
    addNode(&(yyval.node), aux1, 0);           // Adiciona aux como o primeiro filho


  }
#line 1282 "parser.tab.c"
  break;

  case 9: /* tipo_especificador: T_INT  */
#line 108 "parser.y"
  {
    (yyval.node) = newNode();
    (yyval.node)->type = T_INT;                  // Assuming T_INT is the token type for "int"
    (yyval.node)->nodeType = nTipoEspecificador; // Defining the node type as a type specifier
    strcpy((yyval.node)->lexeme, "int");         // Set lexeme to "int"
    (yyval.node)->lineNumber = currentTokenLine;

    addNode(&(yyval.node), (yyvsp[0].node), 0); // Adiciona o identificador como o primeiro filho
  }
#line 1294 "parser.tab.c"
  break;

  case 10: /* tipo_especificador: T_VOID  */
#line 115 "parser.y"
  {
    (yyval.node) = newNode();
    (yyval.node)->type = T_VOID; // Assuming T_VOID is the token type for "void"
    strcpy((yyval.node)->lexeme, "void");
    (yyval.node)->lineNumber = currentTokenLine;

    addNode(&(yyval.node), (yyvsp[0].node), 0); // Adiciona o identificador como o primeiro filho
  }
#line 1305 "parser.tab.c"
  break;

  case 11: /* fun_declaracao: tipo_especificador fun_id T_LPAREN params T_RPAREN composto_decl  */
#line 124 "parser.y"
  {
    (yyval.node) = (yyvsp[-5].node);                // O especificador de tipo torna-se o nó raiz para a declaração da função
    (yyval.node)->type = currentTokenType;          // Assume que T_FUN é o tipo de token para declarações de função
    (yyval.node)->lineNumber = currentTokenLine;    // Define o número da linha
    (yyval.node)->nodeType = nTipoEspecificador;        // Define o tipo do nó como declaração de função
    (yyval.node)->isDecl = 1; // Defining the node type as a variable declaration
    (yyval.node)->isUsage = 0; // Defining the node type as a variable declaration
    (yyval.node)->isFunction = 1; // Defining the node type as a function declaration
    (yyval.node)->isArray = 0; // Defining the node type as a array declaration
    (yyval.node)->isParam = 0; // Defining the node type as a array declaration

    addNode(&(yyval.node), (yyvsp[-4].node), 1);    // Adiciona identificador da função como o primeiro filho
    addNode(&(yyval.node), (yyvsp[-2].node), 0);    // Adiciona parâmetros como o segundo filho
    addNode(&(yyvsp[-4].node), (yyvsp[0].node), 0); // Adiciona declaração composta como filho do identificador da função
  }
#line 1330 "parser.tab.c"
  break;

  case 12: /* fun_id: T_ID  */
#line 147 "parser.y"
  {
    (yyval.node) = newNode();
    (yyval.node)->nodeType = nFunDeclaracao;        // Define o tipo do nó como declaração de função
    (yyval.node)->type = T_ID;                         // Assume que T_ID é o tipo de token para identificadores
    strcpy((yyval.node)->lexeme, get_id_from_stack()); // Copia o lexema do identificador
    (yyval.node)->isUsage = 0; // Defining the node type as a variable declaration
    (yyval.node)->lineNumber = currentTokenLine;

    

    addNode(&(yyval.node), (yyvsp[0].node), 0); // Adiciona o identificador como o primeiro filho
  }
#line 1342 "parser.tab.c"
  break;

  case 13: /* params: param_lista  */
#line 158 "parser.y"
  {
    (yyval.node) = (yyvsp[0].node); // Directly use the parameter list node
  }
#line 1351 "parser.tab.c"
  break;

  case 14: /* params: T_VOID  */
#line 162 "parser.y"
  {
    (yyval.node) = newNode();
    (yyval.node)->type = T_VOID;          // Assuming T_VOID is the token type for "void"
    strcpy((yyval.node)->lexeme, "void"); // Set lexeme to "void"
    (yyval.node)->lineNumber = currentTokenLine;
    (yyval.node)->nodeType = nParam;
  }
#line 1364 "parser.tab.c"
  break;

  case 15: /* param_lista: param_lista T_COMMA param  */
#line 174 "parser.y"
  {
    if ((yyvsp[-2].node) != NULL)
    {
      addNode(&(yyvsp[-2].node), (yyvsp[0].node), -1); // Add $3 as a sibling to $1
      (yyval.node) = (yyvsp[-2].node);                 // The first parameter list node is the root of the list
    }
    else
    {
      (yyval.node) = (yyvsp[0].node); // If $1 is NULL, use $3 as the start of the list
    }
  }
#line 1377 "parser.tab.c"
  break;

  case 16: /* param_lista: param  */
#line 182 "parser.y"
  {
    (yyval.node) = (yyvsp[0].node); // For a single parameter, just use the parameter node
  }
#line 1385 "parser.tab.c"
  break;

  case 17: /* param: tipo_especificador T_ID  */
#line 189 "parser.y"
  {
    (yyval.node) = newNode();
    (yyval.node)->type = T_ID;
    (yyval.node)->lineNumber = currentTokenLine;
    (yyval.node)->nodeType = nParam;

    TreeNode *tipoEspecificadorNode = (yyvsp[-1].node); // Capturando o nó tipo_especificador
    TreeNode *idNode = newNode();                       // Criando um novo nó para o identificador
    strcpy(idNode->lexeme, get_id_from_stack());
    idNode->lineNumber = currentTokenLine;
    idNode->type = T_ID;
    idNode->nodeType = nVarDeclaracao;
    idNode->isDecl = 1; // Defining the node type as a variable declaration

    addNode(&(yyval.node), tipoEspecificadorNode, 0); // Adiciona o tipo_especificador como primeiro filho
    addNode(&(yyval.node), idNode, 1);                // Adiciona o identificador como segundo filho
  }
#line 1404 "parser.tab.c"
  break;

  case 18: /* param: tipo_especificador T_ID T_LSQBRA T_RSQBRA  */
#line 204 "parser.y"
  {
    (yyval.node) = newNode();
    (yyval.node)->type = T_ID;
    (yyval.node)->lineNumber = currentTokenLine;
    (yyval.node)->isDecl = 1;
    (yyval.node)->isArray = 1;
    (yyval.node)->isParam = 1;
    (yyval.node)->isUsage = 0;
    (yyval.node)->isFunction = 0;
    (yyval.node)->nodeType = nParam;

    TreeNode *tipoEspecificadorNode = (yyvsp[-3].node); // Capturando o nó tipo_especificador
    tipoEspecificadorNode->nodeType = nTipoEspecificador;
    TreeNode *idNode = newNode();                       // Criando um novo nó para o identificador
    strcpy(idNode->lexeme, get_id_from_stack());
    idNode->lineNumber = currentTokenLine;
    idNode->type = T_ID;
    idNode->nodeType = nVarArrDecl;
    idNode->isDecl = 1; // Defining the node type as a variable declaration
    idNode->isArray = 1;

    addNode(&(yyval.node), tipoEspecificadorNode, 0); // Adiciona o tipo_especificador como primeiro filho
    addNode(&(yyval.node), idNode, 1);                // Adiciona o identificador como segundo filho
  }
#line 1423 "parser.tab.c"
  break;

  case 19: /* composto_decl: T_LBRACE local_declaracoes statement_lista T_RBRACE  */
#line 222 "parser.y"
  {
    (yyval.node) = newNode();                    // Create a new node for the compound declaration
    (yyval.node)->type = T_LBRACE;               // Assuming T_LBRACE represents a compound declaration
    (yyval.node)->lineNumber = currentTokenLine; // Set the line number
    (yyval.node)->nodeType = nCompostoDecl;

    if ((yyvsp[-2].node) != NULL)
    {
      //(yyval.node)= (yyvsp[-2].node);

      addNode(&(yyval.node), (yyvsp[-2].node), 1); // Add local declarations as the first child
      (yyval.node) = (yyvsp[-2].node);
    }
    if ((yyvsp[-1].node) != NULL)
    {
      //(yyval.node) = (yyvsp[-1].node); // Add statements as the second child
      addNode(&(yyval.node), (yyvsp[-1].node), -1); // Add local declarations as the first child
      //(yyval.node) = (yyvsp[-1].node);

    }
  }
#line 1445 "parser.tab.c"
  break;

  case 20: /* local_declaracoes: local_declaracoes var_declaracao  */
#line 242 "parser.y"
  {
    if ((yyvsp[-1].node) != NULL)
    {
      addNode(&(yyvsp[-1].node), (yyvsp[0].node), -1); // Add $2 as a sibling to $1
      (yyval.node) = (yyvsp[-1].node);                 // The first local declarations node remains the root
    }
    else
    {
      (yyval.node) = (yyvsp[0].node); // If $1 is NULL, use $2 as the start of the list
    }
  }
#line 1458 "parser.tab.c"
  break;

  case 21: /* local_declaracoes: %empty  */
#line 250 "parser.y"
  {
    (yyval.node) = NULL; // For an empty production, set $$ to NULL
  }
#line 1466 "parser.tab.c"
  break;

  case 22: /* statement_lista: statement_lista statement  */
#line 257 "parser.y"
  {
    if ((yyvsp[-1].node) != NULL)
    {
      addNode(&(yyvsp[-1].node), (yyvsp[0].node), -1); // Add $2 as a sibling to $1
      (yyval.node) = (yyvsp[-1].node);                 // The first statement list node remains the root
    }
    else
    {
      (yyval.node) = (yyvsp[0].node); // If $1 is NULL, use $2 as the start of the list
    }
  }
#line 1479 "parser.tab.c"
  break;

  case 23: /* statement_lista: %empty  */
#line 265 "parser.y"
  {
    (yyval.node) = NULL; // For an empty production, set $$ to NULL
  }
#line 1487 "parser.tab.c"
  break;

  case 24: /* statement: expressao_decl  */
#line 272 "parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1495 "parser.tab.c"
  break;

  case 25: /* statement: composto_decl  */
#line 275 "parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1503 "parser.tab.c"
  break;

  case 26: /* statement: selecao_decl  */
#line 278 "parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1511 "parser.tab.c"
  break;

  case 27: /* statement: iteracao_decl  */
#line 281 "parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1519 "parser.tab.c"
  break;

  case 28: /* statement: retorno_decl  */
#line 284 "parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1527 "parser.tab.c"
  break;

  case 29: /* expressao_decl: expressao T_SEMI  */
#line 291 "parser.y"
  {
    (yyval.node) = (yyvsp[-1].node); // The result is the expression's subtree
  }
#line 1535 "parser.tab.c"
  break;

  case 30: /* expressao_decl: T_SEMI  */
#line 295 "parser.y"
  {
    (yyval.node) = NULL; // Representing an empty statement with NULL
  }
#line 1543 "parser.tab.c"
  break;

  case 31: /* selecao_decl: T_IF T_LPAREN expressao T_RPAREN statement  */
#line 302 "parser.y"
  {
    (yyval.node) = newNode();
    (yyval.node)->type = T_IF; // Defining the type as an if statement
    strcpy((yyval.node)->lexeme, "if");
    (yyval.node)->lineNumber = currentTokenLine;
    (yyval.node)->nodeType = nSelecaoDecl;

    addNode(&(yyval.node), (yyvsp[-2].node), 0); // Add the expression as the first child
    addNode(&(yyval.node), (yyvsp[0].node), 1);  // Add the statement as the second child
  }
#line 1558 "parser.tab.c"
  break;

  case 32: /* selecao_decl: T_IF T_LPAREN expressao T_RPAREN statement T_ELSE statement  */
#line 312 "parser.y"
  {
    (yyval.node) = newNode();
    (yyval.node)->type = T_IF; // Defining the type as an if statement
    strcpy((yyval.node)->lexeme, "if");
    (yyval.node)->lineNumber = currentTokenLine;
    (yyval.node)->nodeType = nSelecaoDecl;

    addNode(&(yyval.node), (yyvsp[-4].node), 0); // Add the expression as the first child
    addNode(&(yyval.node), (yyvsp[-2].node), 1); // Add the statement as the second child

    // Create a new node for the "else" part
    TreeNode *elseNode = newNode();
    strcpy(elseNode->lexeme, "else");
    elseNode->nodeType = nSelecaoDecl;
    elseNode->type = T_ELSE;
    elseNode->lineNumber = currentTokenLine;

    addNode(&(yyval.node), elseNode, 2);      // Add the "else" part as the third child
    addNode(&(elseNode), (yyvsp[0].node), 0); // Add the statement after "else" as a child of the "else" node
  }
#line 1574 "parser.tab.c"
  break;

  case 33: /* iteracao_decl: T_WHILE T_LPAREN expressao T_RPAREN statement  */
#line 327 "parser.y"
  {
    (yyval.node) = newNode();
    (yyval.node)->type = T_WHILE;          // Assuming T_WHILE is the token type for "while" loops
    strcpy((yyval.node)->lexeme, "while"); // Set lexeme to "WHILE"
    (yyval.node)->lineNumber = currentTokenLine;
    (yyval.node)->nodeType = nIteracaoDecl;

    addNode(&(yyval.node), (yyvsp[-2].node), 0); // Add the expression as the first child
    addNode(&(yyval.node), (yyvsp[0].node), 1);  // Add the statement as the second child
  }
#line 1590 "parser.tab.c"
  break;

  case 34: /* retorno_decl: T_RETURN T_SEMI  */
#line 343 "parser.y"
  {
    (yyval.node) = newNode();
    (yyval.node)->type = T_RETURN;              // Assuming T_RETURN is the token type for "return"
    strcpy((yyval.node)->lexeme, "return_void"); // Set lexeme to "return_void"
    (yyval.node)->lineNumber = currentTokenLine;
    (yyval.node)->nodeType = nRetornoDecl;

    addNode(&(yyval.node), NULL, 0); // Add a NULL child to represent the expression
  }
#line 1604 "parser.tab.c"
  break;

  case 35: /* retorno_decl: T_RETURN expressao T_SEMI  */
#line 353 "parser.y"
  {
    (yyval.node) = newNode();
    (yyval.node)->type = T_RETURN;             // Assuming T_RETURN is the token type for "return"
    strcpy((yyval.node)->lexeme, "return_int"); // Set lexeme to "return_int"
    (yyval.node)->lineNumber = currentTokenLine;
    (yyval.node)->nodeType = nRetornoDecl;

    addNode(&(yyval.node), (yyvsp[-1].node), 0); // Add the expression as the first child
  }
#line 1620 "parser.tab.c"
  break;

  case 36: /* expressao: var T_ATRB expressao  */
#line 367 "parser.y"
  {
    (yyval.node) = newNode();
    (yyval.node)->type = T_ATRB; // Assuming T_ATRB is the token type for assignment operator
    (yyval.node)->lineNumber = currentTokenLine;
    (yyval.node)->nodeType = nAtrb;
    addNode(&(yyval.node), (yyvsp[-2].node), 0); // Add the variable as the first child
    addNode(&(yyval.node), (yyvsp[0].node), 1);  // Add the expression as the second child
  }
#line 1636 "parser.tab.c"
  break;

  case 37: /* expressao: simples_expressao  */
#line 379 "parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1645 "parser.tab.c"
  break;

  case 38: /* var: T_ID  */
#line 386 "parser.y"
  {
    (yyval.node) = newNode();
    (yyval.node)->type = T_ID;                         // Assuming T_ID is the token type for identifiers
    strcpy((yyval.node)->lexeme, get_id_from_stack()); // Copy the identifier's lexeme
    (yyval.node)->lineNumber = currentTokenLine;
    (yyval.node)->nodeType = nVar;
    (yyval.node)->isDecl = 0; // Defining the node type as a variable declaration
    (yyval.node)->isUsage = 1; // Defining the node type as a variable declaration
    (yyval.node)->isFunction = 0; // Defining the node type as a function declaration
    (yyval.node)->isArray = 0; // Defining the node type as a array declaration
    (yyval.node)->isParam = 0; // Defining the node type as a array declaration

    //addNode(&(yyval.node), (yyvsp[0].node), 0); // Add a NULL child to represent the index expression
    addNode(&(yyval.node), NULL, 0); // Add a NULL child to represent the index expression
  }
#line 1658 "parser.tab.c"
  break;

  case 39: /* var: T_ID T_LSQBRA expressao T_RSQBRA  */
#line 395 "parser.y"
  {
    (yyval.node) = newNode();
    (yyval.node)->type = T_ID;                         // Assuming T_ID is used for array identifiers as well
    (yyval.node)->isUsage = 1;                          // Defining the node type as a variable
    strcpy((yyval.node)->lexeme, get_id_from_stack()); // Copy the identifier's lexeme
    (yyval.node)->lineNumber = currentTokenLine;
    (yyval.node)->nodeType = nVarArr;
    (yyval.node)->isDecl = 0; // Defining the node type as a variable declaration
    (yyval.node)->isUsage = 1; // Defining the node type as a variable declaration
    (yyval.node)->isFunction = 0; // Defining the node type as a function declaration
    (yyval.node)->isArray = 1; // Defining the node type as a array declaration
    (yyval.node)->isParam = 0; // Defining the node type as a parameter declaration

    addNode(&(yyval.node), (yyvsp[-2].node), 0); // Add the index expression as the first child
    addNode(&(yyval.node), (yyvsp[-1].node), 0); // Add the index expression as the first child
  }
#line 1674 "parser.tab.c"
  break;

  case 40: /* simples_expressao: soma_expressao relacional soma_expressao  */
#line 410 "parser.y"
  {
    (yyval.node) = (yyvsp[-1].node); // Use the relational operator's node as the base
    addNode(&(yyval.node), (yyvsp[-2].node), 0); // Add the first expression as the first child
    addNode(&(yyval.node), (yyvsp[0].node), 1);  // Add the second expression as the second child
  }
#line 1685 "parser.tab.c"
  break;

  case 41: /* simples_expressao: soma_expressao  */
#line 416 "parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1694 "parser.tab.c"
  break;

  case 42: /* relacional: T_LT  */
#line 423 "parser.y"
  {
    (yyval.node) = newNode();
    (yyval.node)->type = T_LT; // Defining the type as a less than operator
    (yyval.node)->lineNumber = currentTokenLine;
    (yyval.node)->nodeType = nRelacional;
    strcpy((yyval.node)->lexeme, "<"); // Set lexeme to "<"

    addNode(&(yyval.node), (yyvsp[-2].node), 0); // Add the first expression as the first child
  }
#line 1706 "parser.tab.c"
  break;

  case 43: /* relacional: T_LTE  */
#line 430 "parser.y"
  {
    (yyval.node) = newNode();
    (yyval.node)->type = T_LTE; // Defining the type as a less than or equal operator
    (yyval.node)->lineNumber = currentTokenLine;
    (yyval.node)->nodeType = nRelacional;
    strcpy((yyval.node)->lexeme, "<="); // Set lexeme to "<="

    addNode(&(yyval.node), (yyvsp[-2].node), 0); // Add the first expression as the first child
  }
#line 1717 "parser.tab.c"
  break;

  case 44: /* relacional: T_GT  */
#line 436 "parser.y"
  {
    (yyval.node) = newNode();
    (yyval.node)->type = T_GT; // Defining the type as a greater than operator
    (yyval.node)->lineNumber = currentTokenLine;
    strcpy((yyval.node)->lexeme, ">"); // Set lexeme to ">"
    (yyval.node)->nodeType = nRelacional;

    addNode(&(yyval.node), (yyvsp[-2].node), 0); // Add the first expression as the first child
  }
#line 1728 "parser.tab.c"
  break;

  case 45: /* relacional: T_GTE  */
#line 442 "parser.y"
  {
    (yyval.node) = newNode();
    (yyval.node)->type = T_GTE; // Defining the type as a greater than or equal operator
    (yyval.node)->lineNumber = currentTokenLine;
    strcpy((yyval.node)->lexeme, ">="); // Set lexeme to ">="
    (yyval.node)->nodeType = nRelacional;

    addNode(&(yyval.node), (yyvsp[-2].node), 0); // Add the first expression as the first child
  }
#line 1739 "parser.tab.c"
  break;

  case 46: /* relacional: T_EQ  */
#line 448 "parser.y"
  {
    (yyval.node) = newNode();
    (yyval.node)->type = T_EQ; // Defining the type as an equal operator
    (yyval.node)->lineNumber = currentTokenLine;
    strcpy((yyval.node)->lexeme, "=="); // Set lexeme to "=="
    (yyval.node)->nodeType = nRelacional;

    addNode(&(yyval.node), (yyvsp[-2].node), 0); // Add the first expression as the first child
  }
#line 1750 "parser.tab.c"
  break;

  case 47: /* relacional: T_NEQ  */
#line 454 "parser.y"
  {
    (yyval.node) = newNode();
    (yyval.node)->type = T_NEQ; // Defining the type as a not equal operator
    (yyval.node)->lineNumber = currentTokenLine;
    strcpy((yyval.node)->lexeme, "!="); // Set lexeme to "!="
    (yyval.node)->nodeType = nRelacional;

    addNode(&(yyval.node), (yyvsp[-2].node), 0); // Add the first expression as the first child
  }
#line 1761 "parser.tab.c"
  break;

  case 48: /* soma_expressao: soma_expressao T_PLUS termo  */
#line 464 "parser.y"
  {
    (yyval.node) = newNode();
    (yyval.node)->type = T_PLUS;       // Defining the type as an addition operator
    strcpy((yyval.node)->lexeme, "+"); // Defining the lexeme as "+"
    (yyval.node)->lineNumber = currentTokenLine;
    (yyval.node)->nodeType = nRelacional;

    addNode(&(yyval.node), (yyvsp[-2].node), 0); // Add the first expression as the first child
    addNode(&(yyval.node), (yyvsp[0].node), 1);  // Add the term as the second child
  }
#line 1775 "parser.tab.c"
  break;

  case 49: /* soma_expressao: soma_expressao T_MINUS termo  */
#line 473 "parser.y"
  {
    (yyval.node) = newNode();
    (yyval.node)->type = T_MINUS;      // Defining the type as a subtraction operator
    strcpy((yyval.node)->lexeme, "-"); // Defining the lexeme as "-"
    (yyval.node)->lineNumber = currentTokenLine;
    (yyval.node)->nodeType = nSomaExpressao;

    addNode(&(yyval.node), (yyvsp[-2].node), 0); // Add the first expression as the first child
    addNode(&(yyval.node), (yyvsp[0].node), 1);  // Add the term as the second child
  }
#line 1789 "parser.tab.c"
  break;

  case 50: /* soma_expressao: termo  */
#line 482 "parser.y"
  {
    (yyval.node) = (yyvsp[0].node); // The result is the term's subtree
  }
#line 1797 "parser.tab.c"
  break;

  case 51: /* termo: termo T_MULT fator  */
#line 489 "parser.y"
  {
    (yyval.node) = newNode();
    (yyval.node)->type = T_MULT;       // Defining the type as an operator of multiplication
    strcpy((yyval.node)->lexeme, "*"); // Defining the lexeme as "*"
    (yyval.node)->lineNumber = currentTokenLine;
    (yyval.node)->nodeType = nTermo;

    addNode(&(yyval.node), (yyvsp[-2].node), 1); // Add the first expression as the first child
    addNode(&(yyval.node), (yyvsp[0].node), 0);  // Add the term as the second child
  }
#line 1809 "parser.tab.c"
  break;

  case 52: /* termo: termo T_DIV fator  */
#line 496 "parser.y"
  {
    (yyval.node) = newNode();
    (yyval.node)->type = T_DIV;        // Defining the type as an operator of division
    strcpy((yyval.node)->lexeme, "/"); // Defining the lexeme as "/"
    (yyval.node)->lineNumber = currentTokenLine;
    (yyval.node)->nodeType = nTermo;

    addNode(&(yyval.node), (yyvsp[-2].node), 1); // Add the first expression as the first child
    addNode(&(yyval.node), (yyvsp[0].node), 0);  // Add the term as the second child
  }
#line 1821 "parser.tab.c"
  break;

  case 53: /* termo: fator  */
#line 503 "parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1829 "parser.tab.c"
  break;

  case 54: /* fator: T_LPAREN expressao T_RPAREN  */
#line 509 "parser.y"
  {
    (yyval.node) = newNode();
    (yyval.node)->nodeType = nFator;
    (yyval.node)->type = T_LPAREN; // Defining the type as a left parenthesis
    (yyval.node)->lineNumber = currentTokenLine;

    addNode(&(yyval.node), (yyvsp[-1].node), 0); // Add the expression as the first child
  }
#line 1841 "parser.tab.c"
  break;

  case 55: /* fator: var  */
#line 516 "parser.y"
  {
    (yyval.node) = (yyvsp[0].node); // The result is the variable's subtree
  }
#line 1849 "parser.tab.c"
  break;

  case 56: /* fator: ativacao  */
#line 519 "parser.y"
  {
    (yyval.node) = (yyvsp[0].node); // The result is the function call's subtree
  }
#line 1857 "parser.tab.c"
  break;

  case 57: /* fator: T_NUM  */
#line 522 "parser.y"
  {
    (yyval.node) = newNode();
    (yyval.node)->type = T_NUM;                                   // Defining the type as a number
    strcpy((yyval.node)->lexeme, tostring(get_num_from_stack())); // Defining the lexeme as the number's value
    (yyval.node)->lineNumber = currentTokenLine;
    (yyval.node)->nodeType = nValue;

    addNode(&(yyval.node), (yyvsp[0].node), 0); // Add the number as the first child
  }
#line 1868 "parser.tab.c"
  break;

  case 58: /* ativacao: fun_id T_LPAREN args T_RPAREN  */
#line 532 "parser.y"
  {
    (yyval.node) = newNode();
    (yyval.node)->nodeType = nFunCall;
    (yyval.node)->type = T_ID;                          // Defining the type as an opening parenthesis
    strcpy((yyval.node)->lexeme, (yyvsp[-3].node)->lexeme); // Copying the function identifier's lexeme
    (yyval.node)->lineNumber = currentTokenLine;            // Defining the line number as the current line
    (yyval.node)->isUsage = 1; // Defining the node type as a variable declaration

    addNode(&(yyval.node), (yyvsp[-1].node), 0); // Add the arguments as the first child
  }
#line 1883 "parser.tab.c"
  break;

  case 59: /* args: arg_lista  */
#line 545 "parser.y"
  {
    (yyval.node) = (yyvsp[0].node); // The result is the argument list's subtree
    
  }
#line 1892 "parser.tab.c"
  break;

  case 60: /* args: %empty  */
#line 549 "parser.y"
  {
    (yyval.node) = NULL; // Representing an empty argument list with NULL
  }
#line 1900 "parser.tab.c"
  break;

  case 61: /* arg_lista: arg_lista T_COMMA expressao  */
#line 555 "parser.y"
  {
    if ((yyvsp[-2].node) != NULL)
    {
      (yyval.node) = (yyvsp[-2].node); // Keep the first argument list node as the root
      addNode(&(yyval.node), (yyvsp[0].node), -1); // Add the expression as a sibling to the first argument list node
    }
    else
    {
      (yyval.node) = (yyvsp[0].node); // If $1 is NULL, use $3 as the start of the list
    }
  }
#line 1914 "parser.tab.c"
  break;

  case 62: /* arg_lista: expressao  */
#line 564 "parser.y"
  {
    (yyval.node) = (yyvsp[0].node); // For a single argument, just use the expression's subtree
  }
#line 1923 "parser.tab.c"
  break;

#line 1927 "parser.tab.c"

  default:
    break;
  }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT("-> $$ =", YY_CAST(yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK(yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
                   ? yytable[yyi]
                   : yydefgoto[yylhs]);
  }

  goto yynewstate;

/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE(yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
  {
    ++yynerrs;
    yyerror(YY_("syntax error"));
  }

  if (yyerrstatus == 3)
  {
    /* If just tried and failed to reuse lookahead token after an
       error, discard it.  */

    if (yychar <= YYEOF)
    {
      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        YYABORT;
    }
    else
    {
      yydestruct("Error: discarding",
                 yytoken, &yylval);
      yychar = YYEMPTY;
    }
  }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;

/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK(yylen);
  yylen = 0;
  YY_STACK_PRINT(yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;

/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3; /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
  {
    yyn = yypact[yystate];
    if (!yypact_value_is_default(yyn))
    {
      yyn += YYSYMBOL_YYerror;
      if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
      {
        yyn = yytable[yyn];
        if (0 < yyn)
          break;
      }
    }

    /* Pop the current state because it cannot handle the error token.  */
    if (yyssp == yyss)
      YYABORT;

    yydestruct("Error: popping",
               YY_ACCESSING_SYMBOL(yystate), yyvsp);
    YYPOPSTACK(1);
    yystate = *yyssp;
    YY_STACK_PRINT(yyss, yyssp);
  }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Shift the error token.  */
  YY_SYMBOL_PRINT("Shifting", YY_ACCESSING_SYMBOL(yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;

/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;

/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror(YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;

/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
  {
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = YYTRANSLATE(yychar);
    yydestruct("Cleanup: discarding lookahead",
               yytoken, &yylval);
  }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK(yylen);
  YY_STACK_PRINT(yyss, yyssp);
  while (yyssp != yyss)
  {
    yydestruct("Cleanup: popping",
               YY_ACCESSING_SYMBOL(+*yyssp), yyvsp);
    YYPOPSTACK(1);
  }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE(yyss);
#endif

  return yyresult;
}

#line 573 "parser.y"

void yyerror(char *s)
{
  // Setting printf to background red and text white bold
  printf("\033[1;37;41m");

  switch (currentToken)
  {
  case T_ID:
    printf("\033[1;37;41m");
    printf("Error: Syntax Problem at line %d -- Unexpected ID %s --", currentTokenLine, s);
    // Setting printf color to default
    printf("\033[0m");
    break;

  case T_NUM:
    printf("Error: Syntax Problem at line %d -- Unexpected NUM %s", currentTokenLine, s);
    // Setting printf color to default
    printf("\033[0m");
    break;

  case T_PLUS:
    printf("Error: Syntax Problem at line %d -- Unexpected '+'", currentTokenLine);
    // Setting printf color to default
    printf("\033[0m");
    break;

  case T_MINUS:
    printf("Error: Syntax Problem at line %d -- Unexpected '-'", currentTokenLine);
    // Setting printf color to default
    printf("\033[0m");
    break;

  case T_MULT:
    printf("Error: Syntax Problem at line %d -- Unexpected '*'", currentTokenLine);
    // Setting printf color to default
    printf("\033[0m");
    break;

  case T_DIV:
    printf("Error: Syntax Problem at line %d -- Unexpected '/'", currentTokenLine);
    // Setting printf color to default
    printf("\033[0m");
    break;

  case T_IF:
    printf("Error: Syntax Problem at line %d -- Unexpected 'if'", currentTokenLine);
    // Setting printf color to default
    printf("\033[0m");
    break;

  case T_ELSE:
    printf("Error: Syntax Problem at line %d -- Unexpected 'else'", currentTokenLine);
    // Setting printf color to default
    printf("\033[0m");
    break;

  case T_WHILE:
    printf("Error: Syntax Problem at line %d -- Unexpected 'while'", currentTokenLine);
    // Setting printf color to default
    printf("\033[0m");
    break;

  case T_RETURN:
    printf("Error: Syntax Problem at line %d -- Unexpected 'return'", currentTokenLine);
    // Setting printf color to default
    printf("\033[0m");
    break;

  case T_LT:
    printf("Error: Syntax Problem at line %d -- Unexpected '<'", currentTokenLine);
    // Setting printf color to default
    printf("\033[0m");
    break;

  case T_LTE:
    printf("Error: Syntax Problem at line %d -- Unexpected '<='", currentTokenLine);
    // Setting printf color to default
    printf("\033[0m");
    break;

  case T_GT:
    printf("Error: Syntax Problem at line %d -- Unexpected '>'", currentTokenLine);
    // Setting printf color to default
    printf("\033[0m");
    break;

  case T_GTE:
    printf("Error: Syntax Problem at line %d -- Unexpected '>='", currentTokenLine);
    // Setting printf color to default
    printf("\033[0m");
    break;

  case T_EQ:
    printf("Error: Syntax Problem at line %d -- Unexpected '=='", currentTokenLine);
    // Setting printf color to default
    printf("\033[0m");
    break;

  case T_NEQ:
    printf("Error: Syntax Problem at line %d -- Unexpected '!='", currentTokenLine);
    // Setting printf color to default
    printf("\033[0m");
    break;

  case T_ATRB:
    printf("Error: Syntax Problem at line %d -- Unexpected '='", currentTokenLine);
    // Setting printf color to default
    printf("\033[0m");
    break;

  case T_LPAREN:
    printf("Error: Syntax Problem at line %d -- Unexpected '('", currentTokenLine);
    // Setting printf color to default
    printf("\033[0m");
    break;

  case T_RPAREN:
    printf("Error: Syntax Problem at line %d -- Unexpected ')'", currentTokenLine);
    // Setting printf color to default
    printf("\033[0m");
    break;

  case T_LBRACE:
    printf("Error: Syntax Problem at line %d -- Unexpected '{'", currentTokenLine);
    // Setting printf color to default
    printf("\033[0m");
    break;

  case T_RBRACE:
    printf("Error: Syntax Problem at line %d -- Unexpected '}'", currentTokenLine);
    // Setting printf color to default
    printf("\033[0m");
    break;

  case T_LSQBRA:
    printf("Error: Syntax Problem at line %d -- Unexpected '['", currentTokenLine);
    // Setting printf color to default
    printf("\033[0m");
    break;

  case T_RSQBRA:
    printf("Error: Syntax Problem at line %d -- Unexpected ']'", currentTokenLine);
    // Setting printf color to default
    printf("\033[0m");
    break;

  case T_SEMI:
    printf("Error: Syntax Problem at line %d -- Unexpected ';'", currentTokenLine);
    // Setting printf color to default
    printf("\033[0m");
    break;

  case T_COMMA:
    printf("Error: Syntax Problem at line %d -- Unexpected ','", currentTokenLine);
    // Setting printf color to default
    printf("\033[0m");
    break;

  case T_VOID:
    printf("Error: Syntax Problem at line %d -- Unexpected 'void'", currentTokenLine);
    // Setting printf color to default
    printf("\033[0m");
    break;

  case T_INT:
    printf("Error: Syntax Problem at line %d -- Unexpected 'int'", currentTokenLine);
    // Setting printf color to default
    printf("\033[0m");
    break;

  case T_EOF:
    printf("\033[1;37;41m");
    printf("Error: Syntax Problem at line %d -- Unexpected end", currentTokenLine);
    // Setting printf color to default
    printf("\033[0m");
    break;

  default:
    printf("Error: Syntax Problem at line %d -- Unexpected token %s", currentTokenLine, s);
    // Setting printf color to default
    printf("\033[0m");
    break;
  }
  printf("\n");
}

int yylex()
{
  int token;
  Analysis *info = createGNT(lex, buffer, file);
  Analysis *temp = info;

  temp = get_next_token(info);
  token = temp->lex->token;

  // Configuração do yylval union
  switch (token)
  {
  case T_NUM:
    put_num_in_stack(atoi(temp->lex->name)); // Se o token for um número, coloca seu lexema na pilha
    break;
  case T_ID:
    put_id_in_stack(temp->lex->name); // Se o token for um identificador, coloca seu lexema na pilha
    break;
  default:
    currentTokenValue = strdup(temp->lex->name); // Se o token for um identificador, copia seu lexema
    break;
  }

  if(temp->lex->token == T_ID){
    currentTokenLine = temp->lex->line;
  }
  currentTokenValue = temp->lex->name;
  currentToken = temp->lex->token;
  info = temp;
  if (token == T_EOF)
  {
    free(info);
    return 0;
  }

  return token;
}

char *tostring(int num)
{
  char *str = (char *)malloc(sizeof(char) * 10);
  sprintf(str, "%d", num);
  return str;
}