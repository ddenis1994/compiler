/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "yacc.y" /* yacc.c:337  */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <fenv.h>
#define SYMBALTABLESIZE 100000
typedef struct node
{
char *token;
struct node *left;
struct node *right;
} node;
typedef struct deciptopn{
	char* id;
	int isProc_func; // if 1 is func 0 is proc 
	char* type;
	char* data;
	char * return_value;
	int frameBelong;
	struct deciptopn * next;
} deciptopn;



typedef struct frame{
	int frameID;
	struct stack_Data * symbels;
} frame;

typedef struct stack_Data{
	char * name;
	struct stack_Data * next;
} stack_Data;


struct Stack 
{ 
    int top; 
    unsigned capacity; 
    struct frame ** array; 
}; 

typedef struct symblaTable{
	/* the name of the symbl*/
	char *  name;
	/* pointer for the symblas */
	struct deciptopn * symbals;
} symblaTable;

static int deep=0;
static struct symblaTable * hashTableSymbel;
static struct Stack * frameStack;
void print_stack();
void pop() ;
void push(struct frame * item) ;
int isEmpty();
int isFull();
int createStack() ;
int creath_hs();
long long compute_hash(char *  s);
int insert_to_ht(deciptopn * symbel);
int insert_symbel(char * id,int is_func_proc,char * type,char * data, char * return_value,int frameBelong);
int CrearhSymbalFrame(node * root);
struct frame * creathFrame();
int startSemantic(node * root);
node *mknode(char *token, node *left, node *right);
node *mkleaf(char *token);
node * creathFuncDec(char * id,node * args,char * typeOfReturn,node * block);
int insert_to_stack(deciptopn * symbel);
void find_var_names(char * type,node * root);



void printtree(node *tree,int space);
void yyerror(char *);
extern int yylex();

#line 150 "y.tab.c" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
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
    CHAR = 258,
    REAL = 259,
    FLOAT = 260,
    INT = 261,
    BOOL = 262,
    STRING = 263,
    CHAR_POINTER = 264,
    REAL_POINTER = 265,
    FLOAT_POINTER = 266,
    INT_POINTER = 267,
    ELSE = 268,
    IF = 269,
    FOR = 270,
    WHILE = 271,
    TRUE = 272,
    FALSE = 273,
    RETURN = 274,
    MAIN = 275,
    VAR = 276,
    FUNC = 277,
    PROC = 278,
    NULL_VALUE = 279,
    AND_OP = 280,
    GE_OP = 281,
    SE_OP = 282,
    NE_OP = 283,
    OR_OP = 284,
    EQL_OP = 285,
    BOOL_VALUE = 286,
    CHAR_VALUE = 287,
    STRING_VALUE = 288,
    INT_NUM = 289,
    F_NUM = 290,
    ID = 291,
    IFX = 292,
    test = 293,
    UMINUS = 294,
    UFUNC = 295
  };
#endif
/* Tokens.  */
#define CHAR 258
#define REAL 259
#define FLOAT 260
#define INT 261
#define BOOL 262
#define STRING 263
#define CHAR_POINTER 264
#define REAL_POINTER 265
#define FLOAT_POINTER 266
#define INT_POINTER 267
#define ELSE 268
#define IF 269
#define FOR 270
#define WHILE 271
#define TRUE 272
#define FALSE 273
#define RETURN 274
#define MAIN 275
#define VAR 276
#define FUNC 277
#define PROC 278
#define NULL_VALUE 279
#define AND_OP 280
#define GE_OP 281
#define SE_OP 282
#define NE_OP 283
#define OR_OP 284
#define EQL_OP 285
#define BOOL_VALUE 286
#define CHAR_VALUE 287
#define STRING_VALUE 288
#define INT_NUM 289
#define F_NUM 290
#define ID 291
#define IFX 292
#define test 293
#define UMINUS 294
#define UFUNC 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 80 "yacc.y" /* yacc.c:352  */

	char * String;
	struct node * Node;

#line 278 "y.tab.c" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   387

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

#define YYUNDEFTOK  2
#define YYMAXUTOK   295

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,     2,     2,     2,    48,     2,
      51,    52,    42,    40,    54,    41,     2,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    53,    39,
      45,    57,    44,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    59,    47,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,    56,     2,     2,     2,     2,
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
      35,    36,    37,    38,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   124,   124,   133,   134,   138,   139,   145,   153,   157,
     158,   164,   170,   171,   176,   177,   184,   185,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   221,   222,   227,   228,   229,   230,   235,   236,   241,
     248,   253,   254,   255,   256,   260,   266,   269,   277,   278,
     283,   284,   285,   286,   290,   291,   295,   296,   297,   302,
     304,   309,   310,   314,   315,   319,   323,   324,   328,   329,
     330,   331,   332,   333
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR", "REAL", "FLOAT", "INT", "BOOL",
  "STRING", "CHAR_POINTER", "REAL_POINTER", "FLOAT_POINTER", "INT_POINTER",
  "ELSE", "IF", "FOR", "WHILE", "TRUE", "FALSE", "RETURN", "MAIN", "VAR",
  "FUNC", "PROC", "NULL_VALUE", "AND_OP", "GE_OP", "SE_OP", "NE_OP",
  "OR_OP", "EQL_OP", "BOOL_VALUE", "CHAR_VALUE", "STRING_VALUE", "INT_NUM",
  "F_NUM", "ID", "IFX", "test", "';'", "'+'", "'-'", "'*'", "'/'", "'>'",
  "'<'", "'!'", "'^'", "'&'", "UMINUS", "UFUNC", "'('", "')'", "':'",
  "','", "'{'", "'}'", "'='", "'['", "']'", "$accept", "S",
  "FUNC_PROC_DEC", "DEF_A", "PROC_DEF", "FUNC_DEF", "ARGES", "OUT_ARGES",
  "OUT_ARGES2", "INNER_ARGS", "FUNC_BLOCK", "EXPRASION", "FUNC_ACTIVE",
  "FUNC_ACTIVE_INNER_ARGES", "STASTMENT_LIST", "IF_STASTMENT", "STASTMENT",
  "RETURN_STATMENT", "LOOP_STATMENT", "UPDATES", "COMPUND_STATMENT",
  "COMPUND_STATMENT_PROC", "INNER_COMPUND_STATMENT", "DEC_INNER_BLOCK",
  "NEW_DECLARE", "VAR_DECLARE", "VF", "CONST", "TYPE", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,    59,
      43,    45,    42,    47,    62,    60,    33,    94,    38,   294,
     295,    40,    41,    58,    44,   123,   125,    61,    91,    93
};
# endif

#define YYPACT_NINF -73

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-73)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      22,     5,    17,    71,   -73,    22,   -73,   -73,   -29,   -29,
     -73,   -73,   -31,    47,    24,    29,   -73,    44,    45,    57,
     102,   -73,    61,   -73,    57,   -73,   -73,   -73,   -73,   -73,
      46,    58,    51,    70,    81,   -73,   -73,    61,   -73,   -73,
     -15,   137,   137,   137,   137,   137,    59,   -73,   -73,   252,
     -73,   187,   -73,   -73,   -73,   -73,    77,   187,    66,    91,
     -73,   -73,   -73,    83,   100,   145,   -73,   137,   137,   137,
      82,   -17,   137,   111,   111,   111,   111,   -14,   137,   -73,
      84,   -16,   137,   137,   137,   137,   137,   137,   -73,   137,
     137,   137,   137,   137,   137,   -73,   -73,   187,   -73,   -73,
      61,   -73,    85,   137,   122,   218,   259,   224,    57,    88,
     -73,    95,    97,   336,   -73,   280,   -73,   -73,    96,   101,
     101,   101,   336,   101,   101,   182,   182,   342,   342,   101,
     101,   -73,   -73,   287,   137,   187,   137,   187,   117,    56,
     -73,    56,   -73,   -73,   109,   308,   156,   315,   -73,   -73,
     -73,   -73,   -73,   114,   187,   138,   -73,   -73,    68,   123,
     136,   141,   187,   -73,   -73,   -73
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,     3,     6,     5,     0,     0,
       1,     4,     0,     0,     0,    14,     9,     0,     0,     0,
       0,     7,     0,    10,     0,    83,    82,    81,    80,    79,
       0,     0,     0,     0,     0,    20,    21,     0,    76,    77,
      22,     0,     0,     0,     0,     0,     0,    64,    72,     0,
      40,    66,    53,    48,    54,    51,     0,    67,    70,    71,
      73,    18,    15,    12,     0,     0,     8,     0,     0,     0,
       0,     0,     0,    25,    26,    23,    24,     0,     0,    60,
       0,     0,     0,     0,     0,     0,     0,     0,    52,     0,
       0,     0,     0,     0,     0,    47,    65,    68,    69,    74,
       0,    11,     0,     0,     0,     0,     0,     0,     0,    43,
      41,     0,    44,    27,    19,     0,    63,    61,     0,    29,
      36,    37,    28,    30,    35,    31,    32,    34,    33,    38,
      39,    13,    78,     0,     0,     0,     0,     0,     0,     0,
      42,     0,    55,    62,     0,     0,    50,     0,    56,    75,
      45,    46,    16,     0,     0,     0,    17,    49,     0,     0,
       0,     0,     0,    58,    59,    57
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -73,   -73,    20,   -73,   -73,   -73,   168,    87,   -73,     2,
     -73,   -35,   -73,   -72,   132,   -73,   -51,   113,   -73,   -73,
     -73,   -73,   -42,   139,   -73,   -73,   131,   -69,   -23
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    48,     5,     6,     7,    13,    17,   101,    18,
      66,    49,    50,   111,    51,    52,    53,    80,    54,   159,
      55,    21,    56,    57,    58,    59,    60,    61,    31
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      95,    63,   112,    78,    81,    15,    73,    74,    75,    76,
      77,    82,    83,    84,    85,    86,    87,    38,    39,   109,
       4,    16,    12,   104,    62,    11,    89,    90,    91,    92,
      93,    94,   105,   106,   107,   110,    71,   113,   114,    70,
     117,     8,    72,   115,     1,     2,    95,   119,   120,   121,
     122,   123,   124,     9,   125,   126,   127,   128,   129,   130,
      25,    26,    27,    28,    29,    30,    19,   150,   133,   151,
     112,    10,   112,    32,    33,    34,    35,    36,    78,    20,
      37,     1,     2,    22,   146,   138,   148,    37,     1,     2,
      38,    39,   109,    38,    39,    40,    23,    15,    24,   145,
      41,   147,    67,   157,    64,    42,    43,    44,   160,   161,
      45,   165,    37,    65,    46,    79,    32,    33,    34,    35,
      36,    68,   100,    37,     1,     2,    -1,    -1,    -1,    85,
      -1,    -1,    69,    96,   102,   108,    38,    39,    40,    85,
     116,   134,   139,    41,   132,    -1,    -1,   140,    42,    43,
      44,   141,   143,    45,    35,    36,   149,    46,    47,    32,
      33,    34,    35,    36,   103,   152,    37,     1,     2,   154,
     156,    38,    39,    40,   158,   162,   163,    14,    41,    38,
      39,    40,   164,    42,    43,    44,    41,   131,    45,    97,
      99,    42,    43,    44,   118,     0,    45,    98,     0,     0,
      46,    32,    33,    34,    35,    36,     0,    82,    83,    84,
      85,    86,    87,     0,     0,     0,     0,     0,     0,     0,
       0,    38,    39,    40,    91,    92,    93,    94,    41,     0,
       0,     0,     0,    42,    43,    44,     0,     0,    45,     0,
       0,     0,    46,    82,    83,    84,    85,    86,    87,    82,
      83,    84,    85,    86,    87,     0,     0,     0,    89,    90,
      91,    92,    93,    94,    89,    90,    91,    92,    93,    94,
     135,     0,     0,     0,     0,     0,   137,    82,    83,    84,
      85,    86,    87,     0,    82,    83,    84,    85,    86,    87,
       0,    88,    89,    90,    91,    92,    93,    94,   136,    89,
      90,    91,    92,    93,    94,    82,    83,    84,    85,    86,
      87,     0,    82,    83,    84,    85,    86,    87,     0,   142,
      89,    90,    91,    92,    93,    94,   144,    89,    90,    91,
      92,    93,    94,    82,    83,    84,    85,    86,    87,     0,
      82,    83,    84,    85,    86,    87,     0,   153,    89,    90,
      91,    92,    93,    94,   155,    89,    90,    91,    92,    93,
      94,    82,    83,    84,    85,    86,    87,    82,    83,    84,
      85,    86,    87,     0,     0,     0,    89,    90,    91,    92,
      93,    94,     0,     0,     0,     0,    93,    94
};

static const yytype_int16 yycheck[] =
{
      51,    24,    71,    19,    46,    36,    41,    42,    43,    44,
      45,    25,    26,    27,    28,    29,    30,    34,    35,    36,
       0,    52,    51,    65,    22,     5,    40,    41,    42,    43,
      44,    45,    67,    68,    69,    52,    51,    72,    52,    37,
      56,    36,    57,    78,    22,    23,    97,    82,    83,    84,
      85,    86,    87,    36,    89,    90,    91,    92,    93,    94,
       3,     4,     5,     6,     7,     8,    19,   139,   103,   141,
     139,     0,   141,    14,    15,    16,    17,    18,    19,    55,
      21,    22,    23,    54,   135,   108,   137,    21,    22,    23,
      34,    35,    36,    34,    35,    36,    52,    36,    53,   134,
      41,   136,    51,   154,    58,    46,    47,    48,    40,    41,
      51,   162,    21,    55,    55,    56,    14,    15,    16,    17,
      18,    51,    39,    21,    22,    23,    25,    26,    27,    28,
      29,    30,    51,    56,    34,    53,    34,    35,    36,    28,
      56,    19,    54,    41,    59,    44,    45,    52,    46,    47,
      48,    54,    56,    51,    17,    18,    39,    55,    56,    14,
      15,    16,    17,    18,    19,    56,    21,    22,    23,    13,
      56,    34,    35,    36,    36,    52,    40,     9,    41,    34,
      35,    36,    41,    46,    47,    48,    41,   100,    51,    57,
      59,    46,    47,    48,    81,    -1,    51,    58,    -1,    -1,
      55,    14,    15,    16,    17,    18,    -1,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    36,    42,    43,    44,    45,    41,    -1,
      -1,    -1,    -1,    46,    47,    48,    -1,    -1,    51,    -1,
      -1,    -1,    55,    25,    26,    27,    28,    29,    30,    25,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    45,    40,    41,    42,    43,    44,    45,
      52,    -1,    -1,    -1,    -1,    -1,    52,    25,    26,    27,
      28,    29,    30,    -1,    25,    26,    27,    28,    29,    30,
      -1,    39,    40,    41,    42,    43,    44,    45,    39,    40,
      41,    42,    43,    44,    45,    25,    26,    27,    28,    29,
      30,    -1,    25,    26,    27,    28,    29,    30,    -1,    39,
      40,    41,    42,    43,    44,    45,    39,    40,    41,    42,
      43,    44,    45,    25,    26,    27,    28,    29,    30,    -1,
      25,    26,    27,    28,    29,    30,    -1,    39,    40,    41,
      42,    43,    44,    45,    39,    40,    41,    42,    43,    44,
      45,    25,    26,    27,    28,    29,    30,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    44,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    22,    23,    61,    62,    63,    64,    65,    36,    36,
       0,    62,    51,    66,    66,    36,    52,    67,    69,    19,
      55,    81,    54,    52,    53,     3,     4,     5,     6,     7,
       8,    88,    14,    15,    16,    17,    18,    21,    34,    35,
      36,    41,    46,    47,    48,    51,    55,    56,    62,    71,
      72,    74,    75,    76,    78,    80,    82,    83,    84,    85,
      86,    87,    69,    88,    58,    55,    70,    51,    51,    51,
      69,    51,    57,    71,    71,    71,    71,    71,    19,    56,
      77,    82,    25,    26,    27,    28,    29,    30,    39,    40,
      41,    42,    43,    44,    45,    76,    56,    74,    83,    86,
      39,    68,    34,    19,    82,    71,    71,    71,    53,    36,
      52,    73,    87,    71,    52,    71,    56,    56,    77,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    67,    59,    71,    19,    52,    39,    52,    88,    54,
      52,    54,    39,    56,    39,    71,    76,    71,    76,    39,
      73,    73,    56,    39,    13,    39,    56,    76,    36,    79,
      40,    41,    52,    40,    41,    76
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    62,    63,    63,    64,    65,    66,
      66,    67,    68,    68,    69,    69,    70,    70,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    72,    73,    73,    73,    73,    74,    74,    75,
      75,    76,    76,    76,    76,    77,    78,    78,    79,    79,
      80,    80,    80,    80,    81,    81,    82,    82,    82,    83,
      83,    84,    84,    85,    85,    86,    87,    87,    88,    88,
      88,    88,    88,    88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     4,     6,     2,
       3,     4,     0,     2,     1,     3,     5,     6,     1,     3,
       1,     1,     1,     2,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     4,     1,     1,     3,     3,     2,     1,     7,
       5,     1,     2,     1,     1,     3,     5,     9,     3,     3,
       2,     3,     4,     3,     2,     3,     1,     1,     2,     2,
       1,     1,     1,     1,     2,     5,     1,     1,     4,     1,
       1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
| yyreduce -- do a reduction.  |
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
#line 124 "yacc.y" /* yacc.c:1652  */
    {
        (yyval.Node)=mknode("BLOCK",(yyvsp[0].Node),NULL);
		startSemantic((yyval.Node));
        printf("ok\n");
        }
#line 1535 "y.tab.c" /* yacc.c:1652  */
    break;

  case 3:
#line 133 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("",(yyvsp[0].Node),NULL);}
#line 1541 "y.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 134 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1547 "y.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 138 "yacc.y" /* yacc.c:1652  */
    {	(yyval.Node)=mknode("NEW_FUNC",(yyvsp[0].Node),NULL);}
#line 1553 "y.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 139 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("NEW_PROC",(yyvsp[0].Node),NULL);}
#line 1559 "y.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 145 "yacc.y" /* yacc.c:1652  */
    {
		(yyval.Node)=mknode("ARGS",NULL,(yyvsp[-1].Node));
		(yyval.Node)=mknode("ID",(yyval.Node),mkleaf((yyvsp[-2].String)));
		(yyval.Node)=mknode("PROC",(yyval.Node),(yyvsp[0].Node));
		}
#line 1569 "y.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 153 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=creathFuncDec((yyvsp[-4].String),(yyvsp[-3].Node),(yyvsp[-1].String),(yyvsp[0].Node));
	}
#line 1576 "y.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 157 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("",NULL,NULL);}
#line 1582 "y.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 158 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(strdup("ARGS "),(yyvsp[-1].Node),NULL);}
#line 1588 "y.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 164 "yacc.y" /* yacc.c:1652  */
    {
						(yyval.Node)=mknode((yyvsp[-1].String),(yyvsp[-3].Node),NULL);
						}
#line 1596 "y.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 170 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("",NULL,NULL);}
#line 1602 "y.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 171 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(":",NULL,NULL);}
#line 1608 "y.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 176 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("ID",NULL,mkleaf((yyvsp[0].String)));}
#line 1614 "y.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 177 "yacc.y" /* yacc.c:1652  */
    {
		(yyval.Node)=mknode("ID",(yyvsp[0].Node),mkleaf((yyvsp[-2].String)));
		}
#line 1622 "y.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 184 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("BLOCK_FUNC",NULL,mknode(strdup("RETURN BLOCK"),(yyvsp[-2].Node),NULL));}
#line 1628 "y.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 185 "yacc.y" /* yacc.c:1652  */
    {
															(yyval.Node)=mknode("BLOCK_FUNC",(yyvsp[-4].Node),mknode(strdup("RETURN BLOCK"),(yyvsp[-2].Node),NULL));}
#line 1635 "y.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 193 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mkleaf((yyvsp[0].String));}
#line 1641 "y.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 194 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=(yyvsp[-1].Node);}
#line 1647 "y.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 195 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mkleaf("TRUE");}
#line 1653 "y.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 196 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mkleaf("FALSE");}
#line 1659 "y.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 197 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mkleaf((yyvsp[0].String));}
#line 1665 "y.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 198 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=(yyvsp[0].Node);}
#line 1671 "y.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 199 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=(yyvsp[0].Node);}
#line 1677 "y.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 200 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=(yyvsp[0].Node);}
#line 1683 "y.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 201 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=(yyvsp[0].Node);}
#line 1689 "y.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 202 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("=",mkleaf((yyvsp[-2].String)),(yyvsp[0].Node));}
#line 1695 "y.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 203 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("!=",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1701 "y.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 204 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("&&",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1707 "y.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 205 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("||",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1713 "y.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 206 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("+",(yyvsp[-2].Node),(yyvsp[0].Node));printf("was");}
#line 1719 "y.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 207 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("-",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1725 "y.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 208 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("/",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1731 "y.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 209 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("*",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1737 "y.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 210 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("==",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1743 "y.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 211 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(">=",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1749 "y.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 212 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("<=",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1755 "y.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 213 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(">",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1761 "y.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 214 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("<",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1767 "y.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 221 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(strcat((yyvsp[-2].String)," ACTIVE:"),mknode(strdup("empty arguments"),NULL,NULL),NULL);}
#line 1773 "y.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 222 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(strcat((yyvsp[-3].String)," ACTIVE:"),mknode(strdup("ARGS "),(yyvsp[-1].Node),NULL),NULL);
							}
#line 1780 "y.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 227 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mkleaf((yyvsp[0].String));}
#line 1786 "y.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 228 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mkleaf((yyvsp[0].String));}
#line 1792 "y.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 229 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("",mkleaf((yyvsp[-2].String)),(yyvsp[0].Node));}
#line 1798 "y.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 230 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("",mkleaf((yyvsp[-2].String)),(yyvsp[0].Node));}
#line 1804 "y.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 235 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1810 "y.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 241 "yacc.y" /* yacc.c:1652  */
    {
		(yyval.Node)=mknode("IF_ELSE",
		mknode("EXPRASION_IF",NULL,(yyvsp[-4].Node)),
		mknode("BODY_IF",mknode("ELSE",NULL,(yyvsp[0].Node)),(yyvsp[-2].Node))
		);
		}
#line 1821 "y.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 248 "yacc.y" /* yacc.c:1652  */
    {  
        (yyval.Node)=mknode("IF",mknode("EXPRASION_IF",NULL,(yyvsp[-2].Node)),mknode("BODY_IF",NULL,(yyvsp[0].Node)));}
#line 1828 "y.tab.c" /* yacc.c:1652  */
    break;

  case 55:
#line 260 "yacc.y" /* yacc.c:1652  */
    {
        (yyval.Node)=mknode("RETURN STATMENT",(yyvsp[-1].Node),NULL);
        }
#line 1836 "y.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 266 "yacc.y" /* yacc.c:1652  */
    {
		(yyval.Node)=mknode("WHILE",mknode("EXPRESSION",NULL,(yyvsp[-2].Node)),mknode("BODY",NULL,(yyvsp[0].Node)));
		}
#line 1844 "y.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 271 "yacc.y" /* yacc.c:1652  */
    {	
		(yyval.Node)=mknode("FOR",mknode("INIT",mknode("EXPRESSION_FOR",mknode("UPDATE",NULL,(yyvsp[-2].Node)),(yyvsp[-4].Node)),(yyvsp[-6].Node)),mknode("BODY",NULL,(yyvsp[0].Node)));
	}
#line 1852 "y.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 277 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(strcat((yyvsp[-2].String),strdup("++")),NULL,NULL);}
#line 1858 "y.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 278 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(strcat((yyvsp[-2].String),strdup("--")),NULL,NULL);}
#line 1864 "y.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 283 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("BLOCK",NULL,NULL);}
#line 1870 "y.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 284 "yacc.y" /* yacc.c:1652  */
    { (yyval.Node)=mknode("BLOCK",NULL,(yyvsp[-1].Node)); }
#line 1876 "y.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 285 "yacc.y" /* yacc.c:1652  */
    { (yyval.Node)=mknode("BLOCK",(yyvsp[-1].Node),(yyvsp[-2].Node)); }
#line 1882 "y.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 286 "yacc.y" /* yacc.c:1652  */
    { (yyval.Node)=mknode("BLOCK",(yyvsp[-1].Node),NULL); }
#line 1888 "y.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 290 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("BLOCK",NULL,NULL);}
#line 1894 "y.tab.c" /* yacc.c:1652  */
    break;

  case 65:
#line 291 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("BLOCK",NULL,(yyvsp[-1].Node));}
#line 1900 "y.tab.c" /* yacc.c:1652  */
    break;

  case 66:
#line 295 "yacc.y" /* yacc.c:1652  */
    { (yyval.Node)=mknode("",NULL,(yyvsp[0].Node));}
#line 1906 "y.tab.c" /* yacc.c:1652  */
    break;

  case 67:
#line 296 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("",(yyvsp[0].Node),NULL);}
#line 1912 "y.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 297 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1918 "y.tab.c" /* yacc.c:1652  */
    break;

  case 69:
#line 302 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("DECLARE",(yyvsp[-1].Node),(yyvsp[0].Node));
	}
#line 1925 "y.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 304 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("DECLARE",(yyvsp[0].Node),NULL);
}
#line 1932 "y.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 314 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("VAR_DECLARE",(yyvsp[0].Node),NULL);}
#line 1938 "y.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 315 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("VAR_DECLARE",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1944 "y.tab.c" /* yacc.c:1652  */
    break;

  case 75:
#line 319 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("TYPE",(yyvsp[-3].Node),mkleaf((yyvsp[-1].String)));}
#line 1950 "y.tab.c" /* yacc.c:1652  */
    break;


#line 1954 "y.tab.c" /* yacc.c:1652  */
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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
#line 335 "yacc.y" /* yacc.c:1918  */


void yyerror(char * msg){
    fprintf(stderr, "%s\n",msg);
    exit(1);
}

int main(){
	return yyparse();
    return 0;
}
void printtree(node * tree,int space){
    int i;
	if (sizeof(tree->token) > 0){
        for(i=0;i<space;i++)
		    printf("\t");
	    printf("(%s ",tree->token);
        if(!tree->left && !tree->right){
		    printf(")\n");
	    }
        else{
            printf("\n");
            if(tree->left)
		        printtree(tree->left ,space+1);
	        
	        if( tree->right)
		        printtree(tree->right,space+1);
            for(i=0;i<space;i++)
		        printf("\t");
            printf(")\n");
        }
	    
    }
    else
    {
        if(tree->left){
		    printtree(tree->left ,space);
	    }
	    if( tree->right)
		    printtree(tree->right,space);
    }
    
	
		
	
}

node *mknode(char *token, node *left, node *right){
	node * newnode=(node*)malloc(sizeof(node));
	char *newstr=(char*)malloc(sizeof(token) + 1);
	strcpy(newstr,token);
	newnode->left=left;
	newnode->right=right;
	newnode->token=newstr;
	return 	newnode;
}
node *mkleaf(char *token){
	node * newnode=(node*)malloc(sizeof(node));
	char *newstr=(char*)malloc(sizeof(token) + 1);
	strcpy(newstr,token);
	newnode->left=NULL;
	newnode->right=NULL;
	newnode->token=newstr;
	return 	newnode;
}




struct frame *  creathFrame(){
	struct frame * temp =(struct frame *)malloc(sizeof(struct frame));
	temp->frameID = ++deep;
	temp->symbels = NULL;
	return temp;


}

long long compute_hash(char *  s) {
    const int p = 52;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
	int i,size;
	size = strlen(s);
    for (i=0;i<size;i++) {
        hash_value = (hash_value + (s[i] - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
	}

int creath_hs(){
	int i;
	if( ( hashTableSymbel = (symblaTable*)malloc(sizeof(symblaTable)*SYMBALTABLESIZE) ) == NULL ) 
		return 1;
	
	for(i=0;i<SYMBALTABLESIZE;i++){
		hashTableSymbel[i].name="";
		hashTableSymbel[i].symbals=NULL;
	}
	return 0;
	}



int insert_to_ht(deciptopn * symbel){
	struct deciptopn * temp_symbal;
	unsigned long long int  sizeHT = SYMBALTABLESIZE;
	//creath first hush key for the string
	unsigned long long int idtemp = compute_hash(symbel->id)  ;
	unsigned long long int id=idtemp-idtemp/sizeHT*sizeHT;
	//chack if alrdy has this symbol

	if(hashTableSymbel[id].name!="")
		if(!strcmp (hashTableSymbel[id].name ,symbel->id ))
			//if not creah table for the symbel
			hashTableSymbel[id].name = symbel->id;
		

	//copy the pointer fot the symbel data

	temp_symbal=hashTableSymbel[id].symbals;

	//look for first empty space
	while(temp_symbal != NULL)
		temp_symbal=temp_symbal -> next;
	//insert in the empty space the the table for the symbel


	//hare can find out if alredy crather this symbol
	//to do chack if symbol alerdy exsists
	if (NULL)
		return 1;

	temp_symbal=symbel;

	return 0;
	}


int createStack() { 

	if( ( frameStack = (struct Stack *) malloc(sizeof(struct Stack)) ) == NULL ) 
		return 1;
    frameStack->capacity = SYMBALTABLESIZE; 
    frameStack->top = -1; 
    frameStack->array = (struct frame **) malloc(frameStack->capacity * sizeof(struct frame **)); 
	return 0;
	} 

// Stack is full when top is equal to the last index 
int isFull() {
	   return frameStack->top == frameStack->capacity - 1; } 
  
// Stack is empty when top is equal to -1 
int isEmpty() 
	{   return frameStack->top == -1;  } 
  
// Function to add an item to stack.  It increases top by 1 
void push( struct frame * item) { 
    if (isFull(frameStack)) {
		printf("the stack is fulll \n");
        return; 
	}
    frameStack->array[++(frameStack->top)] = item; 
	} 
  
// Function to remove an item from stack.  It decreases top by 1 
void pop() { 
    if (isEmpty(frameStack)) 
        return ; 
	deep--;
	struct frame * temp=frameStack->array[(frameStack->top)--];
    free(temp);

	} 
void print_stack(){
	int i ;
	struct stack_Data * symbals_top_frame;

	for (i=frameStack->top;i>-1;i--){
		printf("level %d  symbals :",i);
		symbals_top_frame=frameStack->array[i]->symbels;
		while(symbals_top_frame!=NULL){
			printf("%s ,",symbals_top_frame->name );
			symbals_top_frame=symbals_top_frame->next;
		}
		printf("\n");
	}
}


node * creathFuncDec(char * id,node * args,char * typeOfReturn,node * block){
	node * temp=mknode("RETURN ",NULL,mkleaf(typeOfReturn));
	temp=mknode("ARGS",temp,args);
	temp=mknode("ID",temp,mkleaf(id));
	temp=mknode("FUNC",temp,block);

	return temp;

	}



int CrearhSymbalFrame(node * root){
	//first to to push empty stack

	if( !strcmp (root->token ,"BLOCK")){

		push(creathFrame());
		printf("found new block %d\n",deep);
		if(root->right)
			CrearhSymbalFrame(root->right);

		printf("finish block %d\n",deep);
		pop();
		return 0;
	}
		
	if( !strcmp (root->token ,"FUNC")){
		
		insert_symbel(
						root->left->right->token,
						1,
						"func_declare",
						NULL,
						root->left->left->left->right->token,
						deep);
						


		push(creathFrame());
		printf("found new block %d\n",deep);


		
		if(root->right->left)
			CrearhSymbalFrame(root->right->left);

		printf("finish block %d\n",deep);
		

		pop();

	
		return 0;

	}

	if( !strcmp (root->token ,"PROC")){


		insert_symbel(
						root->left->right->token,
						1,
						"proc_declare",
						NULL,
						NULL,
						deep);

		push(creathFrame());
		printf("found new block %d\n",deep);

		if(root->right->left)
			CrearhSymbalFrame(root->right->left);


		pop();
		return 0;
	}

	if( !strcmp (root->token ,"IF")){
		printf("found new block %d\n",deep);
		push(creathFrame());

		//TODO take data from left son 

		CrearhSymbalFrame(root->right);

		pop();
		return 0;

	}
	if( !strcmp (root->token ,"IF_ELSE")){
		printf("found new block %d\n",deep);
		push(creathFrame());



		//TODO crate new method for chaking the else!!

		CrearhSymbalFrame(root->right);

		pop();
		return 0;
	}


	if( !strcmp (root->token ,"WHILE")){
		printf("found new block %d\n",deep);
		push(creathFrame());

		//TODO take data from left son 

		CrearhSymbalFrame(root->right);

		pop();
		return 0;
	}

	if( !strcmp (root->token ,"FOR")){
		printf("found new block %d\n",deep);
		push(creathFrame());

		//TODO take data from left son 

		CrearhSymbalFrame(root->right);

		pop();
		return 0;
	}

	if( !strcmp (root->token ,"VAR_DECLARE")){
		find_var_names(root->left->right->token,root->left->left);
		
	}



	if(root->left)
		CrearhSymbalFrame(root->left);
	if(root->right)
		CrearhSymbalFrame(root->right);
	


}



int startSemantic(node * root){

	if(strcmp (root->token ,"BLOCK" ))
		return 1;
	//first allocate space for HT
	if(creath_hs()==1){
		printf("cannot allocate space for HT exit\n");
		exit(1);
	}
	//secuond allocate space for stack
	if(createStack()==1){
		printf("cannot allocate space for STACK exit\n");
		exit(1);
	}

	push(creathFrame());
	CrearhSymbalFrame(root->left);



	//start to clear data
	free(hashTableSymbel->symbals);
	free(hashTableSymbel);
	return 0;
	
	
}

int insert_symbel(char * id,int is_func_proc,char * type,char * data, char * return_value,int frameBelong){
	struct deciptopn * temp=(struct deciptopn *)malloc(sizeof(deciptopn));
	temp->id=id;
	temp->isProc_func=is_func_proc;

	if(temp->isProc_func)
		temp->return_value=return_value;
	else
		temp->return_value=NULL;
	temp->type=type;
	temp->data=data;
	temp->frameBelong=frameBelong;
	temp->next=NULL;
	insert_to_ht(temp);
	insert_to_stack(temp);

	print_stack();
	
	
}

int insert_to_stack(deciptopn * symbel){

	struct stack_Data * temp_symbal =(stack_Data *)malloc(sizeof(stack_Data));

	struct stack_Data * temp = (frameStack->array[(frameStack->top)])->symbels;

	temp_symbal->name=symbel->id;
	temp_symbal->next=NULL;

	if(temp!=NULL){
		if(!strcmp(temp->name,symbel->id)){
				printf("double declarasion %s\n",symbel->id);
				exit(1);
		}
		while(temp->next != NULL){
			if(!strcmp(temp->name,symbel->id)){
				printf("double declarasion %s\n",symbel->id);
				exit(1);
			}
			temp=temp->next;
		}
		temp->next=temp_symbal;
	}
	else
		(frameStack->array[(frameStack->top)])->symbels=temp_symbal;


	return 0;
}

void find_var_names(char * type,node * root){

	insert_symbel(root->right->token,0,type,NULL,NULL,deep);
	if(root->left)
		find_var_names(type,root->left);
}
