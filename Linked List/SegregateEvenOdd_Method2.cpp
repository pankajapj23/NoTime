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

void segregateEvenOdd_Method2(struct node *head){

	struct node *start = head, *evenList=NULL, *evenHead=NULL, *oddHead=NULL, *oddList=NULL;
	//Find if there any only even or only odd node present in list
	struct node *temp2=head, *end=NULL; int even=0, odd=0;
	while(temp2!=NULL){
		if(temp2->data%2 == 0) even=1;
		else odd=1;
		end=temp2;//this is find the end of list
		temp2=temp2->next;
	}
	//If List have only even or only odd then return list as it is
	if(even==0 || odd==0){
		printf("\nList contain only even or only odd hence no segregation required!!\n");
		displayList2(head);
		return;
	}

	struct node *prev=NULL, *newend=end;
	while(start!=end->next) //problem is when loop should end -Debug
	{
		if(start->data%2==0){
			prev=start;
			start=start->next;
		}
		if(start->data%2==1) //if data is odd
		{
			//If first element in the list is ODD then head needs to changed
			if(prev==NULL){
				head=start->next;
				start->next=prev;
				newend->next=start; newend=newend->next;
				start=head;
			}

			else{
			prev->next=start->next;
			newend->next = start; newend=newend->next;
			start->next=NULL;
			start=prev->next;
			}
		}
	}
	displayList2(head);
		
}


int main(){
	struct node *head=NULL;
	append(&head, 17);
	append(&head, 15);
	append(&head, 8);
//	append(&head, 12);
//	append(&head, 10);
	append(&head, 5);
	append(&head, 4);
	append(&head, 1);
	//append(&head, 7);
	append(&head, 6);

	displayList2(head);

	segregateEvenOdd_Method2(head);

	return 0;
}