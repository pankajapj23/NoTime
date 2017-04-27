#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
 int data;
 struct node *left;
 struct node *right;
}tree;

struct Queue 
{
	tree* data;
	struct Queue *next;
};

void enqueue(struct Queue **front, struct Queue **rear, tree *data)
{
	struct Queue *temp = *front;

	struct Queue *newnode = (struct Queue *)malloc(sizeof(struct Queue));
	newnode->data = data;
	newnode->next = NULL;
	if (temp == NULL)
	{
		*front = newnode;
		*rear = newnode;
		return;
	}
	else
	{
		(*rear)->next = newnode;
		*rear = newnode;
	}
}

void dequeue(struct Queue **front)
{
	struct Queue *temp = *front;
  
	if(temp==NULL) return; //Queue is already empty

	*front = (*front)->next;
	free(temp);
}

void levelOrder(tree *root)
{
	//Queue declaration
	struct Queue *front = NULL, *rear = NULL;
	if (root==NULL) return; //Empty tree
    enqueue(&front, &rear, root);
	while (front!=NULL) //Queue is not empty
	{
		printf(" %d ", front->data->data);
		if (front->data->left!= NULL) enqueue(&front, &rear,front->data->left);
		if (front->data->right!= NULL) enqueue (&front, &rear, front->data->right);
		dequeue(&front);
	}
}

tree* addNode(int data)
{
	tree *newdata= (tree *)malloc(sizeof(tree));
	newdata->data= data; 
	newdata->left=NULL;
	newdata->right =NULL;
	return newdata;
}

int main()
{
	tree *root=NULL;

	root = addNode(1);
	root->left = addNode(2);
	root->right = addNode(3);
	root->left->left = addNode(4);
	root->left->right = addNode(5);
	root->right->left = addNode(6);
	root->right->right = addNode(7);
	root->right->right->left = addNode(8);

	printf("\nLevel Order of Traversal of tree: ");
	levelOrder(root);	
	printf("\n");
	return 0;
}