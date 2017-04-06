#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct tree{
	int data;
	struct tree *left;
	struct tree *right;
};

struct tree* addNode(int data)
{
	struct tree *newnode = (struct tree *)malloc(sizeof(struct tree));
	newnode->data = data;
	newnode->left = newnode->right = NULL;
	return newnode;
}

void InOrderTraversal(struct tree *root)
{
	if (root == NULL) return;
	InOrderTraversal(root->left);
	printf(" %d ", root->data);
	InOrderTraversal(root->right);	
}

int BSTUtil(struct tree *node, int min, int max)
{
	if (node == NULL) return 1;
	
	if((node->data >min && node->data <max) &&
	   BSTUtil(node->left,min,node->data) &&
	   BSTUtil(node->right,node->data,max))
	return 1;
	else
	return 0;
}

int isBST(struct tree *root)
{
	return BSTUtil(root, INT_MIN, INT_MAX);
}


int main(void){
	struct tree *root = NULL;
	root = addNode(10);
	root->left = addNode(8);
	root->right = addNode (11);
	root->left->right = addNode (14);
	
	InOrderTraversal(root);
	
	int x= isBST(root);
	
	if(x) printf("\nBST");
	else printf("\nNo BST");
	return 0;
}