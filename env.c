#include <stdio.h>
#include "util.h"
#include "symbol.h"
#include "types.h"
#include "env.h"

E_enventry E_VarEntry(Ty_ty ty) {
	E_enventry p = checked_malloc(sizeof(*p));
	p->kind = E_varEntry;
	p->u.var.ty = ty;
	return p;
}

E_enventry E_FunEntry(Ty_tyList formals, Ty_ty result) {
	E_enventry p = checked_malloc(sizeof(*p));
	p->kind = E_funEntry;
	p->u.fun.formals = formals;
	p->u.fun.result = result;
	return p;
}

S_table E_base_tenv(void) {
	S_table st = S_empty();
	S_enter(st, S_Symbol("int"), E_VarEntry(Ty_Int()));
	S_enter(st, S_Symbol("string"), E_VarEntry(Ty_String()));
	return st;
}

S_table E_base_venv(void) {
	S_table st = S_empty;
	S_enter(st, S_Symbol("print"),
		E_FunEntry(	Ty_TyList(Ty_String(), NULL),
					NULL));
	S_enter(st, S_Symbol("flush"),
		E_FunEntry(	Ty_TyList(NULL, NULL),
					NULL));
	S_enter(st, S_Symbol("getchar"),
		E_FunEntry(	Ty_TyList(NULL, NULL),
					Ty_String()));
	S_enter(st, S_Symbol("ord"),
		E_FunEntry(	Ty_TyList(Ty_String(), NULL),
					Ty_Int()));
	S_enter(st, S_Symbol("chr"),
		E_FunEntry(	Ty_TyList(Ty_Int(), NULL),
					Ty_String()));
	S_enter(st, S_Symbol("size"),
		E_FunEntry( Ty_TyList(Ty_String(), NULL),
					Ty_Int()));
	S_enter(st, S_Symbol("substring"),
		E_FunEntry(	Ty_TyList(Ty_String(), 
					Ty_TyList(Ty_Int(),
					Ty_TyList(Ty_Int(),
					NULL))),
					Ty_String()));
	S_enter(st, S_Symbol("not"),
		E_FunEntry(	Ty_TyList(Ty_Int(), NULL),
					Ty_Int()));
	S_enter(st, S_Symbol("exit"),
		E_FunEntry(	Ty_TyList(Ty_Int(), NULL),
					NULL));
}