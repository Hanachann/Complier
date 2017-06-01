#include "ErrorMsg.h"

bool anyErrors = FALSE;
static string fileName = "";
static int lineNum = 1;
int em_tokPos = 0;
extern FILE *yyin;
typedef struct intList {int i;struct intList *reset;} *IntList;

static IntList intList(int i, IntList reset){
	IntList l = checked_malloc(sizeof *l);
	l->i = i; l->reset = reset;
	return l;
}

static IntList linePos = NULL;

void em_newline(void){
	lineNum++;
	linePos = intList(em_tokPos, linePos);
}

void em_error(int pos, char *msg, ...){
	va_list ap;
	IntList lines = linePos;
	int num = lineNum;

	anyErrors = TRUE;
	 while (lines && lines->i >= pos)
	 {
	 	lines = lines->reset;
	 	num--;
	 }
	 if (fileName) fprintf(stderr,"%s:",fileName);
	 if (lines) fprintf(stderr,"%d.%d: ",num, pos - lines->i);
	 va_start(ap,msg);
	 vfprintf(stderr, msg, ap);
	 va_end(ap);
	 fprintf(stderr,"\n");
}

void em_reset(char *file){
	anyErrors = FALSE;
	fileName = file;
	lineNum = 1;
	linePos = intList(0,NULL);
	yyin = fopen(file, "r");
	if (!yyin) {
		em_error(0,"cannot open");
		exit(1);
	}
}
