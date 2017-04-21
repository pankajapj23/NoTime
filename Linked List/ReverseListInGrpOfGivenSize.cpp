#include "main.h"

void reverse(struct node **start, struct node **end)
{
	struct node *prev = *end, *cur = *start, *next = *start;
    while (next!=(*end))
	{
		cur  = next;
		next = next->next;
		cur->next = prev;
		prev = cur;
	}
    *start = cur;
}

void reverseListMain(struct node **head)
{
	struct node *temp = *head, *start=NULL, *end =NULL, *prevEnd =NULL;
	int flag=1;

	start = temp;
	while (temp!=NULL)
	{
		//start = temp;
		if(temp->data != 1) 
			temp = temp->next;

		if(temp && temp->data ==1)
		{
			prevEnd = end; end = temp;
			reverse(&start, &end);
			if(flag) //do it only first time because head will change
			{
				*head = start;
				flag=0;
			}
			else
				prevEnd->next = start;
			start = end->next; //for next iteration
			temp=temp->next;
		}
	}
}

int main()
{
	struct node *head = (struct node *)malloc(sizeof(struct node));
	head->data = 1;
	head->next = NULL;
	pustAtEnd(head, 2);
	pustAtEnd(head, 3);
	pustAtEnd(head, 4);
	//pustAtEnd(head, 1);
	pustAtEnd(head, 5);
	pustAtEnd(head, 6);
	pustAtEnd(head, 7);
	//spustAtEnd(head, 1);
	pustAtEnd(head, 8);
	pustAtEnd(head, 1);
	printf("Input list:\n");
	displayList(head); //Print the linked list
	reverseListMain(&head);
	printf("Result list:\n");
	displayList(head); //Print the linked list


	return 0;
}