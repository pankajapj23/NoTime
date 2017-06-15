#include <stdio.h>
#include <stdlib.h>

#define max(a,b) ((a>b)?a:b)

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
//Note: If given node present at more than one level in tree then farthest level will be returned
int nodeAtKdist_Rec(struct node *root, int givenData, int level)
{
  if(!root) return 0;
  if(root->data == givenData) return level;

  int left = nodeAtKdist_Rec(root->left,givenData,level+1);
  int right = nodeAtKdist_Rec(root->right,givenData, level+1);
  return max(left, right);
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

//Iterative Solution
//Note: If given node present at more than one level in tree then farthest level will be returned
int nodeAtKdist_Iter(struct node *root, int givenData, int level)
{
	if(!root) return 0;
    if(root->data == givenData) 
		return level;

	struct queue *front=NULL, *rear=NULL;
	enqueue(root, &front, &rear);
	int i=1;
	while(front) //Run until queue is not empty
	{
		level++; //increment the level as node is node found at previous level
		int size = queueSize(front, rear), j=1;

		while(j++ <=size)
		{
			if(front->data->left)
			{
				if(front->data->left->data != givenData) 
					enqueue(front->data->left, &front, &rear);
				else
					return level;
			}
							
			if(front->data->right)
			{
				if(front->data->right->data != givenData) 
					enqueue(front->data->right, &front, &rear);
				else 
					return level;
			}
			dequeue(&front, &rear);
		}
	}
	//If control comes here that means node not found in tree
	if(!front) return 0; 
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
    int data = 9;

	int level1 = nodeAtKdist_Rec(root,data,1); //level will passed as 1
	printf("\nRecursive - Level of Node %d in Given Tree: %d",data,level1);

	int level2 = nodeAtKdist_Iter(root,data,1); //level will passed as 1
    printf("\nIterative - Level of Node %d in Given Tree: %d",data, level2);
		
	printf("\n\n");
	return 0;
}
