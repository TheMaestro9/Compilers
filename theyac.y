%{
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
%}

%union {
    int iValue;                 /* integer value */
    float fValue;               /* Float Value */
    char cValue;
    char sIndex;                /* symbol table index */
    nodeType *nPtr;             /* node pointer */
    char * sChar ; 
};

%token <iValue> INTEGER
%token <cValue> CHARACTER
%token <fValue> FLOATNUM
%token <sIndex> VARIABLE
%token WHILE FOR IF PRINT INCREMENT DECREMENT 
%token REPEAT UNTIL TRUE FALSE CONST  
%token INT FLOAT LONG BOOL DOUBLE VOID CHAR 
%token CASE BREAK SWITCH DEFAULT
%nonassoc IFX
%nonassoc ELSE

   
%left '+' '-' OR
%left '*' '/' AND
%right NOT 
%left GE LE EQ NE '>' '<'
%nonassoc UMINUS

%type <nPtr> stmt expr stmt_list swcase case ArithmiticExpressions  CondtionalExpressions VariDecl IncDecExpressions ArithExForLoop
%type <iValue> declare 

%%

program:
        function    {
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
        ;

function:
          function stmt         { ex($2 , 0 ); freeNode($2); }
        | /* NULL */
        ;

stmt:
          ';'                                  { $$ = opr(';', 2, NULL, NULL); }
        | PRINT expr ';'                       { $$ = opr(PRINT, 1, $2); }
	| expr ';'                             { $$ = $1; }
	| VariDecl			       { $$ = $1; } 	
        | WHILE '(' expr ')' stmt              { $$ = opr(WHILE, 2, $3, $5); }
        | IF '(' CondtionalExpressions ')' stmt %prec IFX       { $$ = opr(IF, 2, $3, $5); }
        | IF '(' CondtionalExpressions ')' stmt ELSE stmt       { $$ = opr(IF, 3, $3, $5, $7); }
        | '{' stmt_list '}'		       {
						 int i = 0  ; 
						 for ( i ; i < 26 ; i ++ ) 
							{
								if ( scopes[i] > scope ) 
									sym [ i ] = -1 ; 
							}
	
						$$ = $2;   }
	| FOR'(' VariDecl  CondtionalExpressions ';' ArithExForLoop ')'stmt { $$ = opr(FOR,4,$3,$4,$6,$8);}
	| declare ';'			     	{ 
							if ( sym[id($1)->id.i] == -1 ) 
							{
							$$ = opr('L', 2, NULL, NULL);
							sym[id($1)->id.i] = 0 ; 
							scopes[id($1)->id.i] = scope ; 
							}
							else 	 
							{
							$$ = NULL ;
							ErrorsLine[CountErrors]=yylineno;
							ErrorsID[CountErrors]=id($1)->id.i + 'a';
							Errors[CountErrors++]="Line %d : Error %c is declared before\n" ; 
							}
	
					       }

	| swcase			       { $$ = $1;  } 
	| REPEAT stmt UNTIL '('expr ')'		{ $$ = opr(REPEAT, 2, $2, $5); }
        ;

VariDecl:
         VARIABLE '=' expr ';'    { 
					if(sym[id($1)->id.i]==-1)
					 {
					 ErrorsLine[CountErrors]=yylineno;
					 ErrorsID[CountErrors]=id($1)->id.i + 'a';
                                         Errors[CountErrors++]="Line %d : Error : Using Variable %c Without Being Declared\n" ;
					 $$=NULL;
					 }
					 else
					 {
	                                sym[id($1)->id.i]=1;
	                                $$ = opr('=', 2, id($1), $3);
					int i=0;
					for(i;i<Count;i++)
					{
					     if(type[id($1)->id.i]!=RHS[i])
						{
					 ErrorsLine[CountErrors]=yylineno;
					 ErrorsID[CountErrors]=id($1)->id.i + 'a';
                                         Errors[CountErrors++]="Line %d : Warning: Improper usage of variables %c with regard to their type\n" ;
					 break;
						}
					}
	                                Count=0;
					}
				}
        | declare '=' expr ';'		       {	
							if ( sym[id($1)->id.i] == -1 ) 
							{
							$$ = opr('=', 2, id($1), $3);
							sym[id($1)->id.i] = 1 ; 
							scopes[id($1)->id.i] = scope ; 
							}
							else 	 
							{
							$$ = NULL ; 
							ErrorsLine[CountErrors]=yylineno;
							ErrorsID[CountErrors]=id($1)->id.i + 'a';
							Errors[CountErrors++]="Line %d : Error %c is declared before\n" ;  
							}
							int i=0;
							for(i;i<Count;i++)
							{
							     if(type[id($1)->id.i]!=RHS[i])
								{
									 ErrorsLine[CountErrors]=yylineno;
									 ErrorsID[CountErrors]=id($1)->id.i + 'a';
									 Errors[CountErrors++]="Line %d : Warning: Improper usage of variables %c with regard to their type\n" ;	
									break;
								}
							}
							Count=0;
					               }
	| CONST declare  '=' expr ';'{                 
	                                               if ( sym[id($2)->id.i] == -1 ) 
							{
							$$ = opr(CONST, 2, id($2), $4); 
							sym[id($2)->id.i] = 1 ; 
							scopes[id($2)->id.i] = scope ; 
							}
							else 	 
							{
							$$ = NULL ; 
							ErrorsLine[CountErrors]=yylineno;
							ErrorsID[CountErrors]=id($2)->id.i + 'a';
							Errors[CountErrors++]="Line %d : Error %c is declared before\n" ; 
							}
							int i=0;
							for(i;i<Count;i++)
							{
							     if(type[id($2)->id.i]!=RHS[i])
								{
									ErrorsLine[CountErrors]=yylineno;
								        ErrorsID[CountErrors]=id($2)->id.i + 'a';
                                                                        Errors[CountErrors++]="Line %d : Warning: Improper usage of variables %c with regard to their type\n" ;
									break;
								}
							}
							Count=0;
				                        }

	| VARIABLE ';'                             { $$ = id($1); }
	;
	

stmt_list:
          stmt                  { $$ = $1; }
        | stmt_list stmt        {$$ = opr('L', 2, $1, $2);  }
        ;

swcase: 
	SWITCH '(' VARIABLE ')'  '{'case '}'  { $$ = opr(SWITCH,2, id($3) , $6 ) ;} 
	; 
case: 
	 CASE INTEGER ':' stmt BREAK ';' case {  $$ = opr(CASE, 3, con($2), $4,$7);}
	|DEFAULT ':' stmt BREAK ';' case     {  $$ = opr(DEFAULT,2,$3,$6);}
	|				  {  $$ = opr(';', 2, NULL, NULL);}
	;

expr:
          INTEGER               { $$ = con($1); RHS[Count++]=2;  }
	| FLOATNUM              { $$ = conf($1);RHS[Count++]=1;  }
	| CHARACTER		{ $$ = conc($1);RHS[Count++]=4;  }
        | VARIABLE              {	RHS[Count++]=type[id($1)->id.i];
					if(sym[id($1)->id.i]==-1)
					{
							ErrorsLine[CountErrors]=yylineno;
							ErrorsID[CountErrors]=id($1)->id.i + 'a';
							Errors[CountErrors++]="Line %d : Using Variable %c Without Being Declared\n" ;
					$$=NULL;
					}
					else
					{
					$$ = id($1);
					if(sym[id($1)->id.i]!=0)
					sym[id($1)->id.i]=2;
					else 
					{
					ErrorsLine[CountErrors]=yylineno;
					ErrorsID[CountErrors]=id($1)->id.i + 'a';
					Errors[CountErrors++]="Line %d : Variable %c used without being initialized\n" ;
					}
					}
				}
        | '-' expr %prec UMINUS { $$ = opr(UMINUS, 1, $2); }
	| ArithmiticExpressions { $$ =$1; }
	| CondtionalExpressions { $$ =$1; }
        | '(' expr ')'          { $$ = $2; }
	| IncDecExpressions     { $$ =$1;}
	| TRUE			{$$ = con(1) ;RHS[Count++]=3; }
	| FALSE			{ $$  =con(0) ;RHS[Count++]=3; } 
        ;

ArithExForLoop:
	VARIABLE'='ArithmiticExpressions { $$ = opr('=', 2, id($1), $3); }
	| IncDecExpressions {$$=$1;}
	;

ArithmiticExpressions:
          expr '+' expr          { $$ = opr('+', 2, $1, $3); }
        | expr '-' expr         { $$ = opr('-', 2, $1, $3); }
        | expr '*' expr         { $$ = opr('*', 2, $1, $3); }
        | expr '/' expr         { $$ = opr('/', 2, $1, $3); }
	;

IncDecExpressions:
	 VARIABLE INCREMENT    { $$ = opr(INCREMENT, 1, id($1)); }    
	| VARIABLE DECREMENT    { $$ = opr(DECREMENT, 1, id($1));}
	;

CondtionalExpressions: 
          expr '<' expr         { $$ = opr('<', 2, $1, $3); }
        | expr '>' expr         { $$ = opr('>', 2, $1, $3); }
        | expr GE expr          { $$ = opr(GE, 2, $1, $3); }
        | expr LE expr          { $$ = opr(LE, 2, $1, $3); }
        | expr NE expr          { $$ = opr(NE, 2, $1, $3); }
        | expr EQ expr          { $$ = opr(EQ, 2, $1, $3); }
	| expr AND expr		{ $$ = opr(AND, 2, $1, $3); } 
	| expr OR expr		{ $$ = opr(OR, 2, $1, $3); }
	| NOT expr		{ $$ = opr(NOT, 1, $2); }
	| expr                  { $$ = opr(EQ,2,$1,con(1));}
	; 	

declare: 
	FLOAT VARIABLE    { $$ = $2; type[id($2)->id.i] = 1 ; 	}
	| INT VARIABLE	  { $$ = $2; type[id($2)->id.i] = 2 ;   }
	| BOOL VARIABLE   { $$ = $2; type[id($2)->id.i] = 3 ;   }
	| CHAR VARIABLE   { $$ = $2; type[id($2)->id.i] = 4 ;   }
	| LONG VARIABLE   { $$ = $2; type[id($2)->id.i] = 5 ;   }
	;



	

%%
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