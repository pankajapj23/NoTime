#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left, *right;
};

struct queue{
	struct node *data;
	struct queue *next;
};

struct node* addNode(int data){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data= data; newnode->left = NULL; newnode->right = NULL;
	return newnode;
}

void inorder(struct node *root){
	if(!root) return;
	inorder(root->left);
    printf(" %d ", root->data);
	inorder(root->right);
}

void enqueue(struct node *root, struct queue **front, struct queue **rear)
{
    struct queue *newnode = (struct queue *)malloc(sizeof(struct queue));
	newnode->data = root; newnode->next = NULL;

	if(!(*front) &&  !(*rear)) //if Queue is empty
	 (*front)=(*rear)=newnode;
	else
	{
		(*rear)->next = newnode;
		*rear = newnode;
	}
}

void dequeue(struct queue **front,struct queue **rear)
{
	if((*front) == (*rear)) *rear=NULL; //make sure to rear pointer does not point to unallocated memory
	struct queue *temp = *front;
	(*front) = (*front)->next;
	free(temp);
	temp=NULL;
}

//Recursive Solution
void nodeAtKdist_Rec(struct node *root, int k)
{
  if(!root) return;
  if(k==0){
	  if(root) //to check if root is not NULL
		  printf(" %d ",root->data);
	  return;
  }
  else{
	  nodeAtKdist_Rec(root->left,k-1);
	  nodeAtKdist_Rec(root->right, k-1);
  }
}

int queueSize(struct queue *front, struct queue *rear)
{
    if(!front) return 0; //if queue is empty	
	int size=1;
	struct queue *temp = front;
	while(temp!=rear)
	{
		size++;
		temp=temp->next;
	}
	return size;
}

void printQueue(struct queue *front, struct queue *rear)
{
	if(!front) return;
	while(front != rear)
	{
		printf(" %d ", front->data->data);
		front=front->next;
	}
	printf(" %d ", front->data->data);
}

//Iterative Solution
void nodeAtKdist_Iter(struct node *root, int k)
{
	if(!root) return;
    if(k==0)
	{
	  printf(" %d ",root->data);
	  return;
	}
	struct queue *front=NULL, *rear=NULL;
	enqueue(root, &front, &rear);
	int i=1;
	while(i++ <=k)
	{
		int size = queueSize(front, rear), j=1;
		while(j++ <=size)
		{
			if(front->data->left) enqueue(front->data->left, &front, &rear);
			if(front->data->right) enqueue(front->data->right, &front, &rear);
			dequeue(&front, &rear);
		}
	}
    
	printQueue(front, rear); //print the data present in queue
}
    
			
 
int main()
{
	int i=1;
	struct node *root=addNode(i++);
	root->left = addNode(i++);
	root->right = addNode(i++);
	root->left->left = addNode(i++);
	root->left->right = addNode(i++);
	root->right->right = addNode(i++);
	root->right->right->left = addNode(i++);
	root->right->right->left->right = addNode(i++);

	printf("\nBinary Tree: ");
	inorder(root);
    int k = 5;

	printf("\nRecursive - Nodes at distance %d from root: ",k);
	nodeAtKdist_Rec(root,k);
    printf("\nIterative - Nodes at distance %d from root: ",k);
	nodeAtKdist_Iter(root,k);
	
	printf("\n\n");
	return 0;
}
