
%{
	#define IF 0 
	#define WHILE 1
	#define DO 2
	#define CATCH 3
	#define SWITCH 4
	#define CASE 5
	#define ELSE 6
	#define TRY 7
	#include "y.tab.h" 
	#include<stdio.h>
%}

%%
 
"if"  { printf ("IF\n" ); return IF ;}
"while"  { printf ("WHILE\n" ); return WHILE ; }
"do" { printf ("DO\n" ); return DO ;}
"catch" { printf ("CATCH\n" );return CATCH ; }
"switch" { printf ("SWITCH\n" );return SWITCH ; }
"case" {printf ("CASE\n" ) ;return CASE ; } 
"else" {printf ("ELSE\n" ) ;return ELSE ; } 
"try"  {printf ("TRY\n" ) ;return TRY ; } 


[1-9][0-9]*|0 { yylval=atoi(yytext) ;  return INTEGER;}
[0-9]+"."[0-9]*|0 { yylval = atof (yytext); printf("float Number");  return FLOATNUM;}

Operations

"==" {printf("EQUALITY CONDITION \n");}
"=" { return *yytext;}
"+=" {printf("INCREMENT AND SAVE \n"); return INCS ; }
"++" {printf("INCREMENT \n"); return INC ; }
"+" { return PLUS ; }
"-" {return MINUS ; } 
"--" {printf("DECREMENT \n"); return DEC ;}
"-=" {printf("DECREMENT AND SAVE \n"); return DECS;}
"/" {printf("DIVIDE \n"); return DIV ; }
"*" {return MUL ; }
"%" {printf("REMAINDER \n"); return MOD; }
"*=" {printf("MULTIPLICATION \n"); return MULS;  }
"/=" {printf("DIVISION \n"); return DIVS; }
"&&" {printf("AND CONDITION \n");}

"struct" {printf("STRUCT \n");}
"class" {printf("CLASS \n");}
"include" {printf("INCLUDE \n");}
"using" {printf("USING \n");}
"||" {printf("OR CONDITION \n");}
"return" {printf("RETURN \n");}
"const" {printf("CONSTANT \n");}
"static" {printf("STATIC \n");}
"char" {return CHAR;}
"int" { return INT; }
"double" {printf("DOUBLE \n");return DOUBLE;}
"float" {return FLOAT;}
"long" {printf("LONG \n"); return LONG;}
"bool" {return BOOL; }
"void" {printf("VOID \n"); return VOID;}
"true" { return TRUE; }
"false" {return FALSE; }
";" {return *yytext ; }
"," {printf("COMMA \n"); return COMMA; }
"." {printf("DOT \n");}
"{" {printf("LEFT CURLY BRACES \n");}
"}" {printf("RIGHT CURLY BRACES \n");}
"(" {return *yytext;}
")" {return *yytext;}
"[" {printf("LEFT SQUARE BRACKET \n");}
"]" {printf("RIGHT SQUARE BRACKET \n");}
"#" {printf("HASHTAG \n");}
"<" {return *yytext;}
"<=" {return *yytext;}
">" {return *yytext;}
">=" {return *yytext;}
([a-zA-Z]+[0-9_a-zA-Z]*) {return VARIABLE ; }



[-+\n]      { return *yytext; }

[ \t]       ;  

%%
int yywrap(void) {
return 1;
}