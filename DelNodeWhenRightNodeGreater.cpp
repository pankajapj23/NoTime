#include "main.h"

struct node* findMax(struct node *start, struct node *end)
{
	struct node *temp=start, *max=start;
	while(temp!=end->next)
	{
		if(temp->data > max->data)
			max= temp;
		temp=temp->next;
	}
return max;
}

void deleteNodeRightGreater(struct node **head)
{
	struct node *start = *head, *end = *head, *maxNode = NULL;

	while(end->next!=NULL) end =end->next;

	while(start!=end)
	{
		maxNode = findMax(start, end);
		//If maximum node is last node in list then just print last node
		if (maxNode == end)
		{
			displayList(maxNode);
			return;
		}
		printf(" %d ", maxNode->data);
		start = maxNode->next;
	}
}


