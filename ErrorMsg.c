#include "ErrorMsg.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

extern FILE * yyin;
static string file_name = "";
static int line_num = 1;
static lineList line_lst = NULL;


void em_newline(int pos) {
    line_num++;
    lineList newline = checked_malloc(sizeof(struct _lineList));
    newline->pos = pos;
    newline->next = line_lst;
    line_lst = newline;
}

void em_error(int pos, string msg) {
    int n = line_num;
    lineList p = line_lst;

    while (p != NULL && p->pos >= pos) {
        p = p->next;
        n--;
    }
    
    if (fileName)
        fprintf(stderr,"%s:",file_name);

    if (lines) 
        fprintf(stderr,"%d.%d: ", n, pos - p->pos);
    
    fprintf(stderr, "%s\n", msg);
}

void em_reset(string fname) {
    file_name = fname;
    line_num = 1;
    line_lst = checked_malloc(sizeof(struct _lineList));
    line_lst->pos = 0; line_lst->next = NULL;

    yyin = fopen(fname,"r");
    if (!yyin) {
        em_error(0,"cannot open");
        exit(1);
    }
}
