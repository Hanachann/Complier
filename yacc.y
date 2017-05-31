%{
#include <stdio.h>
#include <stdlib.h>

#include "errmsg.h"
#include "symbol.h"
#include "util.h"
#include "ast.h"



int yylex(void);
void yyerror(char *msg);
%}

%union {
	int pos;
    int num;
    string str;
    ast_declList declList;
    ast_exprList exprList;
    ast_funcdeclList funcdeclList;
    ast_nametypeList nametypeList;
    ast_fieldList fieldList;
    ast_efieldList efieldList;
    S_symbol sym;
    ast_decl decl;
    ast_expr expr;
    ast_type type;
    ast_var var;
    ast_func func;
}

%{
static void print_token_value(FILE *fp, int type, YYSTYPE value);
#define YYPRINT(fp, type, value) print_token_value(fp,type,value);

#define DECLSLIST_ADD(target,prev,elem) \
	do \
	{ \
		ast_declList p, e = Ast_decllist((elem),NULL); \
		(target) = p = (prev); \
		if (p) \
			{ \
				while (p->next) \
					p = p->next; \
				p->next = e; \
			} \
			else \
				(target) = e; \
	} \
	while (false)

#define TYPEDECLS_ADD(target,prev,elem) \
	do \
	{ \
		ast_nametypeList p, e = Ast_nametypelist((elem),NULL); \
		(target) = p = (prev); \
		if (p) \
			{ \
				while (p->next) \
					p = p->next; \
				p->next = e; \
			} \
			else \
				(target) = e; \
	} \
	while (false)

#define FUNCDECLS_ADD(target,prev,elem) \
	do \
	{ \
		ast_funcdeclList p, e = Ast_funcdecllist((elem),NULL); \
		(target) = p = (prev); \
		if (p) \
			{ \
				while (p->next) \
					p = p->next; \
				p->next = e; \
			} \
			else \
				(target) = e; \
	} \
	while (false)

#define EXPRLIST_ADD(target,prev,elem) \
	do \
	{ \
		ast_exprList p, e = Ast_exprlist((elem),NULL); \
		(target) = p = (prev); \
		if (p) \
			{ \
				while (p->next) \
					p = p->next; \
				p->next = e; \
			} \
			else \
				(target) = e; \
	} \
	while (false)

#define EFIELDLIST_ADD(target,prev,elem) \
	do \
	{ \
		ast_efieldList p, e = Ast_efieldlist((elem),NULL); \
		(target) = p = (prev); \
		if (p) \
			{ \
				while (p->next) \
					p = p->next; \
				p->next = e; \
			} \
			else \
				(target) = e; \
	} \
	while (false)

#define FIELDLIST_ADD(target,prev,elem) \
	do \
	{ \
		ast_fieldList p, e = Ast_fieldlist((elem),NULL); \
		(target) = p = (prev); \
		if (p) \
			{ \
				while (p->next) \
					p = p->next; \
				p->next = e; \
			} \
			else \
				(target) = e; \
	} \
	while (false)

#define LVALUE_ACT(target, prev, elem) \
		do \
	{ \
		ast_var p, var = (elem); \
		(target) = p = (prev); \
		if (p) \
		{ \
			while (p->u.field.var) \
				p = p->u.field.var; \
			p->u.field.var = var; \
		} \
		else \
			(target) = var; \
	} \
	while (false)
static ast_expr _program;

%}

%token <str> TK_ID TK_STRING
%token <num> TK_INT
%token <pos>
	TK_COMMA TK_COLON TK_LPARAN TK_RPARAN TK_LBRACK TK_RBRACK
    TK_LBRACE TK_RBRACE TK_DOT
    TK_ARRAY TK_IF TK_THEN TK_ELSE TK_WHILE TK_FOR TK_TO TK_LET TK_IN
    TK_END TK_OF TK_BREAK TK_NIL
    TK_FUNCTION TK_VAR TK_TYPE

%left <pos> TK_SEMICOLON
%nonassoc <pos> TK_DO
%nonassoc <pos> TK_ASSIGN
%left <pos> TK_OR
%left <pos> TK_AND
%nonassoc <pos> TK_EQ TK_NEQ TK_LT TK_LE TK_GT TK_GE
%left <pos> TK_PLUS TK_MINUS
%left <pos> TK_TIMES TK_DIVIDE
%left <pos> TK_UMINUS


// union {
// 	int pos;
//  int num;
//  string str;
//  ast_declList declList;
//  ast_exprList exprList;
//  ast_funcdeclList funcdeclList;
//  ast_nametypeList nametypeList;
//  ast_fieldList fieldList;
//  ast_efieldList efieldList;
//  S_symbol sym;
//  ast_decl decl;
//  ast_expr expr;
//  ast_type type;
//  ast_var var;
//  ast_func func;
// }

%type <decl> decl var_decl
%type <expr> program expr
%type <type> type
%type <var> lvalue lvalue_
%type <declList> decls type_decls
%type <exprList> expr_list args_list
%type <funcdeclList> func_decls
%type <nametypeList> type_decls
%type <fieldList> field_list
%type <efieldList> efield_list
%type <func> func_decl
%type <sym> id

%start program

%%

program:
	expr
	{ _program = $1; }

expr:
	lvalue
	{ $$ = Ast_varexpr($1->pos, $1); }
|	TK_NIL
	{ $$ = Ast_nilexpr($1); }
|	expr expr_list
	{ $$ = Ast_seqexpr($1->pos, Ast_exprlist($1,$2)); }
|	TK_LPARAN TK_RPARAN
	{ $$ = Ast_seqexpr($1, NULL); }
|	TK_LPARAN expr TK_RPARAN
	{ $$ = $2; }
|	TK_INT
	{ $$ = Ast_intexpr(tokPos, $1); }
|	TK_STRING
	{ $$ = Ast_stringexpr(tokPos, $1); }
|	TK_MINUS expr TK_UMINUS					//TK_MINUS expr %prec TK_UMINUS
	{ $$ = Ast_opexpr($1, Ast_intexpr($1,0), AST_MINUS, $2); }
|	id TK_LPARAN TK_RPARAN
	{ $$ = Ast_callexpr($2, $1, NULL); }
|	id TK_LPARAN expr args_list TK_RPARAN
	{ $$ = Ast_callexpr($2, $1, Ast_exprlist($3, $4)); }
|	expr TK_PLUS expr
	{ $$ = Ast_opexpr($2, AST_PLUS, $1, $3); }
|	expr TK_MINUS expr
	{ $$ = Ast_opexpr($2, AST_MINUS, $1, $3); }
|	expr TK_TIMES expr
	{ $$ = Ast_opexpr($2, AST_TIMES, $1, $3); }
|	expr TK_DIVIDE expr
	{ $$ = Ast_opexpr($2, AST_DIV, $1, $3); }
|	expr TK_EQ expr
	{ $$ = Ast_opexpr($2, AST_EQ, $1, $3); }
|	expr TK_NEQ expr
	{ $$ = Ast_opexpr($2, AST_NEQ, $1, $3); }
|	expr TK_LT expr
	{ $$ = Ast_opexpr($2, AST_LT, $1, $3); }
|	expr TK_LE expr
	{ $$ = Ast_opexpr($2, AST_LE, $1, $3); }
|	expr TK_GT expr 
	{ $$ = Ast_opexpr($2, AST_GT, $1, $3); }
|	expr TK_GE expr 
	{ $$ = Ast_opexpr($2, AST_GE, $1, $3); }
|	expr TK_AND expr
	{ $$ = Ast_ifexpr($2, $1, $3, Ast_intexpr($2, 0)); }
|	expr TK_OR expr
	{ $$ = Ast_ifexpr($2, $1, Ast_intexpr($2, 1), $3); }
|	id TK_LBRACE TK_RBRACE
	{ $$ = Ast_recexpr($2, $1, NULL); }
|	id TK_LBRACE id TK_EQ expr efield_list TK_RBRACE
	{ $$ = Ast_recexpr($2, $1, Ast_efieldlist(Ast_efield($4, $3, $5),$6)); }
|	id TK_LBRACK expr TK_RBRACK TK_OF expr
	{ $$ = Ast_arrayexpr($2, $1, $3, $6); }
|	lvalue TK_ASSIGN expr
	{ $$ = Ast_assignexpr($2, $1, $3); }
|	TK_IF expr TK_THEN expr
	{ $$ = Ast_ifexpr($1, $2, $4, NULL); }
|	TK_IF expr TH_THEN expr TK_ELSE expr
	{ $$ = Ast_ifexpr($1, $2, $4, $6); }
|	TK_WHILE expr TK_DO expr
	{ $$ = Ast_whileexpr($1, $2, $4); }
|	TK_FOR id TK_ASSIGN expr TK_TO expr TK_DO expr
	{ $$ = Ast_forexpr($1, $2, $4, $6, $8); }
|	TK_BREAK
	{ $$ = Ast_breakexpr($1); }
|	TK_LET decls TK_IN expr TK_END
	{ $$ = Ast_letexpr($1, $2, $4); }

decls:
	/*Nothing*/
	{ $$ = NULL; }
|	decls decl
	{ DECLSLIST_ADD($$, $1, $2); }

decl:
	type_decls
	{ $$ = Ast_typedecl(((ast_type) $1->head)->pos, $1); }
|	var_decl
|	func_decls
	{ $$ = Ast_functiondecl(((ast_func) $1->head)->pos, $1); }

type_decls:
	TK_TYPE id TK_EQ type
	{ $$ = Ast_nametypelist(Ast_nametype($2, $4), NULL); }
|	type_decls TK_TYPE id TK_EQ type
	{ TYPEDECLS_ADD($$, $1, Ast_nametype($3, $5)); }

type:
	id
	{ $$ = Ast_nametype(tokPos, $1); }
|	TK_LBRACE fields TK_RBRACE
	{ $$ = Ast_recordtype($1, $2); }
|	TK_ARRAY TK_OF id
	{ $$ = Ast_arraytype($1, $3); }

fields:
	/*Nothing*/
	{ $$ = NULL; }
|	id TK_COLON id field_list
	{ $$ = Ast_fieldlist(Ast_field($1, $3), $4); }

var_decl:
	TK_VAR id TK_ASSIGN expr
	{ $$ = Ast_vardecl($1, $2, NULL, $4); }
|	TK_VAR id TK_COLON id TK_ASSIGN expr
	{ $$ = Ast_vardecl($1, $2, $4, $6); }

func_decls:
	func_decl
	{ $$ = Ast_funcdecllist($1, NULL); }
|	func_decls func_decl
	{ FUNCDECLS_ADD($$, $1, $2); }

func_decl:
	TK_FUNCTION id TK_LPARAN fields TK_RPARAN TK_EQ expr
	{ $$ = Ast_funcdecl($1, $2, $4, NULL, $7); }
|	TK_FUNCTION id TK_LPARAN fields TK_RPARAN TK_COLON id TK_EQ expr
	{ $$ = Ast_funcdecl($1, $2, $4, $7, $9); }

expr_list:
	TK_SEMICOLON expr
	{ $$ = Ast_exprlist($2, NULL); }
|
	expr_seq TK_SEMICOLON expr
	{ EXPRLIST_ADD($$, $1, $3); }

args_list:
	/*Nothing*/
	{ $$ = NULL; }
|	args_list TK_COMMA expr
	{ EXPRLIST_ADD($$, $1, $3); }

efield_list:
	/*Nothing*/
	{ $$ = NULL; }
|	efield_list TK_COMMA id TK_EQ expr
	{ EFIELDLIST_ADD($$, $1, Ast_efield($4, $3, $5)); }

field_list:
	/*Nothing*/
	{ $$ = NULL; }
|	field_list TK_COMMA id TK_COLON id
	{ FIELDLIST_ADD($$, $1, Ast_field($3, $5)); }

lvalue:
	id lvalue_
	{ LVALUE_ACT($$, $2, Ast_simplevar(tokPos, $1)); }

lvalue_:
	/*Nothing*/
	{ $$ = NULL; }
|	TK_DOT id lvalue_
	{ LVALUE_ACT($$, $3, Ast_fieldvar($1, NULL, $2)); }
|	TK_LBRACK expr TK_RBRACK lvalue_
	{ LVALUE_ACT($$ ,$4, Ast_subscriptvar($1, NULL, $2)); }

id:
	TK_ID
	{ $$ = symbol($1); }
%%

void yyerror(char *msg)
{
	em_error(tokPos, "%s",msg);
}

static void print_token_value(FILE *fp, int type, YYSTYPE value)
{
    switch (type)
    {
        case TK_ID:
        case TK_STRING:
            fprintf(fp, "%s", value.str);
            break;
        case TK_INT:
            fprintf(fp, "%d", value.num);
            break;
    }
}

ast_expr_t parse(string_t filename)
{
    em_reset(filename);
    if (yyparse() == 0)
        return _program;
    else
        return NULL;
}

