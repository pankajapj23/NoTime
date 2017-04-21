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
char pop(struct node **stack){
	struct node *temp=*stack;
	if(temp==NULL){
		printf("\nStack Underflow!!!"); return 0;
	}
	*stack=temp->next;
	char a = temp->data;
	free(temp);
	return a;
}

int isEmpty(struct node *stack){
	if(stack==NULL) return 1;
	else return 0;
}

void reverseString(char *str){
	struct node *stack=NULL;
	int i=0,j=0;
	
	for( i=0; i < strlen(str); i++)
		push(&stack, str[i]);

	while(!isEmpty(stack))
		str[j++]=pop(&stack);
}

int main(){
	char exp[50] = "JAKNAPIHKAR";
	reverseString(exp);
	printf("\nReversed String: ");
	for (int i=0; i<strlen(exp); i++)
		printf(" %c ", exp[i]);
	
	printf("\n");
	return 0;
}