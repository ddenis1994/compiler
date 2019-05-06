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


typedef struct symbolNode{
    int isProc; //0 if primitive symbol, 1 if is procedure
	char* id;
	char* type;
	char* data;
	int scopeID;
	struct treeNode *params;
	struct symbolNode *next;
} symbolNode;

typedef struct scopeNode{
	char* scopeName;
	int scopeNum;
	int scopeLevel;
	symbolNode *symbolTable;
	struct scopeNode *next;
} scopeNode;

symbolNode* head = NULL;
scopeNode* topStack = NULL;
int SCOPE_NUM=0;

int startSemantic(node * root);
node *mknode(char *token, node *left, node *right);
node *mkleaf(char *token);



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
%token TRUE FALSE
%token RETURN MAIN
%token <String> VAR FUNC PROC
%token NULL_VALUE 
%token AND_OP GE_OP SE_OP NE_OP OR_OP EQL_OP
%token <String> BOOL_VALUE CHAR_VALUE STRING_VALUE INT_NUM F_NUM
%token <String> ID 
%type <String> TYPE 
%type <Node> INNER_ARGS 
%type <String> CONST 
%type <Node> OUT_ARGES ARGES FUNC_DEF FUNC_BLOCK INNER_COMPUND_STATMENT EXPRASION 
%type <Node> FUNC_ACTIVE  COMPUND_STATMENT
%type <Node> STASTMENT_LIST DEC_INNER_BLOCK
%type<Node> STASTMENT IF_STASTMENT LOOP_STATMENT
%type<Node> UPDATES VF VAR_DECLARE FUNC_PROC_DEC DEF_A
%type<Node> CODE PROC_DEF NEW_DECLARE   MAIN
%type <Node> MAIN_FUNC  
%type<Node> S RETURN_STATMENT CODE2 ARGES2 OUT_ARGES2
%type<Node> FUNC_PROC_DEC2 COMPUND_STATMENT_PROC FUNC_ACTIVE_INNER_ARGES
%nonassoc IFX
%nonassoc test
%nonassoc ELSE
%right RETURN  
%right ';'
%left '+' '-'
%left '*' '/'

%nonassoc OR_OP AND_OP '>' '<' GE_OP SE_OP EQL_OP
%right '!' '^' '&' 
%right UMINUS
%left UFUNC


%%
S: 
	CODE {
        $$=mknode("CODE",$1,NULL);
        printtree($$,0);
		startSemantic($$);
        printf("ok\n");
        }
	;
CODE:
	FUNC_PROC_DEC  CODE2 {$$=mknode("",$1,$2);}
	|MAIN_FUNC 
	;
	
CODE2:
	{$$=mknode("",NULL,NULL);}
	|MAIN_FUNC
	;

MAIN_FUNC:
	PROC MAIN COMPUND_STATMENT{$$=mknode("PROC MAIN",$3,NULL);}
	;

FUNC_PROC_DEC:
	DEF_A FUNC_PROC_DEC2 {$$=mknode("",$1,$2);}
	;

FUNC_PROC_DEC2:
	{$$=mknode("",NULL,NULL);}
	|DEF_A FUNC_PROC_DEC2 {$$=mknode("",$1,$2);}
	;

DEF_A:
	FUNC_DEF 
	|PROC_DEF
	;



PROC_DEF:
	PROC ID ARGES COMPUND_STATMENT_PROC  {$$=mknode(strcat(strdup("PROC "),$2),$4,NULL);}
	;

FUNC_DEF:
	FUNC ID  ARGES  RETURN TYPE FUNC_BLOCK {
											$$=mknode(strcat(strdup("RET "),$5),NULL,NULL);
											$3=mknode("",$3,$$);
											$$=mknode(strcat(strdup("FUNC "),$2),$3,$6);
											}
	;

ARGES: '(' ARGES2 {$$=$2;}
	;

ARGES2:
	')' {$$=mknode("",NULL,NULL);}
	| OUT_ARGES ')' {$$=mknode(strdup("ARGS "),$1,NULL);}
	;

OUT_ARGES:
	INNER_ARGS ':' TYPE OUT_ARGES2{
						$$=mknode($3,$1,NULL);
						}
	;

OUT_ARGES2:
	{$$=mknode("",NULL,NULL);}
	| ';' OUT_ARGES {$$=mknode(":",NULL,NULL);}
	;


INNER_ARGS:
	ID {$$=mkleaf($1);}
	|ID ',' INNER_ARGS {
		$$=mknode("",mkleaf($1),$3);
		}
	;


FUNC_BLOCK:
	'{' RETURN EXPRASION ';' '}'  {
								$$=mknode("",NULL,mknode(strdup("RETURN "),$3,NULL));}
	|'{' INNER_COMPUND_STATMENT RETURN EXPRASION ';' '}'  {
															$$=mknode("BLOCK",$2,mknode(strdup("RETURN "),$4,NULL));}
	;




EXPRASION:
	CONST {$$=mkleaf($1);}
	|'(' EXPRASION ')'  {$$=$2;}
	|TRUE {$$=mkleaf("TRUE");}
	|FALSE {$$=mkleaf("FALSE");}
	|ID {$$=mkleaf($1);}
	|'^' EXPRASION {$$=$2;}
	| '&' EXPRASION {$$=$2;}
	|'-' EXPRASION %prec UMINUS {$$=$2;} 
	|'!' EXPRASION {$$=$2;}
	|ID '=' EXPRASION {$$=mknode("=",mkleaf($1),$3);}
	|EXPRASION NE_OP EXPRASION  {$$=mknode("!=",$1,$3);}
	|EXPRASION AND_OP EXPRASION  {$$=mknode("&&",$1,$3);}
	|EXPRASION OR_OP EXPRASION  {$$=mknode("||",$1,$3);}
	|EXPRASION '+' EXPRASION  {$$=mknode("+",$1,$3);printf("was");}
	|EXPRASION '-' EXPRASION  {$$=mknode("-",$1,$3);}
	|EXPRASION '/' EXPRASION  {$$=mknode("/",$1,$3);}
	|EXPRASION '*' EXPRASION  {$$=mknode("*",$1,$3);}
	|EXPRASION EQL_OP EXPRASION  {$$=mknode("==",$1,$3);}
	|EXPRASION GE_OP EXPRASION  {$$=mknode(">=",$1,$3);}
	|EXPRASION SE_OP EXPRASION  {$$=mknode("<=",$1,$3);}
	|EXPRASION '>' EXPRASION  {$$=mknode(">",$1,$3);}
	|EXPRASION '<' EXPRASION  {$$=mknode("<",$1,$3);}
	|FUNC_ACTIVE

	;


FUNC_ACTIVE:
	ID '(' ')' {$$=mknode(strcat($1," ACTIVE:"),mknode(strdup("empty arguments"),NULL,NULL),NULL);}
	|ID '(' FUNC_ACTIVE_INNER_ARGES ')' {$$=mknode(strcat($1," ACTIVE:"),mknode(strdup("ARGS "),$3,NULL),NULL);
							}
	;

FUNC_ACTIVE_INNER_ARGES:
	ID {$$=mkleaf($1);}
	|CONST  {$$=mkleaf($1);}
	|ID ',' FUNC_ACTIVE_INNER_ARGES {$$=mknode("",mkleaf($1),$3);}
	|CONST ',' FUNC_ACTIVE_INNER_ARGES {$$=mknode("",mkleaf($1),$3);}
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
	COMPUND_STATMENT
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

COMPUND_STATMENT_PROC:
	'{' '}' {$$=mknode("empty statments",NULL,NULL);}
	|'{' INNER_COMPUND_STATMENT '}' { $$=$2; }
	;

INNER_COMPUND_STATMENT:
	STASTMENT_LIST { $$=mknode("BODY",NULL,$1);}
	|DEC_INNER_BLOCK {/* hare we start */$$=mknode("BODY",$1,NULL);}
	|DEC_INNER_BLOCK  STASTMENT_LIST {$$=mknode("BODY",$1,$2);}
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
	VAR INNER_ARGS ':' TYPE  ';' {$$=mknode($4,$2,NULL);}
	;






CONST:
	INT_NUM 
	|F_NUM 
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
int startSemantic(node * root){
	if(strcmp (root->token ,"CODE" ))
		return 1;

	
	printf("got tree %s dsa \n",root->token);
		return 0;
	
	
}