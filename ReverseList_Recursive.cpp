#include <stdio.h>
#include <stdlib.h>

struct node{
	int data; struct node *next;
};

void addNodeAtEnd(struct node **head, int data){
	struct node *newnode = (struct node *)malloc(sizeof(struct node *));
	newnode->data = data; newnode->next=NULL;
	if((*head) == NULL) *head = newnode;
	else{
		struct node *temp = *head;
		while(temp->next!=NULL) temp=temp->next;
		temp->next = newnode;
	}
}

void displayList(struct node *head){
	if(head==NULL) return;	
	while(head!=NULL){
		printf(" %d -> ", head->data);
		head=head->next;
	}
	printf(" NULL\n");
}

struct node* reverseListRecursive(struct node *head, struct node *end){
	
	struct node *newhead=head;	
	if(end==NULL) return newhead;
	
	newhead = reverseListRecursive(head->next,end->next);
	end->next =head;
	head->next = NULL;
	
	return newhead;
}


int main()
{
	struct node *list1=NULL;
	addNodeAtEnd(&list1, 1);
	addNodeAtEnd(&list1, 2);
	addNodeAtEnd(&list1, 3);
	addNodeAtEnd(&list1, 4);
	addNodeAtEnd(&list1, 5);
	addNodeAtEnd(&list1, 6);
	addNodeAtEnd(&list1, 7);
	addNodeAtEnd(&list1, 8);
	addNodeAtEnd(&list1, 9);
	displayList(list1);

	struct node *temp = reverseListRecursive(list1,list1->next);
	displayList(temp);

	printf("\n");
	return 0;
}

