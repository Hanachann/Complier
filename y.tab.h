/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_ID = 258,
    TK_STRING = 259,
    TK_INT = 260,
    TK_COMMA = 261,
    TK_COLON = 262,
    TK_LPARAN = 263,
    TK_RPARAN = 264,
    TK_LBRACK = 265,
    TK_RBRACK = 266,
    TK_LBRACE = 267,
    TK_RBRACE = 268,
    TK_DOT = 269,
    TK_ARRAY = 270,
    TK_IF = 271,
    TK_THEN = 272,
    TK_ELSE = 273,
    TK_WHILE = 274,
    TK_FOR = 275,
    TK_TO = 276,
    TK_LET = 277,
    TK_IN = 278,
    TK_END = 279,
    TK_OF = 280,
    TK_BREAK = 281,
    TK_NIL = 282,
    TK_FUNCTION = 283,
    TK_VAR = 284,
    TK_TYPE = 285,
    TK_SEMICOLON = 286,
    TK_DO = 287,
    TK_ASSIGN = 288,
    TK_OR = 289,
    TK_AND = 290,
    TK_EQ = 291,
    TK_NEQ = 292,
    TK_LT = 293,
    TK_LE = 294,
    TK_GT = 295,
    TK_GE = 296,
    TK_PLUS = 297,
    TK_MINUS = 298,
    TK_TIMES = 299,
    TK_DIVIDE = 300,
    TK_UMINUS = 301
  };
#endif
/* Tokens.  */
#define TK_ID 258
#define TK_STRING 259
#define TK_INT 260
#define TK_COMMA 261
#define TK_COLON 262
#define TK_LPARAN 263
#define TK_RPARAN 264
#define TK_LBRACK 265
#define TK_RBRACK 266
#define TK_LBRACE 267
#define TK_RBRACE 268
#define TK_DOT 269
#define TK_ARRAY 270
#define TK_IF 271
#define TK_THEN 272
#define TK_ELSE 273
#define TK_WHILE 274
#define TK_FOR 275
#define TK_TO 276
#define TK_LET 277
#define TK_IN 278
#define TK_END 279
#define TK_OF 280
#define TK_BREAK 281
#define TK_NIL 282
#define TK_FUNCTION 283
#define TK_VAR 284
#define TK_TYPE 285
#define TK_SEMICOLON 286
#define TK_DO 287
#define TK_ASSIGN 288
#define TK_OR 289
#define TK_AND 290
#define TK_EQ 291
#define TK_NEQ 292
#define TK_LT 293
#define TK_LE 294
#define TK_GT 295
#define TK_GE 296
#define TK_PLUS 297
#define TK_MINUS 298
#define TK_TIMES 299
#define TK_DIVIDE 300
#define TK_UMINUS 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "yacc.y" /* yacc.c:1909  */

	int pos;
    int num;
    string str;
    ast_declList declList;
    ast_exprList exprList;
    ast_funcdeclList funcdeclList;
    ast_nametypeList nametypeList;
    ast_fieldList fieldList;
    ast_efieldList efieldList;
    S_symbol sym;
    ast_decl decl;
    ast_expr expr;
    ast_type type;
    ast_var var;
    ast_funcdecl func;

#line 164 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
