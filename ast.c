#include "ast.h"

//All function are begin with Ast_lowercase

//AST_SimpleVar, AST_FieldVar, AST_SubscriptVar

ast_var Ast_simplevar(int pos, S_symbol sym){
	ast_var p = checked_malloc(sizeof(*p));
	p->kind = AST_SimpleVar;
	p->pos = pos;
	p->u.simple = sym;
	return p;
}
ast_var Ast_fieldvar(int pos, ast_var var, S_symbol sym){
	ast_var p = checked_malloc(sizeof(*p));
	p->kind = AST_FieldVar;
	p->pos = pos;
	p->u.field.var = var;
	p->u.field.sym = sym;
	return p;
}
ast_var Ast_subscriptvar(int pos, ast_var var, ast_expr expr){
	ast_var p = checked_malloc(sizeof(*p));
	p->kind = AST_SubscriptVar;
	p->pos = pos;
	p->u.subscript.var = var;
	p->u.subscript.expr = exp;
	return p;
}

// AST_nilExpr, AST_varExpr, AST_intExpr, AST_stringExpr, AST_callExpr,
// AST_opExpr, AST_recExpr, AST_seqExpr, AST_assignExpr, AST_ifExpr,
// AST_whileExpr, AST_forExpr, AST_breakExpr, AST_letExpr, AST_arrayExpr

ast_expr Ast_nilexpr(int pos)
{
	ast_expr p =checked_malloc(sizeof(*p));
	p->kind = AST_nilExpr;
	p->pos = pos;
	return p;
}
ast_expr Ast_varexpr(int pos, ast_var var){
	ast_expr p = checked_malloc(sizeof(*p));
	p->kind = AST_varExpr;
	p->pos = pos;
	p->u.var = var;
	return p;
}
ast_expr Ast_intexpr(int pos, int i){
	ast_expr p = checked_malloc(sizeof(*p));
	p->kind = AST_intExpr;
	p->pos = pos;
	p->u.int_t = i;
	return p;
}
ast_expr Ast_stringexpr(int pos, string s){
	ast_expr p = checked_malloc(sizeof(*p));
	p->kind = AST_stringExpr;
	p->pos = pos;
	p->u.string_t =s;
	return p;
}
ast_expr Ast_callexpr(int pos, S_symbol func, ast_exprList args){
	ast_expr p = checked_malloc(sizeof(*p));
	p->kind = AST_callExpr;
	p->pos = pos;
	p->u.call.func = func;
	p->u.call.args = args;
	return p;
}
ast_expr Ast_opexpr(int pos, ast_operation operation, ast_expr left, ast_expr right){
	ast_expr p = checked_malloc(sizeof(*p));
	p->kind = AST_opExpr;
	p->pos = pos;
	p->u.op.oper = operation;
	p->u.op.left = left;
	p->u.op.right = right;
	return p;
}
ast_expr Ast_recexpr(int pos, S_symbol type, ast_efieldList fields){
	ast_expr p = checked_malloc(sizeof(*p));
	p->kind = AST_recExpr;
	p->pos = pos;
	p->u.record.type = type;
	p->u.record.fields = fields;
	return p;
}
ast_expr Ast_seqexpr(int pos, ast_exprList seq){
	ast_expr p = checked_malloc(sizeof(*p));
	p->kind = AST_seqExpr;
	p->pos = pos;
	p->u.seq = seq;
	return p;
}
ast_expr Ast_assignexpr(int pos, ast_var var, ast_expr expr){
	ast_expr p = checked_malloc(sizeof(*p));
	p->kind = AST_assignExpr;
	p->pos = pos;
	p->u.assign.var = var;
	p->u.assign.expr = expr;
	return p;
}
ast_expr Ast_ifexpr(int pos, ast_expr condition, ast_expr then, ast_expr else_){
	ast_expr p = checked_malloc(sizeof(*p));
	p->kind = AST_ifExpr;
	p->pos = pos;
	p->u.if_.condition = condition;
	p->u.if_.then = then;
	p->u.if_.else = else_;
	return p;
}
ast_expr Ast_whileexpr(int pos, ast_expr condition, ast_expr body) {
	ast_expr p = checked_malloc(sizeof(*p));
	p->kind = AST_whileExpr;
	p->pos = pos;
	p->u.while_.condition = condition;
	p->u.while_.body = body;
	return p;
}
ast_expr Ast_forexpr(int pos, S_symbol var, ast_expr lo, ast_expr hi, ast_expr body) {
	ast_expr p = checked_malloc(sizeof(*p));
	p->kind = AST_forExpr;
	p->pos = pos;
	p->u.for_.var = var;
	p->u.for_.lo = lo;
	p->u.for_.hi = hi;
	p->u.for_.body = body;
	p->u.for_.escape = TRUE;
	return p;
}
ast_expr Ast_breakexpr(int pos) {
	ast_expr p = checked_malloc(sizeof(*p));
	p->kind = AST_breakExpr;
	p->pos = pos;
	return p;
}
ast_expr Ast_letexpr(int pos, ast_declList decls, ast_expr body) {
	ast_expr p = checked_malloc(sizeof(*p));
	p->kind = AST_letExpr;
	p->pos = pos;
	p->u.let.decls = decls;
	p->u.let.body = body;
	return p;
}
ast_expr Ast_arrayexpr(int pos, S_symbol type, ast_expr size, ast_expr init) {
	ast_expr p = checked_malloc(sizeof(*p));
	p->kind = AST_arrayExpr;
	p->pos = pos;
	p->u.array.type = type;
	p->u.array.size = size;
	p->u.array.init = init;
	return p;
}

// AST_functionDecl, AST_varDecl, AST_typeDecl

ast_decl Ast_functiondecl(int pos, ast_funcdeclList function) {
	ast_decl p = checked_malloc(sizeof(*p));
	p->kind = AST_functionDecl;
	p->pos = pos;
	p->u.function = function;
	return p;
}
ast_decl Ast_vardecl(int pos, S_symbol var, S_symbol type, ast_expr init) {
	ast_decl p = checked_malloc(sizeof(*p));
	p->kind = AST_varDecl;
	p->pos = pos;
	p->u.var.var = var;
	p->u.var.type = type;
	p->u.var.init = init;
	p->u.var.escape = TRUE;
	return p;
}
ast_decl Ast_typedecl(int pos, ast_nametypeList type) {
	ast_decl p = checked_malloc(sizeof(*p));
	p->kind = AST_typeDecl;
	p->pos = pos;
	p->u.type = type;
	return p;
}

// AST_nameType, AST_recordType, AST_arrayType
ast_type Ast_nametype(int pos, S_symbol name) {
	ast_type p = checked_malloc(sizeof(*p));
	p->kind = AST_nameType;
	p->pos = pos;
	p->u.name = name;
	return p;
}
ast_type Ast_recordtype(int pos, ast_fieldList record) {
	ast_type p = checked_malloc(sizeof(*p));
	p->kind = AST_recordType;
	p->pos = pos;
	p->u.record = record;
	return p;
}
ast_type Ast_arraytype(int pos, S_symbol array) {
	ast_type p = checked_malloc(sizeof(*p));
	p->kind = AST_arrayType;
	p->pos = pos;
	p->u.array = array;
	return p;
}

ast_field Ast_field(S_symbol name, S_symbol type) {
	ast_field p = checked_malloc(sizeof(*p));
	p->name = name;
	p->type = type;
	p->escape = FALSE;
	return p;
}
ast_fieldList Ast_fieldlist(ast_field head, ast_fieldList tail) {
	ast_fieldList p = checked_malloc(sizeof(*p));
	p->head = head;
	p->tail = tail;
	return p;
}
ast_exprList Ast_exprlist(ast_expr head, ast_exprList tail) {
	ast_exprList p = checked_malloc(sizeof(*p));
	p->head = head;
	p->tail = tail;
	return p;
}
ast_funcdecl Ast_funcdecl(int pos, S_symbol name, ast_fieldList params,
	S_symbol result, ast_expr body) {
	ast_funcdecl p = checked_malloc(sizeof(*p));
	p->pos = pos;
	p->name = name;
	p->params = params;
	p->result = result;
	p->body = body;
	return p;
}
ast_funcdeclList Ast_funcdecllist(ast_funcdecl head, ast_funcdeclList tail) {
	ast_funcdeclList p = checked_malloc(sizeof(*p));
	p->head = head;
	p->tail = tail;
	return p;
}
ast_declList Ast_decllist(ast_decl head, ast_declList tail) {
	ast_declList p = checked_malloc(sizeof(*p));
	p->head = head;
	p->tail = tail;
	return p;
}
ast_nametype Ast_nametype(S_symbol name, ast_type type) {
	ast_nametype p = checked_malloc(sizeof(*p));
	p->name = name;
	p->type = type;
	return p;
}
ast_nametypeList Ast_nametypelist(ast_nametype head, ast_nametypeList tail) {
	ast_nametypeList p = checked_malloc(sizeof(*p));
	p->head = head;
	p->tail = tail;
	return p;
}
ast_efield Ast_efield(int pos, S_symbol name, ast_expr expr) {
	ast_efield p = checked_malloc(sizeof(*p));
	p->pos = pos;
	p->name = name;
	p->expr = expr;
	return p;
}
ast_efieldList Ast_efieldlist(ast_efield head, ast_efieldList tail) {
	ast_efieldList p = checked_malloc(sizeof(*p));
	p->head = head;
	p->tail = tail;
	return p;
}