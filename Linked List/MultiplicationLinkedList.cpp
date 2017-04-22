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

struct node *addNode(int data){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = data; newnode->next=NULL;
	return newnode;
}

void reverseList(struct node **head){
	struct node *cur=NULL, *next=*head, *prev=NULL;
	while(next!=NULL){
		cur = next;
		next = next->next;
		cur->next = prev;
		prev = cur;
	}
	*head = cur; //update the head of list
}

void muliplyList(struct node *head1,struct node *head2){
	
	struct node *list1 = head1, *list2 = head2, *newhead=NULL, *newlist=NULL;
	int res=0, temp=0, carry1=0, carry2=0, count=0, flag=1, flag2=1,res2=0, temp2=0;
	//Reverse both the input list
	reverseList(&list1);
	reverseList(&list2);
	struct node *list1Start = list1;

	while(list2!=NULL)
	{
		if(list1!=NULL)
		{
			res = (list1->data * list2->data) + carry1;
			temp = res%10; carry1 = res/10;
			if(newhead==NULL)
			{ //do this first time to save the head of list
				newlist=addNode(temp);
				newhead=newlist;
			}
			else if(newhead!=NULL && flag)
			{
				newlist->next = addNode(temp);
				newlist=newlist->next;
			}
			else
			{
				if(newlist!=NULL && flag2)
				{
					res2 = newlist->data + temp + carry2;
					temp2 = res2%10 ; carry2= res2/10;
					newlist->data = temp2; 
					if(newlist->next!=NULL)
						newlist=newlist->next;
					else
						flag2=0;//when next node is NULL

				}
				else
				{
					res2 = temp + carry2;
					temp2 = res2%10 ; carry2= res/10;
					newlist->next = addNode(temp2);
					newlist=newlist->next;
					flag2=1;
				}
			}
		 list1=list1->next;
		}
		else
		{
			list1= list1Start;
			list2=list2->next;
			if(list2==NULL) break;
			newlist=newhead;
			flag=0; 
			count++; 
			int tempCnt = count;
			while(tempCnt--)
				newlist=newlist->next;
		}
	}

	if(carry1!=0)
		newlist->next=addNode(carry1);
	reverseList(&newhead);
	printf("\nMultiplication of List 1 and 2: \n");
	displayList(newhead);
}

int main()
{
	struct node *list1=NULL, *list2=NULL;
	addNodeAtEnd(&list1, 1);
	addNodeAtEnd(&list1, 2);
	addNodeAtEnd(&list1, 3);
	addNodeAtEnd(&list2, 1);
	addNodeAtEnd(&list2, 2);
	addNodeAtEnd(&list2, 4);
	addNodeAtEnd(&list1, 7);
	addNodeAtEnd(&list1, 8);
	addNodeAtEnd(&list1, 9);
	printf("\nList 1: ");
	displayList(list1);
	printf("\nList 2: ");
	displayList(list2);

	muliplyList(list1, list2);

	printf("\n");
	return 0;
}