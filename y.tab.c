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
	node * arges;
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
int insert_symbel(char * id,int is_func_proc,char * type,char * data, char * return_value,int frameBelong,node * arges);
int CrearhSymbalFrame(node * root);
struct frame * creathFrame();
int startSemantic(node * root);
node *mknode(char *token, node *left, node *right);
node *mkleaf(char *token);
node * creathFuncDec(char * id,node * args,char * typeOfReturn,node * block);
int insert_to_stack(deciptopn * symbel);
void find_var_names(char * type,node * root);
deciptopn * get_symbal_from_hash(char * name);
node * makeArgsReq(node * root);
node * getInnerArges(node * root ,char * type);
void printLinkedList(node * root);
int checkFunc(node * originalArges,node * newArges);
node * creath_arges(node* root);
int chack_arges(deciptopn * originalArges,node * newArges,int typeofchack);


void printtree(node *tree,int space);
void yyerror(char *);
extern int yylex();

#line 157 "y.tab.c" /* yacc.c:337  */
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
    CHAR_POINER = 264,
    REAL_POINER = 265,
    FLOAT_POINER = 266,
    INT_POINER = 267,
    CHAR_POINTER = 268,
    REAL_POINTER = 269,
    FLOAT_POINTER = 270,
    INT_POINTER = 271,
    ELSE = 272,
    IF = 273,
    FOR = 274,
    WHILE = 275,
    TRUE = 276,
    FALSE = 277,
    RETURN = 278,
    MAIN = 279,
    VAR = 280,
    FUNC = 281,
    PROC = 282,
    NULL_VALUE = 283,
    AND_OP = 284,
    GE_OP = 285,
    SE_OP = 286,
    NE_OP = 287,
    OR_OP = 288,
    EQL_OP = 289,
    BOOL_VALUE = 290,
    CHAR_VALUE = 291,
    STRING_VALUE = 292,
    INT_NUM = 293,
    F_NUM = 294,
    HEX_NUM = 295,
    ID = 296,
    IFX = 297,
    test = 298,
    UMINUS = 299,
    UFUNC = 300
  };
#endif
/* Tokens.  */
#define CHAR 258
#define REAL 259
#define FLOAT 260
#define INT 261
#define BOOL 262
#define STRING 263
#define CHAR_POINER 264
#define REAL_POINER 265
#define FLOAT_POINER 266
#define INT_POINER 267
#define CHAR_POINTER 268
#define REAL_POINTER 269
#define FLOAT_POINTER 270
#define INT_POINTER 271
#define ELSE 272
#define IF 273
#define FOR 274
#define WHILE 275
#define TRUE 276
#define FALSE 277
#define RETURN 278
#define MAIN 279
#define VAR 280
#define FUNC 281
#define PROC 282
#define NULL_VALUE 283
#define AND_OP 284
#define GE_OP 285
#define SE_OP 286
#define NE_OP 287
#define OR_OP 288
#define EQL_OP 289
#define BOOL_VALUE 290
#define CHAR_VALUE 291
#define STRING_VALUE 292
#define INT_NUM 293
#define F_NUM 294
#define HEX_NUM 295
#define ID 296
#define IFX 297
#define test 298
#define UMINUS 299
#define UFUNC 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 87 "yacc.y" /* yacc.c:352  */

	char * String;
	struct node * Node;

#line 295 "y.tab.c" /* yacc.c:352  */
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
#define YYLAST   465

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

#define YYUNDEFTOK  2
#define YYMAXUTOK   300

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
       2,     2,     2,    51,     2,     2,     2,     2,    53,     2,
      56,    57,    47,    45,    59,    46,     2,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    58,    44,
      50,    62,    49,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,    52,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    60,     2,    61,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    54,
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   131,   131,   140,   141,   145,   146,   152,   160,   164,
     165,   172,   173,   180,   181,   188,   189,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     225,   226,   232,   233,   234,   235,   236,   237,   242,   243,
     248,   255,   260,   261,   262,   263,   267,   273,   276,   284,
     285,   291,   292,   296,   297,   301,   302,   303,   308,   310,
     315,   316,   320,   321,   325,   329,   330,   334,   335,   336,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR", "REAL", "FLOAT", "INT", "BOOL",
  "STRING", "CHAR_POINER", "REAL_POINER", "FLOAT_POINER", "INT_POINER",
  "CHAR_POINTER", "REAL_POINTER", "FLOAT_POINTER", "INT_POINTER", "ELSE",
  "IF", "FOR", "WHILE", "TRUE", "FALSE", "RETURN", "MAIN", "VAR", "FUNC",
  "PROC", "NULL_VALUE", "AND_OP", "GE_OP", "SE_OP", "NE_OP", "OR_OP",
  "EQL_OP", "BOOL_VALUE", "CHAR_VALUE", "STRING_VALUE", "INT_NUM", "F_NUM",
  "HEX_NUM", "ID", "IFX", "test", "';'", "'+'", "'-'", "'*'", "'/'", "'>'",
  "'<'", "'!'", "'^'", "'&'", "UMINUS", "UFUNC", "'('", "')'", "':'",
  "','", "'{'", "'}'", "'='", "'['", "']'", "$accept", "S",
  "FUNC_PROC_DEC", "DEF_A", "PROC_DEF", "FUNC_DEF", "ARGES", "OUT_ARGES",
  "INNER_ARGS", "FUNC_BLOCK", "EXPRASION", "FUNC_ACTIVE",
  "FUNC_ACTIVE_INNER_ARGES", "STASTMENT_LIST", "IF_STASTMENT", "STASTMENT",
  "RETURN_STATMENT", "LOOP_STATMENT", "UPDATES", "COMPUND_STATMENT",
  "COMPUND_STATMENT_PROC", "INNER_COMPUND_STATMENT", "DEC_INNER_BLOCK",
  "NEW_DECLARE", "VAR_DECLARE", "VF", "VFDEC", "CONST", "TYPE", YY_NULLPTR
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
     295,   296,   297,   298,    59,    43,    45,    42,    47,    62,
      60,    33,    94,    38,   299,   300,    40,    41,    58,    44,
     123,   125,    61,    91,    93
};
# endif

#define YYPACT_NINF -127

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-127)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,   -12,   -10,    46,  -127,    11,  -127,  -127,    -2,    -2,
    -127,  -127,   -13,    38,    17,    21,  -127,    19,    27,   159,
      90,  -127,    54,  -127,   159,  -127,  -127,  -127,  -127,  -127,
      34,  -127,  -127,  -127,  -127,    36,    42,    44,    47,  -127,
    -127,    54,  -127,  -127,  -127,   -26,   243,   243,   243,   243,
     243,   134,  -127,  -127,   328,  -127,   220,  -127,  -127,  -127,
    -127,    41,   220,    67,    79,  -127,  -127,  -127,    62,    75,
     177,  -127,   243,   243,   243,    66,  -127,   -25,   243,    93,
      93,    93,    93,   271,   243,    65,    84,   243,   243,   243,
     243,   243,   243,  -127,   243,   243,   243,   243,   243,   243,
    -127,  -127,   220,  -127,  -127,    54,    63,   243,   110,   277,
     335,   306,   159,    16,  -127,    76,    77,    78,   415,  -127,
     357,  -127,    83,    33,    33,    33,   415,    33,    33,    -7,
      -7,    89,    89,    33,    33,  -127,  -127,   364,   243,   220,
     243,   220,    96,    49,    49,  -127,    49,  -127,  -127,    86,
     386,   128,   393,  -127,    54,  -127,  -127,  -127,  -127,    87,
     220,   108,  -127,  -127,  -127,   -40,   101,   131,   132,   220,
    -127,  -127,  -127
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,     3,     6,     5,     0,     0,
       1,     4,     0,     0,     0,    13,     9,     0,     0,     0,
       0,     7,     0,    10,     0,    85,    84,    83,    82,    81,
       0,    86,    87,    88,    89,     0,     0,     0,     0,    19,
      20,     0,    77,    78,    79,    21,     0,     0,     0,     0,
       0,     0,    63,    71,     0,    39,    65,    54,    49,    55,
      52,     0,    66,    69,    70,    72,    17,    14,    11,     0,
       0,     8,     0,     0,     0,     0,    74,     0,     0,    24,
      25,    22,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,     0,     0,     0,     0,     0,     0,
      48,    64,    67,    68,    73,     0,     0,     0,     0,     0,
       0,     0,     0,    42,    40,    43,     0,    44,    26,    18,
       0,    62,     0,    28,    35,    36,    27,    29,    34,    30,
      31,    33,    32,    37,    38,    12,    80,     0,     0,     0,
       0,     0,     0,     0,     0,    41,     0,    56,    61,     0,
       0,    51,     0,    57,    75,    45,    47,    46,    15,     0,
       0,     0,    76,    16,    50,     0,     0,     0,     0,     0,
      59,    60,    58
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,    69,  -127,  -127,  -127,   168,    74,   -22,  -127,
     -39,   -73,  -126,   119,  -127,   -55,    97,  -127,  -127,  -127,
    -127,   -49,   121,  -127,  -127,   118,    35,   -65,   -21
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    53,     5,     6,     7,    13,    17,    18,    71,
      54,    55,   116,    56,    57,    58,    85,    59,   166,    60,
      21,    61,    62,    63,    64,    65,    76,    66,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      67,   100,    86,    68,   115,   167,   168,    79,    80,    81,
      82,    83,   117,    42,    43,    44,   113,   155,   156,    75,
     157,   108,    87,    88,    89,    90,    91,    92,    15,     8,
      77,     9,   114,   109,   110,   111,    78,     1,     2,   118,
      96,    97,    98,    99,    16,   120,    10,   100,   123,   124,
     125,   126,   127,   128,    12,   129,   130,   131,   132,   133,
     134,    19,    -1,    -1,    -1,    90,    -1,    -1,   137,     4,
     115,   115,    77,   115,    11,   143,    23,    20,   117,   117,
      22,   117,    -1,    -1,   151,    24,   153,    42,    43,    44,
     113,   142,    41,     1,     2,    15,    70,    69,    72,   150,
      73,   152,   101,    74,    41,   164,   105,    84,    36,    37,
      38,    39,    40,   106,   172,    41,     1,     2,    87,    88,
      89,    90,    91,    92,   112,    90,   121,   136,    42,    43,
      44,    45,    75,   138,   145,   144,    46,   146,    98,    99,
     154,    47,    48,    49,   148,   160,    50,   158,   163,   165,
      51,    52,    36,    37,    38,    39,    40,    84,   169,    41,
       1,     2,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    42,    43,    44,    45,   170,    14,   171,   135,
      46,   102,   104,   122,   103,    47,    48,    49,     0,   162,
      50,     0,     0,     0,    51,    36,    37,    38,    39,    40,
     107,     0,    41,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    42,    43,    44,    45,     0,
       0,     0,     0,    46,     0,     0,     0,     0,    47,    48,
      49,     0,     0,    50,     0,     0,     0,    51,    36,    37,
      38,    39,    40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    42,    43,
      44,    45,     0,     0,    39,    40,    46,     0,     0,     0,
       0,    47,    48,    49,     0,     0,    50,     0,     0,     0,
      51,    42,    43,    44,    45,     0,     0,     0,     0,    46,
       0,     0,     0,     0,    47,    48,    49,     0,     0,    50,
      87,    88,    89,    90,    91,    92,    87,    88,    89,    90,
      91,    92,     0,     0,     0,     0,    94,    95,    96,    97,
      98,    99,    94,    95,    96,    97,    98,    99,   119,     0,
       0,     0,     0,     0,   139,    87,    88,    89,    90,    91,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,    98,    99,    87,    88,    89,
      90,    91,    92,   141,    87,    88,    89,    90,    91,    92,
       0,     0,    93,    94,    95,    96,    97,    98,    99,   140,
      94,    95,    96,    97,    98,    99,    87,    88,    89,    90,
      91,    92,     0,    87,    88,    89,    90,    91,    92,     0,
       0,   147,    94,    95,    96,    97,    98,    99,   149,    94,
      95,    96,    97,    98,    99,    87,    88,    89,    90,    91,
      92,     0,    87,    88,    89,    90,    91,    92,     0,     0,
     159,    94,    95,    96,    97,    98,    99,   161,    94,    95,
      96,    97,    98,    99,    87,    88,    89,    90,    91,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,    98,    99
};

static const yytype_int16 yycheck[] =
{
      22,    56,    51,    24,    77,    45,    46,    46,    47,    48,
      49,    50,    77,    38,    39,    40,    41,   143,   144,    41,
     146,    70,    29,    30,    31,    32,    33,    34,    41,    41,
      56,    41,    57,    72,    73,    74,    62,    26,    27,    78,
      47,    48,    49,    50,    57,    84,     0,   102,    87,    88,
      89,    90,    91,    92,    56,    94,    95,    96,    97,    98,
      99,    23,    29,    30,    31,    32,    33,    34,   107,     0,
     143,   144,    56,   146,     5,    59,    57,    60,   143,   144,
      59,   146,    49,    50,   139,    58,   141,    38,    39,    40,
      41,   112,    25,    26,    27,    41,    60,    63,    56,   138,
      56,   140,    61,    56,    25,   160,    44,    23,    18,    19,
      20,    21,    22,    38,   169,    25,    26,    27,    29,    30,
      31,    32,    33,    34,    58,    32,    61,    64,    38,    39,
      40,    41,   154,    23,    57,    59,    46,    59,    49,    50,
      44,    51,    52,    53,    61,    17,    56,    61,    61,    41,
      60,    61,    18,    19,    20,    21,    22,    23,    57,    25,
      26,    27,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    38,    39,    40,    41,    45,     9,    46,   105,
      46,    62,    64,    86,    63,    51,    52,    53,    -1,   154,
      56,    -1,    -1,    -1,    60,    18,    19,    20,    21,    22,
      23,    -1,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    52,
      53,    -1,    -1,    56,    -1,    -1,    -1,    60,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    -1,    -1,    21,    22,    46,    -1,    -1,    -1,
      -1,    51,    52,    53,    -1,    -1,    56,    -1,    -1,    -1,
      60,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    51,    52,    53,    -1,    -1,    56,
      29,    30,    31,    32,    33,    34,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    45,    46,    47,    48,    49,    50,    57,    -1,
      -1,    -1,    -1,    -1,    57,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    48,    49,    50,    29,    30,    31,
      32,    33,    34,    57,    29,    30,    31,    32,    33,    34,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    44,
      45,    46,    47,    48,    49,    50,    29,    30,    31,    32,
      33,    34,    -1,    29,    30,    31,    32,    33,    34,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    44,    45,
      46,    47,    48,    49,    50,    29,    30,    31,    32,    33,
      34,    -1,    29,    30,    31,    32,    33,    34,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    44,    45,    46,
      47,    48,    49,    50,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    26,    27,    66,    67,    68,    69,    70,    41,    41,
       0,    67,    56,    71,    71,    41,    57,    72,    73,    23,
      60,    85,    59,    57,    58,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    93,    18,    19,    20,    21,
      22,    25,    38,    39,    40,    41,    46,    51,    52,    53,
      56,    60,    61,    67,    75,    76,    78,    79,    80,    82,
      84,    86,    87,    88,    89,    90,    92,    73,    93,    63,
      60,    74,    56,    56,    56,    73,    91,    56,    62,    75,
      75,    75,    75,    75,    23,    81,    86,    29,    30,    31,
      32,    33,    34,    44,    45,    46,    47,    48,    49,    50,
      80,    61,    78,    87,    90,    44,    38,    23,    86,    75,
      75,    75,    58,    41,    57,    76,    77,    92,    75,    57,
      75,    61,    81,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    72,    64,    75,    23,    57,
      44,    57,    93,    59,    59,    57,    59,    44,    61,    44,
      75,    80,    75,    80,    44,    77,    77,    77,    61,    44,
      17,    44,    91,    61,    80,    41,    83,    45,    46,    57,
      45,    46,    80
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    67,    68,    68,    69,    70,    71,
      71,    72,    72,    73,    73,    74,    74,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      76,    76,    77,    77,    77,    77,    77,    77,    78,    78,
      79,    79,    80,    80,    80,    80,    81,    82,    82,    83,
      83,    84,    84,    85,    85,    86,    86,    86,    87,    87,
      88,    88,    89,    89,    90,    91,    91,    92,    92,    92,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     4,     6,     2,
       3,     3,     5,     1,     3,     5,     6,     1,     3,     1,
       1,     1,     2,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     4,     1,     1,     1,     3,     3,     3,     2,     1,
       7,     5,     1,     2,     1,     1,     3,     5,     9,     3,
       3,     4,     3,     2,     3,     1,     1,     2,     2,     1,
       1,     1,     1,     2,     2,     4,     5,     1,     1,     1,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 131 "yacc.y" /* yacc.c:1652  */
    {
        (yyval.Node)=mknode("BLOCK",(yyvsp[0].Node),NULL);
		startSemantic((yyval.Node));
        printf("ok\n");
        }
#line 1574 "y.tab.c" /* yacc.c:1652  */
    break;

  case 3:
#line 140 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("",(yyvsp[0].Node),NULL);}
#line 1580 "y.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 141 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1586 "y.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 145 "yacc.y" /* yacc.c:1652  */
    {	(yyval.Node)=mknode("NEW_FUNC",(yyvsp[0].Node),NULL);}
#line 1592 "y.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 146 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("NEW_PROC",(yyvsp[0].Node),NULL);}
#line 1598 "y.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 152 "yacc.y" /* yacc.c:1652  */
    {
		(yyval.Node)=mknode("ARGS",NULL,(yyvsp[-1].Node));
		(yyval.Node)=mknode("ID",(yyval.Node),mkleaf((yyvsp[-2].String)));
		(yyval.Node)=mknode("PROC",(yyval.Node),(yyvsp[0].Node));
		}
#line 1608 "y.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 160 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=creathFuncDec((yyvsp[-4].String),(yyvsp[-3].Node),(yyvsp[-1].String),(yyvsp[0].Node));
	}
#line 1615 "y.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 164 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mkleaf("NULL_ARGS");}
#line 1621 "y.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 165 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(strdup("ARGS "),(yyvsp[-1].Node),NULL);
	}
#line 1628 "y.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 172 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode((yyvsp[0].String),(yyvsp[-2].Node),NULL);}
#line 1634 "y.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 173 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode((yyvsp[-2].String),(yyvsp[-4].Node),(yyvsp[0].Node));}
#line 1640 "y.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 180 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("ID",NULL,mkleaf((yyvsp[0].String)));}
#line 1646 "y.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 181 "yacc.y" /* yacc.c:1652  */
    {
		(yyval.Node)=mknode("ID",(yyvsp[0].Node),mkleaf((yyvsp[-2].String)));
		}
#line 1654 "y.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 188 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("BLOCK_FUNC",NULL,mknode(strdup("RETURN BLOCK"),(yyvsp[-2].Node),NULL));}
#line 1660 "y.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 189 "yacc.y" /* yacc.c:1652  */
    {
															(yyval.Node)=mknode("BLOCK_FUNC",(yyvsp[-4].Node),mknode(strdup("RETURN BLOCK"),(yyvsp[-2].Node),NULL));}
#line 1667 "y.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 198 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=(yyvsp[-1].Node);}
#line 1673 "y.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 199 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mkleaf("TRUE");}
#line 1679 "y.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 200 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mkleaf("FALSE");}
#line 1685 "y.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 201 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mkleaf((yyvsp[0].String));}
#line 1691 "y.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 202 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=(yyvsp[0].Node);}
#line 1697 "y.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 203 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=(yyvsp[0].Node);}
#line 1703 "y.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 204 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=(yyvsp[0].Node);}
#line 1709 "y.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 205 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=(yyvsp[0].Node);}
#line 1715 "y.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 206 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("=",mkleaf((yyvsp[-2].String)),(yyvsp[0].Node));}
#line 1721 "y.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 207 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("!=",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1727 "y.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 208 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("&&",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1733 "y.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 209 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("||",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1739 "y.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 210 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("+",(yyvsp[-2].Node),(yyvsp[0].Node));printf("was");}
#line 1745 "y.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 211 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("-",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1751 "y.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 212 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("/",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1757 "y.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 213 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("*",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1763 "y.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 214 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("==",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1769 "y.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 215 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(">=",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1775 "y.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 216 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("<=",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1781 "y.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 217 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(">",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1787 "y.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 218 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("<",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1793 "y.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 225 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("FUNC_PROC_ACTIVE",mknode("ID",NULL,mkleaf((yyvsp[-2].String))),mkleaf("Arges")); }
#line 1799 "y.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 226 "yacc.y" /* yacc.c:1652  */
    {
		(yyval.Node)=mknode("FUNC_PROC_ACTIVE",mknode("ID",NULL,mkleaf((yyvsp[-3].String))),mknode("Arges",NULL,(yyvsp[-1].Node)));
	}
#line 1807 "y.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 232 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("ID_ARG",mkleaf((yyvsp[0].String)),NULL);}
#line 1813 "y.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 233 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("FUNC_ARG",(yyvsp[0].Node),NULL);}
#line 1819 "y.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 234 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("CONST_ARG",(yyvsp[0].Node),NULL);}
#line 1825 "y.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 235 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("ID_ARG",mkleaf((yyvsp[-2].String)),(yyvsp[0].Node));}
#line 1831 "y.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 236 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("CONST_ARG",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1837 "y.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 237 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("FUNC_ARG",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1843 "y.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 242 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1849 "y.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 248 "yacc.y" /* yacc.c:1652  */
    {
		(yyval.Node)=mknode("IF_ELSE",
		mknode("EXPRASION_IF",NULL,(yyvsp[-4].Node)),
		mknode("BODY_IF",mknode("ELSE",NULL,(yyvsp[0].Node)),(yyvsp[-2].Node))
		);
		}
#line 1860 "y.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 255 "yacc.y" /* yacc.c:1652  */
    {  
        (yyval.Node)=mknode("IF",mknode("EXPRASION_IF",NULL,(yyvsp[-2].Node)),mknode("BODY_IF",NULL,(yyvsp[0].Node)));}
#line 1867 "y.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 267 "yacc.y" /* yacc.c:1652  */
    {
        (yyval.Node)=mknode("RETURN STATMENT",(yyvsp[-1].Node),NULL);
        }
#line 1875 "y.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 273 "yacc.y" /* yacc.c:1652  */
    {
		(yyval.Node)=mknode("WHILE",mknode("EXPRESSION",NULL,(yyvsp[-2].Node)),mknode("BODY",NULL,(yyvsp[0].Node)));
		}
#line 1883 "y.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 278 "yacc.y" /* yacc.c:1652  */
    {	
		(yyval.Node)=mknode("FOR",mknode("INIT",mknode("EXPRESSION_FOR",mknode("UPDATE",NULL,(yyvsp[-2].Node)),(yyvsp[-4].Node)),(yyvsp[-6].Node)),mknode("BODY",NULL,(yyvsp[0].Node)));
	}
#line 1891 "y.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 284 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(strcat((yyvsp[-2].String),strdup("++")),NULL,NULL);}
#line 1897 "y.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 285 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(strcat((yyvsp[-2].String),strdup("--")),NULL,NULL);}
#line 1903 "y.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 291 "yacc.y" /* yacc.c:1652  */
    { (yyval.Node)=mknode("BLOCK",(yyvsp[-1].Node),(yyvsp[-2].Node)); }
#line 1909 "y.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 292 "yacc.y" /* yacc.c:1652  */
    { (yyval.Node)=mknode("BLOCK",(yyvsp[-1].Node),NULL); }
#line 1915 "y.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 296 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("BLOCK",NULL,NULL);}
#line 1921 "y.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 297 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("BLOCK",NULL,(yyvsp[-1].Node));}
#line 1927 "y.tab.c" /* yacc.c:1652  */
    break;

  case 65:
#line 301 "yacc.y" /* yacc.c:1652  */
    { (yyval.Node)=mknode("",NULL,(yyvsp[0].Node));}
#line 1933 "y.tab.c" /* yacc.c:1652  */
    break;

  case 66:
#line 302 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("",(yyvsp[0].Node),NULL);}
#line 1939 "y.tab.c" /* yacc.c:1652  */
    break;

  case 67:
#line 303 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1945 "y.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 308 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("DECLARE",(yyvsp[-1].Node),(yyvsp[0].Node));
	}
#line 1952 "y.tab.c" /* yacc.c:1652  */
    break;

  case 69:
#line 310 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("DECLARE",(yyvsp[0].Node),NULL);
}
#line 1959 "y.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 320 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("VAR_DECLARE",(yyvsp[0].Node),NULL);}
#line 1965 "y.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 321 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("VAR_DECLARE",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1971 "y.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 325 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=(yyvsp[0].Node);}
#line 1977 "y.tab.c" /* yacc.c:1652  */
    break;

  case 75:
#line 329 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode((yyvsp[-1].String),(yyvsp[-3].Node),NULL);}
#line 1983 "y.tab.c" /* yacc.c:1652  */
    break;

  case 76:
#line 330 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode((yyvsp[-2].String),(yyvsp[-4].Node),(yyvsp[0].Node));}
#line 1989 "y.tab.c" /* yacc.c:1652  */
    break;

  case 77:
#line 334 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("int",mkleaf((yyvsp[0].String)),NULL);}
#line 1995 "y.tab.c" /* yacc.c:1652  */
    break;

  case 78:
#line 335 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("float",mkleaf((yyvsp[0].String)),NULL);}
#line 2001 "y.tab.c" /* yacc.c:1652  */
    break;

  case 79:
#line 336 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("hex",mkleaf((yyvsp[0].String)),NULL);}
#line 2007 "y.tab.c" /* yacc.c:1652  */
    break;

  case 89:
#line 349 "yacc.y" /* yacc.c:1652  */
    {printf("got hare\n");}
#line 2013 "y.tab.c" /* yacc.c:1652  */
    break;


#line 2017 "y.tab.c" /* yacc.c:1652  */
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
#line 351 "yacc.y" /* yacc.c:1918  */


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
	struct deciptopn ** temp_symbal;
	int i=0;
	unsigned long long int  sizeHT = SYMBALTABLESIZE;
	//creath first hush key for the string
	unsigned long long int idtemp = compute_hash(symbel->id)  ;
	unsigned long long int id=idtemp-idtemp/sizeHT*sizeHT;
	//chack if alrdy has this symbol

	if(strcmp(hashTableSymbel[id].name ,"")==0)
		hashTableSymbel[id].name = symbel->id;

	if(hashTableSymbel[id].name=="")
		if(!strcmp (hashTableSymbel[id].name ,symbel->id ))
			//if not creah table for the symbel
			hashTableSymbel[id].name = symbel->id;
	

	//copy the pointer fot the symbel data

	temp_symbal=&(hashTableSymbel[id].symbals);

	//look for first empty space
	while((*temp_symbal) != NULL)
		temp_symbal=&((*temp_symbal) -> next);
	
	//insert in the empty space the the table for the symbel


	//hare can find out if alredy crather this symbol
	//to do chack if symbol alerdy exsists
	if (NULL)
		return 1;

	(*temp_symbal)=symbel;


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
	struct deciptopn * temp ;

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
						deep,
						root->left->left->right->left);
						

		push(creathFrame());
		printf("found new block %d\n",deep);

		find_var_names("",root->left->left->right->left);
		


		
		if(root->right)
			CrearhSymbalFrame(root->right);

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
						deep,
						root->left->left->right->left);

		push(creathFrame());
		if(root->left->left->right->left)
			find_var_names("",root->left->left->right->left);

		printf("found new block %d\n",deep);

		if(root->right)
			CrearhSymbalFrame(root->right);


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
		find_var_names(" ",root->left);
		
	}

	if( !strcmp (root->token ,"FUNC_PROC_ACTIVE")){
		int temp1;
		temp=get_symbal_from_hash(root->left->right->token);


		if(temp==NULL){
			printf("the func proc %s was not declared\n",root->left->right->token);
			exit(1);
		}
		if((temp1=checkFunc(temp->arges,root->right))==1){
			printf("too many arges for func %s\n",root->left->right->token);
			exit(1);
		}
		
		else if(temp1==2){
			printf("too few arges for func %s\n",root->left->right->token);
			exit(1);
		}

		
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

int insert_symbel(char * id,int is_func_proc,char * type,char * data, char * return_value,int frameBelong , node * arges){
	struct deciptopn * temp=(struct deciptopn *)malloc(sizeof(deciptopn));
	temp->id=id;
	temp->isProc_func=is_func_proc;

	if(temp->isProc_func)
		temp->return_value=return_value;
	else
		temp->return_value=NULL;

	if(arges)
		temp->arges=makeArgsReq(arges);

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

	if ((strcmp(root->token,"ID")) && (strcmp(root->token,""))){

		if(root->left)
			find_var_names(root->token,root->left);
				if(root->right)
					find_var_names("",root->right);
	}
	else
	{
		insert_symbel(root->right->token ,0,type,NULL,NULL,deep,NULL);
		if(root->left)
			find_var_names(root->token,root->left);
	}
}

deciptopn * get_symbal_from_hash(char * name){
	struct deciptopn * temp;

	unsigned long long int  sizeHT = SYMBALTABLESIZE;
	//creath first hush key for the string
	unsigned long long int idtemp = compute_hash(name);
	unsigned long long int id=idtemp-idtemp/sizeHT*sizeHT;

	temp=hashTableSymbel[id].symbals;
	return temp;

}

node * makeArgsReq(node * root){
	node * temp, * last;
	temp=getInnerArges(root->left,root->token);
	last=temp;
	while(last->right)
		last=last->right;
	
	if(root->right)
		
		last->right=makeArgsReq(root->right);

	return temp;	
	
}

node * getInnerArges(node * root ,char * type){
	node * new_arg;
	new_arg=(node*)malloc(sizeof(node));

	new_arg->token=type;

	if(root->left)
		new_arg->right=getInnerArges(root->left,type);
	else
		new_arg->right=NULL;

	return new_arg;
}

void printLinkedList(node * root){
	if(root)
		printf(" %s -> ",root->token);
	if(root->right)
		printLinkedList(root->right);
	else
		printf("\n");
}

int checkFunc(node * originalArges,node * newArges){
	char * arg_type;
	struct deciptopn * temp;
	node * temp2;
	int temp1;

	while(originalArges){
		
		
		if(!newArges)
			return 1;
		
		if(newArges->right){

			arg_type=originalArges->token;

			newArges=newArges->right;
			temp2=originalArges;
			originalArges=originalArges->right;



			if(strcmp("CONST_ARG",newArges->token)==0){
				temp=(struct deciptopn *)malloc(sizeof(deciptopn));
				temp->id=newArges->left->left->token;
				temp->type=newArges->left->token;
				temp->data=newArges->left->left->token;
				chack_arges(temp,temp2,0);
			}

			else if(strcmp("ID_ARG",newArges->token)==0){
				temp=get_symbal_from_hash(newArges->left->token);
				if(temp==NULL){
					printf("used symbel %s before declorasion \n",newArges->left->token);
					exit(1);
				}

				chack_arges(temp,temp2,0);
			}

			else if(strcmp("FUNC_ARG",newArges->token)==0){
				temp=get_symbal_from_hash(newArges->left->left->right->token);
			

				if(temp==NULL){
					printf("used symbel %s before declorasion \n",newArges->left->token);
					exit(1);
				}
				if((temp1=checkFunc(temp->arges,newArges->left->right))==1){
					printf("too many arges for func %s\n",temp->id);
					exit(1);
				}

		
		



				chack_arges(temp,temp2,1);

				




			}


		}
		else if(!newArges->right)
			return 2;
	}
}

int chack_arges(deciptopn * originalArges,node * newArges,int typeofchack){
	if(typeofchack==0)
		if (strcmp(newArges->token,originalArges->type))
			{
				printf("wrong type for var %s \nexpected %s got %s\n",originalArges->id,
				newArges->token,originalArges->type);
				exit(1);
			}

	if(typeofchack==1)
		if (strcmp(newArges->token,originalArges->return_value))
			{
				printf("wrong type for func/proc %s \nexpected %s got %s\n",originalArges->id,
				newArges->token,originalArges->return_value);
				exit(1);
			}
		return 0;
}
