#ifndef __ERROR_MSG_H__
#define __ERROR_MSG_H__

typedef struct _lineList * lineList;
struct _lineList {
    int pos;
    lineList next;
};

void em_newline(int pos);
void em_error(int pos, string msg);
void em_reset(string fname);

#endif
