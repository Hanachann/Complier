#include <stdio.h>
#include "util.h"
#include "table.h"

#define TABLESIZE 127

typedef struct binder_ *binder;
struct binder_{
	void *key;
	void *value;
	binder next;
	void *prevtop;
};
struct TAB_table_{
	binder table[TABLESIZE];
	void *top;
};

static binder Binder(void *key, void *value, binder next, void *prevtop){
	binder b = checked_malloc(sizeof(*b));
	b->key = key;
	b->value = value;
	b->next = next;
	b->prevtop = prevtop;
	return b;
}

TAB_table TAB_empty(void){
	TAB_table t = checked_malloc(sizeof(*t));
	int i;
	t->top = NULL;
	for (i = 0; i < TABLESIZE; i++)
		t->table[i] = NULL;
	return t;
}

void TAB_enter(TAB_table t,void *key, void *value){
	int index;
	assert(t && key);
	index = ((unsigned)key) % TABLESIZE;
	t->table[index] = Binder(key,value,t->table[index],t->top);
	t->top = key;
}

void *TAB_look(TAB_table t,void *key){
	int index;
	binder b;
	assert(t && key);
	index = ((unsigned)key) % TABLESIZE;
	for (b=t->table[index];b;b=b->next)
		if (b->key == key) return  b->value;
	return NULL;
}

void *TAB_pop(TAB_table t){
	void *k;
	binder b;
	int index;
	assert(t);
	k = t->top;
	assert(k);
	index = ((unsigned)k) % TABLESIZE;
	b = t->table[index];
	assert(b);
	t->table[index] = b->next;
	t->top = b->prevtop;
	return b->key;
}

void TAB_dump(TAB_table t, void (*show)(void *key, void *value)){
	void *k = t->top;
	int index = ((unsigned)k) % TABLESIZE;
	binder b = t->table[index];
	if (b == NULL) return ;
	t->table[index] = b->next;
	t->top = b->prevtop;
	show(b->key,b->value);
	TAB_dump(t,show);
	assert(t->top == b->prevtop && t->table[index] == b->next);
	t->top = k;
	t->table[index] = b;
}