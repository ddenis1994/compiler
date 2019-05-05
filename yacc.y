%{
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
%}
%union {
	char * String;
	struct node * Node;
}
%start S
%token <String> CHAR REAL FLOAT INT BOOL STRING
%token <String> CHAR_POINTER REAL_POINTER FLOAT_POINTER INT_POINTER 
%token ELSE IF
%token FOR WHILE
%token RETURN MAIN
%token <String> VAR FUNC PROC
%token NULL_VALUE 
%token AND_OP GE_OP SE_OP NE_OP OR_OP EQL_OP
%token <String> BOOL_VALUE CHAR_VALUE STRING_VALUE INT_NUM F_NUM
%token <String> ID 
%type <String> TYPE 
%type <String> INNER_ARGS 
%type <Node> OUT_ARGES ARGES FUNC_DEF FUNC_BLOCK INNER_COMPUND_STATMENT EXPRASION 
%type <Node> CONST FUNC_ACTIVE REL_EXPRATION ASSIGNMENT COMPUND_STATMENT
%type <Node> STASTMENT_LIST DEC_INNER_BLOCK
%type<Node> STASTMENT IF_STASTMENT LOOP_STATMENT
%type<Node> UPDATES VF VAR_DECLARE FUNC_PROC_DEC DEF_A
%type<Node> CODE PROC_DEF NEW_DECLARE LOG_EXPRATIOSN_LIST UNARY_EXPRATION MAIN
%type <Node> MAIN_FUNC
%type<Node> S RETURN_STATMENT
%nonassoc IFX
%nonassoc test
%nonassoc ELSE

%right RETURN  
%right ';'
%left '+' '-' OR_OP AND_OP
%left '*' '/'
%left UMINUS
%left '>' '<' GE_OP SE_OP EQL_OP
%left UFUNC


%%
S: 
	CODE {
        $$=mknode("CODE",$1,NULL);
        printtree($$,0);
        printf("ok\n");
        }
	;
CODE:
	FUNC_PROC_DEC  
	|FUNC_PROC_DEC MAIN_FUNC {$$=mknode("",$1,$2);}
	|MAIN_FUNC 
	;
MAIN_FUNC:
	PROC MAIN COMPUND_STATMENT{$$=mknode("PROC MAIN",$3,NULL);}
	;

FUNC_PROC_DEC:
	DEF_A
	|FUNC_PROC_DEC DEF_A {$$=mknode("",$1,$2);}
	;

DEF_A:
	FUNC_DEF 
	|PROC_DEF
	;



PROC_DEF:
	PROC ID ARGES COMPUND_STATMENT  {$$=mknode(strcat(strdup("PROC "),$2),$4,NULL);}
	;

FUNC_DEF:
	FUNC ID  ARGES  RETURN TYPE FUNC_BLOCK {
											$$=mknode(strcat(strdup("RET "),$5),NULL,NULL);
											$3=mknode("",$3,$$);
											$$=mknode(strcat(strdup("FUNC "),$2),$3,$6);
											}
	;

ARGES: '(' ')' {
				$$=mknode(strdup("empty arguments"),NULL,NULL);
				}
	| '(' OUT_ARGES ')' {$$=mknode(strdup("ARGS "),$2,NULL);}
	;

OUT_ARGES:
	INNER_ARGS ':' TYPE {
						strcat($3,": ");
						strcat($3,$1);
						$$=mknode($3,NULL,NULL);
						}
	|INNER_ARGS ':' TYPE ';' OUT_ARGES {
						strcat($3,": ");
						strcat($3,$1);
						$$=mknode($3,$5,NULL);
						moveDown($5);
						}
	;

INNER_ARGS: ID 
	|ID ',' INNER_ARGS {
		strcat($1," ");
		strcat($1,$3);
		}
	;


FUNC_BLOCK:
	'{' RETURN EXPRASION ';' '}'  {
								$$=mknode("",NULL,mknode(strdup("RETURN "),$3,NULL));}
	|'{' INNER_COMPUND_STATMENT RETURN EXPRASION ';' '}'  {
															$$=mknode("",$2,mknode(strdup("RETURN "),$4,NULL));}
	;


REL_EXPRATION:
	CONST 
	|REL_EXPRATION '>' REL_EXPRATION {$$=mknode(">",$1,$3);}
	|REL_EXPRATION '<' REL_EXPRATION {$$=mknode("<",$1,$3);}
	|REL_EXPRATION GE_OP REL_EXPRATION {$$=mknode(">=",$1,$3);}
	|REL_EXPRATION SE_OP REL_EXPRATION {$$=mknode("<=",$1,$3);}
	| REL_EXPRATION EQL_OP REL_EXPRATION {$$=mknode("==",$1,$3);}
	| '(' REL_EXPRATION ')' {$$=$2;}
	;




EXPRASION:
	LOG_EXPRATIOSN_LIST 
	|ASSIGNMENT 
	|FUNC_ACTIVE 
	|REL_EXPRATION 
	|UNARY_EXPRATION
	;
ASSIGNMENT:
	ID '=' EXPRASION {$$=mknode(strcat($1," ="),$3,NULL);}
    |ID '=' '&' ID {
        strcat($1," = & ");
        strcat($1,$4);
        $$=mknode($1,NULL,NULL);}
	;

FUNC_ACTIVE:
	ID '(' ')' {$$=mknode(strcat($1," ACTIVE:"),mknode(strdup("empty arguments"),NULL,NULL),NULL);}
	|ID '(' INNER_ARGS ')' {$$=mknode(strcat($1," ACTIVE:"),mknode(strdup("ARGS "),mknode($3,NULL,NULL),NULL),NULL);
							moveDown($$->left->left);
							}
	;


STASTMENT_LIST:
	STASTMENT_LIST STASTMENT {$$=mknode("",$1,$2);moveDown($2);}
	|STASTMENT 
	;


IF_STASTMENT:
	IF '(' EXPRASION ')' STASTMENT ELSE STASTMENT {$$=mknode("IF_ELSE",mknode("EXPRASION",$3,$5),mknode("ELSE_STATEMENT",$7,NULL));
																												//moveDown($$->right);
																												}
	|IF '(' EXPRASION ')'  STASTMENT %prec IFX {
        
        $$=mknode("IF",$3,$5);}
	;

STASTMENT:
    REL_EXPRATION
	|COMPUND_STATMENT
	|EXPRASION ';' 
	|IF_STASTMENT
	|LOOP_STATMENT
    
	;
RETURN_STATMENT:
    RETURN EXPRASION ';' {
        $$=mknode("RETURN STATMENT",$2,NULL);
        }
    ;

LOOP_STATMENT:
	WHILE '(' EXPRASION ')' STASTMENT {$$=mknode("WHILE LOOP",mknode("EXPRESSION",$3,NULL),$5);}
	|FOR '(' EXPRASION ';' EXPRASION ';' UPDATES ')' STASTMENT
		
	{	
		$3=mknode("",$3,NULL);
        $5=mknode("",$5,$3);
		$7=mknode("",$7,$5);
		$$=mknode("FOR LOOP",mknode("EXPRESSION",$7,NULL),$9);}
	;

UPDATES:
	ID '+' '+' {$$=mknode(strcat($1,strdup("++")),NULL,NULL);}
	|ID '-' '-' {$$=mknode(strcat($1,strdup("--")),NULL,NULL);}
	;


COMPUND_STATMENT:
	'{' '}' {$$=mknode("empty statments",NULL,NULL);}
    |'{' INNER_COMPUND_STATMENT '}' { $$=$2; }
	|'{' INNER_COMPUND_STATMENT RETURN_STATMENT '}' { $$=$2; }
    |'{'  RETURN_STATMENT '}' { $$=$2; }
	;

INNER_COMPUND_STATMENT:
	STASTMENT_LIST { 
        $$=mknode("BODY",NULL,$1);}
	|DEC_INNER_BLOCK {$$=mknode("BODY",$1,NULL);}
	|DEC_INNER_BLOCK  STASTMENT_LIST {$$=mknode("BODY",$1,$2);
				 }
	;




DEC_INNER_BLOCK:
	NEW_DECLARE DEC_INNER_BLOCK {mknode("",$1,$2);}
	|NEW_DECLARE
	;

NEW_DECLARE:
	VAR_DECLARE
	|FUNC_PROC_DEC
	;

VAR_DECLARE:
	 VF 
	|VAR_DECLARE VF {$$=mknode("",$1,$2);}
	;

VF: 
	VAR INNER_ARGS ':' TYPE  ';' {$$=mknode($4,mknode($2,NULL,NULL),NULL);}
	;

LOG_EXPRATIOSN_LIST:
	CONST 
	|LOG_EXPRATIOSN_LIST AND_OP LOG_EXPRATIOSN_LIST {$$=mknode("&&",$1,$3);}
	|LOG_EXPRATIOSN_LIST OR_OP  LOG_EXPRATIOSN_LIST {$$=mknode("||",$1,$3);}
	;



UNARY_EXPRATION:
	CONST 
	|UNARY_EXPRATION '+' UNARY_EXPRATION {$$=mknode("+",$1,$3);}
	|UNARY_EXPRATION '-' UNARY_EXPRATION {$$=mknode("-",$1,$3);}
	|UNARY_EXPRATION '*' UNARY_EXPRATION {$$=mknode("*",$1,$3);}
	|UNARY_EXPRATION '/' UNARY_EXPRATION {$$=mknode("/",$1,$3);}
	|'-' UNARY_EXPRATION {$$=mknode("minus",$2,NULL);}
	|'(' UNARY_EXPRATION ')'  {$$=$2;}
	;

CONST:
	INT_NUM {$$=mknode($1,NULL,NULL);}
	|F_NUM {$$=mknode($1,NULL,NULL);}
	|FUNC_ACTIVE {$$=$1;}
	|ID {$$=mknode($1,NULL,NULL);}
	;



TYPE:	
	STRING '[' INT_NUM ']'
	|BOOL 
	|INT 
	|FLOAT 
	|REAL 
	|CHAR 
	;
%%

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
