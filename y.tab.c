/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "yacc.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>

#include "ErrorMsg.h"
#include "symbol.h"
#include "util.h"
#include "ast.h"



int yylex(void);
void yyerror(char *msg);

#line 81 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 16 "yacc.y" /* yacc.c:355  */

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

#line 231 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */
#line 34 "yacc.y" /* yacc.c:358  */

static void print_token_value(FILE *fp, int type, YYSTYPE value);
#define YYPRINT(fp, type, value) print_token_value(fp,type,value);
#define DECLSLIST_ADD(target,prev,elem) \
	do \
	{ \
		ast_declList p, e = Ast_decllist((elem),NULL); \
		(target) = p = (prev); \
		if (p) \
			{ \
				while (p->tail) \
					p = p->tail; \
				p->tail = e; \
			} \
			else \
				(target) = e; \
	} \
	while (FALSE)

#define TYPEDECLS_ADD(target,prev,elem) \
	do \
	{ \
		ast_nametypeList p, e = Ast_nameTypelist((elem),NULL); \
		(target) = p = (prev); \
		if (p) \
			{ \
				while (p->tail) \
					p = p->tail; \
				p->tail = e; \
			} \
			else \
				(target) = e; \
	} \
	while (FALSE)

#define FUNCDECLS_ADD(target,prev,elem) \
	do \
	{ \
		ast_funcdeclList p, e = Ast_funcdecllist((elem),NULL); \
		(target) = p = (prev); \
		if (p) \
			{ \
				while (p->tail) \
					p = p->tail; \
				p->tail = e; \
			} \
			else \
				(target) = e; \
	} \
	while (FALSE)

#define EXPRLIST_ADD(target,prev,elem) \
	do \
	{ \
		ast_exprList p, e = Ast_exprlist((elem),NULL); \
		(target) = p = (prev); \
		if (p) \
			{ \
				while (p->tail) \
					p = p->tail; \
				p->tail = e; \
			} \
			else \
				(target) = e; \
	} \
	while (FALSE)

#define EFIELDLIST_ADD(target,prev,elem) \
	do \
	{ \
		ast_efieldList p, e = Ast_efieldlist((elem),NULL); \
		(target) = p = (prev); \
		if (p) \
			{ \
				while (p->tail) \
					p = p->tail; \
				p->tail = e; \
			} \
			else \
				(target) = e; \
	} \
	while (FALSE)

#define FIELDLIST_ADD(target,prev,elem) \
	do \
	{ \
		ast_fieldList p, e = Ast_fieldlist((elem),NULL); \
		(target) = p = (prev); \
		if (p) \
			{ \
				while (p->tail) \
					p = p->tail; \
				p->tail = e; \
			} \
			else \
				(target) = e; \
	} \
	while (FALSE)

#define LVALUE_ACT(target, prev, elem) \
		do \
	{ \
		ast_var p, var = (elem); \
		(target) = p = (prev); \
		if (p) \
		{ \
			while (p->u.field.var) \
				p = p->u.field.var; \
			p->u.field.var = var; \
		} \
		else \
			(target) = var; \
	} \
	while (FALSE)
static ast_expr _program;


#line 365 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   398

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   208,   208,   212,   214,   216,   218,   220,   222,   224,
     226,   228,   230,   232,   234,   236,   238,   240,   242,   244,
     246,   248,   250,   252,   254,   256,   258,   260,   262,   264,
     266,   268,   270,   272,   274,   279,   280,   284,   286,   287,
     291,   293,   297,   299,   301,   306,   307,   311,   313,   317,
     319,   323,   325,   329,   332,   337,   338,   343,   344,   349,
     350,   354,   359,   360,   362,   366
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_ID", "TK_STRING", "TK_INT",
  "TK_COMMA", "TK_COLON", "TK_LPARAN", "TK_RPARAN", "TK_LBRACK",
  "TK_RBRACK", "TK_LBRACE", "TK_RBRACE", "TK_DOT", "TK_ARRAY", "TK_IF",
  "TK_THEN", "TK_ELSE", "TK_WHILE", "TK_FOR", "TK_TO", "TK_LET", "TK_IN",
  "TK_END", "TK_OF", "TK_BREAK", "TK_NIL", "TK_FUNCTION", "TK_VAR",
  "TK_TYPE", "TK_SEMICOLON", "TK_DO", "TK_ASSIGN", "TK_OR", "TK_AND",
  "TK_EQ", "TK_NEQ", "TK_LT", "TK_LE", "TK_GT", "TK_GE", "TK_PLUS",
  "TK_MINUS", "TK_TIMES", "TK_DIVIDE", "TK_UMINUS", "$accept", "program",
  "expr", "decls", "decl", "type_decls", "type", "fields", "var_decl",
  "func_decls", "func_decl", "expr_list", "args_list", "efield_list",
  "field_list", "lvalue", "lvalue_", "id", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF -34

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-34)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     136,   -34,   -34,   -34,    79,   136,   136,    13,   -34,   -34,
     -34,   136,    39,   310,     7,   100,   -34,   151,   202,   280,
      14,   -21,   264,   -34,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,    15,   136,   127,
     136,     2,    13,   -34,   -34,   136,   136,   136,   136,    13,
      13,    13,   -34,    18,   -34,    34,   -34,   -34,   322,   333,
     343,   353,   353,   353,   353,   353,   353,   -33,   -33,   -34,
     -34,   136,   322,   -34,   310,   166,   -34,    31,    27,   -17,
     322,   227,   249,    61,    -1,    40,    13,   -34,   322,     4,
      64,   136,   136,   -34,   136,   136,   -34,    13,    13,   136,
      65,    45,   136,   -34,   136,   -34,   310,   187,   310,   295,
      66,    78,    53,   310,    13,    67,   -34,   -34,    65,   310,
     310,    32,    27,   136,    -3,    13,   136,    81,    13,   -34,
      13,   -34,   322,    13,   136,   -34,   310,   -34,   -34,    68,
      73,   310,    91,   136,   136,    13,   310,   310,    93,    13,
     -34
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    65,     9,     8,     0,     0,     0,     0,    35,    33,
       4,     0,     0,     2,     3,    62,     6,     0,     0,     0,
       0,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     0,     0,
       0,     0,     0,    61,     7,     0,     0,     0,     0,     0,
       0,     0,    36,    37,    38,    39,    49,    10,    53,    24,
      23,    17,    18,    19,    20,    21,    22,    13,    14,    15,
      16,     0,    28,    11,    55,     0,    25,     0,    62,    29,
      31,     0,     0,     0,     0,     0,     0,    50,    54,     0,
      62,     0,     0,    63,     0,     0,    34,    45,     0,     0,
       0,     0,     0,    12,     0,    64,    57,     0,    30,     0,
       0,     0,     0,    47,    45,     0,    40,    42,     0,    56,
      27,     0,    62,     0,     0,     0,     0,     0,     0,    41,
       0,    26,    32,     0,     0,    59,    48,    43,    44,     0,
       0,    51,    46,     0,     0,     0,    58,    52,     0,     0,
      60
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -34,   -34,    25,   -34,   -34,   -34,   -16,   -11,   -34,   -34,
      58,   -34,   -34,   -34,   -34,   -34,   -12,    -7
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    21,    52,    53,   116,   110,    54,    55,
      56,    37,    89,   121,   142,    14,   105,    15
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      20,    94,    48,    43,   133,     1,    98,    49,    50,    51,
     102,    35,    36,   103,    24,    76,     1,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    17,
      18,    19,    99,   134,    77,    78,    22,    92,   130,    23,
      38,    42,    83,    84,    85,   131,    71,    47,    86,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    49,    72,    74,    75,    93,    91,     1,    97,
      79,    80,    81,    82,    92,   124,   100,   114,    42,   101,
     115,   118,     1,     2,     3,   125,   126,     4,    16,   104,
     111,   112,   128,   117,   137,     5,    88,   145,     6,     7,
     149,     8,   129,   127,   143,     9,    10,   111,    39,   144,
      40,   117,    41,    87,    42,     0,   106,   107,   135,   108,
     109,   138,    11,   139,   113,     0,   140,   119,     0,   120,
       1,     2,     3,     0,     0,     4,    73,     0,   148,     1,
       2,     3,   150,     5,     4,     0,     6,     7,   132,     8,
       0,   136,     5,     9,    10,     6,     7,     0,     8,   141,
      44,     0,     9,    10,     0,     0,     0,     0,   146,   147,
      11,     0,     0,     0,     0,     0,     0,    90,     0,    11,
       0,     0,    24,     0,     0,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    24,   122,     0,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,     0,     0,     0,     0,     0,     0,    24,    45,
       0,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    24,     0,     0,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,     0,
       0,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    96,     0,     0,     0,     0,     0,     0,
      24,     0,     0,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    24,     0,     0,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      57,    24,    46,     0,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    24,   123,     0,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    24,     0,     0,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36
};

static const yytype_int16 yycheck[] =
{
       7,    18,    23,    15,     7,     3,     7,    28,    29,    30,
       6,    44,    45,     9,    31,    13,     3,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,     4,
       5,     6,    33,    36,    41,    42,    11,    10,     6,     0,
      33,    14,    49,    50,    51,    13,    31,    33,    30,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    28,    38,    39,    40,    78,    36,     3,     8,
      45,    46,    47,    48,    10,     9,    36,    12,    14,    86,
      15,    36,     3,     4,     5,     7,    33,     8,     9,    25,
      97,    98,    25,   100,    13,    16,    71,     6,    19,    20,
       7,    22,   118,   114,    36,    26,    27,   114,     8,    36,
      10,   118,    12,    55,    14,    -1,    91,    92,   125,    94,
      95,   128,    43,   130,    99,    -1,   133,   102,    -1,   104,
       3,     4,     5,    -1,    -1,     8,     9,    -1,   145,     3,
       4,     5,   149,    16,     8,    -1,    19,    20,   123,    22,
      -1,   126,    16,    26,    27,    19,    20,    -1,    22,   134,
       9,    -1,    26,    27,    -1,    -1,    -1,    -1,   143,   144,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,    43,
      -1,    -1,    31,    -1,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    31,    11,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    31,    17,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    31,    -1,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    31,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    31,    32,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    31,    -1,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     8,    16,    19,    20,    22,    26,
      27,    43,    48,    49,    62,    64,     9,    49,    49,    49,
      64,    50,    49,     0,    31,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    58,    33,     8,
      10,    12,    14,    63,     9,    17,    32,    33,    23,    28,
      29,    30,    51,    52,    55,    56,    57,    46,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    31,    49,     9,    49,    49,    13,    64,    64,    49,
      49,    49,    49,    64,    64,    64,    30,    57,    49,    59,
      11,    36,    10,    63,    18,    21,    24,     8,     7,    33,
      36,    64,     6,     9,    25,    63,    49,    49,    49,    49,
      54,    64,    64,    49,    12,    15,    53,    64,    36,    49,
      49,    60,    11,    32,     9,     7,    33,    54,    25,    53,
       6,    13,    49,     7,    36,    64,    49,    13,    64,    64,
      64,    49,    61,    36,    36,     6,    49,    49,    64,     7,
      64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    50,    50,    51,    51,    51,
      52,    52,    53,    53,    53,    54,    54,    55,    55,    56,
      56,    57,    57,    58,    58,    59,    59,    60,    60,    61,
      61,    62,    63,    63,    63,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     3,     1,     1,
       3,     3,     5,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     7,     6,     3,     4,
       6,     4,     8,     1,     5,     0,     2,     1,     1,     1,
       4,     5,     1,     3,     3,     0,     4,     4,     6,     1,
       2,     7,     9,     2,     3,     0,     3,     0,     5,     0,
       5,     2,     0,     3,     4,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 209 "yacc.y" /* yacc.c:1646  */
    { _program = (yyvsp[0].expr); }
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 213 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_varexpr((yyvsp[0].var)->pos, (yyvsp[0].var)); }
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 215 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_nilexpr((yyvsp[0].pos)); }
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 217 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_seqexpr((yyvsp[-1].expr)->pos, Ast_exprlist((yyvsp[-1].expr),(yyvsp[0].exprList))); }
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 219 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_seqexpr((yyvsp[-1].pos), NULL); }
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 221 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 223 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_intexpr(em_tokPos, (yyvsp[0].num)); }
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 225 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_stringexpr(em_tokPos, (yyvsp[0].str)); }
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 227 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_opexpr((yyvsp[-2].pos), AST_MINUS, Ast_intexpr((yyvsp[-2].pos),0), (yyvsp[-1].expr)); }
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 229 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_callexpr((yyvsp[-1].pos), (yyvsp[-2].sym), NULL); }
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 231 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_callexpr((yyvsp[-3].pos), (yyvsp[-4].sym), Ast_exprlist((yyvsp[-2].expr), (yyvsp[-1].exprList))); }
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 233 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_opexpr((yyvsp[-1].pos), AST_PLUS, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 235 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_opexpr((yyvsp[-1].pos), AST_MINUS, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 237 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_opexpr((yyvsp[-1].pos), AST_TIMES, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 239 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_opexpr((yyvsp[-1].pos), AST_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 241 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_opexpr((yyvsp[-1].pos), AST_EQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 243 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_opexpr((yyvsp[-1].pos), AST_NEQ, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 245 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_opexpr((yyvsp[-1].pos), AST_LT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 247 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_opexpr((yyvsp[-1].pos), AST_LE, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 249 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_opexpr((yyvsp[-1].pos), AST_GT, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 251 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_opexpr((yyvsp[-1].pos), AST_GE, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 253 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_ifexpr((yyvsp[-1].pos), (yyvsp[-2].expr), (yyvsp[0].expr), Ast_intexpr((yyvsp[-1].pos), 0)); }
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 255 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_ifexpr((yyvsp[-1].pos), (yyvsp[-2].expr), Ast_intexpr((yyvsp[-1].pos), 1), (yyvsp[0].expr)); }
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 257 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_recexpr((yyvsp[-1].pos), (yyvsp[-2].sym), NULL); }
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 259 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_recexpr((yyvsp[-5].pos), (yyvsp[-6].sym), Ast_efieldlist(Ast_efield((yyvsp[-3].pos), (yyvsp[-4].sym), (yyvsp[-2].expr)),(yyvsp[-1].efieldList))); }
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 261 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_arrayexpr((yyvsp[-4].pos), (yyvsp[-5].sym), (yyvsp[-3].expr), (yyvsp[0].expr)); }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 263 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_assignexpr((yyvsp[-1].pos), (yyvsp[-2].var), (yyvsp[0].expr)); }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 265 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_ifexpr((yyvsp[-3].pos), (yyvsp[-2].expr), (yyvsp[0].expr), NULL); }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 267 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_ifexpr((yyvsp[-5].pos), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 269 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_whileexpr((yyvsp[-3].pos), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 271 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_forexpr((yyvsp[-7].pos), (yyvsp[-6].sym), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 273 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_breakexpr((yyvsp[0].pos)); }
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 275 "yacc.y" /* yacc.c:1646  */
    { (yyval.expr) = Ast_letexpr((yyvsp[-4].pos), (yyvsp[-3].declList), (yyvsp[-1].expr)); }
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 279 "yacc.y" /* yacc.c:1646  */
    { (yyval.declList) = NULL; }
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 281 "yacc.y" /* yacc.c:1646  */
    { DECLSLIST_ADD((yyval.declList), (yyvsp[-1].declList), (yyvsp[0].decl)); }
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 285 "yacc.y" /* yacc.c:1646  */
    { (yyval.decl) = Ast_typedecl(((ast_type) (yyvsp[0].nametypeList)->head)->pos, (yyvsp[0].nametypeList)); }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 288 "yacc.y" /* yacc.c:1646  */
    { (yyval.decl) = Ast_functiondecl(((ast_funcdecl) (yyvsp[0].funcdeclList)->head)->pos, (yyvsp[0].funcdeclList)); }
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 292 "yacc.y" /* yacc.c:1646  */
    { (yyval.nametypeList) = Ast_nameTypelist(Ast_nameType((yyvsp[-2].sym), (yyvsp[0].type)), NULL); }
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 294 "yacc.y" /* yacc.c:1646  */
    { TYPEDECLS_ADD((yyval.nametypeList), (yyvsp[-4].nametypeList), Ast_nameType((yyvsp[-2].sym), (yyvsp[0].type))); }
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 298 "yacc.y" /* yacc.c:1646  */
    { (yyval.type) = Ast_nametype(em_tokPos, (yyvsp[0].sym)); }
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 300 "yacc.y" /* yacc.c:1646  */
    { (yyval.type) = Ast_recordtype((yyvsp[-2].pos), (yyvsp[-1].fieldList)); }
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 302 "yacc.y" /* yacc.c:1646  */
    { (yyval.type) = Ast_arraytype((yyvsp[-2].pos), (yyvsp[0].sym)); }
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 306 "yacc.y" /* yacc.c:1646  */
    { (yyval.fieldList) = NULL; }
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 308 "yacc.y" /* yacc.c:1646  */
    { (yyval.fieldList) = Ast_fieldlist(Ast_field((yyvsp[-3].sym), (yyvsp[-1].sym)), (yyvsp[0].fieldList)); }
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 312 "yacc.y" /* yacc.c:1646  */
    { (yyval.decl) = Ast_vardecl((yyvsp[-3].pos), (yyvsp[-2].sym), NULL, (yyvsp[0].expr)); }
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 314 "yacc.y" /* yacc.c:1646  */
    { (yyval.decl) = Ast_vardecl((yyvsp[-5].pos), (yyvsp[-4].sym), (yyvsp[-2].sym), (yyvsp[0].expr)); }
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 318 "yacc.y" /* yacc.c:1646  */
    { (yyval.funcdeclList) = Ast_funcdecllist((yyvsp[0].func), NULL); }
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 320 "yacc.y" /* yacc.c:1646  */
    { FUNCDECLS_ADD((yyval.funcdeclList), (yyvsp[-1].funcdeclList), (yyvsp[0].func)); }
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 324 "yacc.y" /* yacc.c:1646  */
    { (yyval.func) = Ast_funcdecl((yyvsp[-6].pos), (yyvsp[-5].sym), (yyvsp[-3].fieldList), NULL, (yyvsp[0].expr)); }
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 326 "yacc.y" /* yacc.c:1646  */
    { (yyval.func) = Ast_funcdecl((yyvsp[-8].pos), (yyvsp[-7].sym), (yyvsp[-5].fieldList), (yyvsp[-2].sym), (yyvsp[0].expr)); }
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 330 "yacc.y" /* yacc.c:1646  */
    { (yyval.exprList) = Ast_exprlist((yyvsp[0].expr), NULL); }
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 333 "yacc.y" /* yacc.c:1646  */
    { EXPRLIST_ADD((yyval.exprList), (yyvsp[-2].exprList), (yyvsp[0].expr)); }
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 337 "yacc.y" /* yacc.c:1646  */
    { (yyval.exprList) = NULL; }
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 339 "yacc.y" /* yacc.c:1646  */
    { EXPRLIST_ADD((yyval.exprList), (yyvsp[-2].exprList), (yyvsp[0].expr)); }
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 343 "yacc.y" /* yacc.c:1646  */
    { (yyval.efieldList) = NULL; }
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 345 "yacc.y" /* yacc.c:1646  */
    { EFIELDLIST_ADD((yyval.efieldList), (yyvsp[-4].efieldList), Ast_efield((yyvsp[-1].pos), (yyvsp[-2].sym), (yyvsp[0].expr))); }
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 349 "yacc.y" /* yacc.c:1646  */
    { (yyval.fieldList) = NULL; }
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 351 "yacc.y" /* yacc.c:1646  */
    { FIELDLIST_ADD((yyval.fieldList), (yyvsp[-4].fieldList), Ast_field((yyvsp[-2].sym), (yyvsp[0].sym))); }
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 355 "yacc.y" /* yacc.c:1646  */
    { LVALUE_ACT((yyval.var), (yyvsp[0].var), Ast_simplevar(em_tokPos, (yyvsp[-1].sym))); }
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 359 "yacc.y" /* yacc.c:1646  */
    { (yyval.var) = NULL; }
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 361 "yacc.y" /* yacc.c:1646  */
    { LVALUE_ACT((yyval.var), (yyvsp[0].var), Ast_fieldvar((yyvsp[-2].pos), NULL, (yyvsp[-1].sym))); }
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 363 "yacc.y" /* yacc.c:1646  */
    { LVALUE_ACT((yyval.var) ,(yyvsp[0].var), Ast_subscriptvar((yyvsp[-3].pos), NULL, (yyvsp[-2].expr))); }
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 367 "yacc.y" /* yacc.c:1646  */
    { (yyval.sym) = S_Symbol((yyvsp[0].str)); }
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1967 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 368 "yacc.y" /* yacc.c:1906  */


void yyerror(char *msg)
{
	em_error(em_tokPos, "%s",msg);
}

static void print_token_value(FILE *fp, int type, YYSTYPE value)
{
    switch (type)
    {
        case TK_ID:
        case TK_STRING:
            fprintf(fp, "%s", value.str);
            break;
        case TK_INT:
            fprintf(fp, "%d", value.num);
            break;
    }
}

ast_expr parse(string filename)
{
    em_reset(filename);
    if (yyparse() == 0)
        return _program;
    else
        return NULL;
}

