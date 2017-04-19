#include <stdio.h>

static int lbl;
int ex(nodeType *p , int RegNum) {
    int lbl1, lbl2;

    if (!p) return 0;
    switch(p->type) {
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
            if (p->opr.nops > 2) {
                /* if else */
                printf("\tjz\tL%03d\n", lbl1 = lbl++);
                ex(p->opr.op[1],0);
                printf("\tjmp\tL%03d\n", lbl2 = lbl++);
                printf("L%03d:\n", lbl1);
                ex(p->opr.op[2],0);
                printf("L%03d:\n", lbl2);
            } else {
                /* if */
                printf("\tjz\tL%03d\n", lbl1 = lbl++);
                ex(p->opr.op[1],0);
                printf("L%03d:\n", lbl1);
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
        default:
	    ex(p->opr.op[0], RegNum+1);
	    ex(p->opr.op[1], RegNum +2 );
            switch(p->opr.oper) {
            case '+':   printf("\tadd R%d, R%d, R%d\n", RegNum , RegNum+1, RegNum+2); break;
            case '-':   printf("\tsub R%d, R%d, R%d\n", RegNum , RegNum+1, RegNum+2); break; 
            case '*':   printf("\tmul R%d, R%d, R%d\n", RegNum , RegNum+1, RegNum+2); break;
            case '/':   printf("\tdiv R%d, R%d, R%d\n", RegNum , RegNum+1, RegNum+2); break;
            case '<':   printf("\tcompLT\n"); break;
            case '>':   printf("\tcompGT\n"); break;
            case GE:    printf("\tcompGE\n"); break;
            case LE:    printf("\tcompLE\n"); break;
            case NE:    printf("\tcompNE\n"); break;
            case EQ:    printf("\tcompEQ\n"); break;
            }
        }
    }
    return 0;
}
