#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left, *right;
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

int rootToLeafPath(struct node *root, int givenNumber)
{
	if(!root) return 0;
	
	givenNumber = givenNumber-root->data;

	if(!root->left && !root->right)
	{
		if(!givenNumber) 
		{
			printf("\nGiven Number IS EQUAL to sum of node in root to leaf path\n\n");	
			exit(1); //terminate the program when sum is equal to given number
		}
		else 
			return 0;
	}
	else
	{
       rootToLeafPath(root->left, givenNumber);
	   rootToLeafPath(root->right, givenNumber);
	}
}


int main()
{
	struct node *root = addNode(10);
	root->left = addNode(20);
	root->right = addNode(30);
	root->left->left = addNode(40);
	root->left->right = addNode(50);
	root->right->left = addNode(60);
		
    printf("Binary Tree: ");
	inorder(root);

	if(!rootToLeafPath(root,110))
		printf("\nGiven Number is NOT equal to sum of node in root to leaf path");

    printf("\n\n");
	return 0;
}