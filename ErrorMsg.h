#ifndef __ERROR_MSG_H__
#define __ERROR_MSG_H__

#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

extern bool em_anyerrors;
extern int em_tokPos;

void em_newline(void);
void em_error(int pos, char *msg, ...);
void em_reset(char *file);
#endif
