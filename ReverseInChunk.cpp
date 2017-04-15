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

struct node* reverse(struct node *start, struct node *end)
{
	struct node *next=start, *cur =NULL, *prev=end->next;
	while(cur!=end){
		cur = next;
		next = next->next;
		cur->next = prev;
		prev=cur;
	}
	return cur;
}

void reverseChunkInGivenSize(struct node **head, int chunkSize)
{
	struct node *temp = *head, *start= *head, *end=NULL, *prevstart =NULL, *newstart =NULL;
	int count =1, flag=1;
	while(temp!=NULL){
		if(count!=chunkSize){
			count++; temp=temp->next;
		}

		if(!temp) return; //If temp reaches NULL before chunksize is found return out of the loop

		if(count==chunkSize){
			count=1; //reset the counter
			end=temp; 
			temp=temp->next;
			newstart = reverse(start, end);
			if(flag){
				*head = newstart; flag=0;
			}
			else
				prevstart->next=newstart;

			prevstart=start; //start node after reversal is the node just before new start of chunk
			start=temp; //set the current of temp and start position of next chunk
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

	reverseChunkInGivenSize(&list1,3);
	displayList(list1);

	printf("\n");
	return 0;
}