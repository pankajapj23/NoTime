#include <stdio.h>
#include <stdlib.h>

struct node {
	int data; struct node *next;
};

void appendNode(struct node **head, int data){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = data; newnode->next=NULL;
	struct node *temp = *head;
	if(!temp){
		*head = newnode;
	}
	else{
		while(temp->next) temp=temp->next;
		temp->next = newnode;
	}
}

void showList(struct node *head) {
	while(head){
		printf(" %d-> ",head->data); head=head->next;
	}
	printf(" NULL");
}

struct node* reverse(struct node *start, struct node *end){
	struct node *next = start, *cur=NULL, *prev=end->next;
	while(cur!=end){
		cur=next;
		next=next->next;
		cur->next=prev;
		prev=cur;
	}
	return cur;
}

void reverseAlternateChunk(struct node **head, int chunkSize){
	struct node *temp = *head, *start = *head, *end=NULL, *newStart=NULL, *prevStart=NULL;
	int flag=1, count=1;

	while(temp!=NULL){
		if(count!=chunkSize){
			count++; temp=temp->next;
		}

		if(temp==NULL) return; //Return If count reaches NULL before next chunk

		if(count==chunkSize){
			count++;
			end=temp;
			temp=temp->next;
			newStart = reverse(start, end);
			if(flag){
				*head=newStart; flag=0;
			}
		else
			prevStart->next=newStart;
		}

		if(count==(chunkSize*2)){
			if(temp==NULL) return;
			count=1; prevStart=temp; 
			temp=temp->next; start=temp;
		}
	}
}


int main(){
	struct node *head=NULL;
	int i=1;
	appendNode(&head,i++);
	appendNode(&head,i++);
	appendNode(&head,i++);
	appendNode(&head,i++);
	appendNode(&head,i++);
	appendNode(&head,i++);
	appendNode(&head,i++);
	appendNode(&head,i++);
	appendNode(&head,i++);
	appendNode(&head,i++);
	appendNode(&head,i++);
	appendNode(&head,i++);
	printf("\nLinked List before Chunk reversal: \n");
	showList(head);
	int chunkSize=3;
	reverseAlternateChunk(&head, chunkSize);
	printf("\n\nLinked List after Chunk size %d reversal: \n", chunkSize);
	showList(head);		
	printf("\n");
	return 0;
}
