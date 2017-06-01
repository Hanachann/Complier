#include <stdio.h>
#include <stdlib.h>
#include "ErrorMsg.h"
#include "env.h"
#include "types.h"
#include "symbol.h"
#include "tree.h"
#include "translate.h"
#include "util.h"
#include "ast.h"
#include "semant.h"

struct expty {
	Tr_exp exp;
	Ty_ty ty;
};

struct expty expTy(Tr_exp exp, Ty_ty ty) {
	struct expty e;
	e.exp = exp;
	e.ty = ty;
	return e;
}

struct expty transVar(S_table venv, S_table tenv, ast_var v);
struct expty transExp(S_table venv, S_table tenv, ast_expr e);
void transDec(S_table venv, S_table tenv, ast_decl d);
Ty_ty transTy(S_table tenv, ast_type a);

struct expty transVar(S_table venv, S_table tenv, ast_var v) {
	switch(v->kind) {
	case AST_SimpleVar: {	/* var id (a) */
		E_enventry x = S_look(venv, v->u.simple);
		if(!x) {
			em_error(v->pos, "Undefined variable %s\n", S_name(v->u.simple));
			return expTy(NULL, Ty_Int());
		}
		else if(x->kind != E_varEntry) {
			em_error(v->pos, "Expect %s to be a variable\n", S_name(v->u.simple));
			return expTy(NULL, Ty_Int());
		}
		return expTy(NULL, Ty_actualTy(x->u.var.ty));
	}
	case AST_FieldVar: {	/* var record (a.b) */
		struct expty et = transVar(venv, tenv, v->u.field.var);
		if(et.ty->kind != Ty_record) {
			em_error(v->pos, "Expected a record type\n");
			return expTy(NULL, Ty_Int());
		}
		for(Ty_fieldList p = et.ty->u.record; p; p = p->next) {
			Ty_field field = p->f;
			if(field->name == v->u.field.sym) {
				return expTy(NULL, Ty_actualTy(field->ty));
			}
		}
		em_error(v->pos, "Can not find field name %s\n", S_name(v->u.field.sym));
		return expTy(NULL, Ty_Int());
	}
	case AST_SubscriptVar: {	/* var array (a[b]) */
		struct expty et = transVar(venv, tenv, v->u.subscript.var);
		if(et.ty->kind != Ty_array) {
			em_error(v->pos, "Expected a array type\n");
		}
		else {
			struct expty et2 = transExp(venv, tenv, v->u.subscript.expr);
			if(et2.ty->kind != Ty_int) {
				em_error(v->pos, "Expected a int index\n");
			}
			else {
				return expTy(NULL, Ty_actualTy(et.ty->u.array));
			}
		}
		return expTy(NULL, Ty_Int());
	}
	default:
		break;
	}
}

struct expty transExp(S_table venv, S_table tenv, ast_expr e) {
	switch(e->kind) {
	case AST_nilExpr:
		return expTy(NULL, Ty_Nil());
	case AST_varExpr:
		return transVar(venv, tenv, e->u.var);
	case AST_intExpr:
		return expTy(NULL, Ty_Int());
	case AST_stringExpr:
		return expTy(NULL, Ty_String());
	case AST_callExpr: {	/* function a(b:int, c:string): d = */
		E_enventry cinfo = S_look(venv, e->u.call.func);
		struct expty et;
		struct expty temp;
		ast_exprList el;
		Ty_tyList tl;
		if(!cinfo) {
			em_error(e->pos, "Undefined Function %s\n", S_name(e->u.call.func));
			return expTy(NULL, Ty_Void());
		}
		else if(cinfo->kind != E_funEntry) {
			em_error(e->pos, "%s need to be a function\n", S_name(e->u.call.func));
			return expTy(NULL, Ty_Void());
		}
		el = e->u.call.args;
		tl = cinfo->u.fun.formals;
		while(el && tl) {
			temp = transExp(venv, tenv, el->head);
			if(!Ty_match(temp.ty, tl->t)) {
				em_error(e->pos, "Unmatch parameters in the function%s\n", S_name(e->u.call.func));
				return expTy(NULL, Ty_Void());
			}
			el = el->tail;
			tl = tl->next;
		}
		if(el && !tl) {
			em_error(e->pos, "Too many parameters in the function%s\n", S_name(e->u.call.func));
			return expTy(NULL, Ty_Void());
		}
		if(!el && tl) {
			em_error(e->pos, "Too less parameters in the function%s\n", S_name(e->u.call.func));
			return expTy(NULL, Ty_Void());
		}
		if(cinfo->u.fun.result) {
			return expTy(NULL, Ty_actualTy(cinfo->u.fun.result));
		}
		else {
			return expTy(NULL, Ty_Void());
		}

	}
	case AST_opExpr: {		/* a op b */
		ast_operation oper = e->u.op.oper;
		struct expty left = transExp(venv, tenv, e->u.op.left);
		struct expty right = transExp(venv, tenv, e->u.op.right);
		
		if(oper == AST_PLUS || oper == AST_MINUS || 
			oper == AST_TIMES || oper == AST_DIV) {
			if(left.ty->kind != Ty_int)
				em_error(e->u.op.left->pos, "Expected Integer\n");
			if(right.ty->kind != Ty_int)
				em_error(e->u.op.right->pos, "Expected Integer\n");
			return expTy(NULL, Ty_Int()); ///////////////////////
		} 
		else {
			if(oper == AST_EQ || oper == AST_NEQ) {
				if(Ty_match(left.ty, right.ty))
					return expTy(NULL, Ty_Int());
			}
			if(left.ty->kind != right.ty->kind) {
				em_error(e->u.op.left->pos, "Type on both sides mismatch\n");
			}
			return expTy(NULL, Ty_Int());
		}
	}
	case AST_recExpr: {
		Ty_ty recty = Ty_actualTy(S_look(tenv, e->u.record.type));
		if(!recty) {
			em_error(e->pos, "Undefined record type %s\n", S_name(e->u.record.type));
			return expTy(NULL, Ty_Record(NULL));
		}
		if(recty->kind != Ty_record) {
			em_error(e->pos, "%s need to be a record\n", S_name(e->u.record.type));
			return expTy(NULL, Ty_Record(NULL));
		}
		struct expty temp;
		Ty_fieldList ty = recty->u.record;
		ast_efieldList fl = e->u.record.fields;
		
		while(ty && fl) {
			temp = transExp(venv, tenv, fl->head->expr);
			if(!Ty_match(temp.ty, ty->f->ty)) {
				em_error(e->pos, "Unmatch parameters in the record %s:%s\n", S_name(e->u.record.type), S_name(ty->f->name));
				return expTy(NULL, Ty_Record(NULL));
			}
			ty = ty->next;
			fl = fl->tail;
		}
		if(ty && !fl) {
			em_error(e->pos, "Too many parameters in the record %s\n", S_name(e->u.record.type));
			return expTy(NULL, Ty_Record(NULL));
		}
		if(!ty && fl) {
			em_error(e->pos, "Too less parameters in the record %s\n", S_name(e->u.record.type));
			return expTy(NULL, Ty_Record(NULL));
		}
		return expTy(NULL, recty);
	}
	case AST_seqExpr: {
		ast_exprList l = e->u.seq;
		if(!l) {
			return expTy(NULL, Ty_Void());
		}
		while(l->tail) {
			transExp(venv, tenv, l->head);
			l = l->tail;
		}
		return transExp(venv, tenv, l->head);
	}
	case AST_assignExpr: {
		struct expty v, r;
		v = transVar(venv, tenv, e->u.assign.var);
		r = transExp(venv, tenv, e->u.assign.expr);
		if(!Ty_match(v.ty, r.ty)) {
			em_error(e->u.op.left->pos, "Type on both sides mismatch\n");
		}
		return expTy(NULL, Ty_Void());
	}
	case AST_ifExpr: {
		struct expty cond, then;
		cond = transExp(venv, tenv, e->u.if_.condition);
		then = transExp(venv, tenv, e->u.if_.then);
		if(Ty_actualTy(cond.ty)->kind != Ty_int) {
			em_error(e->pos, "Condition must be a int type\n");
		}
		if(e->u.if_.else_) {
			struct expty else_ = transExp(venv, tenv, e->u.if_.else_);
			if(!Ty_match(then.ty, else_.ty)) {
				em_error(e->pos, "Type of then and else mismatch\n");
			}
			return expTy(NULL, then.ty);
		}
		else if(then.ty->kind != TY_VOID)
			em_error(expr->pos, "if-then should return nothing\n");
		return expTy(NULL, Ty_Void());
	}
	case AST_whileExpr: {
		struct expty cond, body;
		cond = transExp(venv, tenv, e->u.while_.condition);
		body = transExp(venv, tenv, e->u.while_.body);
		if(Ty_actualTy(cond.ty)->kind != Ty_int) {
			em_error(e->pos, "Condition must be a int type\n");
		}
		if(Ty_actualTy(body.ty)->kind != Ty_void) {
			em_error(e->pos, "while-do should return nothing\n");
		}
		return expTy(NULL, Ty_Void());
	}
	case AST_forExpr: {
		struct expty lo = transExp(venv, tenv, e->u.for_.lo);
		struct expty hi = transExp(venv, tenv, e->u.for_.hi);
		struct expty body;

		if(lo.ty->kind != Ty_int || hi.ty->kind != Ty_int) {
			em_error(e->pos, "Upper & lower bound of \'for\' must be int\n");
		}
		S_beginScope(venv);
		transDec(venv, tenv, Ast);
		body = transExp(venv, tenv, e->u.for_.body);
		S_endScope(venv);
		return expTy(NULL, Ty_Void());
	}
	case AST_breakExpr:
		return expTy(NULL, Ty_Void());
	case AST_letExpr: {
		struct expty et;
		ast_declList d;
		S_beginScope(venv);
		S_beginScope(tenv);
		for(d = e->u.let.decls; d; d=d->tail) {
			transDec(venv, tenv, d->head);
		}
		et = transExp(venv, tenv, e->u.let.body);
		S_endScope(tenv);
		S_endScope(venv);
		return et;
	}
	case AST_arrayExpr: {
		Ty_ty arrty = Ty_actualTy(S_look(tenv, e->u.array.type));
		if(!arrty) {
			em_error(e->pos, "Undefined array type %s\n", S_name(e->u.array.type));
			return expTy(NULL, Ty_Array(NULL));
		}
		if(arrty->kind != Ty_array) {
			em_error(e->pos, "%s need to be a array\n", S_name(e->u.array.type));
			return expTy(NULL, Ty_Array(NULL));
		}
		struct expty siz, ini;
		siz = transExp(venv, tenv, e->u.array.size);
		ini = transExp(venv, tenv, e->u.array.init);
		if(siz.ty->kind != Ty_int) {
			em_error(e->pos, "Size of array need to be int in %s\n", S_name(e->u.array.type));
			return expTy(NULL, Ty_Array(NULL));
		}
		if(Ty_match(arrty->u.array, ini.ty)) {
			em_error(e->pos, "Type of array unmatch in %s\n", S_name(e->u.array.type));
			return expTy(NULL, Ty_Array(NULL));
		}
		return expTy(NULL, arrty);
	}
	default:
		assert(0);
	}
}

static Ty_tyList makeFormalTyList(S_table t, ast_fieldList fl) {
	Ty_tyList temp = NULL, tl = temp;

	for(ast_fieldList l = fl;; l; l = l->tail) {
		Ty_ty ty = S_look(t, l->head->type);
		if(!ty) {
			em_error(l->head->pos, "undefined type %s", S_name(l->head->type));
			ty = Ty_Int();
		}
		if(!temp) {
			temp = Ty_TyList(ty, NULL);
			tl = temp;
		}
		else {
			temp->tail = Ty_TyList(ty, NULL);
			temp = temp->tail;
		}
	}
	return tl;
}

void transDec(S_table venv, S_table tenv, ast_decl d) {
	switch(d->kind) {
	case AST_varDecl: {
		struct expty et = transExp(venv, tenv, d->u.var.init);
		if(d->u.var.type) {
			Ty_ty ty = S_look(tenv, d->u.var.type);
			if(!ty) {
				em_error(e->pos, "Undefined type %s\n", S_name(d->u.var.type));
				return;
			}
			if(!Ty_match(ty, et.ty)) {
				em_error(e->pos, "Mismatch type %s\n", S_name(d->u.var.type));
			}
			S_enter(venv, d->u.var.var, E_VarEntry(ty));
		}
		else if(et.ty->kind == Ty_nil || et.ty->kind == Ty_void) {
			em_error(e->pos, "Need type specified in %s\n", S_name(d->u.var.var));
		}
		S_enter(venv, d->u.var.var, E_VarEntry(et.ty));
		return;
	}
	case AST_typeDecl: {
		for(ast_nametypeList nl = d->u.type; nl; nl = nl->tail) {
			Ty_ty ty = transTy(tenv, nl->head->type);
			S_enter(tenv, nl->head->name, Ty_Name(nl->head->name, ty));
		}
		/* Infinite recursive type */
		for(ast_nametypeList nl = d->u.type; nl; nl = nl->tail) {
			Ty_ty namety = S_look(tenv, nl->head->name);
			if(Ty_actualTy(namety) == namety) {
				em_error(d->pos, "Infinite recursive type '%s'", S_name(nl->head->name));
			}
		}
		return;
	}
	case AST_functionDecl: {
		for(ast_funcdeclList p = d->u.function; p; p = p->tail) {
			ast_funcdecl f = p->head;
			Ty_ty resty;
			Ty_tyList formaltys;
			if(f->result) {
				resty = = S_look(tenv, f->result);
				if(!resty) {
					em_error(f->pos, "Unknown return type in %s\n", S_name(f->name));
					resty = Ty_Void();
				}
				else {
					resty = Ty_Void();
				}
			}
			formaltys = = makeFormalTyList(tenv, f->params);
			S_enter(venv, f->name, E_FunEntry(formaltys, resty));
			S_beginScope(venv);
			{
				ast_fieldList l;
				Ty_tyList t;
				for(l = f->params, t = formaltys; l; l = l->tail, t = t->next) {
					S_enter(venv, l->head->name, E_VarEntry(t->t));
				}
				struct expty et = transExp(venv, tenv, f->body);
				E_enventry fun = S_look(venv, f->name);
				if(!Ty_match(fun->u.fun.result, et.ty)) {
					em_error(f->pos, "Unmatch return type in function %s\n", S_name(f->name));
				}
			}
			S_endScope(venv);
		}
		return;
	}
	default:
		assert(0);
	}
}

Ty_ty transTy(S_table tenv, ast_type a) {
	switch(a->kind) {
	case AST_nameType: {
		Ty_ty ty = S_look(tenv, a->u.name);
		if(!ty) {
			em_error(a->pos, "Undefined type %s\n", S_name(a->u.name));
			ty = Ty_Int();
		}
		return ty;
	}
	case AST_recordType: {
		Ty_fieldList fl, ltmp = NULL;
		Ty_ty ty;
		Ty_field ftmp;

		for(ast_fieldList f = a->u.record; f; f = f->tail) {
			ty = S_look(tenv, f->head->type);
			if(!ty) {
				em_error(a->pos, "Undefined type %s\n", S_name(f->head->name));
				ty = Ty_Int();
			}
			ftmp = Ty_Field(f->head->name, ty);
			if(!ltmp) {
				ltmp = Ty_FieldList(ftmp, NULL);
				fl = ltmp;
			}
			else {
				ltmp->next = Ty_FieldList(ftmp, NULL);
				ltmp = ltmp->next;
			}
		}
		return  Ty_Record(fl);
	}
	case AST_arrayType: {
		Ty_ty aty = S_look(tenv, a->u.array);
		if(!aty) {
			em_error(a->pos, "Undefined type %s\n", S_name(a->u.array));
			aty = Ty_Int();
		}
		return  Ty_Array(aty);
	}
	default:
		assert(0);
	}
}

void SEM_transProg(ast_expr exp) {
	struct expty et;

	S_table tenv = E_base_tenv();
	S_table venv = E_base_venv();
	et = transExp(venv, tenv, exp);
}