#include <stdio.h>
#include <stdlib.h>

struct node {
	int data; 
	struct node *left, *right;
};

struct node* addNode(int data)
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = data; 
	newnode->left = NULL; newnode->right=NULL;
	return newnode;
}

int sizeofTree(struct node *root)
{
	if(root==NULL) return 0;
	
	int sizeLeftTree = sizeofTree(root->left);
    int sizeRightTree = sizeofTree(root->right);
	return sizeLeftTree+sizeRightTree+1;
}

void inorderTraversal(struct node *root)
{
	if(root==NULL) return;
	inorderTraversal(root->left);
	printf(" %d ", root->data);
	inorderTraversal(root->right);
}

int main()
{
	struct node *root = addNode(1);
	root->left = addNode(2);
	root->right = addNode(3);
	root->left->left = addNode(4);
	root->left->right = addNode(5);
	printf("\nBinary Tree: ");
	inorderTraversal(root);

	int size=0;
	size = sizeofTree(root);
	printf("\nSize of Binary Tree: %d\n\n", size);
	return 0;
}