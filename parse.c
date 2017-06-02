#include "ast.h"
#include "ErrorMsg.h"
#include "y.tab.h"
#include "symbol.h"

extern int yyparse(void);

static void var_p(FILE *filename, ast_var data, int d);
static void decl_p(FILE *filename, ast_decl data, int d);
static void type_p(FILE *filename, ast_type data, int d);
static void field_p(FILE *filename, ast_field data, int d);
static void fieldList_p(FILE *filename, ast_fieldList data, int d);
static void exprList_p(FILE *filename, ast_exprList data, int d);
static void funcdecl_p(FILE *filename, ast_funcdecl data, int d);
static void funcdeclList_p(FILE *filename, ast_funcdeclList data, int d);
static void declList_p(FILE *filename, ast_declList data, int d);
static void nametype_p(FILE *filename, ast_nametype data, int d);
static void nametypeList_p(FILE *filename, ast_nametypeList data, int d);
static void efield_p(FILE *filename, ast_efield data, int d);
static void efieldList_p(FILE *filename, ast_efieldList data, int d);
static void oper_p(FILE *filename, ast_operation data);
void expr_p(FILE *filename, ast_expr data, int d);

static void Indent(FILE *filename,int d){
	int i;
	for (i = 0; i <= d; i++) fprintf(filename,"-");
}

ast_expr parser(string filename){
	return parse(filename);
}

static char operation_str[][12] = {
	"PLUS", "MINUS", "TIMES", "DIVIDE",
	"EQUAL", "NOTEQUAL", "LESSTHAN", "LESSEQ", "GREAT", "GREATEQ" };

static void var_p(FILE *filename, ast_var data, int d)
{
	Indent(filename, d);
	switch (data->kind)
	{
		case AST_SimpleVar:
		{
			fprintf(filename, "simpleVar(%s)", S_name(data->u.simple));
			break;
		}
		case AST_FieldVar:
		{
			fprintf(filename, "%s\n", "fieldVar(");
			var_p(filename, data->u.field.var, d + 1);
			fprintf(filename, "%s\n", ",");
			Indent(filename, d + 1);
			fprintf(filename, "%s)", S_name(data->u.field.sym));
			break;
		}
		case AST_SubscriptVar:
		{
			fprintf(filename, "%s\n", "subscriptVar(");
			var_p(filename, data->u.subscript.var, d + 1);
			fprintf(filename, "%s\n", ",");
			expr_p(filename, data->u.subscript.expr, d + 1);
			fprintf(filename, "%s", ")");
			break;
		}
		default:
			assert(0);
			break;
	}
}


static void oper_p(FILE *filename, ast_operation data)
{
	fprintf(filename, "%s", operation_str[data]);
}

void expr_p(FILE *filename, ast_expr data, int d)
{
	Indent(filename, d);
	switch (data->kind)
	{
		case AST_varExpr: 
		{
			fprintf(filename, "varExp(\n");
			var_p(filename, data->u.var, d + 1);
			fprintf(filename, "%s", ")");
			break;
		}
		case AST_nilExpr:
		{
			fprintf(filename, "nilExp()");
			break;
		}
		case AST_intExpr:
		{
			fprintf(filename, "intExp(%d)", data->u.int_t);
			break;
		}
		case AST_stringExpr:
		{
			fprintf(filename, "stringExp(%s)", data->u.string_t);
			break;
		}
		case AST_callExpr:
		{
			fprintf(filename, "callExp(%s,\n", S_name(data->u.call.func));
			exprList_p(filename, data->u.call.args, d + 1);
			fprintf(filename, ")");
			break;
		}
		case AST_opExpr:
		{
			fprintf(filename, "opExp(\n");
			Indent(filename, d + 1);
			oper_p(filename, data->u.op.oper);
			fprintf(filename, ",\n");
			expr_p(filename, data->u.op.left, d + 1);
			fprintf(filename, ",\n");
			expr_p(filename, data->u.op.right, d + 1);
			fprintf(filename, ")");
			break;
		}
		case AST_recExpr:
		{
			fprintf(filename, "recordExp(%s,\n", S_name(data->u.record.type));
			efieldList_p(filename, data->u.record.fields, d + 1);
			fprintf(filename, ")");
			break;
		}
		case AST_seqExpr:
		{
			fprintf(filename, "seqExp(\n");
			exprList_p(filename, data->u.seq, d + 1);
			fprintf(filename, ")");
			break;
		}
		case AST_assignExpr:
		{
			fprintf(filename, "assignExpr(\n");
			var_p(filename, data->u.assign.var, d + 1);
			fprintf(filename, ",\n");
			expr_p(filename, data->u.assign.expr, d + 1);
			fprintf(filename, ")");
			break;
		}
		case AST_ifExpr:
		{
			fprintf(filename, "ifExp(\n");
			expr_p(filename, data->u.if_.condition, d + 1);
			fprintf(filename, ",\n");
			expr_p(filename, data->u.if_.then, d + 1);
			if (data->u.if_.else_) {
				fprintf(filename, ",\n");
				expr_p(filename, data->u.if_.else_, d + 1);
			}
			fprintf(filename, ")");
			break;
		}
		case AST_whileExpr:
		{
			fprintf(filename, "whileExp(\n");
			expr_p(filename, data->u.while_.condition, d + 1);
			fprintf(filename, ",\n");
			expr_p(filename, data->u.while_.body, d + 1);
			fprintf(filename, ")\n");
			break;
		}
		case AST_forExpr:
		{
			fprintf(filename, "forExp(%s,\n", S_name(data->u.for_.var));
			expr_p(filename, data->u.for_.lo, d + 1);
			fprintf(filename, ",\n");
			expr_p(filename, data->u.for_.hi, d + 1);
			fprintf(filename, "%s\n", ",");
			expr_p(filename, data->u.for_.body, d + 1);
			fprintf(filename, ",\n");
			Indent(filename, d + 1);
			fprintf(filename, "%s", data->u.for_.escape ? "TRUE)" : "FALSE)");
			break;
		}
		case AST_breakExpr:
		{
			fprintf(filename, "breakExp()");
			break;
		}
		case AST_letExpr:
		{
			fprintf(filename, "letExp(\n");
			declList_p(filename, data->u.let.decls, d + 1);
			fprintf(filename, ",\n");
			expr_p(filename, data->u.let.body, d + 1);
			fprintf(filename, ")");
			break;
		}
		case AST_arrayExpr:
		{
			fprintf(filename, "arrayExp(%s,\n", S_name(data->u.array.type));
			expr_p(filename, data->u.array.size, d + 1);
			fprintf(filename, ",\n");
			expr_p(filename, data->u.array.init, d + 1);
			fprintf(filename, ")");
			break;
		}
	default:
		assert(0);
		break;	
	}
}


static void decl_p(FILE *filename, ast_decl data, int d)
{
	Indent(filename, d);
	switch (data->kind) {
		case AST_functionDecl:
		{
			fprintf(filename, "functionDec(\n");
			funcdeclList_p(filename, data->u.function, d + 1);
			fprintf(filename, ")");
			break;
		}
		case AST_varDecl:
		{
			fprintf(filename, "varDec(%s,\n", S_name(data->u.var.var));
			if (data->u.var.type) {
				Indent(filename, d + 1); 
				fprintf(filename, "%s,\n", S_name(data->u.var.type));
			}
			expr_p(filename, data->u.var.init, d + 1); fprintf(filename, ",\n");
			Indent(filename, d + 1); 
			fprintf(filename, "%s", data->u.var.escape ? "TRUE)" : "FALSE)");
			break;
		}
		case AST_typeDecl:
		{
			fprintf(filename, "typeDec(\n");
			nametypeList_p(filename, data->u.type, d + 1); 
			fprintf(filename, ")");
			break;
		}
		default:
			assert(0);
			break;
	}
}
static void type_p(FILE *filename, ast_type data, int d) {
	Indent(filename, d);
	switch (data->kind)
	{
		case AST_nameType:
		{
			fprintf(filename, "nameType(%s)", S_name(data->u.name));
			break;
		}
		case AST_recordType:
		{
			fprintf(filename, "recordType(\n");
			fieldList_p(filename, data->u.record, d + 1);
			fprintf(filename, ")");
			break;
		}
		case AST_arrayType:
		{
			fprintf(filename, "arrayType(%s)", S_name(data->u.array));
			break;
		}
	default:
		assert(0);
		break;
	}
}

static void field_p(FILE *filename, ast_field data, int d) {
	Indent(filename, d);
	fprintf(filename, "field(%s,\n", S_name(data->name));
	Indent(filename, d + 1);
	fprintf(filename, "%s,\n", S_name(data->type));
	Indent(filename, d + 1);
	fprintf(filename, "%s", data->escape ? "TRUE)" : "FALSE)");
}
static void fieldList_p(FILE *filename, ast_fieldList data, int d)
{
	Indent(filename, d);
	if (data) {
		fprintf(filename, "fieldList(\n");
		field_p(filename, data->head, d + 1);
		fprintf(filename, ",\n");
		fieldList_p(filename, data->tail, d + 1);
		fprintf(filename, ")");
	}
	else
		fprintf(filename, "fieldList()");
}
static void exprList_p(FILE *filename, ast_exprList data, int d)
{
	Indent(filename, d);
	if (data) {
		fprintf(filename, "expList(\n");
		expr_p(filename, data->head, d + 1);
		fprintf(filename, ",\n");
		exprList_p(filename, data->tail, d + 1);
		fprintf(filename, ")");
	}
	else
		fprintf(filename, "expList()");
}
static void funcdecl_p(FILE *filename, ast_funcdecl data, int d)
{
	Indent(filename, d);
	fprintf(filename, "funcdecl(%s,\n", S_name(data->name));
	fieldList_p(filename, data->params, d + 1);
	fprintf(filename, ",\n");
	if (data->result) {
		Indent(filename, d + 1);
		fprintf(filename, "%s,\n", S_name(data->result));
	}
	expr_p(filename, data->body, d + 1);
	fprintf(filename, ")");
}
static void funcdeclList_p(FILE *filename, ast_funcdeclList data, int d)
{
	Indent(filename, d);
	if (data) {
		fprintf(filename, "funcdeclList(\n");
		funcdecl_p(filename, data->head, d + 1);
		fprintf(filename, ",\n");
		funcdeclList_p(filename, data->tail, d + 1);
		fprintf(filename, ")");
	}
	else
		fprintf(filename, "funcdeclList()");
}
static void declList_p(FILE *filename, ast_declList data, int d)
{
	Indent(filename, d);
	if (data) {
		fprintf(filename, "declList(\n");
		decl_p(filename, data->head, d + 1);
		fprintf(filename, ",\n");
		declList_p(filename, data->tail, d + 1);
		fprintf(filename, ")");
	}
	else fprintf(filename, "declList()");
}
static void nametype_p(FILE *filename, ast_nametype data, int d)
{
	Indent(filename, d);
	fprintf(filename, "nameType(%s,\n", S_name(data->name));
	type_p(filename, data->type, d + 1);
	fprintf(filename, ")");
}
static void nametypeList_p(FILE *filename, ast_nametypeList data, int d)
{
	Indent(filename, d);
	if (data) {
		fprintf(filename, "nametypeList(\n");
		nametype_p(filename, data->head, d + 1);
		fprintf(filename, ",\n");
		nametypeList_p(filename, data->tail, d + 1);
		fprintf(filename, ")");
	}
	else 
		fprintf(filename, "nametypeList()");
}
static void efield_p(FILE *filename, ast_efield data, int d)
{
	Indent(filename, d);
	if (data) {
		fprintf(filename, "efield(%s,\n", S_name(data->name));
		expr_p(filename, data->expr, d + 1);
		fprintf(filename, ")");
	}
	else
		fprintf(filename, "efield()");
}
static void efieldList_p(FILE *filename, ast_efieldList data, int d)
{
	Indent(filename, d);
	if (data) {
		fprintf(filename, "efieldList(\n");
		efield_p(filename, data->head, d + 1);
		fprintf(filename, ",\n");
		efieldList_p(filename, data->tail, d + 1);
		fprintf(filename, ")");
	}
	else
		fprintf(filename, "efieldList()");
}


int main(int argc, char** argv)
{
	if(argc < 2)
		exit(1);
	FILE *fname;
	ast_expr absTree = parser(argv[1]);
	fname = fopen("result.txt", "w");
	expr_p(fname, absTree, 0);
	fclose(fname);
	return 0;
}

