#include <stdio.h>
#include <stdlib.h>

struct node {
	int data; struct node *right; struct node *below;
};

void displayRight(struct node *head)
{
	printf("Horizontal list:  ");
	while (head!=NULL){
		printf(" %d-> ", head->data); head=head->right;
	}
}

void displaybelow(struct node *head)
{
	while(head!=NULL){
		struct node *temp = head->below;
		printf("\nVertical list of %d:\n", head->data);
		while (temp!=NULL){
		printf("                   %d \n", temp->data); temp=temp->below;
		}
		head=head->right;		
	}
}

void addRight(struct node **head, int data)
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = data; 
	newnode->below=NULL; newnode->right=NULL;
	if ((*head) == NULL) (*head) = newnode;
	else{
		struct node *temp = *head;
		while(temp->right!=NULL) temp=temp->right;
		temp->right=newnode;
	}
}

void addbelow(struct node *head, int data)
{
	struct node *newnode= (struct node *)malloc(sizeof(struct node));
	newnode->data= data; newnode->below=NULL; newnode->right=NULL;
	if(head==NULL) {
		printf("\nBelow list can not created as 1st level of node is not present!");
		return;
	}
	else
	{
		struct node *temp = head;
		if(temp->below==NULL) temp->below = newnode;
		else {
			while(temp->below!=NULL) temp = temp->below;
			temp->below = newnode;
		}
	}
}

void disp(struct node *start)
{
	if (start==NULL)
		printf("\nEmpty linked list\n");

	while(start!= NULL)
	{
		printf("%d-> ",start->data);
		start = start->right;
	}
	printf("NULL\n");
	
}

void flatten(struct node *head)
{
	struct node *temp2 = head, *temp1 = head;
	while(temp1!=NULL){
		if(temp2->right!=NULL) 
			temp2=temp2->right;
		else{
			if(temp1->below!=NULL){
			temp2->right = temp1->below;
			temp1->below = NULL;
			}
			temp1=temp1->right;
		}
	}	
	printf("\nFlattened Linked list:\n");
	disp(head);
}

int main()
{  
	struct node *head = NULL;
	addRight(&head,5);
	addRight(&head,10);
	addRight(&head,19);
	addRight(&head,28);
	
	addbelow(head,6);
	addbelow(head,30);
	addbelow(head,120);
	addbelow(head,900);
	addbelow(head->right,12);
	addbelow(head->right,20);
	addbelow(head->right->right,50);
	addbelow(head->right->right->right,35);

	displayRight(head);
	printf("\n");
	displaybelow(head);
	flatten(head);
	printf("\n\n");
	return 0;
}