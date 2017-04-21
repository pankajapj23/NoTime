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

void deleteMnodesAfterNnodes(struct node *head, int n, int m){
	struct node *temp=head;
	int ncnt=1,mcnt=1;
	if(m==0 || n==0) return;
	while(temp!=NULL){
		if(ncnt!=n){
			ncnt++; temp=temp->next;
		}
		if(temp && ncnt==n){
			if(temp->next!=NULL && mcnt<=m){
				struct node *todel=temp->next;
				temp->next = todel->next;
				todel=NULL;
				free(todel);
			}
			if(mcnt++==m){
				mcnt=1;ncnt=1;
				temp=temp->next;
			}
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
	deleteMnodesAfterNnodes(list1,0,1);
	displayList(list1);
	return 0;
}
