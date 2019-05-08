%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define SYMBALTABLESIZE 100000
typedef struct node
{
char *token;
struct node *left;
struct node *right;
} node;
typedef struct deciptopn{
	char* id;
	int isProc_func; 
	char* type;
	char* data;
	char * return_value;
	int frameBelong;
	struct treeNode * params;
	struct deciptopn * next;
} deciptopn;

typedef struct symbolNode{
	char* id;
	char* data;
	struct deciptopn * sing;
} symbolNode;



typedef struct frame{
	int frameID;
	struct frame *next;
} frame;

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
	struct symbolNode * symbals;
} symblaTable;

int deep;
struct symblaTable * hashTableSymbel;
struct Stack * frameStack;

struct frame * pop() ;
void push(struct frame * item) ;
int isEmpty();
int isFull();
int createStack() ;
int creath_hs();
long long compute_hash(char *  s);
int insert(deciptopn * symbel);
int CrearhSymbalFrame(node * root);
struct frame * creathFrame();
int startSemantic(node * root);
node *mknode(char *token, node *left, node *right);
node *mkleaf(char *token);
node * creathFuncDec(char * id,node * args,char * typeOfReturn,node * block);



void printtree(node *tree,int space);
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
%type<Node> S RETURN_STATMENT ARGES2 OUT_ARGES2
%type<Node> COMPUND_STATMENT_PROC FUNC_ACTIVE_INNER_ARGES
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
        $$=mknode("BLOCK",$1,NULL);
		startSemantic($$);
        printf("ok\n");
        }
	;
CODE:
	FUNC_PROC_DEC {$$=mknode("DEC",NULL,$1);}
	|FUNC_PROC_DEC MAIN_FUNC {$$=mknode("DEC&MAIN",$1,$2);}
	|MAIN_FUNC {$$=mknode("MAIN",NULL,$1);}
	;
	

MAIN_FUNC:
	PROC MAIN COMPUND_STATMENT{$$=mknode("PROCMAIN",$3,NULL);}
	;

FUNC_PROC_DEC:
	DEF_A {$$=mknode("",$1,NULL);}
	|DEF_A FUNC_PROC_DEC {$$=mknode("",$1,$2);}
	;

DEF_A:
	FUNC_DEF {$$=mknode("NEW_FUNC",$1,NULL);}
	|PROC_DEF {$$=mknode("NEW_PROC",$1,NULL);}
	;



PROC_DEF:
	PROC ID ARGES COMPUND_STATMENT_PROC  {$$=mknode(strcat(strdup("PROC "),$2),$4,NULL);}
	;

FUNC_DEF:
	FUNC ID  ARGES  RETURN TYPE FUNC_BLOCK {$$=creathFuncDec($2,$3,$5,$6);
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
	'{' RETURN EXPRASION ';' '}'  {$$=mknode("BLOCK",NULL,mknode(strdup("RETURN BLOCK"),$3,NULL));}
	|'{' INNER_COMPUND_STATMENT RETURN EXPRASION ';' '}'  {
															$$=mknode("BLOCK",$2,mknode(strdup("RETURN BLOCK"),$4,NULL));}
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
	STASTMENT_LIST STASTMENT {$$=mknode("",$1,$2);}
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
	'{' '}' {$$=mknode("BLOCK",NULL,NULL);}
    |'{' INNER_COMPUND_STATMENT '}' { $$=mknode("BLOCK",NULL,$2); }
	|'{' INNER_COMPUND_STATMENT RETURN_STATMENT '}' { $$=mknode("BLOCK",$3,$2); }
    |'{'  RETURN_STATMENT '}' { $$=mknode("BLOCK",$2,NULL); }
	;

COMPUND_STATMENT_PROC:
	'{' '}' {$$=mknode("BLOCK",NULL,NULL);}
	|'{' INNER_COMPUND_STATMENT '}' {$$=mknode("BLOCK",NULL,$2);}
	;

INNER_COMPUND_STATMENT:
	STASTMENT_LIST { $$=mknode("",NULL,$1);}
	|DEC_INNER_BLOCK {$$=mknode("",$1,NULL);}
	|DEC_INNER_BLOCK  STASTMENT_LIST {$$=mknode("",$1,$2);}
	;


DEC_INNER_BLOCK:
	NEW_DECLARE DEC_INNER_BLOCK {mknode("DECLARE",$1,$2);}
	|NEW_DECLARE {mknode("DECLARE",$1,NULL);}
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
	deep=0;
	push(creathFrame());
	CrearhSymbalFrame(root->left);

	free(hashTableSymbel->symbals);
	free(hashTableSymbel);
	return 0;
	
	
}

struct frame *  creathFrame(){
	struct frame * temp =(struct frame *)malloc(sizeof(struct frame));
	temp->frameID++;
	temp->next=NULL;
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



int insert(deciptopn * symbel){
	struct deciptopn * temp_symbal;
	long sizeHT = SYMBALTABLESIZE;
	//creath first hush key for the string
	long long id =compute_hash(symbel->id) % sizeHT;
	//chack if alrdy has this symbol

	if(strcmp (hashTableSymbel[id].name ,symbel->id )!=0)
		//if not creah table for the symbel
		hashTableSymbel[id].name = symbel->id;
	//copy the pointer fot the symbel data

	temp_symbal=hashTableSymbel[id].symbals->sing;
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
    if (isFull(frameStack)) 
        return; 
    frameStack->array[++frameStack->top] = item; 
	} 
  
// Function to remove an item from stack.  It decreases top by 1 
struct frame * pop() { 
    if (isEmpty(frameStack)) 
        return NULL; 
    return frameStack->array[frameStack->top--]; 
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
	if( strcmp (root->token ,strdup("BLOCK"))==0){
	push(creathFrame());

	printf("found new block\n");

	}
	if(root->left)
		CrearhSymbalFrame(root->left);
	if(root->right)
		CrearhSymbalFrame(root->right);
	


}