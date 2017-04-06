#include "main.h"

void append(struct node **head, int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	struct node *end= *head;
	temp->data =data; temp->next =NULL;
	if((*head) == NULL) *head = temp;
	else
	{
		while(end->next!=NULL) end = end->next;
		end->next = temp;
	}
}

int reverse(struct node **start)
{
	struct node *prev = NULL, *cur = *start, *next = *start;
	int sizeoflist =0;
    while (next!=NULL)
	{
		cur  = next;
		next = next->next;
		cur->next = prev;
		prev = cur;
		sizeoflist++;
	}
    *start = cur;
	return sizeoflist;
}

void subtractList(struct node **head1, struct node **head2)
{
	struct node *newlist=NULL; int carry=0;
	struct node *list1 = *head1, *list2 =*head2;
	int len_l1 = reverse(&list1);	
	int len_l2 = reverse(&list2);

	if(len_l1 < len_l2) //do this if list 1 length us lesser then list2
	{
		struct node *temp = list1;
		list1=list2;
		list2=temp;
	}

	if (len_l1==len_l2)
	{
		//Go till end of the list to find the first element as list is already reversed
		struct node *t1 = list1, *t2 = list2;	
		while(t1->next!=NULL)
		{
			t1=t1->next; t2=t2->next;
		}

		if(t1->data < t2->data)
		{
			struct node *temp = list1;
			list1=list2;
			list2=temp;
		}
	}

	while(list1 && list2)
	{
		if(list1->data > list2->data)
		{
			if(carry)
			{
				pushInFront(&newlist, ((list1->data)-1) - list2->data);
				carry=0; //reset
			}
			else
				pushInFront(&newlist, list1->data - list2->data);
		}
		else if (list1->data < list2->data)
		{
			if(carry)
			{
				pushInFront(&newlist, ((list1->data)-1+10) - list2->data);
			}
			else
			{
				pushInFront(&newlist, ((list1->data)+10) - list2->data);
				carry =1;
			}
		}
	   else
			pushInFront(&newlist, 0);

		list1=list1->next; list2=list2->next;

	}

	while(list1!=NULL)
	{
		if(carry){
			pushInFront(&newlist, (list1->data)-1); carry=0;
		}
		else
		pushInFront(&newlist, list1->data);
		list1=list1->next;
	}

	printf("\nSubtraction of list1 and list2: ");
	displayList(newlist);
}


int main()
{
	struct node *list1=NULL, *list2=NULL;
	append(&list1,3);
	append(&list1,8);
	append(&list1,7);
	//append(&list1,1);
	//append(&list1,0);

	append(&list2,4);
	append(&list2,8);
	append(&list2,7);
	append(&list2,7);
	printf("\nList1: ");
	displayList(list1);
	printf("\nList2: ");
	displayList(list2);

	subtractList(&list1, &list2);





	printf("\n");
	return 0;
}