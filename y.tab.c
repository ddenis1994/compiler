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
#include <string.h>
typedef struct node
{
char *token;
int deep;
struct node *left;
struct node *right;
} node;



node *mknode(char *token, node *left, node *right);

void printtree(node *tree,int space);
void moveUp(node * );
void moveDown(node *);
void yyerror(char *);
extern int yylex();

#line 93 "y.tab.c" /* yacc.c:337  */
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
    RETURN = 272,
    MAIN = 273,
    VAR = 274,
    FUNC = 275,
    PROC = 276,
    NULL_VALUE = 277,
    AND_OP = 278,
    GE_OP = 279,
    SE_OP = 280,
    NE_OP = 281,
    OR_OP = 282,
    EQL_OP = 283,
    BOOL_VALUE = 284,
    CHAR_VALUE = 285,
    STRING_VALUE = 286,
    INT_NUM = 287,
    F_NUM = 288,
    ID = 289,
    IFX = 290,
    test = 291,
    UMINUS = 292,
    UFUNC = 293
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
#define RETURN 272
#define MAIN 273
#define VAR 274
#define FUNC 275
#define PROC 276
#define NULL_VALUE 277
#define AND_OP 278
#define GE_OP 279
#define SE_OP 280
#define NE_OP 281
#define OR_OP 282
#define EQL_OP 283
#define BOOL_VALUE 284
#define CHAR_VALUE 285
#define STRING_VALUE 286
#define INT_NUM 287
#define F_NUM 288
#define ID 289
#define IFX 290
#define test 291
#define UMINUS 292
#define UFUNC 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 23 "yacc.y" /* yacc.c:352  */

	char * String;
	struct node * Node;

#line 217 "y.tab.c" /* yacc.c:352  */
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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   271

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  182

#define YYUNDEFTOK  2
#define YYMAXUTOK   293

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
       2,     2,     2,     2,     2,     2,     2,     2,    53,     2,
      46,    47,    40,    38,    49,    39,     2,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    37,
      44,    52,    43,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    55,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,    51,     2,     2,     2,     2,
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
      35,    36,    42,    45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    63,    63,    70,    71,    72,    75,    79,    80,    84,
      85,    91,    95,   102,   105,   109,   114,   122,   123,   131,
     133,   139,   140,   144,   145,   146,   147,   148,   149,   155,
     156,   157,   158,   159,   162,   163,   170,   171,   177,   178,
     183,   186,   192,   193,   194,   195,   196,   200,   206,   207,
     217,   218,   223,   224,   225,   226,   230,   232,   233,   241,
     242,   246,   247,   251,   252,   256,   260,   261,   262,   268,
     269,   270,   274,   275,   276,   277,   278,   282,   283,   284,
     285,   291,   292,   293,   294,   295,   296
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR", "REAL", "FLOAT", "INT", "BOOL",
  "STRING", "CHAR_POINTER", "REAL_POINTER", "FLOAT_POINTER", "INT_POINTER",
  "ELSE", "IF", "FOR", "WHILE", "RETURN", "MAIN", "VAR", "FUNC", "PROC",
  "NULL_VALUE", "AND_OP", "GE_OP", "SE_OP", "NE_OP", "OR_OP", "EQL_OP",
  "BOOL_VALUE", "CHAR_VALUE", "STRING_VALUE", "INT_NUM", "F_NUM", "ID",
  "IFX", "test", "';'", "'+'", "'-'", "'*'", "'/'", "UMINUS", "'>'", "'<'",
  "UFUNC", "'('", "')'", "':'", "','", "'{'", "'}'", "'='", "'&'", "'['",
  "']'", "$accept", "S", "CODE", "MAIN_FUNC", "FUNC_PROC_DEC", "DEF_A",
  "PROC_DEF", "FUNC_DEF", "ARGES", "OUT_ARGES", "INNER_ARGS", "FUNC_BLOCK",
  "REL_EXPRATION", "REL_EXPRATION2", "EXPRASION", "ASSIGNMENT",
  "FUNC_ACTIVE", "STASTMENT_LIST", "IF_STASTMENT", "STASTMENT",
  "RETURN_STATMENT", "LOOP_STATMENT", "UPDATES", "COMPUND_STATMENT",
  "INNER_COMPUND_STATMENT", "DEC_INNER_BLOCK", "NEW_DECLARE",
  "VAR_DECLARE", "VF", "LOG_EXPRATIOSN_LIST", "UNARY_EXPRATION",
  "UNARY_EXPRATION2", "CONST", "TYPE", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,    59,    43,    45,
      42,    47,   292,    62,    60,   293,    40,    41,    58,    44,
     123,   125,    61,    38,    91,    93
};
# endif

#define YYPACT_NINF -114

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-114)))

#define YYTABLE_NINF -67

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      50,   -30,     6,    15,  -114,  -114,    50,  -114,  -114,  -114,
      17,   -17,    17,  -114,  -114,  -114,   -13,    37,   124,  -114,
     -17,    24,  -114,    58,    60,   233,    65,    76,    78,    70,
     116,   120,  -114,  -114,    55,   186,   189,  -114,    98,   118,
     125,  -114,    -2,   153,  -114,  -114,   121,  -114,  -114,   -14,
     153,     8,   157,  -114,    39,  -114,   166,  -114,   116,  -114,
     233,  -114,  -114,  -114,  -114,  -114,   123,   133,    70,    70,
      70,  -114,   151,   136,    -8,   -21,   149,   186,  -114,   204,
     204,   155,   161,   173,  -114,  -114,  -114,  -114,   145,   153,
    -114,  -114,   147,   147,   127,   127,   127,   186,   186,   186,
     186,   127,   127,  -114,  -114,  -114,   163,   183,   132,  -114,
     177,   190,   179,  -114,   233,  -114,   182,   196,  -114,  -114,
      89,   204,  -114,  -114,  -114,  -114,   127,    89,    89,    89,
      89,   204,   204,   204,   204,    89,    89,   116,   176,    70,
     216,   153,    70,   153,   197,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,
     209,    70,   234,   211,  -114,  -114,   198,   213,   153,   217,
    -114,   201,  -114,    92,   206,  -114,   218,   215,   153,  -114,
    -114,  -114
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,     5,     3,     7,    10,     9,
       0,     0,     0,     1,     4,     8,     0,     0,     0,     6,
       0,    17,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    77,    78,    80,     0,     0,    52,    62,    42,
       0,    30,    79,    56,    45,    39,     0,    46,    43,     0,
      57,    60,    61,    63,    29,    33,    23,    11,     0,    14,
       0,    86,    85,    84,    83,    82,     0,     0,     0,     0,
       0,    32,     0,     0,     0,     0,    80,     0,    79,    72,
      72,     0,     0,    23,    44,    38,    55,    53,     0,    58,
      59,    64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,    69,    18,    15,     0,     0,    12,
       0,     0,     0,    47,     0,    36,     0,     0,    34,    70,
      23,    72,    54,    67,    66,    68,     0,    23,    23,    23,
      23,    72,    72,    72,    72,    23,    23,     0,     0,     0,
       0,     0,     0,     0,     0,    37,    35,    22,    71,    26,
      27,    28,    73,    74,    75,    76,    24,    25,    16,    81,
       0,     0,    41,     0,    48,    65,     0,     0,     0,     0,
      19,     0,    40,     0,     0,    20,     0,     0,     0,    50,
      51,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -114,  -114,  -114,   249,   257,     0,  -114,  -114,   246,   122,
     -22,  -114,   -27,  -113,   -19,  -114,   -16,   210,  -114,   -43,
     212,  -114,  -114,    33,   154,   214,  -114,  -114,   219,    44,
      29,   -74,    -5,   -59
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    38,     7,     8,     9,    17,    23,
      24,   109,    39,   103,    40,    41,    42,    43,    44,    45,
      46,    47,   174,    48,    49,    50,    51,    52,    53,    54,
      55,   104,    56,    67
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      85,   106,    71,    29,    10,   119,    15,   147,    73,    81,
      72,    32,    33,    34,   149,    13,   150,   151,    35,    78,
      78,    21,   156,   157,    11,    36,    21,    30,     1,    31,
      80,    83,   117,    18,    22,   -31,   105,    87,    15,   115,
      12,    71,    71,    71,    19,   -31,    85,   148,    71,   110,
     111,   112,   116,    57,    25,   144,   118,   152,   153,   154,
     155,    78,    92,    16,    79,    82,    93,   127,   129,   130,
       1,     2,    80,    58,   135,   136,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,   124,   124,   128,
     128,   128,    80,    80,    80,    80,   128,   128,   162,    81,
     164,    74,    32,    33,    34,    59,    82,    75,    60,    35,
      78,    68,    71,    94,    95,    71,    36,    96,     1,    31,
     160,   128,    69,   163,    70,   172,   131,   132,   133,   134,
     176,   177,   101,   102,    71,   181,   123,   125,    26,    27,
      28,    29,   167,    30,     1,    31,    26,    27,    28,   139,
      21,    30,     1,    31,    12,   -32,    32,    33,    34,    32,
      33,    76,    84,    35,    32,    33,    34,    26,    27,    28,
      36,    35,    86,   126,    18,    37,    30,   107,    36,    32,
      33,    76,    18,   108,   114,    32,    33,    34,   113,   -66,
      94,    95,    35,   -66,    96,    74,   122,    94,    95,    36,
     137,    96,   120,    18,    97,    98,    99,   100,   121,   101,
     102,    97,    98,    99,   100,   138,   101,   102,    32,    33,
      76,    32,    33,    76,   141,    35,   143,   142,    35,   145,
     146,   159,    77,   161,   165,    36,    61,    62,    63,    64,
      65,    66,    97,    98,    99,   100,   166,   168,   169,   170,
     171,   173,   175,   178,   180,    14,   179,     6,    20,   158,
      89,    88,   140,     0,     0,    90,     0,     0,     0,     0,
       0,    91
};

static const yytype_int16 yycheck[] =
{
      43,    60,    29,    17,    34,    79,     6,   120,    30,    36,
      29,    32,    33,    34,   127,     0,   129,   130,    39,    35,
      36,    34,   135,   136,    18,    46,    34,    19,    20,    21,
      35,    36,    53,    50,    47,    37,    58,    51,    38,    47,
      34,    68,    69,    70,    11,    47,    89,   121,    75,    68,
      69,    70,    74,    20,    17,   114,    75,   131,   132,   133,
     134,    77,    23,    46,    35,    36,    27,    94,    95,    96,
      20,    21,    77,    49,   101,   102,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   141,   126,
     143,    46,    32,    33,    34,    47,    77,    52,    48,    39,
     126,    46,   139,    24,    25,   142,    46,    28,    20,    21,
     139,   126,    46,   142,    46,   168,    97,    98,    99,   100,
      38,    39,    43,    44,   161,   178,    92,    93,    14,    15,
      16,    17,   161,    19,    20,    21,    14,    15,    16,    17,
      34,    19,    20,    21,    34,    37,    32,    33,    34,    32,
      33,    34,    37,    39,    32,    33,    34,    14,    15,    16,
      46,    39,    51,    46,    50,    51,    19,    54,    46,    32,
      33,    34,    50,    50,    48,    32,    33,    34,    37,    23,
      24,    25,    39,    27,    28,    46,    51,    24,    25,    46,
      37,    28,    47,    50,    38,    39,    40,    41,    47,    43,
      44,    38,    39,    40,    41,    32,    43,    44,    32,    33,
      34,    32,    33,    34,    47,    39,    47,    37,    39,    47,
      34,    55,    46,    17,    37,    46,     3,     4,     5,     6,
       7,     8,    38,    39,    40,    41,    37,    13,    37,    51,
      37,    34,    51,    47,    39,     6,    38,     0,    12,   137,
      50,    49,   108,    -1,    -1,    51,    -1,    -1,    -1,    -1,
      -1,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    21,    57,    58,    59,    60,    61,    62,    63,
      34,    18,    34,     0,    59,    61,    46,    64,    50,    79,
      64,    34,    47,    65,    66,    17,    14,    15,    16,    17,
      19,    21,    32,    33,    34,    39,    46,    51,    60,    68,
      70,    71,    72,    73,    74,    75,    76,    77,    79,    80,
      81,    82,    83,    84,    85,    86,    88,    79,    49,    47,
      48,     3,     4,     5,     6,     7,     8,    89,    46,    46,
      46,    68,    70,    66,    46,    52,    34,    46,    72,    86,
      88,    68,    86,    88,    37,    75,    51,    51,    76,    73,
      81,    84,    23,    27,    24,    25,    28,    38,    39,    40,
      41,    43,    44,    69,    87,    66,    89,    54,    50,    67,
      70,    70,    70,    37,    48,    47,    66,    53,    70,    87,
      47,    47,    51,    85,    88,    85,    46,    68,    88,    68,
      68,    86,    86,    86,    86,    68,    68,    37,    32,    17,
      80,    47,    37,    47,    89,    47,    34,    69,    87,    69,
      69,    69,    87,    87,    87,    87,    69,    69,    65,    55,
      70,    17,    75,    70,    75,    37,    37,    70,    13,    37,
      51,    37,    75,    34,    78,    51,    38,    39,    47,    38,
      39,    75
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    58,    58,    59,    60,    60,    61,
      61,    62,    63,    64,    64,    65,    65,    66,    66,    67,
      67,    68,    68,    69,    69,    69,    69,    69,    69,    70,
      70,    70,    70,    70,    71,    71,    72,    72,    73,    73,
      74,    74,    75,    75,    75,    75,    75,    76,    77,    77,
      78,    78,    79,    79,    79,    79,    80,    80,    80,    81,
      81,    82,    82,    83,    83,    84,    85,    85,    85,    86,
      86,    86,    87,    87,    87,    87,    87,    88,    88,    88,
      88,    89,    89,    89,    89,    89,    89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     3,     1,     2,     1,
       1,     4,     6,     2,     3,     3,     5,     1,     3,     5,
       6,     2,     4,     0,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     3,     4,     3,     4,     2,     1,
       7,     5,     1,     1,     2,     1,     1,     3,     5,     9,
       3,     3,     2,     3,     4,     3,     1,     1,     2,     2,
       1,     1,     1,     1,     2,     5,     1,     3,     3,     2,
       3,     4,     0,     3,     3,     3,     3,     1,     1,     1,
       1,     4,     1,     1,     1,     1,     1
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
#line 63 "yacc.y" /* yacc.c:1652  */
    {
        (yyval.Node)=mknode("CODE",(yyvsp[0].Node),NULL);
        printtree((yyval.Node),0);
        printf("ok\n");
        }
#line 1461 "y.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 71 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1467 "y.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 75 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("PROC MAIN",(yyvsp[0].Node),NULL);}
#line 1473 "y.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 80 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1479 "y.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 91 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(strcat(strdup("PROC "),(yyvsp[-2].String)),(yyvsp[0].Node),NULL);}
#line 1485 "y.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 95 "yacc.y" /* yacc.c:1652  */
    {
											(yyval.Node)=mknode(strcat(strdup("RET "),(yyvsp[-1].String)),NULL,NULL);
											(yyvsp[-3].Node)=mknode("",(yyvsp[-3].Node),(yyval.Node));
											(yyval.Node)=mknode(strcat(strdup("FUNC "),(yyvsp[-4].String)),(yyvsp[-3].Node),(yyvsp[0].Node));
											}
#line 1495 "y.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 102 "yacc.y" /* yacc.c:1652  */
    {
				(yyval.Node)=mknode(strdup("empty arguments"),NULL,NULL);
				}
#line 1503 "y.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 105 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(strdup("ARGS "),(yyvsp[-1].Node),NULL);}
#line 1509 "y.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 109 "yacc.y" /* yacc.c:1652  */
    {
						strcat((yyvsp[0].String),": ");
						strcat((yyvsp[0].String),(yyvsp[-2].String));
						(yyval.Node)=mknode((yyvsp[0].String),NULL,NULL);
						}
#line 1519 "y.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 114 "yacc.y" /* yacc.c:1652  */
    {
						strcat((yyvsp[-2].String),": ");
						strcat((yyvsp[-2].String),(yyvsp[-4].String));
						(yyval.Node)=mknode((yyvsp[-2].String),(yyvsp[0].Node),NULL);
						moveDown((yyvsp[0].Node));
						}
#line 1530 "y.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 123 "yacc.y" /* yacc.c:1652  */
    {
		strcat((yyvsp[-2].String)," ");
		strcat((yyvsp[-2].String),(yyvsp[0].String));
		}
#line 1539 "y.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 131 "yacc.y" /* yacc.c:1652  */
    {
								(yyval.Node)=mknode("",NULL,mknode(strdup("RETURN "),(yyvsp[-2].Node),NULL));}
#line 1546 "y.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 133 "yacc.y" /* yacc.c:1652  */
    {
															(yyval.Node)=mknode("",(yyvsp[-4].Node),mknode(strdup("RETURN "),(yyvsp[-2].Node),NULL));}
#line 1553 "y.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 139 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("()",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1559 "y.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 140 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("()",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1565 "y.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 144 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("",NULL,NULL);}
#line 1571 "y.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 145 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(">=",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1577 "y.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 146 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(">=",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1583 "y.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 147 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(">=",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1589 "y.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 148 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("<=",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1595 "y.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 149 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("==",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1601 "y.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 162 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(strcat((yyvsp[-2].String)," ="),(yyvsp[0].Node),NULL);}
#line 1607 "y.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 163 "yacc.y" /* yacc.c:1652  */
    {
        strcat((yyvsp[-3].String)," = & ");
        strcat((yyvsp[-3].String),(yyvsp[0].String));
        (yyval.Node)=mknode((yyvsp[-3].String),NULL,NULL);}
#line 1616 "y.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 170 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(strcat((yyvsp[-2].String)," ACTIVE:"),mknode(strdup("empty arguments"),NULL,NULL),NULL);}
#line 1622 "y.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 171 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(strcat((yyvsp[-3].String)," ACTIVE:"),mknode(strdup("ARGS "),mknode((yyvsp[-1].String),NULL,NULL),NULL),NULL);
							}
#line 1629 "y.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 177 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("",(yyvsp[-1].Node),(yyvsp[0].Node));moveDown((yyvsp[0].Node));}
#line 1635 "y.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 183 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("IF_ELSE",mknode("EXPRASION",(yyvsp[-4].Node),(yyvsp[-2].Node)),mknode("ELSE_STATEMENT",(yyvsp[0].Node),NULL));
																												//moveDown($$->right);
																												}
#line 1643 "y.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 186 "yacc.y" /* yacc.c:1652  */
    {
        
        (yyval.Node)=mknode("IF",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1651 "y.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 200 "yacc.y" /* yacc.c:1652  */
    {
        (yyval.Node)=mknode("RETURN STATMENT",(yyvsp[-1].Node),NULL);
        }
#line 1659 "y.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 206 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("WHILE LOOP",mknode("EXPRESSION",(yyvsp[-2].Node),NULL),(yyvsp[0].Node));}
#line 1665 "y.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 209 "yacc.y" /* yacc.c:1652  */
    {	
		(yyvsp[-6].Node)=mknode("",(yyvsp[-6].Node),NULL);
        (yyvsp[-4].Node)=mknode("",(yyvsp[-4].Node),(yyvsp[-6].Node));
		(yyvsp[-2].Node)=mknode("",(yyvsp[-2].Node),(yyvsp[-4].Node));
		(yyval.Node)=mknode("FOR LOOP",mknode("EXPRESSION",(yyvsp[-2].Node),NULL),(yyvsp[0].Node));}
#line 1675 "y.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 217 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(strcat((yyvsp[-2].String),strdup("++")),NULL,NULL);}
#line 1681 "y.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 218 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(strcat((yyvsp[-2].String),strdup("--")),NULL,NULL);}
#line 1687 "y.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 223 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("empty statments",NULL,NULL);}
#line 1693 "y.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 224 "yacc.y" /* yacc.c:1652  */
    { (yyval.Node)=(yyvsp[-1].Node); }
#line 1699 "y.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 225 "yacc.y" /* yacc.c:1652  */
    { (yyval.Node)=(yyvsp[-2].Node); }
#line 1705 "y.tab.c" /* yacc.c:1652  */
    break;

  case 55:
#line 226 "yacc.y" /* yacc.c:1652  */
    { (yyval.Node)=(yyvsp[-1].Node); }
#line 1711 "y.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 230 "yacc.y" /* yacc.c:1652  */
    { 
        (yyval.Node)=mknode("BODY",NULL,(yyvsp[0].Node));}
#line 1718 "y.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 232 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("BODY",(yyvsp[0].Node),NULL);}
#line 1724 "y.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 233 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("BODY",(yyvsp[-1].Node),(yyvsp[0].Node));
				 }
#line 1731 "y.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 241 "yacc.y" /* yacc.c:1652  */
    {mknode("",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1737 "y.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 252 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1743 "y.tab.c" /* yacc.c:1652  */
    break;

  case 65:
#line 256 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode((yyvsp[-1].String),mknode((yyvsp[-3].String),NULL,NULL),NULL);}
#line 1749 "y.tab.c" /* yacc.c:1652  */
    break;

  case 67:
#line 261 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("&&",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1755 "y.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 262 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("||",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1761 "y.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 269 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("minus",(yyvsp[-1].Node),NULL);}
#line 1767 "y.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 270 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=(yyvsp[-2].Node);}
#line 1773 "y.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 274 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("+",NULL,NULL);}
#line 1779 "y.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 275 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("+",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1785 "y.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 276 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("-",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1791 "y.tab.c" /* yacc.c:1652  */
    break;

  case 75:
#line 277 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("*",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1797 "y.tab.c" /* yacc.c:1652  */
    break;

  case 76:
#line 278 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("/",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1803 "y.tab.c" /* yacc.c:1652  */
    break;

  case 77:
#line 282 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode((yyvsp[0].String),NULL,NULL);}
#line 1809 "y.tab.c" /* yacc.c:1652  */
    break;

  case 78:
#line 283 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode((yyvsp[0].String),NULL,NULL);}
#line 1815 "y.tab.c" /* yacc.c:1652  */
    break;

  case 79:
#line 284 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=(yyvsp[0].Node);}
#line 1821 "y.tab.c" /* yacc.c:1652  */
    break;

  case 80:
#line 285 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode((yyvsp[0].String),NULL,NULL);}
#line 1827 "y.tab.c" /* yacc.c:1652  */
    break;


#line 1831 "y.tab.c" /* yacc.c:1652  */
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
#line 298 "yacc.y" /* yacc.c:1918  */


void yyerror(char * msg){
    fprintf(stderr, "%s\n",msg);
    exit(1);
}

int main(){
    yyparse();
    return 0;
}
void printtree(node * tree,int space)
{
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

node *mknode(char *token, node *left, node *right)
{
node * newnode=(node*)malloc(sizeof(node));
char *newstr=(char*)malloc(sizeof(token) + 1);
strcpy(newstr,token);
newnode->left=left;
newnode->right=right;
newnode->token=newstr;
newnode->deep=0;
return 	newnode;
}




void moveUp(node * tree){
	tree->deep=tree->deep+1;
	if(tree->right)
		moveUp(tree->right);
	if(tree->left)
		moveUp(tree->left);
}

void moveDown(node * tree){
	if(tree->deep > 0)
		(tree->deep)=(tree->deep)-1;
	if(tree->right!=NULL)
		moveDown(tree->right);
	if(tree->left!=NULL)
		moveDown(tree->left);
}
