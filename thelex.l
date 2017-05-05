%{
#include <stdlib.h>
#include "calc3.h"
#include "y.tab.h"
void yyerror(char *);
int yylineno=1;
int scope = 0 ; 
%}

%%
 
"while"         return WHILE;
"if"            return IF;
"for"           return FOR;
"else"          return ELSE;
"print"         return PRINT;
"int" { return INT; }
"double" {return DOUBLE;}
"float" {return FLOAT;}
"long" { return LONG;}
"bool" { return BOOL; }
"void" { return VOID;}
"break" {return BREAK; }
"char" {return CHAR;}
"case" {return CASE ; } 
"switch" {return SWITCH; } 
"default" {return DEFAULT;}
"repeat" {return REPEAT ; } 
"until" {return UNTIL; } 
"false" {return FALSE; } 
"true" {return TRUE ; } 
"const" {return CONST ; }
"\n"     ++yylineno;
'[a-zA-z]' {yylval.cValue = yytext[1]; return CHARACTER;}
([a-zA-Z]+[0-9_a-zA-Z]*) {   yylval.sIndex = *yytext - 'a';return VARIABLE ; }

[1-9][0-9]*|0 { yylval.iValue=atoi(yytext) ;  return INTEGER;}
[0-9]+"."[0-9]*|0 { yylval.fValue = atof (yytext);  return FLOATNUM;}


[-()<>=+*/;:.] {   return *yytext;    }
"{"		{ scope ++ ; return *yytext; } 
"}"		{ scope -- ; return *yytext; } 
">="            return GE;
"<="            return LE;
"=="            return EQ;
"!="            return NE;
"&&"		return AND; 
"||"		return OR ; 
"!"		return NOT; 
"++"            return INCREMENT;
"--"            return DECREMENT;           
[ \t]+        ;       /* ignore whitespace */

.               yyerror("Unknown character");
%%
int yywrap(void) {
    return 1;
	}

