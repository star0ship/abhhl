#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tac.h"

/* global var */
int scope_local, next_tmp, next_label;
SYM *sym_tab_global, *sym_tab_local;
TAC *tac_first, *tac_last;

void tac_init()
{
	scope_local=0;
	sym_tab_global=NULL;
	sym_tab_local=NULL;	
	next_tmp=0;
	next_label=1;
}

void tac_complete()
{
	TAC *cur=NULL; 		/* Current TAC */
	TAC *prev=tac_last; 	/* Previous TAC */

	while(prev !=NULL)
	{
		prev->next=cur;
		cur=prev;
		prev=prev->prev;
	}

	tac_first = cur;
}

SYM *lookup_sym(SYM *symtab, char *name)
{
	SYM *t=symtab;

	while(t !=NULL)
	{
		if(strcmp(t->name, name)==0) break; 
		else t=t->next;
	}
	
	return t; /* NULL if not found */
}

void insert_sym(SYM **symtab, SYM *sym)
{
	sym->next=*symtab; /* Insert at head */
	*symtab=sym;
}

SYM *mk_sym(void)
{
	SYM *t;
	t=(SYM *)malloc(sizeof(SYM));
	return t;
}

SYM *mk_var(char *name)
{
	SYM *sym=NULL;

	if(scope_local)  
		sym=lookup_sym(sym_tab_local,name);
	else
		sym=lookup_sym(sym_tab_global,name);

	/* var already declared */
	if(sym!=NULL)
	{
		error("variable already declared");
		return NULL;
	}

	/* var unseen before, set up a new symbol table node, insert_sym it into the symbol table. */
	sym=mk_sym();
	sym->type=SYM_VAR;
	sym->name=name; /* ysj */
	sym->offset=-1; /* Unset address */

	if(scope_local)  
		insert_sym(&sym_tab_local,sym);
	else
		insert_sym(&sym_tab_global,sym);

	return sym;
}

TAC *join_tac(TAC *c1, TAC *c2)
{
	TAC *t;

	if(c1==NULL) return c2;
	if(c2==NULL) return c1;

	/* Run down c2, until we get to the beginning and then add c1 */
	t=c2;
	while(t->prev !=NULL) 
		t=t->prev;

	t->prev=c1;
	return c2;
}

TAC *declare_var(char *name)
{
	return mk_tac(TAC_VAR,mk_var(name),NULL,NULL);
}

TAC *declare_pointer(char *name) {
    SYM *sym = NULL;

    if (scope_local)
        sym = lookup_sym(sym_tab_local, name);
    else
        sym = lookup_sym(sym_tab_global, name);

    if (sym != NULL) {
        error("pointer already declared");
        return NULL;
    }

    sym = mk_sym();
    sym->type = SYM_PTR;
    sym->name = name;
    sym->offset = -1; 

    if (scope_local)
        insert_sym(&sym_tab_local, sym);
    else
        insert_sym(&sym_tab_global, sym);

	return mk_tac(TAC_PTR,sym,NULL,NULL);
}



TAC *mk_tac(int op, SYM *a, SYM *b, SYM *c)
{
	TAC *t=(TAC *)malloc(sizeof(TAC));

	t->next=NULL; /* Set these for safety */
	t->prev=NULL;
	t->op=op;
	t->a=a;
	t->b=b;
	t->c=c;

	return t;
}  

SYM *mk_label(char *name)
{
	SYM *t=mk_sym();

	t->type=SYM_LABEL;
	t->name=strdup(name);

	return t;
}  

TAC *do_func(SYM *func, TAC *args, TAC *code)
{
	TAC *tlist; /* The backpatch list */

	TAC *tlab; /* Label at start of function */
	TAC *tbegin; /* BEGINFUNC marker */
	TAC *tend; /* ENDFUNC marker */

	tlab=mk_tac(TAC_LABEL, mk_label(func->name), NULL, NULL);
	tbegin=mk_tac(TAC_BEGINFUNC, NULL, NULL, NULL);
	tend=mk_tac(TAC_ENDFUNC,   NULL, NULL, NULL);

	tbegin->prev=tlab;
	code=join_tac(args, code);
	tend->prev=join_tac(tbegin, code);

	return tend;
}

SYM *mk_tmp(void)
{
	SYM *sym;
	char *name;

	name=malloc(12);
	sprintf(name, "t%d", next_tmp++); /* Set up text */
	return mk_var(name);
}

TAC *declare_para(char *name)
{
	return mk_tac(TAC_FORMAL,mk_var(name),NULL,NULL);
}

TAC *declare_para_ptr(char *name)
{
	SYM *sym = NULL;

    if (scope_local)
        sym = lookup_sym(sym_tab_local, name);
    else
        sym = lookup_sym(sym_tab_global, name);

    if (sym != NULL) {
        error("pointer already declared");
        return NULL;
    }

    sym = mk_sym();
    sym->type = SYM_PTR;
    sym->name = name;
    sym->offset = -1; 

    if (scope_local)
        insert_sym(&sym_tab_local, sym);
    else
        insert_sym(&sym_tab_global, sym);

    return mk_tac(TAC_FORMAL,sym,NULL,NULL);
}

SYM *declare_func(char *name)
{
	SYM *sym=NULL;

	sym=lookup_sym(sym_tab_global,name);

	/* name used before declared */
	if(sym!=NULL)
	{
		if(sym->type==SYM_FUNC)
		{
			error("func already declared");
			return NULL;
		}

		if(sym->type !=SYM_UNDEF)
		{
			error("func name already used");
			return NULL;
		}

		return sym;
	}
	
	
	sym=mk_sym();
	sym->type=SYM_FUNC;
	sym->name=name;
	sym->address=NULL;

	insert_sym(&sym_tab_global,sym);
	return sym;
}

TAC *do_assign(SYM *var, EXP *exp) {
    TAC *code;

    if (var->type != SYM_VAR && var->type != SYM_CONST_CHAR && var->type != SYM_PTR) {
        error("assignment to non-variable");
        return NULL;
    }

    code = mk_tac(TAC_COPY, var, exp->ret, NULL);
    code->prev = exp->tac;
    var->value = exp->ret->value;

    // 保留字符型处理的逻辑
    if (var->type == SYM_CONST_CHAR && (var->value > 127 || var->value < -128)) {
        var->value = var->value - ((var->value >> 8) << 8) - 256;
    }

    return code;
}


TAC *do_assign_pointer(SYM *var, EXP *exp) {
    TAC *code;
	TAC *temp;

    if (var->type != SYM_PTR) {
		printf("%s, type: %d", var->name, var->type);
        error("assignment to non-pointer variable");
        return NULL;
    }
    code = mk_tac(TAC_ASSIGN_PTR, var, exp->ret, NULL);
    code->prev = exp->tac;

    return code;
}



void insert_tac(TAC *code) {
    if (tac_last == NULL) {
        tac_first = tac_last = code;
    } else {
        tac_last->next = code;
        code->prev = tac_last;
        tac_last = code;
    }
}

EXP *get_address(SYM *var){
	TAC *temp; /* TAC code for temp symbol */
	TAC *ret; /* TAC code for result */

	temp=mk_tac(TAC_VAR, mk_tmp(), NULL, NULL);
	ret=mk_tac(TAC_ADDR, temp->a, var, NULL);
	ret->prev = temp;

	return mk_exp(NULL, temp->a, ret);
}

EXP *mk_dereference(EXP *exp){
	TAC *temp; /* TAC code for temp symbol */
	TAC *ret; /* TAC code for result */

	temp=mk_tac(TAC_VAR, mk_tmp(), NULL, NULL);
	temp->prev=exp->tac;
	ret=mk_tac(TAC_DEREF, temp->a, exp->ret, NULL);
	ret->prev = temp;

	exp->ret=temp->a;
	exp->tac=ret;
	return exp;

	//return mk_exp(NULL, temp->a, ret);
}



EXP *do_bin( int binop, EXP *exp1, EXP *exp2)
{
	TAC *temp; /* TAC code for temp symbol */
	TAC *ret; /* TAC code for result */

	printf("type :%d\n",exp1->ret->type);
	if((exp1->ret->type==SYM_INT||exp1->ret->type==SYM_CHAR) 
		&& (exp2->ret->type==SYM_INT||exp2->ret->type==SYM_CHAR))
	{
		int newval; /* The result of constant folding */

		switch(binop) /* Chose the operator */
		{
			case TAC_ADD:
			newval=exp1->ret->value + exp2->ret->value;
			break;

			case TAC_SUB:
			newval=exp1->ret->value - exp2->ret->value;
			break;

			case TAC_MUL:
			newval=exp1->ret->value * exp2->ret->value;
			break;

			case TAC_DIV:
			newval=exp1->ret->value / exp2->ret->value;
			break;
			
		}
		if (exp1->ret->type==SYM_CHAR||exp1->ret->type==SYM_CONST_CHAR)
		{
			if(newval>127||newval<0)
				error("char variable out of interval!");
		}

		exp1->ret=mk_const(newval); /* New space for result */

		return exp1; /* The new expression */
	}

	temp=mk_tac(TAC_VAR, mk_tmp(), NULL, NULL);
	temp->prev=join_tac(exp1->tac, exp2->tac);
	ret=mk_tac(binop, temp->a, exp1->ret, exp2->ret);
	ret->prev=temp;

	exp1->ret=temp->a;
	exp1->tac=ret;

	return exp1;  
}   

EXP *do_cmp( int binop, EXP *exp1, EXP *exp2)
{
	TAC *temp; /* TAC code for temp symbol */
	TAC *ret; /* TAC code for result */

	if((exp1->ret->type==SYM_INT||exp1->ret->type==SYM_CHAR) 
		&& (exp2->ret->type==SYM_INT||exp2->ret->type==SYM_CHAR))
	{
		int newval; /* The result of constant folding */

		switch(binop) /* Chose the operator */
		{
			case TAC_EQ:
			newval=(exp1->ret->value==exp2->ret->value);
			break;
			
			case TAC_NE:
			newval=(exp1->ret->value !=exp2->ret->value);
			break;
			
			case TAC_LT:
			newval=(exp1->ret->value < exp2->ret->value);
			break;
			
			case TAC_LE:
			newval=(exp1->ret->value <=exp2->ret->value);
			break;
			
			case TAC_GT:
			newval=(exp1->ret->value > exp2->ret->value);
			break;
			
			case TAC_GE:
			newval=(exp1->ret->value >=exp2->ret->value);
			break;
		}

		exp1->ret=mk_const(newval); /* New space for result */
		return exp1; /* The new expression */
	}

	temp=mk_tac(TAC_VAR, mk_tmp(), NULL, NULL);
	temp->prev=join_tac(exp1->tac, exp2->tac);
	ret=mk_tac(binop, temp->a, exp1->ret, exp2->ret);
	ret->prev=temp;

	exp1->ret=temp->a;
	exp1->tac=ret;

	return exp1;  
}   

EXP *do_un( int unop, EXP *exp) 
{
	TAC *temp; /* TAC code for temp symbol */
	TAC *ret; /* TAC code for result */

	/* Do constant folding if possible. Calculate the constant into exp */
	if(exp->ret->type==SYM_INT||exp->ret->type==SYM_CHAR||exp->ret->type==SYM_VAR||exp->ret->type==SYM_CONST_CHAR)
	{
		switch(unop) /* Chose the operator */
		{
			case TAC_NEG:
			exp->ret->value = - exp->ret->value;
			break;
		}

		return exp; /* The new expression */
	}

	temp=mk_tac(TAC_VAR, mk_tmp(), NULL, NULL);
	temp->prev=exp->tac;
	ret=mk_tac(unop, temp->a, exp->ret, NULL);
	ret->prev=temp;

	exp->ret=temp->a;
	exp->tac=ret;

	return exp;   
}

TAC *do_call(char *name, EXP *arglist)
{
	EXP  *alt; /* For counting args */
	TAC *code; /* Resulting code */
	TAC *temp; /* Temporary for building code */

	code=NULL;
	for(alt=arglist; alt !=NULL; alt=alt->next) code=join_tac(code, alt->tac);

	while(arglist !=NULL) /* Generate ARG instructions */
	{
		temp=mk_tac(TAC_ACTUAL, arglist->ret, NULL, NULL);
		temp->prev=code;
		code=temp;

		alt=arglist->next;
		arglist=alt;
	};

	temp=mk_tac(TAC_CALL, NULL, (SYM *)strdup(name), NULL);
	temp->prev=code;
	code=temp;

	return code;
}

EXP *do_call_ret(char *name, EXP *arglist)
{
	EXP  *alt; /* For counting args */
	SYM *ret; /* Where function result will go */
	TAC *code; /* Resulting code */
	TAC *temp; /* Temporary for building code */

	ret=mk_tmp(); /* For the result */
	code=mk_tac(TAC_VAR, ret, NULL, NULL);

	for(alt=arglist; alt !=NULL; alt=alt->next) code=join_tac(code, alt->tac);

	while(arglist !=NULL) /* Generate ARG instructions */
	{
		temp=mk_tac(TAC_ACTUAL, arglist->ret, NULL, NULL);
		temp->prev=code;
		code=temp;

		alt=arglist->next;
		arglist=alt;
	};

	temp=mk_tac(TAC_CALL, ret, (SYM *)strdup(name), NULL);
	temp->prev=code;
	code=temp;

	return mk_exp(NULL, ret, code);
}

TAC *do_lib(char *name, SYM *arg)
{
        TAC *a=mk_tac(TAC_ACTUAL, arg, NULL, NULL);
        TAC *c=mk_tac(TAC_CALL, NULL, (SYM *)strdup(name), NULL);
        c->prev=a;
        return c;
}

char *mk_lstr(int i)
{
	char lstr[10]="L";
	sprintf(lstr,"L%d",i);
	return(strdup(lstr));	
}

TAC *do_if(EXP *exp, TAC *stmt)
{
	TAC *label=mk_tac(TAC_LABEL, mk_label(mk_lstr(next_label++)), NULL, NULL);
	TAC *code=mk_tac(TAC_IFZ, label->a, exp->ret, NULL);

	code->prev=exp->tac;
	code=join_tac(code, stmt);
	label->prev=code;

	return label;
}

TAC *do_test(EXP *exp, TAC *stmt1, TAC *stmt2)
{
	TAC *label1=mk_tac(TAC_LABEL, mk_label(mk_lstr(next_label++)), NULL, NULL);
	TAC *label2=mk_tac(TAC_LABEL, mk_label(mk_lstr(next_label++)), NULL, NULL);
	TAC *code1=mk_tac(TAC_IFZ, label1->a, exp->ret, NULL);
	TAC *code2=mk_tac(TAC_GOTO, label2->a, NULL, NULL);

	code1->prev=exp->tac; /* Join the code */
	code1=join_tac(code1, stmt1);
	code2->prev=code1;
	label1->prev=code2;
	label1=join_tac(label1, stmt2);
	label2->prev=label1;
	
	return label2;
}

TAC *do_while(EXP *exp, TAC *stmt) 
{
	TAC *label=mk_tac(TAC_LABEL, mk_label(mk_lstr(next_label++)), NULL, NULL);
	TAC *code=mk_tac(TAC_GOTO, label->a, NULL, NULL);

	code->prev=stmt; /* Bolt on the goto */

	return join_tac(label, do_if(exp, code));
}

TAC *do_for(TAC *stmt1, EXP *exp, TAC *stmt2, TAC *code)
{
	TAC *label=mk_tac(TAC_LABEL, mk_label(mk_lstr(next_label++)), NULL, NULL); /*Label at start of for-loop (except initialize)*/
	TAC *back=mk_tac(TAC_GOTO, label->a, NULL, NULL);

	label = join_tac(stmt1, label);	/*Label at start of for-loop*/
	code = join_tac(code, stmt2);

	back->prev = code;
	return join_tac(label, do_if(exp, back));
}


SYM *get_var(char *name)
{
	SYM *sym=NULL; /* Pointer to looked up symbol */

	//printf("%s \n", name);
	if(scope_local) sym=lookup_sym(sym_tab_local,name);

	if(sym==NULL) sym=lookup_sym(sym_tab_global,name);

	if(sym==NULL)
	{
		error("name not declared as local/global variable");
		return NULL;
	}

	if((sym->type!=SYM_VAR)&&(sym->type!=SYM_CONST_CHAR)&&(sym->type!=SYM_PTR)&&(sym->type!=SYM_ARRAY))
	{
		//printf("%s\n", sym->name);
		error("not a variable");
		return NULL;
	}

	return sym;
} 

EXP *mk_exp(EXP *next, SYM *ret, TAC *code)
{
	EXP *exp=(EXP *)malloc(sizeof(EXP));

	exp->next=next;
	exp->ret=ret;
	exp->tac=code;

	return exp;
}

SYM *mk_text(char *text)
{
	SYM *sym=NULL; /* Pointer to looked up symbol */

	sym=lookup_sym(sym_tab_global,text);

	/* text already used */
	if(sym!=NULL)
	{
		return sym;
	}

	/* text unseen before, set up a new symbol table node, insert_sym it into the symbol table. */
	sym=mk_sym();
	sym->type=SYM_TEXT;
	sym->name=text; /* ysj */
	sym->label=next_label++; /* ysj */

	insert_sym(&sym_tab_global,sym);
	return sym;
}

SYM *mk_const(int n)
{
	SYM *c=mk_sym(); /* Create a new node */

	c->type=SYM_INT;
	c->value=n; /* ysj */
	return c;
}     

char *to_str(SYM *s, char *str) 
{
	/* Check we haven't been given NULL */
	if(s==NULL)	return "NULL";

	/* Identify the type */
	switch(s->type)
	{
		case SYM_FUNC:
		case SYM_VAR:
		case SYM_CONST_CHAR:
		case SYM_PTR:
		case SYM_ARRAY:
		/* Just return the name */
		return s->name; /* ysj */

		case SYM_TEXT:
		/* Put the address of the text */
		sprintf(str, "L%d", s->label);
		return str;

		case SYM_INT:
		/* Convert the number to string */
		sprintf(str, "%d", s->value);
		return str;

		case SYM_CHAR:
		/*print charactor's ASCII code*/
		sprintf(str, "%d", s->value);
		return str;


		default:
		/* Unknown arg type */
		error("unknown TAC arg type");
		return "?";
	}
} 

void tac_print(TAC *i)
{
	char sa[12]; /* For text of TAC args */
	char sb[12];
	char sc[12];

	switch(i->op)
	{
		case TAC_UNDEF:
		printf("undef");
		break;

		case TAC_ADD:
		printf("%s = %s + %s", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_SUB:
		printf("%s = %s - %s", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_MUL:
		printf("%s = %s * %s", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_DIV:
		printf("%s = %s / %s", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_EQ:
		printf("%s = (%s == %s)", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_NE:
		printf("%s = (%s != %s)", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_LT:
		printf("%s = (%s < %s)", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_LE:
		printf("%s = (%s <= %s)", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_GT:
		printf("%s = (%s > %s)", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_GE:
		printf("%s = (%s >= %s)", to_str(i->a, sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_NEG:
		printf("%s = - %s", to_str(i->a, sa), to_str(i->b, sb));
		break;

		case TAC_COPY:
		printf("%s = %s", to_str(i->a, sa), to_str(i->b, sb));
		break;

		case TAC_GOTO:
		printf("goto %s", i->a->name);
		break;

		case TAC_IFZ:
		printf("ifz %s goto %s", to_str(i->b, sb), i->a->name);
		break;

		case TAC_ACTUAL:
		printf("actual %s", to_str(i->a, sa));
		break;

		case TAC_FORMAL:
		printf("formal %s", to_str(i->a, sa));
		break;

		case TAC_CALL:
		if(i->a==NULL) printf("call %s", (char *)i->b);
		else printf("%s = call %s", to_str(i->a, sa), (char *)i->b);
		break;

		case TAC_RETURN:
		printf("return %s", to_str(i->a, sa));
		break;

		case TAC_LABEL:
		printf("label %s", i->a->name);
		break;

		case TAC_VAR:
		printf("var %s", to_str(i->a, sa));
		break;

		case TAC_CHAR:
		printf("char %s", to_str(i->a, sa));
		break;

		case TAC_BEGINFUNC:
		printf("begin");
		break;

		case TAC_ENDFUNC:
		printf("end");
		break;

		case TAC_PTR:
		printf("pointer %s", to_str(i->a, sa));
		break;

		case TAC_ADDR:
        printf("%s = &%s", to_str(i->a, sa), to_str(i->b, sb));
        break;

        case TAC_DEREF:
        printf("%s = *%s", to_str(i->a, sa), to_str(i->b, sb));
        break;

		case TAC_ARRAY:
		printf("array %s",to_str(i->a, sa));
		break;

		case TAC_COPY_ARRAY:
		printf("%s[%s] = %s",to_str(i->a,sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_ARRAY_COPY:
		printf("%s = %s[%s]",to_str(i->a,sa), to_str(i->b, sb), to_str(i->c, sc));
		break;

		case TAC_ASSIGN_PTR:
		printf("*%s = %s", to_str(i->a,sa), to_str(i->b, sb));
		break;

		default:
		error("unknown TAC opcode");
		break;
	}

	fflush(stdout);

}

void tac_dump()
{
	TAC * cur;
	for(cur = tac_first; cur !=NULL; cur=cur->next)
	{
		tac_print(cur);
		printf("\n");
	}
}

void error(char *str)
{
	fprintf(stderr, "error: %s\n", str);
	exit(0);
} 

SYM *mk_char(char* n)
{
	SYM *c=mk_sym(); /* Create a new node */

	c->type=SYM_CHAR;
	c->value=n[1]; /* czj */
	return c;
	
}     

SYM *mk_escape_char(char* n)
{
	SYM *c=mk_sym(); /* Create a new node */

	c->type=SYM_CHAR;
	switch(n[2])
	{
		case '\'':
		{
			c->value='\'';
			break;
		}
		case '"':
		{
			c->value='\"';
			break;
		}
		case '?':
		{
			c->value='\?';
			break;
		}
		case '\\':
		{
			c->value='\\';
			break;
		}
		case 'a':
		{
			c->value='\a';
			break;
		}
		case 'b':
		{
			c->value='\b';
			break;
		}
		case 'f':
		{
			c->value='\f';
			break;
		}
		case 'n':
		{
			c->value='\n';
			break;
		}
		case 'r':
		{
			c->value='\r';
			break;
		}
		case 't':
		{
			c->value='\t';
			break;
		}
		case 'v':
		{
			c->value='\v';
			break;
		}
		default:
		{
			error("undefined escape charactor");
			break;
		}

	}
	return c;
}

SYM *mk_const_char(char *name)
{
	SYM *sym=NULL;

	if(scope_local)  
		sym=lookup_sym(sym_tab_local,name);
	else
		sym=lookup_sym(sym_tab_global,name);

	/* var already declared */
	if(sym!=NULL)
	{
		error("variable already declared");
		return NULL;
	}

	/* var unseen before, set up a new symbol table node, insert_sym it into the symbol table. */
	sym=mk_sym();
	sym->type=SYM_CONST_CHAR;
	sym->name=name; /* ysj */
	sym->offset=-1; /* Unset address */

	if(scope_local)  
		insert_sym(&sym_tab_local,sym);
	else
		insert_sym(&sym_tab_global,sym);

	return sym;
}

TAC *declare_char(char *name)
{
	return mk_tac(TAC_CHAR,mk_const_char(name),NULL,NULL);
}

SYM *mk_array(char *name,int n,int type)
{
	SYM *sym=NULL;

	if(scope_local)  
		sym=lookup_sym(sym_tab_local,name);
	else
		sym=lookup_sym(sym_tab_global,name);

	/* var already declared */
	if(sym!=NULL)
	{
		error("variable already declared");
		return NULL;
	}

	/* var unseen before, set up a new symbol table node, insert_sym it into the symbol table. */
	sym=mk_sym();
	sym->type=SYM_ARRAY;
	sym->in_type=type;
	sym->name=name; /* ysj */
	sym->offset=-1; /* Unset address */
	sym->upper_bound=n;

	if(scope_local)  
		insert_sym(&sym_tab_local,sym);
	else
		insert_sym(&sym_tab_global,sym);

	sym->arr_list=mk_array_list(name, n,type);
	//sym->value=sym->arr_list;

	return sym;
}

TAC *declare_array(char* name, int n,int type)
{
	return mk_tac(TAC_ARRAY,mk_array(name,n,type),NULL,NULL);
}

SYM *mk_array_list(char* name, int n,int type)
{
	SYM *sym=NULL;
	sym=mk_sym();
	SYM *p=sym;
	for(int i=0;i<n-1;i++)
	{
		char elem_name[50];
		sprintf(elem_name,"%s[%d]",name,i);
		p->name=elem_name;
		p->type=type;
		p->offset=-1;
		p->next=mk_sym();
		p=p->next;
	}
	char elem_name[50];
	sprintf(elem_name,"%s[%d]",name,n-1);
	p->name=elem_name;
	p->type=type;
	p->offset=-1;
	p->next=NULL;

	return sym;
}

TAC *do_assign_array(SYM *var, EXP *pos, EXP *exp)
{
	TAC *code;

    if (var->type != SYM_ARRAY) {
        error("assignment to non-pointer variable");
        return NULL;
    }

	if(pos->ret->value>=var->upper_bound||pos->ret->value<0)
	{
		error("out of array's interval");
        return NULL;
	}
    code = mk_tac(TAC_COPY_ARRAY, var, pos->ret ,exp->ret);
    code->prev = join_tac(pos->tac, exp->tac);

    return code;
	
}

SYM *get_array(char *name,EXP *pos)
{
	SYM *sym=NULL; /* Pointer to looked up symbol */

	//printf("%s \n", name);
	if(scope_local) sym=lookup_sym(sym_tab_local,name);

	if(sym==NULL) sym=lookup_sym(sym_tab_global,name);

	if(sym==NULL)
	{
		error("name not declared as local/global variable");
		return NULL;
	}

	if((sym->type!=SYM_ARRAY))
	{
		//printf("%s\n", sym->name);
		error("not a array");
		return NULL;
	}

	SYM *elem =sym->arr_list;
	int upper = pos->ret->value;
	for(int i=0; i<upper;i++)
	{
		elem=elem->next;
	}

	return elem;
}

EXP *do_array(SYM *var, EXP *exp)
{
	TAC *code;
	TAC *temp;
	int type;

	if(exp->ret->value<var->upper_bound&&exp->ret->value>=0)
	{
		temp=mk_tac(TAC_VAR, mk_tmp(), NULL, NULL);
		//printf("%s",temp->a->name);
		temp->prev=exp->tac;
		//temp->a->value=exp->ret->value;
		//printf("temp: %s, %d\n",temp->a->name,temp->a->value);
		code=mk_tac(TAC_ARRAY_COPY,temp->a,var,exp->ret);
		code->prev=temp;
		return mk_exp(NULL,temp->a,code);
	}
	else
	{
		error("out of array's interval");
		return NULL;
	}
}