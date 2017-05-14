#include <stdio.h>
#include <stdlib.h>
 
struct node{
    int data;
    struct node* left, *right;
};

struct queue{
	struct node *element;
	struct queue *next;
};

void enqueue(struct queue **front, struct queue **rear, struct node *data)
{
	struct queue *newnode = (struct queue *)malloc(sizeof(struct queue));
	newnode->element = data; newnode->next=NULL;
	if(!(*front) && !(*rear)) //if queue is empty
	{
		*front = newnode; *rear = newnode;
	}
	else  //add element at the end of queue
	{
		(*rear)->next = newnode;
		*rear = newnode;
	}
}

struct node* dequeue(struct queue **front)
{
	struct queue *temp = *front;
	*front = (*front)->next;
    struct node *temp1 = temp->element;
	free(temp);
	return(temp1);
}


void childSum(struct node *root)
{
	if(!root) return;
	struct queue *front = NULL, *rear =NULL;
	enqueue(&front, &rear, root);
	while(front) //until queue is not empty
	{
		int leftdata=0,rightdata=0;
		if(root->left && root->right)
		{
			if(root->left)
			{
				enqueue(&front, &rear, root->left);
				leftdata=root->left->data;
			}
			if(root->right)
			{
				enqueue(&front, &rear, root->right);
				rightdata=root->right->data;
			}
			if(root->data != leftdata+rightdata)
			{
				printf("\nChildren sum is NOT equal to Root\n");
				return;
			}
		}
		root = dequeue(&front);
	}
	printf("\nChildren sum is equals to Root\n");
}

struct node* newNode(int data){
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;  node->left = NULL;  node->right = NULL; 
  return node;
}

int main()
{
  struct node *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5); 
  root->left->right->left = newNode(4);
  root->left->right->right = newNode(1);
  root->right->left = newNode(2);
  root->right->right= newNode(0);

  if((!root->left && !root->right) && (root->data == 0))
    printf("InMain() - Children sum is equal to root data\n");
  else if((!root->left && !root->right) && (root->data != 0))
	printf("In Main() - Children sum is NOT equal to root data\n");	 
  else	  
    childSum(root);
  
  printf("\n");
  return 0;
}