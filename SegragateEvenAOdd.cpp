#include <stdio.h>
#include <stdlib.h>

struct node {
	int data; struct node *next;
};

void append(struct node **head, int data){
	struct node *newnode = (struct node *)malloc(sizeof(struct node *));
	newnode->data = data; newnode->next=NULL;
	if((*head) == NULL) *head = newnode;
	else{
		struct node *temp = *head;
		while(temp->next!=NULL) temp=temp->next;
		temp->next = newnode;
	}
}

void displayList2(struct node *head){
	if(head==NULL) return;	
	while(head!=NULL){
		printf(" %d ->", head->data);
		head=head->next;
	}
	printf(" NULL\n");
}

struct node* addNode(int data){
	struct node *newnode = (struct node *)malloc(sizeof(struct node *));
	newnode->data = data; newnode->next=NULL;
	return newnode;
}

void segregateEvenOdd(struct node *head){

	struct node *temp = head, *evenList=NULL, *evenHead=NULL, *oddHead=NULL, *oddList=NULL;
	//Find if there any only even or only odd node present in list
	struct node *temp2=head; int even=0, odd=0;
	while(temp2!=NULL){
		if(temp2->data%2 == 0) even=1;
		else odd=1;
		temp2=temp2->next;
	}
	//If List have only even or only odd then return list as it is
	if(even==0 || odd==0){
		printf("\nList contain only even or only odd hence no segregation required!!\n");
		displayList2(head);
		return;
	}

	while(temp!=NULL)
	{
		if(temp->data%2==0){
			if(evenHead==NULL) {
				evenList=addNode(temp->data);
				evenHead=evenList; 
			}
			else{
				evenList->next=addNode(temp->data);
				evenList=evenList->next;
			}
		}
			
		else{			
			if(oddHead==NULL){
				oddList=addNode(temp->data);				
				oddHead=oddList;
			}
			else{
				oddList->next=addNode(temp->data);
				oddList=oddList->next;
			}
		}
		temp=temp->next;
	}

	evenList->next = oddHead;
	displayList2(evenHead);
}


int main(){
	struct node *head=NULL;
	append(&head, 17);
	append(&head, 15);
	append(&head, 8);
	append(&head, 12);
	append(&head, 10);
	append(&head, 5);
	append(&head, 4);
	append(&head, 1);
	append(&head, 7);
	append(&head, 6);

	displayList2(head);

	segregateEvenOdd(head);

	return 0;
}