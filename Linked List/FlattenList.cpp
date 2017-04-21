#include <stdio.h>
#include <stdlib.h>

////1-D list
//struct node {
//	int data; struct node *next;
//};

//2-D linked list
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
void append(struct node **head, int data)
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data =data ; newnode->right =NULL; newnode->below=NULL;

	if((*head)==NULL)
		*head = newnode;
	else{
	struct node *temp = *head;
	while(temp->below!=NULL) temp=temp->below;
	temp->below= newnode;
	}
}

void disp(struct node *start)
{
	if (start==NULL)
		printf("\nEmpty linked list\n");

	while(start!= NULL)
	{
		printf("%d-> ",start->data);
		start = start->below;
	}
	printf("NULL\n");
	
}

void flatten(struct node *head)
{
	if(head==NULL) return;

	struct node *temp = head;	
	struct node *list1 = temp; 
	temp=temp->right;	
	struct node *list2 = temp;
	struct node *newlist = NULL; 
		
	while(temp!=NULL)
	{
		if(list1 && list2) //both lists are not empty
		{
			if(list1->data < list2->data)
			{
				append(&newlist,list1->data); list1=list1->below;
			}
			else if (list1->data > list2->data)
			{
				append(&newlist,list2->data); list2=list2->below;
			}

		}		
		else if(list1==NULL && list2!=NULL){
			while(list2!=NULL){
				append(&newlist,list2->data); list2=list2->below;
			}
		}
		 
		else if(list1!=NULL && list2==NULL){
			while(list1!=NULL){
				append(&newlist,list1->data); list1=list1->below;
			}
		}
		else
		{
		temp=temp->right;
		if(temp !=NULL)
		{
			list1 = newlist;
			list2 = temp;
			newlist = NULL;
			free(newlist);
		}
		}
	}
	printf("\nFlattened Linked list:\n");
	disp(newlist);
}

int main()
{  
	struct node *head = NULL;
	addRight(&head,5);
	addRight(&head,10);
	addRight(&head,19);
	addRight(&head,28);
	
	addbelow(head,60);
	addbelow(head,70);
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