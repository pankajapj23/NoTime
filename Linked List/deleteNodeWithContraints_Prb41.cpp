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


void deleteNode(struct node *head, int data){

	struct node *temp=head, *prev=NULL;

	if(head->data == data){
		temp=head->next;
		head->data=temp->data;
		head->next=temp->next;
		temp=NULL;
		free(temp); return;
	}
	else{
		while(temp && temp->data!=data){
			prev=temp;	temp=temp->next;
		}
		if(temp==NULL){ 
			printf("\nData not present in list\n"); return;
		}
		else{
		prev->next=temp->next;
		temp=NULL;
		free(temp);
		}
	}
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

	deleteNode(list1, 1);
	displayList(list1);
	return 0;
}