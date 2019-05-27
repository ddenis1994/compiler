%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <fenv.h>
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
	node * arges;
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
int insert_symbel(char * id,int is_func_proc,char * type,char * data, char * return_value,int frameBelong,node * arges);
int CrearhSymbalFrame(node * root);
struct frame * creathFrame();
int startSemantic(node * root);
node *mknode(char *token, node *left, node *right);
node *mkleaf(char *token);
node * creathFuncDec(char * id,node * args,char * typeOfReturn,node * block);
int insert_to_stack(deciptopn * symbel);
void find_var_names(char * type,node * root);
deciptopn * get_symbal_from_hash(char * name);
node * makeArgsReq(node * root);
node * getInnerArges(node * root ,char * type);
void printLinkedList(node * root);
int checkFunc(node * originalArges,node * newArges);
node * creath_arges(node* root);
int chack_arges(deciptopn * originalArges,node * newArges,int typeofchack);


void printtree(node *tree,int space);
void yyerror(char *);
extern int yylex();
%}
%union {
	char * String;
	struct node * Node;
}
%start S
%token <String> CHAR REAL FLOAT INT BOOL STRING CHAR_POINER REAL_POINER FLOAT_POINER INT_POINER
%token <String> CHAR_POINTER REAL_POINTER FLOAT_POINTER INT_POINTER 
%token ELSE IF
%token FOR WHILE
%token TRUE FALSE
%token RETURN MAIN
%token <String> VAR FUNC PROC
%token NULL_VALUE 
%token AND_OP GE_OP SE_OP NE_OP OR_OP EQL_OP
%token <String> BOOL_VALUE CHAR_VALUE STRING_VALUE INT_NUM F_NUM HEX_NUM
%token <String> ID 
%type <String> TYPE 
%type <Node> INNER_ARGS 
%type <Node> CONST 
%type <Node> OUT_ARGES ARGES FUNC_DEF FUNC_BLOCK INNER_COMPUND_STATMENT EXPRASION 
%type <Node> FUNC_ACTIVE  COMPUND_STATMENT
%type <Node> STASTMENT_LIST DEC_INNER_BLOCK
%type<Node> STASTMENT IF_STASTMENT LOOP_STATMENT
%type<Node> UPDATES VF VAR_DECLARE FUNC_PROC_DEC DEF_A VFDEC
%type<Node> PROC_DEF NEW_DECLARE   MAIN
%type<Node> S RETURN_STATMENT VALUE
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
%right MAIN 


%%
S: 
	FUNC_PROC_DEC {
        $$=mknode("BLOCK",$1,NULL);
		startSemantic($$);
        printf("ok\n");
        }
	;


FUNC_PROC_DEC:
	DEF_A {$$=mknode("",$1,NULL);}
	|FUNC_PROC_DEC DEF_A  {$$=mknode("",$1,$2);}
	;

DEF_A:
	FUNC_DEF {	$$=mknode("NEW_FUNC",$1,NULL);}
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

ARGES: '(' ')' {$$=mkleaf("NULL_ARGS");}
	| '(' OUT_ARGES ')' {$$=mknode(strdup("ARGS "),$2,NULL);
	}
	;



OUT_ARGES:
	INNER_ARGS ':' TYPE {$$=mknode($3,$1,NULL);}
	|INNER_ARGS ':' TYPE ';' OUT_ARGES {$$=mknode($3,$1,$5);}
	;




INNER_ARGS:
	ID {$$=mknode("ID",NULL,mkleaf($1));}
	|ID ',' INNER_ARGS {
		$$=mknode("ID",$3,mkleaf($1));
		}
	;


FUNC_BLOCK:
	'{' RETURN EXPRASION ';' '}'  {$$=mknode("BLOCK_FUNC",NULL,mknode(strdup("RETURN STATMENT"),$3,NULL));}
	|'{' INNER_COMPUND_STATMENT RETURN EXPRASION ';' '}'  {
															$$=mknode("BLOCK_FUNC",$2,mknode(strdup("RETURN STATMENT"),$4,NULL));}
	;




EXPRASION:
	CONST 
	|'(' EXPRASION ')'  {$$=$2;}
	|TRUE {$$=mknode("BOOL_RXPRASION",mkleaf("false"),NULL);}
	|FALSE {$$=mknode("BOOL_RXPRASION",mkleaf("true"),NULL);}
	|ID {$$=mknode("ID_EXPRASION",mkleaf($1),NULL);}
	|'^' EXPRASION {$$=mknode("ADDR_RXPRASION",mkleaf("^"),NULL);}
	| '&' EXPRASION {$$=mknode("ADDR_RXPRASION",mkleaf("&"),NULL);}
	|'-' EXPRASION %prec UMINUS {$$=mknode("NUM_RXPRASION",mkleaf("&"),NULL);}
	|'!' EXPRASION {$$=mknode("BOOL_RXPRASION",mkleaf("&"),NULL);}
	|ID '=' EXPRASION {$$=mknode("=",mkleaf($1),$3);}
	|EXPRASION NE_OP VALUE  {$$=mknode("BOOL_RXPRASION",mknode("!=",$1,$3),NULL);}
	|EXPRASION AND_OP VALUE  {$$=mknode("BOOL_RXPRASION",mknode("&&",$1,$3),NULL);}
	|EXPRASION OR_OP VALUE  {$$=mknode("BOOL_RXPRASION",mknode("||",$1,$3),NULL);}
	|EXPRASION '+' VALUE  {$$=mknode("NUM_RXPRASION",mknode("+",$1,$3),NULL);}
	|EXPRASION '-' VALUE  {$$=mknode("NUM_RXPRASION",mknode("-",$1,$3),NULL);}
	|EXPRASION '/' VALUE  {$$=mknode("NUM_RXPRASION",mknode("/",$1,$3),NULL);}
	|EXPRASION '*' VALUE  {$$=mknode("NUM_RXPRASION",mknode("*",$1,$3),NULL);}
	|EXPRASION EQL_OP VALUE  {$$=mknode("BOOL_RXPRASION",mknode("==",$1,$3),NULL);}
	|EXPRASION GE_OP VALUE  {$$=mknode("BOOL_RXPRASION",mknode(">=",$1,$3),NULL);}
	|EXPRASION SE_OP VALUE  {$$=mknode("BOOL_RXPRASION",mknode("<=",$1,$3),NULL);}
	|EXPRASION '>' VALUE  {$$=mknode("BOOL_RXPRASION",mknode(">",$1,$3),NULL);}
	|EXPRASION '<' VALUE  {$$=mknode("BOOL_RXPRASION",mknode("<",$1,$3),NULL);}
	|FUNC_ACTIVE 
	;

VALUE:
	CONST 
	|'(' EXPRASION ')'  {$$=$2;}
	|TRUE {$$=mkleaf("TRUE");}
	|FALSE {$$=mkleaf("FALSE");}
	|ID {$$=mkleaf($1);}
	;



FUNC_ACTIVE:
	ID '(' ')' {$$=mknode("FUNC_PROC_ACTIVE",mknode("ID",NULL,mkleaf($1)),mkleaf("Arges")); }
	|ID '(' FUNC_ACTIVE_INNER_ARGES ')' {
		$$=mknode("FUNC_PROC_ACTIVE",mknode("ID",NULL,mkleaf($1)),mknode("Arges",NULL,$3));
	}
	;

FUNC_ACTIVE_INNER_ARGES:
	ID {$$=mknode("ID_ARG",mkleaf($1),NULL);}
	|FUNC_ACTIVE {$$=mknode("FUNC_ARG",$1,NULL);}
	|CONST  {$$=mknode("CONST_ARG",$1,NULL);}
	|ID ',' FUNC_ACTIVE_INNER_ARGES {$$=mknode("ID_ARG",mkleaf($1),$3);}
	|CONST ',' FUNC_ACTIVE_INNER_ARGES {$$=mknode("CONST_ARG",$1,$3);}
	|FUNC_ACTIVE ',' FUNC_ACTIVE_INNER_ARGES {$$=mknode("FUNC_ARG",$1,$3);}
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
		printf("got hare\n");
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

	'{' INNER_COMPUND_STATMENT RETURN_STATMENT '}' { $$=mknode("BLOCK",$3,$2); }
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
	NEW_DECLARE DEC_INNER_BLOCK {$$=mknode("DECLARE",$1,$2);
	}
	|NEW_DECLARE {$$=mknode("DECLARE",$1,NULL);
}
	;

NEW_DECLARE:
	VAR_DECLARE
	|FUNC_PROC_DEC
	;

VAR_DECLARE:
	 VF {$$=mknode("VAR_DECLARE",$1,NULL);}
	|VAR_DECLARE VF {$$=mknode("VAR_DECLARE",$1,$2);}
	;

VF: 
	VAR VFDEC {$$=$2;}
	;

VFDEC:
	INNER_ARGS ':' TYPE  ';' {$$=mknode($3,$1,NULL);}
	|INNER_ARGS ':' TYPE  ';' VFDEC {$$=mknode($3,$1,$5);}
	;

CONST:
	INT_NUM {$$=mknode("int",mkleaf($1),NULL);}
	|F_NUM {$$=mknode("float",mkleaf($1),NULL);}
	|HEX_NUM {$$=mknode("hex",mkleaf($1),NULL);}
	;

TYPE:	
	STRING '[' INT_NUM ']'
	|BOOL 
	|INT 
	|FLOAT 
	|REAL 
	|CHAR 
	|CHAR_POINER
	|REAL_POINER
	|FLOAT_POINER
	|INT_POINER {printf("got hare\n");}
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
	struct deciptopn ** temp_symbal;
	int i=0;
	unsigned long long int  sizeHT = SYMBALTABLESIZE;
	//creath first hush key for the string
	unsigned long long int idtemp = compute_hash(symbel->id)  ;
	unsigned long long int id=idtemp-idtemp/sizeHT*sizeHT;
	//chack if alrdy has this symbol

	if(strcmp(hashTableSymbel[id].name ,"")==0)
		hashTableSymbel[id].name = symbel->id;

	if(hashTableSymbel[id].name=="")
		if(!strcmp (hashTableSymbel[id].name ,symbel->id ))
			//if not creah table for the symbel
			hashTableSymbel[id].name = symbel->id;
	

	//copy the pointer fot the symbel data

	temp_symbal=&(hashTableSymbel[id].symbals);

	//look for first empty space
	while((*temp_symbal) != NULL)
		temp_symbal=&((*temp_symbal) -> next);
	
	//insert in the empty space the the table for the symbel


	//hare can find out if alredy crather this symbol
	//to do chack if symbol alerdy exsists
	if (NULL)
		return 1;

	(*temp_symbal)=symbel;


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
	deep--;
	struct frame * temp=frameStack->array[(frameStack->top)--];
    free(temp);

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


node * creathFuncDec(char * id,node * args,char * typeOfReturn,node * block){
	node * temp=mknode("RETURN ",NULL,mkleaf(typeOfReturn));
	temp=mknode("ARGS",temp,args);
	temp=mknode("ID",temp,mkleaf(id));
	temp=mknode("FUNC",temp,block);

	return temp;

	}



int CrearhSymbalFrame(node * root){
	//first to to push empty stack
	struct deciptopn * temp ;
	struct deciptopn * temp2 ;
	static char * current;

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
						deep,
						root->left->left->right->left);

		current=root->left->right->token;
						

		push(creathFrame());
		printf("found new block %d\n",deep);

		find_var_names("",root->left->left->right->left);
		

		if(root->right)
			CrearhSymbalFrame(root->right);

		printf("finish block %d\n",deep);
		

		pop();

		//look for return stat


	
		return 0;

	}

	if( !strcmp (root->token ,"PROC")){


		insert_symbel(
						root->left->right->token,
						1,
						"proc_declare",
						NULL,
						NULL,
						deep,
						root->left->left->right->left);

		current=root->left->right->token;

		push(creathFrame());
		if(root->left->left->right->left)
			find_var_names("",root->left->left->right->left);

		printf("found new block %d\n",deep);

		if(root->right)
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
	if( !strcmp (root->token ,"VAR_DECLARE")){
		find_var_names(" ",root->left);
		
	}

	if( !strcmp (root->token ,"FUNC_PROC_ACTIVE")){
		int temp1;
		temp=get_symbal_from_hash(root->left->right->token);


		if(temp==NULL){
			printf("the func proc %s was not declared\n",root->left->right->token);
			exit(1);
		}
		if((temp1=checkFunc(temp->arges,root->right))==1){
			printf("too many arges for func %s\n",root->left->right->token);
			exit(1);
		}
		
		else if(temp1==2){
			printf("too few arges for func %s\n",root->left->right->token);
			exit(1);
		}

		
	}

	if( !strcmp (root->token ,"RETURN STATMENT")){
		
		temp2=get_symbal_from_hash(current);

		
		
		if(!strcmp(root->left->token, "FUNC_PROC_ACTIVE")){

			temp=get_symbal_from_hash(root->left->left->right->token);

			if(temp==NULL){
			printf("%s was used before declared\n",root->left->left->token);
			exit(1);
		}

		if(strcmp(temp->return_value,temp2->return_value)){
			printf("wrong return type in func %s \n",temp2->id);
			exit(1);
		}

		}

		else if(!strcmp(root->left->token, "ID_EXPRASION")){

			temp=get_symbal_from_hash(root->left->left->token);
			if(temp==NULL){
				printf("%s was used before declared\n",root->left->left->token);
				exit(1);
			}

			if(strcmp(temp->type,temp2->return_value)){
				printf("wrong return type in func %s \n",temp2->id);
				exit(1);
			}

		}
		else{
			temp=(struct deciptopn *)malloc(sizeof(deciptopn));
			temp->id=root->left->token;
			temp->type=root->left->token;
			temp->data=root->left->token;

			

			if(strcmp(temp->type,temp2->return_value)){
				printf("wrong return type in func %s \n",temp2->id);
				exit(1);
			}
		}

	}
	if( !strcmp (root->token ,"=")){
		temp=get_symbal_from_hash(root->left->token);
		//printf("%s \n",root->right->token);
		printtree(root,0);

		if(!strcmp(root->right->token,"FUNC_PROC_ACTIVE")){
			temp2=get_symbal_from_hash(root->right->left->right->token);
			if(strcmp(temp->type,temp2->return_value)){
				printf("wrong assignment type \nexpected %s got %s\n",
				temp->type,temp2->return_value);
				exit(1);
			}
		}
		if(!strcmp(root->right->token,"ID_EXPRASION")){
			temp2=get_symbal_from_hash(root->right->left->token);
			if(strcmp(temp->type,temp2->type)){
				printf("wrong assignment type \nexpected %s got %s\n",
				temp->type,temp2->type);
				exit(1);
			}

		}
		else{
			if(strcmp(temp->type,root->right->token)){
				printf("wrong assignment type \nexpected %s got %s\n",
				temp->type,root->right->token);
				exit(1);
			}
		}
		


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

int insert_symbel(char * id,int is_func_proc,char * type,char * data, char * return_value,int frameBelong , node * arges){
	struct deciptopn * temp=(struct deciptopn *)malloc(sizeof(deciptopn));
	temp->id=id;
	temp->isProc_func=is_func_proc;

	if(temp->isProc_func)
		temp->return_value=return_value;
	else
		temp->return_value=NULL;

	if(arges)
		temp->arges=makeArgsReq(arges);

	temp->type=type;
	temp->data=data;
	temp->frameBelong=frameBelong;
	temp->next=NULL;
	insert_to_ht(temp);
	insert_to_stack(temp);
	//print_stack();
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


	return 0;
}

void find_var_names(char * type,node * root){

	if ((strcmp(root->token,"ID")) && (strcmp(root->token,""))){

		if(root->left)
			find_var_names(root->token,root->left);
				if(root->right)
					find_var_names("",root->right);
	}
	else
	{
		insert_symbel(root->right->token ,0,type,NULL,NULL,deep,NULL);
		if(root->left)
			find_var_names(root->token,root->left);
	}
}

deciptopn * get_symbal_from_hash(char * name){
	struct deciptopn * temp;

	unsigned long long int  sizeHT = SYMBALTABLESIZE;
	//creath first hush key for the string
	unsigned long long int idtemp = compute_hash(name);
	unsigned long long int id=idtemp-idtemp/sizeHT*sizeHT;

	temp=hashTableSymbel[id].symbals;
	if(!temp)
	{
		printf("first used before declare %s\nsemantic error\n",name);
		exit(1);
	}
	return temp;

}

node * makeArgsReq(node * root){
	node * temp, * last;
	temp=getInnerArges(root->left,root->token);
	last=temp;
	while(last->right)
		last=last->right;
	
	if(root->right)
		
		last->right=makeArgsReq(root->right);

	return temp;	
	
}

node * getInnerArges(node * root ,char * type){
	node * new_arg;
	new_arg=(node*)malloc(sizeof(node));

	new_arg->token=type;

	if(root->left)
		new_arg->right=getInnerArges(root->left,type);
	else
		new_arg->right=NULL;

	return new_arg;
}

void printLinkedList(node * root){
	if(root)
		printf(" %s -> ",root->token);
	if(root->right)
		printLinkedList(root->right);
	else
		printf("\n");
}

int checkFunc(node * originalArges,node * newArges){
	char * arg_type;
	struct deciptopn * temp;
	node * temp2;
	int temp1;

	while(originalArges){
		
		
		if(!newArges)
			return 1;
		
		if(newArges->right){

			arg_type=originalArges->token;

			newArges=newArges->right;
			temp2=originalArges;
			originalArges=originalArges->right;



			if(strcmp("CONST_ARG",newArges->token)==0){
				temp=(struct deciptopn *)malloc(sizeof(deciptopn));
				temp->id=newArges->left->left->token;
				temp->type=newArges->left->token;
				temp->data=newArges->left->left->token;
				chack_arges(temp,temp2,0);
			}

			else if(strcmp("ID_ARG",newArges->token)==0){
				temp=get_symbal_from_hash(newArges->left->token);
				if(temp==NULL){
					printf("used symbel %s before declorasion \n",newArges->left->token);
					exit(1);
				}

				chack_arges(temp,temp2,0);
			}

			else if(strcmp("FUNC_ARG",newArges->token)==0){
				temp=get_symbal_from_hash(newArges->left->left->right->token);
			

				if(temp==NULL){
					printf("used symbel %s before declorasion \n",newArges->left->token);
					exit(1);
				}
				if((temp1=checkFunc(temp->arges,newArges->left->right))==1){
					printf("too many arges for func %s\n",temp->id);
					exit(1);
				}

		
		



				chack_arges(temp,temp2,1);

				




			}


		}
		else if(!newArges->right)
			return 2;
	}
}

int chack_arges(deciptopn * originalArges,node * newArges,int typeofchack){
	if(typeofchack==0)
		if (strcmp(newArges->token,originalArges->type))
			{
				printf("wrong type for var %s \nexpected %s got %s\n",originalArges->id,
				newArges->token,originalArges->type);
				exit(1);
			}

	if(typeofchack==1)
		if (strcmp(newArges->token,originalArges->return_value))
			{
				printf("wrong type for func/proc %s \nexpected %s got %s\n",originalArges->id,
				newArges->token,originalArges->return_value);
				exit(1);
			}
		return 0;
}
