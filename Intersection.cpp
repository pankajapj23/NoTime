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

struct node* createNode(int data)
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node *));
	newnode->data = data; newnode->next=NULL; return newnode;
}

void displayList(struct node *head)
{
	if(head==NULL) return;
	
	while(head!=NULL)
	{
		printf(" %d ", head->data);
		head=head->next;
	}
	printf("\n");
}

void intersection(struct node *list1, struct node *list2)
{
	struct node *newlist=NULL, *newhead=NULL;
	while(list1 && list2){
		if(list1->data == list2->data)
		{
			if(newhead==NULL) {
				newlist = createNode(list1->data);
				newhead = newlist;
			}
			else {
				newlist->next = createNode(list1->data);
				newlist=newlist->next;
			}
			list1=list1->next; list2=list2->next;

		}

		else if(list1->data < list2->data)
			list1=list1->next;
		else
			list2=list2->next;
	}

	printf("\nIntersection of list: ");
	displayList(newhead);
}

int main()
{
	struct node *list1=NULL, *list2=NULL;
	addNodeAtEnd(&list2, 1);
	addNodeAtEnd(&list2, 2);
	addNodeAtEnd(&list2, 3);
	addNodeAtEnd(&list2, 4);
	addNodeAtEnd(&list2, 5);
	addNodeAtEnd(&list2, 6);

	addNodeAtEnd(&list1, 2);
	addNodeAtEnd(&list1, 4);
	addNodeAtEnd(&list1, 5);
	displayList(list1);
	displayList(list2);
	
	intersection(list1, list2);
	return 0;
}