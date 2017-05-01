#include <stdio.h>
#include <stdlib.h>

#define max(a,b) ((a>b)?a:b)

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

//Assumpation: Height of an empty tree is -1 and height of tree with one node is 0
int heightofTree(struct node *root)
{
	if(root==NULL) return -1;
	
	int leftHeight = heightofTree(root->left);
    int rightHeight = heightofTree(root->right);
	return max(leftHeight, rightHeight)+1;
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
	root->left->left->right = addNode(5);
	root->right->right = addNode(6);	
	root->right->right->right = addNode(8);
	root->right->right->right->right = addNode(9);
	printf("\nBinary Tree: ");
	inorderTraversal(root);

	int height=0;
	height = heightofTree(root);
	printf("\nHeight of Binary Tree: %d\n\n", height);
	return 0;
}