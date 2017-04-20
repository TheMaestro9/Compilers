%{
#include <stdlib.h>
#include "calc3.h"
#include "y.tab.h"
void yyerror(char *);
%}

%%
"while"         return WHILE;
"if"            return IF;
"else"          return ELSE;
"print"         return PRINT;
"int" { return INT; }
"double" {return DOUBLE;}
"float" {return FLOAT;}
"long" { return LONG;}
"bool" { return BOOL; }
"void" { return VOID;}
"break" {return BREAK; } 
"case" {return CASE ; } 
"switch" {return SWITCH; } 

([a-zA-Z]+[0-9_a-zA-Z]*) {   yylval.sIndex = *yytext - 'a';return VARIABLE ; }

[1-9][0-9]*|0 { yylval.iValue=atoi(yytext) ;  return INTEGER;}
[0-9]+"."[0-9]*|0 { yylval.iValue = atoi (yytext); printf("float Number");  return FLOATNUM;}


[-()<>=+*/;:{}.] {   return *yytext;    }

">="            return GE;
"<="            return LE;
"=="            return EQ;
"!="            return NE;
"&&"		return AND; 
"||"		return OR ; 
"!"		return NOT; 


[ \t\n]+        ;       /* ignore whitespace */

.               yyerror("Unknown character");
%%
int yywrap(void) {
    return 1;
}
