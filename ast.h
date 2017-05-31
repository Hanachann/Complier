#ifndef AST_H
#define AST_H

#include "symbol.h"
#include "util.h"

//all struct are lowercase

typedef struct ast_var_ *ast_var;
typedef struct ast_decl_ *ast_decl;
typedef struct ast_expr_ *ast_expr;
typedef struct ast_type_ *ast_type;


typedef struct ast_field_ *ast_field;
typedef struct ast_efield_ *ast_efield;
typedef struct ast_funcdecl_ *ast_funcdecl;
typedef struct ast_nametype_ *ast_nametype;

//All list are lowercaseList
typedef struct ast_declList_ *ast_declList;
typedef struct ast_exprList_ *ast_exprList;
typedef struct ast_fieldList_ *ast_fieldList;
typedef struct ast_efieldList_ *ast_efieldList;
typedef struct ast_funcdeclList_ *ast_funcdeclList;
typedef struct ast_nametypeList_ *ast_nametypeList;


typedef enum{
	AST_PLUS, AST_MINUS, AST_TIMES, AST_DIV, AST_EQ,
	AST_NEQ, AST_LT, AST_LE, AST_GT, AST_GE} ast_operation;

struct ast_var_{
	enum{AST_SimpleVar, AST_FieldVar, AST_SubscriptVar} kind;
	int pos;
	union{S_symbol simple;
			struct {ast_var var;
				    S_symbol sym;} field;
			struct {ast_var var;
			        ast_expr expr;} subscript;
	} u;
};

struct ast_expr_{
	enum{AST_nilExpr, AST_varExpr, AST_intExpr, AST_stringExpr, AST_callExpr,
	     AST_opExpr, AST_recExpr, AST_seqExpr, AST_assignExpr, AST_ifExpr,
	     AST_whileExpr, AST_forExpr, AST_breakExpr, AST_letExpr, AST_arrayExpr} kind;
	int pos;
	union{ast_var var;
		  int int_t;
		  string string_t;
		  struct { S_symbol func; ast_exprList args;} call;
		  struct { ast_operation oper; ast_expr left; ast_expr right;} op;
		  struct { S_symbol type; ast_efieldList fields;} record;
		  struct { S_symbol type; ast_expr size, init;} array;
		  ast_exprList seq;
		  struct { ast_var var; ast_expr expr;} assign;
		  struct { ast_expr condition, then , else_;} if_;
		  struct { ast_expr condition, body;} while_;
		  struct { S_symbol var; ast_expr lo,hi,body; bool escape;} for_;
		  struct { ast_declList decls; ast_expr body;} let; 
	} u;
};

struct ast_decl_{
	enum{ AST_functionDecl, AST_varDecl, AST_typeDecl} kind;
	int pos;
	union{
		ast_funcdeclList function;
		struct { S_symbol var; S_symbol type; ast_expr init; bool escape;} var;
		ast_nametypeList type;
	} u;
};

struct ast_type_{
	enum {AST_nameType, AST_recordType, AST_arrayType} kind;
	int pos;
	union {
		S_symbol name;
		ast_fieldList record;
		S_symbol array;
	} u;
};

struct ast_field_ { S_symbol name, type; bool escape};
struct ast_efield_ { int pos; S_symbol name; ast_expr expr;};
struct ast_funcdecl_ { int pos;
					   S_symbol name; ast_fieldList params;
					   S_symbol result; ast_expr body;};
struct ast_nametype_ { S_symbol name; ast_type type;};
struct ast_declList_ { ast_decl head; ast_declList tail;};
struct ast_exprList_ { ast_expr head; ast_exprList tail;};
struct ast_fieldList_ { ast_field head; ast_fieldList tail;};
struct ast_efieldList_ { ast_efield head; ast_efieldList tail;};
struct ast_funcdeclList_ { ast_funcdecl head; ast_funcdeclList tail;};
struct ast_nametypeList_ { ast_nametype head; ast_nametypeList tail;};

//All function are begin with Ast_lowercase

//AST_SimpleVar, AST_FieldVar, AST_SubscriptVar

ast_var Ast_simplevar(int pos, S_symbol sym);
ast_var Ast_fieldvar(int pos, ast_var var, S_symbol sym);
ast_var Ast_subscriptvar(int pos, ast_var var, ast_expr expr);

// AST_nilExpr, AST_varExpr, AST_intExpr, AST_stringExpr, AST_callExpr,
// AST_opExpr, AST_recExpr, AST_seqExpr, AST_assignExpr, AST_ifExpr,
// AST_whileExpr, AST_forExpr, AST_breakExpr, AST_letExpr, AST_arrayExpr

ast_expr Ast_nilexpr(int pos);
ast_expr Ast_varexpr(int pos, ast_var var);
ast_expr Ast_intexpr(int pos, int i);
ast_expr Ast_stringexpr(int pos, string s);
ast_expr Ast_callexpr(int pos, S_symbol func, ast_exprList args);
ast_expr Ast_opexpr(int pos, ast_operation operation, ast_expr left, ast_expr right);
ast_expr Ast_recexpr(int pos, S_symbol type, ast_efieldList fields);
ast_expr Ast_seqexpr(int pos, ast_exprList seq);
ast_expr Ast_assignexpr(int pos, ast_var var, ast_expr expr);
ast_expr Ast_ifexpr(int pos, ast_expr condition, ast_expr then, ast_expr else_);
ast_expr Ast_whileexpr(int pos, ast_expr condition, ast_expr body);
ast_expr Ast_forexpr(int pos, S_symbol var, ast_expr lo, ast_expr hi, ast_expr body);
ast_expr Ast_breakexpr(int pos);
ast_expr Ast_letexpr(int pos, ast_declList decls, ast_expr body);
ast_expr Ast_arrayexpr(int pos, S_symbol type, ast_expr size, ast_expr init);

// AST_functionDecl, AST_varDecl, AST_typeDecl

ast_decl Ast_functiondecl(int pos, ast_funcdeclList function);
ast_decl Ast_vardecl(int pos, S_symbol var, S_symbol type, ast_expr init);
ast_decl Ast_typedecl(int pos, ast_nametypeList type);

// AST_nameType, AST_recordType, AST_arrayType
ast_type Ast_nametype(int pos, S_symbol name);
ast_type Ast_recordtype(int pos, ast_fieldList record);
ast_type Ast_arraytype(int pos, S_symbol array);

ast_field Ast_field(S_symbol name, S_symbol type);
ast_fieldList Ast_fieldlist(ast_field head, ast_fieldList tail);
ast_exprList Ast_exprlist(ast_expr head, ast_exprList tail);
ast_funcdecl Ast_funcdecl(int pos, S_symbol name, ast_fieldList params, 
						  S_symbol result, ast_expr body);
ast_funcdeclList Ast_funcdecllist(ast_funcdecl head, ast_funcdeclList tail);
ast_declList Ast_decllist(ast_decl head, ast_declList tail);
ast_nametype Ast_nametype(S_symbol name, ast_type type);
ast_nametypeList Ast_nametypelist(ast_nametype head, ast_nametypeList tail);
ast_efield Ast_efield(int pos, S_symbol name, ast_expr expr);
ast_efieldList Ast_efieldlist(ast_efield head, ast_efieldList tail);
