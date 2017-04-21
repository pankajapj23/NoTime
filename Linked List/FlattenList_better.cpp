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
struct node* createnode(int data)
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data =data ; newnode->right =NULL; newnode->below=NULL;
	return newnode;
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
//Insert the element before end
void insertBefore(struct node *start, struct node *end, int data)
{
	if(start==NULL) return;
	while (start->right!=end) start=start->right;
	struct node *newdata = (struct node *)malloc(sizeof(struct node));
	newdata->data=data; newdata->below=NULL;
	newdata->right = start->right;
	start->right=newdata;
}

//Insert element after end node so that element will placed at correct position to maintain sorted list
void insertAtCorrectPos(struct node *start, int data)
{
	if(start==NULL) return;
	struct node *prev=NULL;
	struct node *newdata = (struct node *)malloc(sizeof(struct node));
	newdata->data=data; newdata->below=NULL;
	while(start->right!=NULL)
	{
		if(start->data < data){
			prev = start;
			start = start->right;
		}
		if( start->data > data){
			newdata->right =prev->right;
			prev->right = newdata; return;
		}
			
	}
	//If no node greater than data found then insert the data at the end
	start->right = newdata;
	newdata->right=NULL;
}

void flatten_method2(struct node *head)
{
	struct node *temp2 = head->below, *temp1 = head->right, *curhead =head;
	while(temp1!=NULL)
	{
		if(temp2 && temp1)
		{
			if(temp2->data < temp1->data)
				insertBefore(head, temp1, temp2->data);
				
			else if(temp2->data > temp1->data)
				insertAtCorrectPos(temp1, temp2->data);
			
			curhead->below= temp2->below;
			struct node *todel = temp2;
			temp2=temp2->below;
			free(todel);
		}
		if(temp2==NULL){
			curhead = temp1;
			temp2= temp1->below;
			temp1= temp1->right;
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
	flatten_method2(head);	
	printf("\n\n");
	return 0;
}