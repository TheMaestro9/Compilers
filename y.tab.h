/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
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
     FLOATNUM = 259,
     VARIABLE = 260,
     WHILE = 261,
     FOR = 262,
     IF = 263,
     PRINT = 264,
     INCREMENT = 265,
     DECREMENT = 266,
     REPEAT = 267,
     UNTIL = 268,
     TRUE = 269,
     FALSE = 270,
     CONST = 271,
     INT = 272,
     FLOAT = 273,
     LONG = 274,
     BOOL = 275,
     DOUBLE = 276,
     VOID = 277,
     CASE = 278,
     BREAK = 279,
     SWITCH = 280,
     DEFAULT = 281,
     IFX = 282,
     ELSE = 283,
     OR = 284,
     AND = 285,
     NOT = 286,
     NE = 287,
     EQ = 288,
     LE = 289,
     GE = 290,
     UMINUS = 291
   };
#endif
/* Tokens.  */
#define INTEGER 258
#define FLOATNUM 259
#define VARIABLE 260
#define WHILE 261
#define FOR 262
#define IF 263
#define PRINT 264
#define INCREMENT 265
#define DECREMENT 266
#define REPEAT 267
#define UNTIL 268
#define TRUE 269
#define FALSE 270
#define CONST 271
#define INT 272
#define FLOAT 273
#define LONG 274
#define BOOL 275
#define DOUBLE 276
#define VOID 277
#define CASE 278
#define BREAK 279
#define SWITCH 280
#define DEFAULT 281
#define IFX 282
#define ELSE 283
#define OR 284
#define AND 285
#define NOT 286
#define NE 287
#define EQ 288
#define LE 289
#define GE 290
#define UMINUS 291



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 30 "theyac.y"

    int iValue;                 /* integer value */
    float fValue;               /* Float Value */
    char sIndex;                /* symbol table index */
    nodeType *nPtr;             /* node pointer */
    char * sChar ; 


/* Line 2058 of yacc.c  */
#line 138 "y.tab.h"
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
