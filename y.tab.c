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
node *mkleaf(char *token);

void printtree(node *tree,int space);
void moveUp(node * );
void moveDown(node *);
void yyerror(char *);
extern int yylex();

#line 94 "y.tab.c" /* yacc.c:337  */
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
#line 24 "yacc.y" /* yacc.c:352  */

	char * String;
	struct node * Node;

#line 218 "y.tab.c" /* yacc.c:352  */
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
#define YYLAST   276

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  189

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
       2,    55,     2,    56,    54,     2,     2,     2,     2,     2,
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
       0,    65,    65,    72,    73,    77,    78,    82,    86,    90,
      91,    95,    96,   102,   106,   113,   117,   118,   122,   130,
     131,   136,   137,   145,   147,   155,   156,   157,   158,   159,
     162,   163,   167,   168,   169,   170,   171,   172,   176,   177,
     178,   182,   183,   184,   185,   186,   190,   191,   192,   198,
     199,   203,   210,   211,   217,   218,   223,   226,   232,   233,
     234,   235,   236,   240,   246,   247,   257,   258,   263,   264,
     265,   266,   270,   272,   273,   281,   282,   286,   287,   291,
     292,   296,   305,   306,   307,   308,   314,   315,   316,   317,
     318,   319
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
  "UFUNC", "'('", "')'", "':'", "','", "'{'", "'}'", "'='", "'&'", "'^'",
  "'['", "']'", "$accept", "S", "CODE", "CODE2", "MAIN_FUNC",
  "FUNC_PROC_DEC", "FUNC_PROC_DEC2", "DEF_A", "PROC_DEF", "FUNC_DEF",
  "ARGES", "ARGES2", "OUT_ARGES", "OUT_ARGES2", "INNER_ARGS", "FUNC_BLOCK",
  "EXPRASION", "REL_EXPRATION", "REL_EXPRATION2", "UNARY_EXPRATION",
  "UNARY_EXPRATION2", "LOG_EXPRATIOSN_LIST", "ASSIGNMENT", "FUNC_ACTIVE",
  "STASTMENT_LIST", "IF_STASTMENT", "STASTMENT", "RETURN_STATMENT",
  "LOOP_STATMENT", "UPDATES", "COMPUND_STATMENT", "INNER_COMPUND_STATMENT",
  "DEC_INNER_BLOCK", "NEW_DECLARE", "VAR_DECLARE", "VF", "CONST", "TYPE", YY_NULLPTR
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
     123,   125,    61,    38,    94,    91,    93
};
# endif

#define YYPACT_NINF -79

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-79)))

#define YYTABLE_NINF -47

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      44,   -25,     1,    16,   -79,   -79,    18,    71,   -79,   -79,
     -35,     6,   -35,   -79,    59,   -79,   -79,    33,   -79,    71,
     -17,    62,   143,   -79,     6,   -79,    48,   -79,   -79,    52,
      58,   233,    68,    70,    73,    78,   102,   -79,   -79,    -5,
     140,   189,   -79,   -79,   124,   134,   -79,    51,   -79,    11,
     151,   -79,   -79,   127,   -79,   -79,   -14,   151,   109,   161,
     -79,   175,   -79,   102,   -79,   233,   -79,   -79,   -79,   -79,
     -79,   132,   138,    78,    78,    78,   159,   -79,   156,   -11,
     -26,   163,   140,   103,   -79,   103,   165,   173,   167,   -79,
     136,   136,   -79,   -79,   -79,   174,   151,   -79,   -79,    -8,
      -8,    -8,   140,   140,   140,   140,    -8,    -8,   -79,   -79,
     -79,   192,   198,    88,   -79,   184,   197,   195,   -79,   233,
     -79,   196,   210,   211,   -79,   -79,   -10,   -79,   -79,   -79,
     -79,   -79,    -8,   -10,   -10,   -10,   -10,   103,   103,   103,
     103,   -10,   -10,   102,   -79,   190,    78,   230,   151,    78,
     151,   212,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   213,    78,   235,
     214,   -79,   -79,   201,   216,   151,   220,   -79,   204,   -79,
      94,   209,   -79,   219,   221,   151,   -79,   -79,   -79
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,     4,     5,     9,    12,    11,
       0,     0,     0,     1,     0,     3,     6,     0,     8,     9,
       0,     0,     0,     7,     0,    10,    21,    16,    15,     0,
       0,     0,     0,     0,     0,     0,     0,    82,    83,    85,
       0,     0,    68,    78,     0,    58,    29,    25,    26,    84,
      72,    61,    55,     0,    62,    59,     0,    73,    76,    77,
      79,    32,    13,     0,    17,     0,    91,    90,    89,    88,
      87,     0,     0,     0,     0,     0,     0,    28,     0,     0,
       0,    85,     0,    41,    84,    41,     0,     0,    32,    60,
       0,     0,    54,    71,    69,     0,    74,    75,    80,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    30,    38,
      22,    19,     0,     0,    14,     0,     0,     0,    63,     0,
      52,     0,     0,     0,    49,    39,    32,    40,    47,    46,
      48,    70,     0,    32,    32,    32,    32,    41,    41,    41,
      41,    32,    32,     0,    18,     0,     0,     0,     0,     0,
       0,     0,    53,    50,    51,    31,    35,    36,    37,    42,
      43,    44,    45,    33,    34,    20,    86,     0,     0,    57,
       0,    64,    81,     0,     0,     0,     0,    23,     0,    56,
       0,     0,    24,     0,     0,     0,    66,    67,    65
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -79,   -79,   -79,   -79,   252,   259,   242,    47,   -79,   -79,
     250,   -79,   120,   -79,   -34,   -79,   -23,   -31,    91,    -9,
     -78,    56,   -79,   -19,   207,   -79,   -50,   215,   -79,   -79,
      29,   152,   208,   -79,   -79,   217,    49,   -64
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    15,     5,    43,    18,     7,     8,     9,
      21,    28,    29,   144,    30,   114,    44,    45,   108,    46,
     109,    47,    48,    49,    50,    51,    52,    53,    54,   181,
      55,    56,    57,    58,    59,    60,    61,    72
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      92,   111,    78,    35,    77,   125,    37,    38,    39,    10,
      86,    20,    76,    40,    99,   100,    13,    26,   101,    11,
      41,    84,    84,    26,    37,    38,    81,   122,   123,   110,
      27,    83,    87,   106,   107,    12,   120,    94,   132,    14,
      23,    79,    77,    77,    77,   121,    92,    80,   -27,    77,
     115,   116,   117,    62,    19,   151,    22,   124,   -27,   159,
     160,   161,   162,    84,     1,     2,    19,    12,   133,   135,
     136,    84,    84,    87,    90,   141,   142,    11,    91,    31,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    85,
      88,     1,    17,   137,   138,   139,   140,    63,   169,    64,
     171,    86,    32,    33,    34,   146,    65,    36,     1,    17,
      37,    38,    39,    84,    73,    77,    74,    40,    77,    75,
      37,    38,    39,   167,    41,   179,   170,    40,    36,     1,
      17,    85,   183,   184,    41,   188,    26,    77,    22,   129,
     129,   102,   103,   104,   105,   174,   128,   130,   134,   134,
     134,    85,    85,    85,    85,   134,   134,    32,    33,    34,
      35,    89,    36,     1,    17,    32,    33,    34,    37,    38,
      81,   -28,    37,    38,    81,    37,    38,    39,    93,    40,
      36,   134,    40,    37,    38,    39,    82,   112,   113,    41,
      40,    99,   100,    22,    42,   101,   118,    41,   -46,    99,
     100,    22,   -46,   101,   119,   102,   103,   104,   105,    79,
     106,   107,   126,   102,   103,   104,   105,   155,   106,   107,
     127,    37,    38,    81,   156,   131,   157,   158,    40,   143,
     145,   148,   163,   164,   149,    41,    66,    67,    68,    69,
      70,    71,   150,   152,   153,   154,   166,   168,   175,   172,
     173,   176,   177,   178,   180,   182,   185,   186,    16,     6,
     187,    25,    24,   165,    96,   147,    97,     0,     0,     0,
       0,    95,     0,     0,     0,     0,    98
};

static const yytype_int16 yycheck[] =
{
      50,    65,    36,    17,    35,    83,    32,    33,    34,    34,
      41,    46,    35,    39,    24,    25,     0,    34,    28,    18,
      46,    40,    41,    34,    32,    33,    34,    53,    54,    63,
      47,    40,    41,    43,    44,    34,    47,    51,    46,    21,
      11,    46,    73,    74,    75,    79,    96,    52,    37,    80,
      73,    74,    75,    24,     7,   119,    50,    80,    47,   137,
     138,   139,   140,    82,    20,    21,    19,    34,    99,   100,
     101,    90,    91,    82,    23,   106,   107,    18,    27,    17,
      99,   100,   101,   102,   103,   104,   105,   106,   107,    40,
      41,    20,    21,   102,   103,   104,   105,    49,   148,    47,
     150,   132,    14,    15,    16,    17,    48,    19,    20,    21,
      32,    33,    34,   132,    46,   146,    46,    39,   149,    46,
      32,    33,    34,   146,    46,   175,   149,    39,    19,    20,
      21,    82,    38,    39,    46,   185,    34,   168,    50,    90,
      91,    38,    39,    40,    41,   168,    90,    91,    99,   100,
     101,   102,   103,   104,   105,   106,   107,    14,    15,    16,
      17,    37,    19,    20,    21,    14,    15,    16,    32,    33,
      34,    37,    32,    33,    34,    32,    33,    34,    51,    39,
      19,   132,    39,    32,    33,    34,    46,    55,    50,    46,
      39,    24,    25,    50,    51,    28,    37,    46,    23,    24,
      25,    50,    27,    28,    48,    38,    39,    40,    41,    46,
      43,    44,    47,    38,    39,    40,    41,   126,    43,    44,
      47,    32,    33,    34,   133,    51,   135,   136,    39,    37,
      32,    47,   141,   142,    37,    46,     3,     4,     5,     6,
       7,     8,    47,    47,    34,    34,    56,    17,    13,    37,
      37,    37,    51,    37,    34,    51,    47,    38,     6,     0,
      39,    19,    12,   143,    57,   113,    58,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    59
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    21,    58,    59,    61,    62,    64,    65,    66,
      34,    18,    34,     0,    21,    60,    61,    21,    63,    64,
      46,    67,    50,    87,    67,    63,    34,    47,    68,    69,
      71,    17,    14,    15,    16,    17,    19,    32,    33,    34,
      39,    46,    51,    62,    73,    74,    76,    78,    79,    80,
      81,    82,    83,    84,    85,    87,    88,    89,    90,    91,
      92,    93,    87,    49,    47,    48,     3,     4,     5,     6,
       7,     8,    94,    46,    46,    46,    73,    74,    71,    46,
      52,    34,    46,    76,    80,    93,    74,    76,    93,    37,
      23,    27,    83,    51,    51,    84,    81,    89,    92,    24,
      25,    28,    38,    39,    40,    41,    43,    44,    75,    77,
      71,    94,    55,    50,    72,    73,    73,    73,    37,    48,
      47,    71,    53,    54,    73,    77,    47,    47,    78,    93,
      78,    51,    46,    74,    93,    74,    74,    76,    76,    76,
      76,    74,    74,    37,    70,    32,    17,    88,    47,    37,
      47,    94,    47,    34,    34,    75,    75,    75,    75,    77,
      77,    77,    77,    75,    75,    69,    56,    73,    17,    83,
      73,    83,    37,    37,    73,    13,    37,    51,    37,    83,
      34,    86,    51,    38,    39,    47,    38,    39,    83
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    61,    62,    63,
      63,    64,    64,    65,    66,    67,    68,    68,    69,    70,
      70,    71,    71,    72,    72,    73,    73,    73,    73,    73,
      74,    74,    75,    75,    75,    75,    75,    75,    76,    76,
      76,    77,    77,    77,    77,    77,    78,    78,    78,    79,
      79,    79,    80,    80,    81,    81,    82,    82,    83,    83,
      83,    83,    83,    84,    85,    85,    86,    86,    87,    87,
      87,    87,    88,    88,    88,    89,    89,    90,    90,    91,
      91,    92,    93,    93,    93,    93,    94,    94,    94,    94,
      94,    94
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     0,     1,     3,     2,     0,
       2,     1,     1,     4,     6,     2,     1,     2,     4,     0,
       2,     1,     3,     5,     6,     1,     1,     1,     1,     1,
       2,     4,     0,     3,     3,     3,     3,     3,     2,     3,
       3,     0,     3,     3,     3,     3,     1,     3,     3,     3,
       4,     4,     3,     4,     2,     1,     7,     5,     1,     1,
       2,     1,     1,     3,     5,     9,     3,     3,     2,     3,
       4,     3,     1,     1,     2,     2,     1,     1,     1,     1,
       2,     5,     1,     1,     1,     1,     4,     1,     1,     1,
       1,     1
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
#line 65 "yacc.y" /* yacc.c:1652  */
    {
        (yyval.Node)=mknode("CODE",(yyvsp[0].Node),NULL);
        printtree((yyval.Node),0);
        printf("ok\n");
        }
#line 1465 "y.tab.c" /* yacc.c:1652  */
    break;

  case 3:
#line 72 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1471 "y.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 77 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("",NULL,NULL);}
#line 1477 "y.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 82 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("PROC MAIN",(yyvsp[0].Node),NULL);}
#line 1483 "y.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 90 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("",NULL,NULL);}
#line 1489 "y.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 91 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1495 "y.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 102 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(strcat(strdup("PROC "),(yyvsp[-2].String)),(yyvsp[0].Node),NULL);}
#line 1501 "y.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 106 "yacc.y" /* yacc.c:1652  */
    {
											(yyval.Node)=mknode(strcat(strdup("RET "),(yyvsp[-1].String)),NULL,NULL);
											(yyvsp[-3].Node)=mknode("",(yyvsp[-3].Node),(yyval.Node));
											(yyval.Node)=mknode(strcat(strdup("FUNC "),(yyvsp[-4].String)),(yyvsp[-3].Node),(yyvsp[0].Node));
											}
#line 1511 "y.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 113 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=(yyvsp[0].Node);}
#line 1517 "y.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 117 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(strdup("empty arguments"),NULL,NULL);}
#line 1523 "y.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 118 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(strdup("ARGS "),(yyvsp[-1].Node),NULL);}
#line 1529 "y.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 122 "yacc.y" /* yacc.c:1652  */
    {
						strcat((yyvsp[-1].String),": ");
						strcat((yyvsp[-1].String),(yyvsp[-3].String));
						(yyval.Node)=mknode((yyvsp[-1].String),NULL,NULL);
						}
#line 1539 "y.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 130 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("",NULL,NULL);}
#line 1545 "y.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 131 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(":",NULL,NULL);}
#line 1551 "y.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 137 "yacc.y" /* yacc.c:1652  */
    {
		strcat((yyvsp[-2].String)," ");
		strcat((yyvsp[-2].String),(yyvsp[0].String));
		}
#line 1560 "y.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 145 "yacc.y" /* yacc.c:1652  */
    {
								(yyval.Node)=mknode("",NULL,mknode(strdup("RETURN "),(yyvsp[-2].Node),NULL));}
#line 1567 "y.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 147 "yacc.y" /* yacc.c:1652  */
    {
															(yyval.Node)=mknode("",(yyvsp[-4].Node),mknode(strdup("RETURN "),(yyvsp[-2].Node),NULL));}
#line 1574 "y.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 162 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("()",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1580 "y.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 163 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("()",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1586 "y.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 167 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("",NULL,NULL);}
#line 1592 "y.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 168 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(">=",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1598 "y.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 169 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(">=",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1604 "y.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 170 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(">=",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1610 "y.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 171 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("<=",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1616 "y.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 172 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("==",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1622 "y.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 177 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("minus",(yyvsp[-1].Node),NULL);}
#line 1628 "y.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 178 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=(yyvsp[-1].Node);}
#line 1634 "y.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 182 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("+",NULL,NULL);}
#line 1640 "y.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 183 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("+",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1646 "y.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 184 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("-",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1652 "y.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 185 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("*",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1658 "y.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 186 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("/",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1664 "y.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 191 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("&&",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1670 "y.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 192 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("||",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1676 "y.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 198 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(strcat((yyvsp[-2].String)," ="),(yyvsp[0].Node),NULL);}
#line 1682 "y.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 199 "yacc.y" /* yacc.c:1652  */
    {
        strcat((yyvsp[-3].String)," = & ");
        strcat((yyvsp[-3].String),(yyvsp[0].String));
        (yyval.Node)=mknode((yyvsp[-3].String),NULL,NULL);}
#line 1691 "y.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 203 "yacc.y" /* yacc.c:1652  */
    {
        strcat((yyvsp[-3].String)," = ^ ");
        strcat((yyvsp[-3].String),(yyvsp[0].String));
        (yyval.Node)=mknode((yyvsp[-3].String),NULL,NULL);}
#line 1700 "y.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 210 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(strcat((yyvsp[-2].String)," ACTIVE:"),mknode(strdup("empty arguments"),NULL,NULL),NULL);}
#line 1706 "y.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 211 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(strcat((yyvsp[-3].String)," ACTIVE:"),mknode(strdup("ARGS "),mknode((yyvsp[-1].String),NULL,NULL),NULL),NULL);
							}
#line 1713 "y.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 217 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("",(yyvsp[-1].Node),(yyvsp[0].Node));moveDown((yyvsp[0].Node));}
#line 1719 "y.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 223 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("IF_ELSE",mknode("EXPRASION",(yyvsp[-4].Node),(yyvsp[-2].Node)),mknode("ELSE_STATEMENT",(yyvsp[0].Node),NULL));
																												//moveDown($$->right);
																												}
#line 1727 "y.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 226 "yacc.y" /* yacc.c:1652  */
    {
        
        (yyval.Node)=mknode("IF",(yyvsp[-2].Node),(yyvsp[0].Node));}
#line 1735 "y.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 240 "yacc.y" /* yacc.c:1652  */
    {
        (yyval.Node)=mknode("RETURN STATMENT",(yyvsp[-1].Node),NULL);
        }
#line 1743 "y.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 246 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("WHILE LOOP",mknode("EXPRESSION",(yyvsp[-2].Node),NULL),(yyvsp[0].Node));}
#line 1749 "y.tab.c" /* yacc.c:1652  */
    break;

  case 65:
#line 249 "yacc.y" /* yacc.c:1652  */
    {	
		(yyvsp[-6].Node)=mknode("",(yyvsp[-6].Node),NULL);
        (yyvsp[-4].Node)=mknode("",(yyvsp[-4].Node),(yyvsp[-6].Node));
		(yyvsp[-2].Node)=mknode("",(yyvsp[-2].Node),(yyvsp[-4].Node));
		(yyval.Node)=mknode("FOR LOOP",mknode("EXPRESSION",(yyvsp[-2].Node),NULL),(yyvsp[0].Node));}
#line 1759 "y.tab.c" /* yacc.c:1652  */
    break;

  case 66:
#line 257 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(strcat((yyvsp[-2].String),strdup("++")),NULL,NULL);}
#line 1765 "y.tab.c" /* yacc.c:1652  */
    break;

  case 67:
#line 258 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode(strcat((yyvsp[-2].String),strdup("--")),NULL,NULL);}
#line 1771 "y.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 263 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("empty statments",NULL,NULL);}
#line 1777 "y.tab.c" /* yacc.c:1652  */
    break;

  case 69:
#line 264 "yacc.y" /* yacc.c:1652  */
    { (yyval.Node)=(yyvsp[-1].Node); }
#line 1783 "y.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 265 "yacc.y" /* yacc.c:1652  */
    { (yyval.Node)=(yyvsp[-2].Node); }
#line 1789 "y.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 266 "yacc.y" /* yacc.c:1652  */
    { (yyval.Node)=(yyvsp[-1].Node); }
#line 1795 "y.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 270 "yacc.y" /* yacc.c:1652  */
    { 
        (yyval.Node)=mknode("BODY",NULL,(yyvsp[0].Node));}
#line 1802 "y.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 272 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("BODY",(yyvsp[0].Node),NULL);}
#line 1808 "y.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 273 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("BODY",(yyvsp[-1].Node),(yyvsp[0].Node));
				 }
#line 1815 "y.tab.c" /* yacc.c:1652  */
    break;

  case 75:
#line 281 "yacc.y" /* yacc.c:1652  */
    {mknode("",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1821 "y.tab.c" /* yacc.c:1652  */
    break;

  case 80:
#line 292 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode("",(yyvsp[-1].Node),(yyvsp[0].Node));}
#line 1827 "y.tab.c" /* yacc.c:1652  */
    break;

  case 81:
#line 296 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode((yyvsp[-1].String),mknode((yyvsp[-3].String),NULL,NULL),NULL);}
#line 1833 "y.tab.c" /* yacc.c:1652  */
    break;

  case 82:
#line 305 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode((yyvsp[0].String),NULL,NULL);}
#line 1839 "y.tab.c" /* yacc.c:1652  */
    break;

  case 83:
#line 306 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode((yyvsp[0].String),NULL,NULL);}
#line 1845 "y.tab.c" /* yacc.c:1652  */
    break;

  case 84:
#line 307 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=(yyvsp[0].Node);}
#line 1851 "y.tab.c" /* yacc.c:1652  */
    break;

  case 85:
#line 308 "yacc.y" /* yacc.c:1652  */
    {(yyval.Node)=mknode((yyvsp[0].String),NULL,NULL);}
#line 1857 "y.tab.c" /* yacc.c:1652  */
    break;


#line 1861 "y.tab.c" /* yacc.c:1652  */
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
#line 321 "yacc.y" /* yacc.c:1918  */


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
node *mkleaf(char *token)
{
node * newnode=(node*)malloc(sizeof(node));
char *newstr=(char*)malloc(sizeof(token) + 1);
strcpy(newstr,token);
newnode->left=NULL;
newnode->right=NULL;
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
