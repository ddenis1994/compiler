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
	int isProc_func; // if 1 is func 0 is proc 
	char* type;
	char* data;
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
int insert_symbel(char * id,int is_func_proc,char * type,char * data, char * return_value,int frameBelong);
int CrearhSymbalFrame(node * root);
struct frame * creathFrame();
int startSemantic(node * root);
node *mknode(char *token, node *left, node *right);
node *mkleaf(char *token);
node * creathFuncDec(char * id,node * args,char * typeOfReturn,node * block);
int insert_to_stack(deciptopn * symbel);



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
	PROC ID ARGES COMPUND_STATMENT_PROC  {
		$$=mknode("ARGS",NULL,$3);
		$$=mknode("ID",$$,mkleaf($2));
		$$=mknode("PROC",$$,$4);
		}
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
	'{' RETURN EXPRASION ';' '}'  {$$=mknode("BLOCK_FUNC",NULL,mknode(strdup("RETURN BLOCK"),$3,NULL));}
	|'{' INNER_COMPUND_STATMENT RETURN EXPRASION ';' '}'  {
															$$=mknode("BLOCK_FUNC",$2,mknode(strdup("RETURN BLOCK"),$4,NULL));}
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
	IF '(' EXPRASION ')' STASTMENT ELSE STASTMENT {
		$$=mknode("IF_ELSE",
		mknode("EXPRASION_IF",NULL,$3),
		mknode("BODY_IF",mknode("ELSE",NULL,$7),$5)
		);
		}		
																										
	|IF '(' EXPRASION ')'  STASTMENT %prec IFX {  
        $$=mknode("IF",mknode("EXPRASION_IF",NULL,$3),mknode("BODY_IF",NULL,$5));}
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
	WHILE '(' EXPRASION ')' STASTMENT {
		$$=mknode("WHILE",mknode("EXPRESSION",NULL,$3),mknode("BODY",NULL,$5));
		}
	|FOR '(' EXPRASION ';' EXPRASION ';' UPDATES ')' STASTMENT
		
	{	
		$$=mknode("FOR",mknode("INIT",mknode("EXPRESSION_FOR",mknode("UPDATE",NULL,$7),$5),$3),mknode("BODY",NULL,$9));
	}
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
	struct deciptopn * temp_symbal;
	long sizeHT = SYMBALTABLESIZE;

	//creath first hush key for the string
	long long id =compute_hash(symbel->id) % sizeHT;
	//chack if alrdy has this symbol

	if(strcmp (hashTableSymbel[id].name ,symbel->id )!=0)
		//if not creah table for the symbel
		hashTableSymbel[id].name = symbel->id;
		

	//copy the pointer fot the symbel data

	temp_symbal=hashTableSymbel[id].symbals;

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
	struct frame * temp=frameStack->array[(frameStack->top)--];
    free(temp);

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
						deep);
						


		push(creathFrame());
		printf("found new block %d\n",deep);


		
		if(root->right->left)
			CrearhSymbalFrame(root->right->left);

		printf("finish block %d\n",deep);
		
		//TODO find away to detrmate the func return type

		pop();

	
		return 0;

	}

	if( !strcmp (root->token ,"PROC")){

		push(creathFrame());
		printf("found new block %d\n",deep);

		//TODO start build table from proc

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

int insert_symbel(char * id,int is_func_proc,char * type,char * data, char * return_value,int frameBelong){
	struct deciptopn * temp=(struct deciptopn *)malloc(sizeof(deciptopn));
	temp->id=id;
	temp->isProc_func=is_func_proc;

	if(temp->isProc_func)
		temp->return_value=return_value;
	else
		temp->return_value=NULL;
	temp->type=type;
	temp->data=data;
	temp->frameBelong=frameBelong;
	temp->next=NULL;
	insert_to_ht(temp);
	insert_to_stack(temp);
	
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


	//print_stack();

	

	return 0;
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