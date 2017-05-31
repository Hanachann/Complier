#ifndef SYMBOL_H
#define SYMBOL_H
#include "table.h"
#include "util.h"

typedef struct S_symbol_ *S_symbol;

S_symbol S_Symbol(string name);

string S_name(S_symbol sym);

typedef struct Tab_teble_ *S_table;

S_table S_empty(void);

void S_enter(S_table tab,S_symbol sym, void *value);

void *S_look(S_table tab,S_symbol sym);

void S_beginScope(S_table tab);

void S_endScope(S_table tab);

#endif