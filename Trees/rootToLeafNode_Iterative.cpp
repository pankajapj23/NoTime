#include <stdio.h>
#include <stdlib.h>
 
struct node{
    int data;
    struct node* left, *right;
};

void printArray(int *A, int len)
{
	for(int i=0; i<len; i++)
		printf("%d ", ((struct node *)A[i])->data);
	printf("\n");
}

void rootToLeafPrint(struct node *root)
{
	int A[100]; int index=0;
	while(root!=NULL)
	{
		A[index++] = (int)root; //store the current node address in array
		if(root->left) root=root->left;
		else if(root->right) root=root->right;
		else //current node is a leaf node
		{
			printArray(A,index);
			index--;//move the index to last stored element
			while(index != -1) //array is empty
			{
				index=index-1; //Change the index to previous node to get the parent node
				if(index == -1) return;
				//Find the immediate parent node of current node
				struct node *parent = (struct node *)A[index];

				if(root == parent->left)
				{
					root=parent->right;
					index++; //move the index so that current node can be stored next empty location
					break;
				}
				else if(root == parent->right)
					root=parent;
			}
		}
	}
}

struct node* newNode(int data){
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL; 
  return node;
}

int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
  root->left->right->left = newNode(6);
  root->left->right->right = newNode(7);
  root->right->left = newNode(8);
  root->right->right= newNode(9);
  rootToLeafPrint(root);
  printf("\n");
  return 0;
}