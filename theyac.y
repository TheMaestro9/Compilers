%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "calc3.h"
/* prototypes */
nodeType *opr(int oper, int nops, ...);
nodeType *id(int i);
nodeType *con(int value);
void freeNode(nodeType *p);
int ex(nodeType *p , int RegNum );
int yylex(void);
int yydebug = 1 ; 

void yyerror(char *s);
int sym[26];                    /* symbol table */
%}

%union {
    int iValue;                 /* integer value */
    char sIndex;                /* symbol table index */
    nodeType *nPtr;             /* node pointer */
    char * sChar ; 
};

%token <iValue> INTEGER FLOATNUM
%token <sIndex> VARIABLE
%token WHILE FOR IF PRINT INCREMENT DECREMENT
%token INT FLOAT LONG BOOL DOUBLE VOID 
%token CASE BREAK SWITCH 
%nonassoc IFX
%nonassoc ELSE

   
%left '+' '-' OR
%left '*' '/' AND
%right NOT 
%left GE LE EQ NE '>' '<'
%nonassoc UMINUS

%type <nPtr> stmt expr stmt_list swcase case  E2
%type <iValue> declare

%%

program:
        function                { exit(0); }
        ;

function:
          function stmt         { ex($2 , 0 ); freeNode($2); }
        | /* NULL */
        ;

stmt:
          ';'                                  { $$ = opr(';', 2, NULL, NULL); }
        | expr ';'                             { $$ = $1; }
        | PRINT expr ';'                       { $$ = opr(PRINT, 1, $2); }
        | VARIABLE '=' expr ';'                { $$ = opr('=', 2, id($1), $3); }
        | WHILE '(' expr ')' stmt              { $$ = opr(WHILE, 2, $3, $5); }
        | IF '(' expr ')' stmt %prec IFX       { $$ = opr(IF, 2, $3, $5); }
        | IF '(' expr ')' stmt ELSE stmt       { $$ = opr(IF, 3, $3, $5, $7); }
        | '{' stmt_list '}'		       { $$ = $2; }
	| FOR'(' stmt  E2 ';' expr ';' ')'         { $$ = opr(FOR,3,$3,$4,$6);}
	| declare ';'			       { $$ = opr(';', 2, NULL, NULL); }
	| declare '=' expr ';'		       { $$ = opr('=', 2, id($1), $3); }
	| SWITCH '(' VARIABLE ')' CASE	INTEGER ':' INTEGER   { $$ = opr(SWITCH,3, id($3) , con($6) , con($8)) ; printf ("fuck");} 
        ;

E2: 
          expr '<' expr         { $$ = opr('<', 2, $1, $3); }
        | expr '>' expr         { $$ = opr('>', 2, $1, $3); }
        | expr GE expr          { $$ = opr(GE, 2, $1, $3); }
        | expr LE expr          { $$ = opr(LE, 2, $1, $3); }
        | expr NE expr          { $$ = opr(NE, 2, $1, $3); }
        | expr EQ expr          { $$ = opr(EQ, 2, $1, $3); }
	| expr AND expr		{ $$ = opr(AND, 2, $1, $3); } 
	| expr OR expr		{ $$ = opr(OR, 2, $1, $3); }
	| NOT expr		{ $$ = opr(NOT, 1, $2); } 
	; 	


stmt_list:
          stmt                  { $$ = $1; }
        | stmt_list stmt        { $$ = opr(';', 2, $1, $2); }
        ;

swcase: 
	SWITCH '(' VARIABLE ')' CASE INTEGER ':' stmt  { $$ = opr(SWITCH,3, $3 , $6 , $8);} 
	; 
case: 
	CASE INTEGER ':' stmt	{  $$ = opr(CASE, 2, $2, $4);}

expr:
          INTEGER               { $$ = con($1); }
        | VARIABLE              { $$ = id($1); }
        | '-' expr %prec UMINUS { $$ = opr(UMINUS, 1, $2); }
        | expr '+' expr         { $$ = opr('+', 2, $1, $3); }
        | expr '-' expr         { $$ = opr('-', 2, $1, $3); }
        | expr '*' expr         { $$ = opr('*', 2, $1, $3); }
        | expr '/' expr         { $$ = opr('/', 2, $1, $3); }
        | expr '<' expr         { $$ = opr('<', 2, $1, $3); }
        | expr '>' expr         { $$ = opr('>', 2, $1, $3); }
        | expr GE expr          { $$ = opr(GE, 2, $1, $3); }
        | expr LE expr          { $$ = opr(LE, 2, $1, $3); }
        | expr NE expr          { $$ = opr(NE, 2, $1, $3); }
        | expr EQ expr          { $$ = opr(EQ, 2, $1, $3); }
	| expr AND expr		{ $$ = opr(AND, 2, $1, $3); } 
	| expr OR expr		{ $$ = opr(OR, 2, $1, $3); }
	| NOT expr		{ $$ = opr(NOT, 1, $2); } 
        | '(' expr ')'          { $$ = $2; }
	| VARIABLE INCREMENT    { $$ = opr(INCREMENT, 1, $1); }    
	| VARIABLE DECREMENT    { $$ = opr(DECREMENT, 1, $1);}
        ;



declare: 
	FLOAT VARIABLE    { $$ = $2; }
	| INT VARIABLE	  { $$ = $2; }
	| BOOL VARIABLE   { $$ = $2; }
	| DOUBLE VARIABLE { $$ = $2; }
	| LONG VARIABLE   { $$ = $2; }
	;

	

%%

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
    fprintf(stdout, "%s\n", s);
}

static int lbl=0;
int ex(nodeType *p , int RegNum ) 
{
    int lbl1, lbl2;
    if (!p) return 0;
    switch(p->type) 
    {
    case typeCon:       
        printf("\tmov R%d , %d\n",RegNum, p->con.value); 
        break;
    case typeId:        
        printf("\tmov R%d, %c\n",RegNum, p->id.i + 'a'); 
        break;
    case typeOpr:
        switch(p->opr.oper) {

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

	case INCREMENT: 
	printf("PLUS PLUS"); break;
	case FOR : 
	    break;

	case SWITCH: 
	
	    break ; 

	case CASE: 
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
            case '<':   printf("\tcompLT\n"); break;
            case '>':   printf("\tcompGT\n"); break;
            case GE:    printf("\tcompGE\n"); break;
            case LE:    printf("\tcompLE\n"); break;
            case NE:    printf("\tcompNE\n"); break;
            case EQ:    printf("\tcompEQ R%d, R%d, R%d \n",RegNum , RegNum+1, RegNum+2); break;
	    case AND:   printf("\tAND R%d, R%d, R%d\n", RegNum , RegNum+1, RegNum+2); break;
	    case OR:   printf("\tOR R%d, R%d, R%d\n", RegNum , RegNum+1, RegNum+2); break;

            }
        }
    }
    return 0;
    }
int main(void) {

   while(1)
   {
    int x=yyparse();
	switch(x)
	{
	case 0 : printf("Kanet 0"); break;
	case 1 : printf("Kanet 1");  break;
	case 2 : printf("Kanet 2"); break;
	default : printf("Maknetsh 7aga aslan"); break;
	}
	
    }

    return 0;
}
