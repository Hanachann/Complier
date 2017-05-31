/***************************************************************
 * Author:          Yicong Chen
 * Email:           704434921@qq.com
 * Last modified:	2017-05-26 20:52
 * Filename:		lex.l
 * Description:     
**************************************************************/

%{

#define __YY_LEX_H__

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Util.h"
#include "ErrorMsg.h"

extern FILE *yyin;

#define ADJ \
do{ \
    tokPos = char_pos; \
    char_pos += yyleng; \
} while(0) \


int yywrap(void);

void newline(void) {
    em_newline(char_c);
}

void err(int pos, string msg) {
    em_error(pos, msg);    
}

typedef _strInfo * strInfo;
struct _strInfo {
    string buf;
    int len;
    int cap;
};
static strInfo str;
static int _comment_level = 0;
unsigned int char_pos = 1;
unsigned int tokPos;
static void str_ini(void);
static void str_apd(char c);

%}

%%
[ \t\f\v\r]             { ADJ; continue;}
\n                      { ADJ; newline(); continue;}

"/*"                    { ADJ; _comment_level = 1; BEGIN(COMMENT); }
<COMMENT> {
    [^*/\n]*            { ADJ; continue;}
    "*"+[^*/\n]*        { ADJ; continue;}
    "/"+[^*/\n]*        { ADJ; continue;}
    \n                  { ADJ; newline(); continue;}
    "/"+"*"             { ADJ; _comment_level++; continue;}
    "*"+"/"             {
                            ADJ;
                            _comment_level--;
                            if (_comment_level <= 0)
                                BEGIN(INITIAL);
                        }
}

","                     { ADJ; return TK_COMMA; }
":"                     { ADJ; return TK_COLON; }
";"                     { ADJ; return TK_SEMICOLON; }
"("                     { ADJ; return TK_LPARAN; }
")"                     { ADJ; return TK_RPARAN; }
"["                     { ADJ; return TK_LBRACK; }
"]"                     { ADJ; return TK_RBRACK; }
"{"                     { ADJ; return TK_LBRACE; }
"}"                     { ADJ; return TK_RBRACE; }
"."                     { ADJ; return TK_DOT; }
"+"                     { ADJ; return TK_PLUS; }
"-"                     { ADJ; return TK_MINUS; }
"*"                     { ADJ; return TK_TIMES; }
"/"                     { ADJ; return TK_DIVIDE; }
"="                     { ADJ; return TK_EQ; }
"<>"                    { ADJ; return TK_NEQ; }
"<"                     { ADJ; return TK_LT; }
"<="                    { ADJ; return TK_LE; }
">"                     { ADJ; return TK_GT; }
">="                    { ADJ; return TK_GE; }
"&"                     { ADJ; return TK_AND; }
"|"                     { ADJ; return TK_OR; }
":="                    { ADJ; return TK_ASSIGN; }

array                   { ADJ; return TK_ARRAY; }
if                      { ADJ; return TK_IF; }
then                    { ADJ; return TK_THEN; }
else                    { ADJ; return TK_ELSE; }
while                   { ADJ; return TK_WHILE; }
for                     { ADJ; return TK_FOR; }
to                      { ADJ; return TK_TO; }
do                      { ADJ; return TK_DO; }
let                     { ADJ; return TK_LET; }
in                      { ADJ; return TK_IN; }
end                     { ADJ; return TK_END; }
of                      { ADJ; return TK_OF; }
break                   { ADJ; return TK_BREAK; }
nil                     { ADJ; return TK_NIL; }
function                { ADJ; return TK_FUNCTION; }
var                     { ADJ; return TK_VAR; }
type                    { ADJ; return TK_TYPE; }

[0-9]+                  { ADJ; yylval.num = atoi(yytext); return TK_INT; }
[_a-zA-Z][_a-zA-Z0-9]*  { ADJ; yylval.str = String(yytext); return TK_ID; }

\"                      { ADJ; str_ini(); BEGIN(STRING); }
<STRING> {
    \"                  {
                            ADJ;
                            BEGIN(INITIAL);
                            yylval.str = str->buf;
                            return TK_STRING;
                        }
    \n                  { ADJ; newline(); continue; }
    \\[0-9]{3}          {
                            ADJ;
                            int result;
                            sscanf(yytext + 1, "%d", &result);
                            if (result > 0xFF)
                                err(tok_pos, "Escape String out of range");
                            str_apd(result);
                        }
    \\n                 { ADJ; str_apd('\n'); continue; }
    \\t                 { ADJ; str_apd('\t'); continue; }
    \\\"                { ADJ; str_apd('\"'); continue; }
    \\\\                { ADJ; str_apd('\\'); continue; }
    \\(.|\n)            { ADJ; str_apd(yytext[1]); continue; }
    [^\\\n\"]+          {
                            ADJ;
                            char *p = yytext;
                            while (*p)
                            str_apd(*p++);
                        }
}

.                       { ADJ; err(tokPos, "Illegal token"); }


%%

int yywrap(void) {
    return 1;
}

static void str_ini(void) {
    str->buf = checked_malloc(32*sizeof(char));
    str->len = 0;
    str->cap = 32*sizeof(char);
    str->buf[0] = '\0';
}

static void str_apd(char c) {
    if(++(str->len) == str->cap) {
        str->cap *= 2;
        string p = checked_malloc(str->cap);
        memcpy(p, str->buf, str->len);
        free(str->buf);
        str->buf = p;
    }
    str->buf[str->len - 1] = c;
    str->buf[str->len] = '\0';
}
