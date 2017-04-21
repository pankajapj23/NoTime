//Sort 0s, 1s and 2s in the linked list
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data; struct node *next;
};

void addInFront(struct node **head, int data){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data=data; 
	newnode->next=(*head);
	*head = newnode;	
}

void addBeforeNode(struct node **head, int data, int k)
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data=data; newnode->next=NULL;
		
	struct node *temp = *head, *prev=NULL;
	//if List is empty then just add this element
	if((*head) ==NULL){
		*head=newnode; return;
	}
	
	while(temp && temp->data != k){
		prev=temp;
		temp=temp->next;
	}
	//If K node is at head 
	if(temp==(*head)){
		newnode->next = (*head);
		*head=newnode;
	}
	
	if(temp==NULL) //K node is not present in list then add the item at the end
	prev->next=newnode;
	else{
	//If node to be inserted between two nodes
	newnode->next = prev->next;
	prev->next=newnode;
	}
}

void append(struct node **head, int data){	
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data=data; newnode->next=NULL;
	if((*head)==NULL) *head = newnode;
	else{
		struct node *temp=*head;
		while(temp->next!=NULL) temp=temp->next;
		temp->next=newnode;
	}
}

void display(struct node *head)
{
	while(head!=NULL)
	{
		printf(" %d ", head->data);
		head=head->next;
	}
}

void sort0s1s2s(struct node **head)
{
	struct node *temp = *head;
	struct node *newlist =NULL;
	
	while(temp!=NULL)
	{
		if(temp->data == 0) addInFront(&newlist, temp->data);
		else if(temp->data == 2) append(&newlist, temp->data);
		else if(temp->data == 1) addBeforeNode(&newlist, temp->data, 2);
		temp=temp->next;
	}
	printf("\nSorted list of 0s, 1s and 2s: \n");
	display(newlist);
}

int main(void){
	
	struct node *head=NULL;
	append(&head, 0);
	append(&head, 2);
	append(&head, 1);
	append(&head, 1);
	append(&head, 2);
	append(&head, 0);
	append(&head, 1);
	printf("\nUnsorted List of 0s, 1s and 2s: \n");	
	display(head);
	sort0s1s2s(&head);
	
	return 0;
}