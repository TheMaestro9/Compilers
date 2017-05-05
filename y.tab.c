/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "theyac.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "calc3.h"
/* prototypes */
nodeType *opr(int oper, int nops, ...);
nodeType *id(int i);
nodeType *con(int value);
nodeType *conf(float value);
nodeType *conc(char value) ;
void freeNode(nodeType *p);
int ex(nodeType *p , int RegNum );
int yylex(void);
int yydebug = 1 ;
int Count=0;
extern  FILE *yyin;
void yyerror(char *s);
int sym[26];                    /* symbol table */
int type[26];
int scopes [26] ; 
int RHS [100];
int ErrorsLine[100];
char * Errors[100];\
char ErrorsID[100];
int CountErrors=0;
extern int yylineno;
extern int scope ; 
void PrintErrors();

/* Line 371 of yacc.c  */
#line 100 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     CHARACTER = 259,
     FLOATNUM = 260,
     VARIABLE = 261,
     WHILE = 262,
     FOR = 263,
     IF = 264,
     PRINT = 265,
     INCREMENT = 266,
     DECREMENT = 267,
     REPEAT = 268,
     UNTIL = 269,
     TRUE = 270,
     FALSE = 271,
     CONST = 272,
     INT = 273,
     FLOAT = 274,
     LONG = 275,
     BOOL = 276,
     DOUBLE = 277,
     VOID = 278,
     CHAR = 279,
     CASE = 280,
     BREAK = 281,
     SWITCH = 282,
     DEFAULT = 283,
     IFX = 284,
     ELSE = 285,
     OR = 286,
     AND = 287,
     NOT = 288,
     NE = 289,
     EQ = 290,
     LE = 291,
     GE = 292,
     UMINUS = 293
   };
#endif
/* Tokens.  */
#define INTEGER 258
#define CHARACTER 259
#define FLOATNUM 260
#define VARIABLE 261
#define WHILE 262
#define FOR 263
#define IF 264
#define PRINT 265
#define INCREMENT 266
#define DECREMENT 267
#define REPEAT 268
#define UNTIL 269
#define TRUE 270
#define FALSE 271
#define CONST 272
#define INT 273
#define FLOAT 274
#define LONG 275
#define BOOL 276
#define DOUBLE 277
#define VOID 278
#define CHAR 279
#define CASE 280
#define BREAK 281
#define SWITCH 282
#define DEFAULT 283
#define IFX 284
#define ELSE 285
#define OR 286
#define AND 287
#define NOT 288
#define NE 289
#define EQ 290
#define LE 291
#define GE 292
#define UMINUS 293



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 33 "theyac.y"

    int iValue;                 /* integer value */
    float fValue;               /* Float Value */
    char cValue;
    char sIndex;                /* symbol table index */
    nodeType *nPtr;             /* node pointer */
    char * sChar ; 


/* Line 387 of yacc.c  */
#line 229 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 257 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   359

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNRULES -- Number of states.  */
#define YYNSTATES  138

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      46,    47,    34,    31,     2,    32,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    51,    45,
      39,    50,    38,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    33,    36,    37,    40,
      41,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    15,    18,    20,
      26,    32,    40,    44,    53,    56,    58,    65,    70,    75,
      81,    84,    86,    89,    97,   105,   112,   113,   115,   117,
     119,   121,   124,   126,   128,   132,   134,   136,   138,   142,
     144,   148,   152,   156,   160,   163,   166,   170,   174,   178,
     182,   186,   190,   194,   198,   201,   203,   206,   209,   212,
     215
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    54,    -1,    54,    55,    -1,    -1,    45,
      -1,    10,    60,    45,    -1,    60,    45,    -1,    56,    -1,
       7,    46,    60,    47,    55,    -1,     9,    46,    64,    47,
      55,    -1,     9,    46,    64,    47,    55,    30,    55,    -1,
      48,    57,    49,    -1,     8,    46,    56,    64,    45,    61,
      47,    55,    -1,    65,    45,    -1,    58,    -1,    13,    55,
      14,    46,    60,    47,    -1,     6,    50,    60,    45,    -1,
      65,    50,    60,    45,    -1,    17,    65,    50,    60,    45,
      -1,     6,    45,    -1,    55,    -1,    57,    55,    -1,    27,
      46,     6,    47,    48,    59,    49,    -1,    25,     3,    51,
      55,    26,    45,    59,    -1,    28,    51,    55,    26,    45,
      59,    -1,    -1,     3,    -1,     5,    -1,     4,    -1,     6,
      -1,    32,    60,    -1,    62,    -1,    64,    -1,    46,    60,
      47,    -1,    63,    -1,    15,    -1,    16,    -1,     6,    50,
      62,    -1,    63,    -1,    60,    31,    60,    -1,    60,    32,
      60,    -1,    60,    34,    60,    -1,    60,    35,    60,    -1,
       6,    11,    -1,     6,    12,    -1,    60,    39,    60,    -1,
      60,    38,    60,    -1,    60,    43,    60,    -1,    60,    42,
      60,    -1,    60,    40,    60,    -1,    60,    41,    60,    -1,
      60,    36,    60,    -1,    60,    33,    60,    -1,    37,    60,
      -1,    60,    -1,    19,     6,    -1,    18,     6,    -1,    21,
       6,    -1,    24,     6,    -1,    20,     6,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    66,    66,    81,    82,    86,    87,    88,    89,    90,
      91,    92,    93,   102,   103,   120,   121,   125,   151,   178,
     206,   211,   212,   216,   219,   220,   221,   225,   226,   227,
     228,   249,   250,   251,   252,   253,   254,   255,   259,   260,
     264,   265,   266,   267,   271,   272,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   289,   290,   291,   292,
     293
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "CHARACTER", "FLOATNUM",
  "VARIABLE", "WHILE", "FOR", "IF", "PRINT", "INCREMENT", "DECREMENT",
  "REPEAT", "UNTIL", "TRUE", "FALSE", "CONST", "INT", "FLOAT", "LONG",
  "BOOL", "DOUBLE", "VOID", "CHAR", "CASE", "BREAK", "SWITCH", "DEFAULT",
  "IFX", "ELSE", "'+'", "'-'", "OR", "'*'", "'/'", "AND", "NOT", "'>'",
  "'<'", "NE", "EQ", "LE", "GE", "UMINUS", "';'", "'('", "')'", "'{'",
  "'}'", "'='", "':'", "$accept", "program", "function", "stmt",
  "VariDecl", "stmt_list", "swcase", "case", "expr", "ArithExForLoop",
  "ArithmiticExpressions", "IncDecExpressions", "CondtionalExpressions",
  "declare", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    43,    45,   286,    42,    47,   287,   288,    62,    60,
     289,   290,   291,   292,   293,    59,    40,    41,   123,   125,
      61,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    56,    56,    56,
      56,    57,    57,    58,    59,    59,    59,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    61,    61,
      62,    62,    62,    62,    63,    63,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    65,    65,    65,    65,
      65
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     3,     2,     1,     5,
       5,     7,     3,     8,     2,     1,     6,     4,     4,     5,
       2,     1,     2,     7,     7,     6,     0,     1,     1,     1,
       1,     2,     1,     1,     3,     1,     1,     1,     3,     1,
       3,     3,     3,     3,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     1,     2,     2,     2,     2,
       2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,    27,    29,    28,    30,     0,     0,
       0,     0,     0,    36,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     0,     0,     3,     8,    15,
       0,    32,    35,    33,     0,    44,    45,    20,     0,     0,
       0,     0,    30,     0,     0,     0,    57,    56,    60,    58,
      59,     0,    31,    54,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
      14,     0,     0,     0,     0,     0,     0,    55,    33,     6,
       0,     0,     0,    34,    12,    22,    40,    41,    53,    42,
      43,    52,    47,    46,    50,    51,    49,    48,     0,    17,
       0,    33,     0,     0,     0,     0,    18,     9,     0,    10,
       0,    19,    26,     0,     0,    39,     0,    16,     0,     0,
       0,     0,     0,    11,     0,     0,    23,    32,    13,     0,
       0,     0,     0,     0,    26,    26,    25,    24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    27,    28,    56,    29,   120,    30,   114,
      31,    32,    33,    34
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -95
static const yytype_int16 yypact[] =
{
     -95,    26,   162,   -95,   -95,   -95,   -95,    -8,   -14,    18,
      22,    30,   162,   -95,   -95,    -2,    63,    64,    66,    67,
      68,    29,    30,    30,   -95,    30,   162,   -95,   -95,   -95,
     231,   -95,   -95,   -95,   -20,   -95,   -95,   -95,    30,    30,
      60,    30,    12,   246,    69,    32,   -95,   -95,   -95,   -95,
     -95,    79,   -95,   -32,   180,   -95,   115,    30,    30,    30,
      30,    30,    30,    30,    30,    30,    30,    30,    30,   -95,
     -95,    30,   261,   197,    -7,    30,    36,   306,    40,   -95,
      43,    30,    44,   -95,   -95,   -95,   316,   316,   316,   -32,
     -32,   -32,   -95,   -95,   -95,   -95,   -95,   -95,   276,   -95,
     162,    47,   162,    30,   291,    46,   -95,   -95,    89,    70,
     214,   -95,    35,     9,    49,   -95,   162,   -95,    94,    48,
      52,    30,   162,   -95,    51,   162,   -95,    56,   -95,   162,
      72,    80,    62,    71,    35,    35,   -95,   -95
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -95,   -95,   -95,   -12,    65,   -95,   -95,   -94,   -10,   -95,
      -9,     0,   -36,   -13
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -39
static const yytype_int16 yytable[] =
{
      44,    43,    45,    35,    36,    78,    63,    64,    65,    66,
      67,    68,    52,    53,    55,    54,    16,    17,    18,    19,
      35,    36,    20,    35,    36,    70,     3,    76,    72,    73,
      71,    77,    39,     4,     5,     6,    42,    37,    37,   101,
     136,   137,    38,    38,    85,    13,    14,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,   121,
     118,    98,    22,   119,    40,    77,    74,    23,    41,    46,
      47,   104,    48,    49,    50,    51,    25,    15,    16,    17,
      18,    19,    81,    80,    20,    82,    71,   102,   107,   103,
     109,   105,   108,   110,   112,   113,   122,   124,   132,   125,
     116,   126,   129,   -38,   123,    75,   133,   134,   115,     0,
     128,    77,   127,   130,     0,     0,   135,   131,     4,     5,
       6,     7,     8,     9,    10,    11,     0,     0,    12,     0,
      13,    14,    15,    16,    17,    18,    19,     0,     0,    20,
       0,     0,    21,     0,     0,     0,     0,    22,     0,     0,
       0,     0,    23,     0,     0,     0,     0,     0,     0,     0,
      24,    25,     0,    26,    84,     4,     5,     6,     7,     8,
       9,    10,    11,     0,     0,    12,     0,    13,    14,    15,
      16,    17,    18,    19,     0,     0,    20,     0,     0,    21,
       0,     0,     0,     0,    22,     0,     0,     0,     0,    23,
       0,     0,     0,     0,     0,     0,     0,    24,    25,     0,
      26,    57,    58,    59,    60,    61,    62,     0,    63,    64,
      65,    66,    67,    68,     0,     0,     0,    83,    57,    58,
      59,    60,    61,    62,     0,    63,    64,    65,    66,    67,
      68,     0,     0,     0,   100,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,     0,     0,
       0,   117,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,     0,    69,    57,    58,    59,
      60,    61,    62,     0,    63,    64,    65,    66,    67,    68,
       0,    79,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,     0,    99,    57,    58,    59,
      60,    61,    62,     0,    63,    64,    65,    66,    67,    68,
       0,   106,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,     0,   111,    57,    58,    59,
      60,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      60,    61,    62,     0,    63,    64,    65,    66,    67,    68
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-95)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      12,    11,    15,    11,    12,    41,    38,    39,    40,    41,
      42,    43,    22,    23,    26,    25,    18,    19,    20,    21,
      11,    12,    24,    11,    12,    45,     0,    40,    38,    39,
      50,    41,    46,     3,     4,     5,     6,    45,    45,    75,
     134,   135,    50,    50,    56,    15,    16,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    50,
      25,    71,    32,    28,    46,    75,     6,    37,    46,     6,
       6,    81,     6,     6,     6,    46,    46,    17,    18,    19,
      20,    21,    50,    14,    24,     6,    50,    47,   100,    46,
     102,    47,    45,   103,    48,     6,    47,     3,    26,    51,
      30,    49,    51,    47,   116,    40,    26,    45,   108,    -1,
     122,   121,   121,   125,    -1,    -1,    45,   129,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    -1,    13,    -1,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    24,
      -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    -1,    48,    49,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    -1,    13,    -1,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    24,    -1,    -1,    27,
      -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,
      48,    31,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    47,    31,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    47,    31,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    47,    31,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    -1,    45,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,    45,    31,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    -1,    45,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      -1,    45,    31,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    43,    -1,    45,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    53,    54,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    13,    15,    16,    17,    18,    19,    20,    21,
      24,    27,    32,    37,    45,    46,    48,    55,    56,    58,
      60,    62,    63,    64,    65,    11,    12,    45,    50,    46,
      46,    46,     6,    60,    55,    65,     6,     6,     6,     6,
       6,    46,    60,    60,    60,    55,    57,    31,    32,    33,
      34,    35,    36,    38,    39,    40,    41,    42,    43,    45,
      45,    50,    60,    60,     6,    56,    65,    60,    64,    45,
      14,    50,     6,    47,    49,    55,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    45,
      47,    64,    47,    46,    60,    47,    45,    55,    45,    55,
      60,    45,    48,     6,    61,    63,    30,    47,    25,    28,
      59,    50,    47,    55,     3,    51,    49,    62,    55,    51,
      55,    55,    26,    26,    45,    45,    59,    59
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 66 "theyac.y"
    {
			PrintErrors();
			int i=0;
			for(i;i<26;i++)
			{
			if(sym[i]==1 || sym[i]==0)
			{
				printf("Warning : Variable %c is not used \n",i+'a');
			}
			}
			exit(0); 
                    }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 81 "theyac.y"
    { ex((yyvsp[(2) - (2)].nPtr) , 0 ); freeNode((yyvsp[(2) - (2)].nPtr)); }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 86 "theyac.y"
    { (yyval.nPtr) = opr(';', 2, NULL, NULL); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 87 "theyac.y"
    { (yyval.nPtr) = opr(PRINT, 1, (yyvsp[(2) - (3)].nPtr)); }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 88 "theyac.y"
    { (yyval.nPtr) = (yyvsp[(1) - (2)].nPtr); }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 89 "theyac.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 90 "theyac.y"
    { (yyval.nPtr) = opr(WHILE, 2, (yyvsp[(3) - (5)].nPtr), (yyvsp[(5) - (5)].nPtr)); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 91 "theyac.y"
    { (yyval.nPtr) = opr(IF, 2, (yyvsp[(3) - (5)].nPtr), (yyvsp[(5) - (5)].nPtr)); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 92 "theyac.y"
    { (yyval.nPtr) = opr(IF, 3, (yyvsp[(3) - (7)].nPtr), (yyvsp[(5) - (7)].nPtr), (yyvsp[(7) - (7)].nPtr)); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 93 "theyac.y"
    {
						 int i = 0  ; 
						 for ( i ; i < 26 ; i ++ ) 
							{
								if ( scopes[i] > scope ) 
									sym [ i ] = -1 ; 
							}
	
						(yyval.nPtr) = (yyvsp[(2) - (3)].nPtr);   }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 102 "theyac.y"
    { (yyval.nPtr) = opr(FOR,4,(yyvsp[(3) - (8)].nPtr),(yyvsp[(4) - (8)].nPtr),(yyvsp[(6) - (8)].nPtr),(yyvsp[(8) - (8)].nPtr));}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 103 "theyac.y"
    { 
							if ( sym[id((yyvsp[(1) - (2)].iValue))->id.i] == -1 ) 
							{
							(yyval.nPtr) = opr('L', 2, NULL, NULL);
							sym[id((yyvsp[(1) - (2)].iValue))->id.i] = 0 ; 
							scopes[id((yyvsp[(1) - (2)].iValue))->id.i] = scope ; 
							}
							else 	 
							{
							(yyval.nPtr) = NULL ;
							ErrorsLine[CountErrors]=yylineno;
							ErrorsID[CountErrors]=id((yyvsp[(1) - (2)].iValue))->id.i + 'a';
							Errors[CountErrors++]="Line %d : Error %c is declared before\n" ; 
							}
	
					       }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 120 "theyac.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr);  }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 121 "theyac.y"
    { (yyval.nPtr) = opr(REPEAT, 2, (yyvsp[(2) - (6)].nPtr), (yyvsp[(5) - (6)].nPtr)); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 125 "theyac.y"
    { 
					if(sym[id((yyvsp[(1) - (4)].sIndex))->id.i]==-1)
					 {
					 ErrorsLine[CountErrors]=yylineno;
					 ErrorsID[CountErrors]=id((yyvsp[(1) - (4)].sIndex))->id.i + 'a';
                                         Errors[CountErrors++]="Line %d : Error : Using Variable %c Without Being Declared\n" ;
					 (yyval.nPtr)=NULL;
					 }
					 else
					 {
	                                sym[id((yyvsp[(1) - (4)].sIndex))->id.i]=1;
	                                (yyval.nPtr) = opr('=', 2, id((yyvsp[(1) - (4)].sIndex)), (yyvsp[(3) - (4)].nPtr));
					int i=0;
					for(i;i<Count;i++)
					{
					     if(type[id((yyvsp[(1) - (4)].sIndex))->id.i]!=RHS[i])
						{
					 ErrorsLine[CountErrors]=yylineno;
					 ErrorsID[CountErrors]=id((yyvsp[(1) - (4)].sIndex))->id.i + 'a';
                                         Errors[CountErrors++]="Line %d : Warning: Improper usage of variables %c with regard to their type\n" ;
					 break;
						}
					}
	                                Count=0;
					}
				}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 151 "theyac.y"
    {	
							if ( sym[id((yyvsp[(1) - (4)].iValue))->id.i] == -1 ) 
							{
							(yyval.nPtr) = opr('=', 2, id((yyvsp[(1) - (4)].iValue)), (yyvsp[(3) - (4)].nPtr));
							sym[id((yyvsp[(1) - (4)].iValue))->id.i] = 1 ; 
							scopes[id((yyvsp[(1) - (4)].iValue))->id.i] = scope ; 
							}
							else 	 
							{
							(yyval.nPtr) = NULL ; 
							ErrorsLine[CountErrors]=yylineno;
							ErrorsID[CountErrors]=id((yyvsp[(1) - (4)].iValue))->id.i + 'a';
							Errors[CountErrors++]="Line %d : Error %c is declared before\n" ;  
							}
							int i=0;
							for(i;i<Count;i++)
							{
							     if(type[id((yyvsp[(1) - (4)].iValue))->id.i]!=RHS[i])
								{
									 ErrorsLine[CountErrors]=yylineno;
									 ErrorsID[CountErrors]=id((yyvsp[(1) - (4)].iValue))->id.i + 'a';
									 Errors[CountErrors++]="Line %d : Warning: Improper usage of variables %c with regard to their type\n" ;	
									break;
								}
							}
							Count=0;
					               }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 178 "theyac.y"
    {                 
	                                               if ( sym[id((yyvsp[(2) - (5)].iValue))->id.i] == -1 ) 
							{
							(yyval.nPtr) = opr(CONST, 2, id((yyvsp[(2) - (5)].iValue)), (yyvsp[(4) - (5)].nPtr)); 
							sym[id((yyvsp[(2) - (5)].iValue))->id.i] = 1 ; 
							scopes[id((yyvsp[(2) - (5)].iValue))->id.i] = scope ; 
							}
							else 	 
							{
							(yyval.nPtr) = NULL ; 
							ErrorsLine[CountErrors]=yylineno;
							ErrorsID[CountErrors]=id((yyvsp[(2) - (5)].iValue))->id.i + 'a';
							Errors[CountErrors++]="Line %d : Error %c is declared before\n" ; 
							}
							int i=0;
							for(i;i<Count;i++)
							{
							     if(type[id((yyvsp[(2) - (5)].iValue))->id.i]!=RHS[i])
								{
									ErrorsLine[CountErrors]=yylineno;
								        ErrorsID[CountErrors]=id((yyvsp[(2) - (5)].iValue))->id.i + 'a';
                                                                        Errors[CountErrors++]="Line %d : Warning: Improper usage of variables %c with regard to their type\n" ;
									break;
								}
							}
							Count=0;
				                        }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 206 "theyac.y"
    { (yyval.nPtr) = id((yyvsp[(1) - (2)].sIndex)); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 211 "theyac.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 212 "theyac.y"
    {(yyval.nPtr) = opr('L', 2, (yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr));  }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 216 "theyac.y"
    { (yyval.nPtr) = opr(SWITCH,2, id((yyvsp[(3) - (7)].sIndex)) , (yyvsp[(6) - (7)].nPtr) ) ;}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 219 "theyac.y"
    {  (yyval.nPtr) = opr(CASE, 3, con((yyvsp[(2) - (7)].iValue)), (yyvsp[(4) - (7)].nPtr),(yyvsp[(7) - (7)].nPtr));}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 220 "theyac.y"
    {  (yyval.nPtr) = opr(DEFAULT,2,(yyvsp[(3) - (6)].nPtr),(yyvsp[(6) - (6)].nPtr));}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 221 "theyac.y"
    {  (yyval.nPtr) = opr(';', 2, NULL, NULL);}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 225 "theyac.y"
    { (yyval.nPtr) = con((yyvsp[(1) - (1)].iValue)); RHS[Count++]=2;  }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 226 "theyac.y"
    { (yyval.nPtr) = conf((yyvsp[(1) - (1)].fValue));RHS[Count++]=1;  }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 227 "theyac.y"
    { (yyval.nPtr) = conc((yyvsp[(1) - (1)].cValue));RHS[Count++]=4;  }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 228 "theyac.y"
    {	RHS[Count++]=type[id((yyvsp[(1) - (1)].sIndex))->id.i];
					if(sym[id((yyvsp[(1) - (1)].sIndex))->id.i]==-1)
					{
							ErrorsLine[CountErrors]=yylineno;
							ErrorsID[CountErrors]=id((yyvsp[(1) - (1)].sIndex))->id.i + 'a';
							Errors[CountErrors++]="Line %d : Using Variable %c Without Being Declared\n" ;
					(yyval.nPtr)=NULL;
					}
					else
					{
					(yyval.nPtr) = id((yyvsp[(1) - (1)].sIndex));
					if(sym[id((yyvsp[(1) - (1)].sIndex))->id.i]!=0)
					sym[id((yyvsp[(1) - (1)].sIndex))->id.i]=2;
					else 
					{
					ErrorsLine[CountErrors]=yylineno;
					ErrorsID[CountErrors]=id((yyvsp[(1) - (1)].sIndex))->id.i + 'a';
					Errors[CountErrors++]="Line %d : Variable %c used without being initialized\n" ;
					}
					}
				}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 249 "theyac.y"
    { (yyval.nPtr) = opr(UMINUS, 1, (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 250 "theyac.y"
    { (yyval.nPtr) =(yyvsp[(1) - (1)].nPtr); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 251 "theyac.y"
    { (yyval.nPtr) =(yyvsp[(1) - (1)].nPtr); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 252 "theyac.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 253 "theyac.y"
    { (yyval.nPtr) =(yyvsp[(1) - (1)].nPtr);}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 254 "theyac.y"
    {(yyval.nPtr) = con(1) ;RHS[Count++]=3; }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 255 "theyac.y"
    { (yyval.nPtr)  =con(0) ;RHS[Count++]=3; }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 259 "theyac.y"
    { (yyval.nPtr) = opr('=', 2, id((yyvsp[(1) - (3)].sIndex)), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 260 "theyac.y"
    {(yyval.nPtr)=(yyvsp[(1) - (1)].nPtr);}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 264 "theyac.y"
    { (yyval.nPtr) = opr('+', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 265 "theyac.y"
    { (yyval.nPtr) = opr('-', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 266 "theyac.y"
    { (yyval.nPtr) = opr('*', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 267 "theyac.y"
    { (yyval.nPtr) = opr('/', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 271 "theyac.y"
    { (yyval.nPtr) = opr(INCREMENT, 1, id((yyvsp[(1) - (2)].sIndex))); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 272 "theyac.y"
    { (yyval.nPtr) = opr(DECREMENT, 1, id((yyvsp[(1) - (2)].sIndex)));}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 276 "theyac.y"
    { (yyval.nPtr) = opr('<', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 277 "theyac.y"
    { (yyval.nPtr) = opr('>', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 278 "theyac.y"
    { (yyval.nPtr) = opr(GE, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 279 "theyac.y"
    { (yyval.nPtr) = opr(LE, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 280 "theyac.y"
    { (yyval.nPtr) = opr(NE, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 281 "theyac.y"
    { (yyval.nPtr) = opr(EQ, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 282 "theyac.y"
    { (yyval.nPtr) = opr(AND, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 283 "theyac.y"
    { (yyval.nPtr) = opr(OR, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 284 "theyac.y"
    { (yyval.nPtr) = opr(NOT, 1, (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 285 "theyac.y"
    { (yyval.nPtr) = opr(EQ,2,(yyvsp[(1) - (1)].nPtr),con(1));}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 289 "theyac.y"
    { (yyval.iValue) = (yyvsp[(2) - (2)].sIndex); type[id((yyvsp[(2) - (2)].sIndex))->id.i] = 1 ; 	}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 290 "theyac.y"
    { (yyval.iValue) = (yyvsp[(2) - (2)].sIndex); type[id((yyvsp[(2) - (2)].sIndex))->id.i] = 2 ;   }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 291 "theyac.y"
    { (yyval.iValue) = (yyvsp[(2) - (2)].sIndex); type[id((yyvsp[(2) - (2)].sIndex))->id.i] = 3 ;   }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 292 "theyac.y"
    { (yyval.iValue) = (yyvsp[(2) - (2)].sIndex); type[id((yyvsp[(2) - (2)].sIndex))->id.i] = 4 ;   }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 293 "theyac.y"
    { (yyval.iValue) = (yyvsp[(2) - (2)].sIndex); type[id((yyvsp[(2) - (2)].sIndex))->id.i] = 5 ;   }
    break;


/* Line 1792 of yacc.c  */
#line 2084 "y.tab.c"
      default: break;
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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
	  yydestruct ("Error: discarding",
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 300 "theyac.y"

nodeType *conc(char value) 
{
    nodeType *p;
    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeConC;
    p->con.cvalue = value;

    return p;
}

nodeType *con(int value) 
{
    nodeType *p;
    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeCon;
    p->con.value = value;

    return p;
}

nodeType *conf(float value) 
{
    nodeType *p;
    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeConf;
    p->con.fvalue = value;

    return p;
}

nodeType *id(int i) 
{
    nodeType *p;
    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeId;
    p->id.i = i;
    return p;
}


nodeType *opr(int oper, int nops, ...) 
{
    va_list ap;
    nodeType *p;
    int i;

    /* allocate node, extending op array */
    if ((p = malloc(sizeof(nodeType) + (nops-1) * sizeof(nodeType *))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    return p;
}

void freeNode(nodeType *p) 
{
    int i;

    if (!p) return;
    if (p->type == typeOpr) {
        for (i = 0; i < p->opr.nops; i++)
            freeNode(p->opr.op[i]);
    }
    free (p);
}

void yyerror(char *s) 
{
     fprintf(stdout, " %s At Line %d:\n", s,yylineno);
}

static int lbl=0;
int ex(nodeType *p , int RegNum ) 
{
    int lbl1, lbl2;
    if (!p) return 0;
    switch(p->type) 
    {
    case typeConC:
	printf("\tmov R%d , %c\n",RegNum, p->con.cvalue);
	break;
    case typeCon:       
        printf("\tmov R%d , %d\n",RegNum, p->con.value); 
        break;
    case typeConf:       
        printf("\tmov R%d , %f\n",RegNum, p->con.fvalue); 
        break;	
    case typeId:        
        printf("\tmov R%d, %c\n",RegNum, p->id.i + 'a'); 
        break;
    case typeOpr:
        switch(p->opr.oper) 
	{
         
	case WHILE:
            printf("L%03d:\n", lbl1 = lbl++);
            ex(p->opr.op[0],0);
            printf("\tjz\tL%03d\n", lbl2 = lbl++);
            ex(p->opr.op[1],0);
            printf("\tjmp\tL%03d\n", lbl1);
            printf("L%03d:\n", lbl2);
            break;
        case IF:
            ex(p->opr.op[0],0);
            if (p->opr.nops > 2) 
	    {
                /* if else */
                printf("\tjz\tL%03d\n", lbl1 = lbl++);
                ex(p->opr.op[1],0);
                printf("\tjmp\tL%03d\n", lbl2 = lbl++);
                printf("L%03d:\n", lbl1);
                ex(p->opr.op[2],0);
                printf("L%03d:\n", lbl2);
            } else {
                /* if */
                printf("\tjz\tL%03d\n", lbl);
                ex(p->opr.op[1],0);
                printf("L%03d:\n", lbl++);
            }
            break;
        case PRINT:     
            ex(p->opr.op[0],0);
            printf("\tprint\n");
            break;
        case '=':       
            ex(p->opr.op[1],RegNum);
            printf("\tmov %c, R%d\n", p->opr.op[0]->id.i + 'a' , RegNum);
            break;
        case UMINUS:    
            ex(p->opr.op[0],0);
            printf("\tneg\n");
            break;
        case NOT:    
            ex(p->opr.op[0],RegNum);
            printf("\tNOT R%d \n" ,  RegNum);
            break;

	case FOR :
	    
            printf("L%03d:\n", lbl1 = lbl++);
            ex(p->opr.op[1],RegNum);
            printf("\tjz\tL%03d\n", lbl2 = lbl++);
            ex(p->opr.op[3],RegNum+1);
	    ex(p->opr.op[2],RegNum+2);
            printf("\tjmp\tL%03d\n", lbl1);
            printf("L%03d:\n", lbl2);
	    
            break;

	case SWITCH: 
		ex(p->opr.op[0],RegNum);
		ex(p->opr.op[1],RegNum);
	    break ; 

	case ';':
	printf("L%03d:\n", lbl1 = lbl++);
	break;
	
	case DEFAULT:
	printf("L%03d:\n", lbl1 = lbl++);
	ex(p->opr.op[0],RegNum+1);
	break;

	case CASE: 
	printf("L%03d:\n", lbl1 = lbl++);
	ex(p->opr.op[0],RegNum+1);
	printf("\tcompEQ R%d, R%d, R%d \n",RegNum+2 , RegNum, RegNum+1);
	printf("\tjz L%03d:\n", lbl);
	ex(p->opr.op[1],RegNum+1);
	ex(p->opr.op[2],RegNum);
	break ; 

	case INCREMENT: 
	printf("\tINC %c\n",p->opr.op[0]->id.i+'a'); 

	break;
        case DECREMENT: 
	printf("\tINC %c\n",p->opr.op[0]->id.i+'a');  
	break;

	case REPEAT: 
	    printf("L%03d:\n", lbl1 = lbl++);
            ex(p->opr.op[0],0);
            ex(p->opr.op[1],0);
	    printf("\tjz\tL%03d\n", lbl1);
            break;

	case CONST: 
	    printf("\t%c equ %d\n" ,  p->opr.op[0]->id.i + 'a' , p->opr.op[1]->con.value ) ; 
	    break ; 
		
        default:
	    ex(p->opr.op[0], RegNum+1 );
	    ex(p->opr.op[1], RegNum +2  );
            switch(p->opr.oper) 
	    {
            case '+':   printf("\tadd R%d, R%d, R%d\n", RegNum , RegNum+1, RegNum+2); break;
            case '-':   printf("\tsub R%d, R%d, R%d\n", RegNum , RegNum+1, RegNum+2); break; 
            case '*':   printf("\tmul R%d, R%d, R%d\n", RegNum , RegNum+1, RegNum+2); break;
            case '/':   printf("\tdiv R%d, R%d, R%d\n", RegNum , RegNum+1, RegNum+2); break;
            case '<':   printf("\tcompLT R%d, R%d, R%d \n",RegNum , RegNum+1, RegNum+2); break;
            case '>':   printf("\tcompGT R%d, R%d, R%d \n",RegNum , RegNum+1, RegNum+2); break;
            case GE:    printf("\tcompGE R%d, R%d, R%d \n",RegNum , RegNum+1, RegNum+2); break;
            case LE:    printf("\tcompLE R%d, R%d, R%d \n",RegNum , RegNum+1, RegNum+2); break;
            case NE:    printf("\tcompNE R%d, R%d, R%d \n",RegNum , RegNum+1, RegNum+2); break;
            case EQ:    printf("\tcompEQ R%d, R%d, R%d \n",RegNum , RegNum+1, RegNum+2); break;
	    case AND:   printf("\tAND R%d, R%d, R%d\n", RegNum , RegNum+1, RegNum+2); break;
	    case OR:   printf("\tOR R%d, R%d, R%d\n", RegNum , RegNum+1, RegNum+2); break;

            }
        }
    }
    return 0;
    }
	void PrintErrors()
	{
	
	int i=0;
	for(i;i<CountErrors;i++)
	{
	printf(Errors[i],ErrorsLine[i],ErrorsID[i]);
	}

	}


int main(int argc, char *argv[]) 
{
	int i = 0 ;
	for ( i ; i < 26 ; i ++ )sym [i] = -1 ;
		if(argc==1)
		{
		   while(1)
		   {
		    int x=yyparse();
		    PrintErrors();
			switch(x)
			{
			case 0 : printf("Memory Issue"); break;
			case 1 : printf("Grammer Issue");  break;
			case 2 : printf("You Have Issue"); break;
			default : printf("Maknetsh 7aga aslan"); break;
			}

		    }
		    return 0;
	}
	
	if(argc==2)
	{
		FILE *myfile = fopen(argv[1], "r");	
		if (!myfile) 
		{
		printf("Error Can't Read Files \n");
			return -1;
		}
		// set flex to read from it instead of defaulting to STDIN:
		yyin = myfile;
		
		// parse through the input until there is no more:
		do {
			yyparse();

		} while (!feof(yyin));

       }
}