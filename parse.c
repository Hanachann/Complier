#include "ast.h"
#include "ErrorMsg.h"
#include "y.tab.h"

extern int yyparse(void);

ast_expr parser(string filename){
	return parse(filename);
}


int main(int argc, char** argv)
{
	if(argc < 2)
		exit(1);
	ast_expr t = parser(argv[1]);
	printf("%d", t->kind);
	return 0;
}

