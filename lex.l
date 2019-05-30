%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
extern void yyerror(const char *);
int comment();
char * cut_first (char * string);


%}

%%
"/%"                { comment();}
"char\*"                  {yylval.String=strdup(yytext); return (CHAR_POINER);}
"real\*"                  {yylval.String=strdup(yytext); return(REAL_POINER);}
"int\*"                   {yylval.String=strdup(yytext); return(INT_POINER);}
"char"                  {yylval.String=strdup(yytext); return (CHAR);}
"null"                  {yylval.String=strdup(yytext); return (NULLA);}
"real"                  {yylval.String=strdup(yytext); return(REAL);}
"else"                  {yylval.String=strdup(yytext); return(ELSE);}
"for"                   { return(FOR);}
"if"                    { return(IF);}
"int"                   {yylval.String=strdup(yytext); return(INT);}
"return"                { return(RETURN);}
"while"                 { return(WHILE); }
"bool"                  {yylval.String=strdup(yytext); return(BOOL); }
"string"                {yylval.String=strdup(yytext); return(STRING); }
"true"                  {yylval.String=strdup(yytext); return(BOOL_VAL); }
"false"                {yylval.String=strdup(yytext); return(BOOL_VAL); }
"var"                   { return(VAR); }
"func"                  { yylval.String=strdup(yytext); return(FUNC); }
"proc"                  { return(PROC); }
"Main"                  { yylval.String=strdup(yytext); return(MAIN); }
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
"{"                     { return '{'; }
"}"                     { return '}'; }
"("                     { return '('; }
")"                     { return ')'; }
"["                     { return '['; }
"]"                     { return ']'; }
\'.\'              {yylval.String=strdup(yytext); return CHAR_VALUE; }
\"[0-9a-zA-Z]*\"        {yylval.String=strdup(yytext); return(STRING_VALUE); }
(0|[1-9][0-9]*)         {yylval.String=strdup(yytext); return(INT_NUM); }
0[xX][a-fA-F0-9]+       {yylval.String=strdup(yytext); return (HEX_NUM); }
[0-9]*"."([Ee]?[+-]?[0-9]+)? {yylval.String=strdup(yytext); return (R_NUM); }
[\&\^][a-zA-Z][a-zA-Z0-9_]*=   {yylval.String=strdup(cut_first(yytext)); return(ADDR_ID);}
[a-zA-Z][a-zA-Z0-9_]*   {yylval.String=strdup(yytext); return(ID);}

[ \t\v\n\f]             { ; }
%%
int yywrap(void)
{
    return 1;
}

int comment()
{
    char  c ,c1;
    loop:
    while((c=input())!= '%' && c !=0);
    \
    
    if(c=='%' && (c1=input())=='/'){
        return 0;
    }
    else
       return (comment());
}

char * cut_first (char * string){
    int i;
    for(i=0;i<strlen(string)+1;i++){
        string[i]=string[i+1];
    }
    return string;
}