%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
extern void yyerror(const char *);
static void comment(void);
%}

%%
("/%"[0-9a-zA-Z]*"%/")                    { }
"char\*"                  {yylval.String=strdup(yytext); return (CHAR_POINER);}
"real\*"                  {yylval.String=strdup(yytext); return(REAL_POINER);}
"int\*"                   {yylval.String=strdup(yytext); return(INT_POINER);}
"char"                  {yylval.String=strdup(yytext); return (CHAR);}
"real"                  {yylval.String=strdup(yytext); return(REAL);}
"else"                  {yylval.String=strdup(yytext); return(ELSE);}
"for"                   { return(FOR);}
"if"                    { return(IF);}
"int"                   {yylval.String=strdup(yytext); return(INT);}
"return"                { return(RETURN);}
"while"                 { return(WHILE); }
"bool"                  {yylval.String=strdup(yytext); return(BOOL); }
"string"                {yylval.String=strdup(yytext); return(STRING); }
"true"                  { return(TRUE); }
"false"                { return(FALSE); }
"var"                   { return(VAR); }
"func"                  { yylval.String=strdup(yytext); return(FUNC); }
"proc"                  { return(PROC); }
"null"                  { return(NULL_VALUE); }
"&&"                    { return(AND_OP); }
"/"                     { return '/'; }
"=="                    { return (EQL_OP); }
">="                    { return (GE_OP); }
"<="                    { return (SE_OP); }
"!="                    { return (NE_OP); }
"||"                    { return (OR_OP); }
"|"                     { return '|'; }
"="                     { return '='; }
">"                     { return '>'; }
"<"                     { return '<'; }
"-"                     { return '-'; }
"!"                     { return '!'; }
"+"                     { return '+'; }
"*"                     { return '*'; }
"&"                     { return '&'; }
"^"                     { return '^'; }
";"                     { return ';'; }
":"                     { return ':'; }
","                     { return ','; }
"|"                     { return '|'; }
"{"                     { return '{'; }
"}"                     { return '}'; }
"("                     { return '('; }
")"                     { return ')'; }
"["                     { return '['; }
"]"                     { return ']'; }
\'.\'                   {yylval.String=strdup(yytext); return(CHAR_VALUE); }
\"[0-9a-zA-Z]*\"        {yylval.String=strdup(yytext); return(STRING_VALUE); }
(0|[1-9][0-9]*)         {yylval.String=strdup(yytext); return(INT_NUM); }
0[xX][a-fA-F0-9]+       {yylval.String=strdup(yytext); return (HEX_NUM); }
[0-9]*"."([Ee]?[+-]?[0-9]+)? {yylval.String=strdup(yytext); return (R_NUM); }
[a-zA-Z][a-zA-Z0-9_]*   {yylval.String=strdup(yytext); return(ID);}

[ \t\v\n\f]             { ; }
%%
int yywrap(void)
{
    return 1;
}

void comment(void)
{
    int c;
    c=input();
    while(c!=0){
    
        if(c=='%'){
            while((c=input())!='%')
            ;
            if (c=='/')
                return;
            if(c==0)
                break;

        }
        c=input();
        }
    yyerror("wrong comment");
}