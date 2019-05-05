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
#line 23 "yacc.y" /* yacc.c:1921  */

	char * String;
	struct node * Node;

#line 139 "y.tab.h" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
