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

int countLeafNode(struct node *root)
{
	if(!root) return 0;
	
	if(!root->left && !root->right) return 1;
	int a = countLeafNode(root->left);
	int b = countLeafNode(root->right);
	return a + b;
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
	root->right->right = addNode(6);	
	root->right->left = addNode(8);
	//root->right->right->right->right = addNode(9);
	printf("\nBinary Tree: ");
	inorderTraversal(root);

	int a = countLeafNode(root);
	printf("\nNumber of leaf nodes are: %d", a);
	printf("\n");
	return 0;
}