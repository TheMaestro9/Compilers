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
/* Line 2058 of yacc.c  */
#line 33 "theyac.y"

    int iValue;                 /* integer value */
    float fValue;               /* Float Value */
    char cValue;
    char sIndex;                /* symbol table index */
    nodeType *nPtr;             /* node pointer */
    char * sChar ; 


/* Line 2058 of yacc.c  */
#line 143 "y.tab.h"
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
