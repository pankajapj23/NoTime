#include "main.h"

struct stack {
	struct node *data;
	struct stack *next;
};

void push(struct stack **head, struct node *data)
{
	struct stack *newdata = (struct stack *)malloc(sizeof(struct stack));
	newdata->data = data;

	if((*head) == NULL)
	{	*head = newdata; newdata->next = NULL;
	}
	else
	{
		newdata->next= *head; *head = newdata;
	}
}

struct node* pop( struct stack **head)
{
	if((*head)==NULL) return NULL;
	struct stack *temp = *head;
	(*head) = (*head)->next;
	struct node *temp2= temp->data;
	free(temp);
	return temp2;
}


void palindrome(struct node *head)
{
	struct node *slow = head, *fast = head, *temp = head, *temp2, *temp3=head;
	struct stack *top =NULL; int startPop=0, odd=0, count=0;

	while(temp3){ temp3=temp3->next; count++;}
	if (count%2!=0) //length of list is odd   
	{ fast = head; odd=1; }
	else
		fast = head->next;
	
	//Find the mid position
	while(fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	//For ODD length fast ptr will not reach NULL while for even length fast pointer reaches NULL
	//if(fast!=NULL) odd=1;

	while(temp!=NULL)
	{
		if(temp!=slow->next && !startPop){
			push(&top, temp); temp=temp->next;}
		else if(!startPop){
			if(odd)	temp = slow; 
			startPop=1;}

		if(startPop)
		{
			temp2 = pop(&top);
			if(temp2!=NULL)
			{
				if(temp->data!= temp2->data)
				{
					printf("\nList is not Palindrome!!!\n");
					return;
				}
			}
			else
			{ startPop=0;}
			temp=temp->next;
		}
	}
	printf("\nList is Palindrome!!!\n");
}

int main()
{
	struct node *head=(struct node *)malloc(sizeof(struct node));
	head->data=1; head->next=NULL;
	pustAtEnd(head,2);
	pustAtEnd(head,2);
	//pustAtEnd(head,0);
	pustAtEnd(head,2);
	pustAtEnd(head,2);
	pustAtEnd(head,1);
	displayList(head);

	palindrome(head);

	return 0;
}