/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
#line 87 "yacc.y" /* yacc.c:1921  */

	char * String;
	struct node * Node;

#line 153 "y.tab.h" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
