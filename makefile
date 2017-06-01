a.out: parsetest.o y.tab.o lex.yy.o errormsg.o util.o ast.o symbol.o table.o
	cc -g parse.o y.tab.o lex.yy.o ErrorMsg.o util.o ast.o symbol.o table.o -o out

parsetest.o: parse.c ErrorMsg.h util.h
	cc -g -c parse.c

y.tab.o: y.tab.c
	cc -g -c y.tab.c

y.tab.c: yacc.y
	yacc -dv yacc.y

y.tab.h: y.tab.c
	echo "y.tab.h was created at the same time as y.tab.c"

errormsg.o: ErrorMsg.c ErrorMsg.h util.h
	cc -g -c ErrorMsg.c

lex.yy.o: lex.yy.c y.tab.h ErrorMsg.h util.h
	cc -g -c lex.yy.c

lex.yy.c: lex.l
	lex lex.l

util.o: util.c util.h
	cc -g -c util.c

ast.o: ast.c ast.h
	cc -g -c ast.c

symbol.o: symbol.c symbol.h
	cc -g -c symbol.c

table.o: table.c table.h
	cc -g -c table.c

clean: 
	rm -f a.out util.o parsetest.o lex.yy.o errormsg.o y.tab.c y.tab.h y.tab.o

