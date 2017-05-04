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

void deleteTree(struct node **root)
{
	if((*root)==NULL) return;	
	deleteTree(&(*root)->left);
	deleteTree(&(*root)->right);
	free(*root);
	*root=NULL;	
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

	deleteTree(&root);
	(!root)?printf("\nBinary Tree: DELETED\n"): printf("\nBinary Tree: ");
	inorderTraversal(root);

	
	return 0;
}