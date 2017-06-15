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

void widthTree(struct node *root)
{
	if(!root) return;
	struct queue *front=NULL, *rear =NULL;
    int width=0, newWidth=0, index=0,prevWidth=0;

	enqueue(root,&front, &rear); width++;
	while(front && index<width) //until queue is not empty and index is less than width
	{
		if(front->data->left)
		{
			enqueue(front->data->left, &front, &rear); 
			newWidth++;
		}

		if(front->data->right)
		{
			enqueue(front->data->right, &front, &rear); 
			newWidth++;
		}
		index++;
		dequeue(&front,&rear);
		if(newWidth > width) 
		{
			prevWidth = width;
			width = newWidth;
		}

		if(index==prevWidth)
		{
			index=0; newWidth=0;
		}
		prevWidth = width;
	}
	printf("\nWidth of Above BT: %d", width);
}

void widthTree_Improved(struct node *root)
{
	if(!root) return;
	struct queue *front=NULL, *rear =NULL;
    int width=0;
	enqueue(root,&front, &rear); width++;
	while(front) //until queue is not empty
	{
		int index=0, newWidth=0;
		while(front && index<width)
		{
			if(front->data->left)
			{
				enqueue(front->data->left, &front, &rear); 
				newWidth++;
			}

			if(front->data->right)
			{
				enqueue(front->data->right, &front, &rear); 
				newWidth++;
			}
			index++;
			dequeue(&front,&rear);
		}

		if(newWidth > width) 
			width = newWidth;
		
	}
	printf("\nImproved -Width of Above BT: %d\n", width);
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
	root->right->right->right = addNode(i++);

	root->left->left->left = addNode(i++);
	root->left->left->right = addNode(i++);
	root->left->right->right = addNode(i++);

	root->right->right->right->right = addNode(i++);

	printf("\nBinary Tree: ");
	inorder(root);

	widthTree(root);
	widthTree_Improved(root);

	printf("\n\n");
	return 0;
}
