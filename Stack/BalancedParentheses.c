#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declare stack structure
struct node{
	char data; struct node *next;
};

//Always add new node at front
void push(struct node **stack, char data){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = data; newnode->next=NULL;

	if((*stack)==NULL) *stack = newnode;
	else{
		newnode->next=(*stack);
		*stack = newnode;
	}
}

//Always delete element at front
void pop(struct node **stack){
	struct node *temp=*stack;
	if(temp==NULL){
		printf("\nStack Underflow!!!"); return;
	}
	*stack=temp->next;
	free(temp);
	
}

int isEmpty(struct node *stack){
	if(stack==NULL) return 1;
	else return 0;
}

//Check if parenetheses are pair
int arePair(char a, char b){
	if(a=='('  && b==')') return 1;
	else if (a=='{'  && b=='}') return 1;
	else if (a=='['  && b==']') return 1;
	else return 0;
}

//Always return the first element of stack
char top(struct node *stack){
	return stack->data;
}

int balancedParentheses(char *exp){
	struct node *stack=NULL;
	int i=0;
	
	for( i=0; i<strlen(exp); i++)
	{
		if((exp[i]== '[') || (exp[i] == '{') || (exp[i]=='('))
			push(&stack, exp[i]);
		else if((exp[i]== ']') || (exp[i] == '}') || (exp[i]==')'))
			{
				if(!isEmpty(stack) && arePair(top(stack), exp[i])) 
					pop(&stack);
				else
					return 0;
			}
	}
   if(isEmpty(stack)) return 1;
   else return 0;
}

int main(){
	char exp[50] = "[()]";	
	(balancedParentheses(exp))? printf("\nBalanced!!!\n"): printf("\nUnbalanced!!!\n");
	printf("\n");
	return 0;
}