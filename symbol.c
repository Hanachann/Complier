#include <stdio.h>
#include <string.h>
#include "util.h"
#include "symbol.h"
#include "table.h"

struct S_symbol_ {string name; S_symbol next;};

static S_symbol mallocsym(string name, S_symbol next){
	S_symbol s = checked_malloc(sizeof(*s));
	s->name = name;
	s->next = next;
	return s;
}

#define HASH_SIZE 109

static S_symbol hashtable[HASH_SIZE];

static unsigned int hash(char * ch){
	unsigned int h= 0;
	char *p;
	for (p = ch; *p; p++)
		h=h*65599 + *p;
	return h;
}

S_symbol S_Symbol(string name){
	int index = hash(name) % HASH_SIZE;
	S_symbol syms = hashtable[index],sym;
	for (sym = syms; sym; sym = sym->next)
		if (strcmp((string)sym->name,name) == 0) 
			return sym;
		sym = mallocsym(name,syms);
		hashtable[index] = sym;
		return sym;
}

string S_name(S_symbol sym){
	return sym->name;
}

S_table S_empty(void){
	return TAB_empty();
}

void S_enter(S_table t, S_symbol sym, void *value){
	TAB_enter(t,sym,value);
}

void *S_look(S_table t, S_symbol sym){
	return TAB_look(t,sym);
}

static struct S_symbol_ marksym = {"<mark>",0};

void S_beginScope(S_table t){
	S_enter(t,&marksym,NULL);
}

void S_endScope(S_table t){
	S_symbol s;
	do s=TAB_pop(t);
	while (s != &marksym);
}

void S_dump(S_table t,void(*show)(S_symbol sym, void *binding)){
	TAB_dump(t,(void(*)(void *, void *)) show);
}
