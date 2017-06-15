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

void doubleTree(struct node *root)
{
	if(!root) return;

	doubleTree(root->left);
	doubleTree(root->right);

	//Add a of copy of node in left subtree
	struct node *temp=root->left;
	root->left = addNode(root->data);
	root->left->left = temp;	
}


int main()
{
	struct node *root = addNode(1);
	root->left = addNode(2);
	root->right = addNode(3);
	root->left->left = addNode(4);
	root->left->right = addNode(5);
	root->right->left = addNode(6);
		
    printf("Binary Tree: ");
	inorder(root);

	printf("\nDouble Tree of above tree: ");
	doubleTree(root);
	inorder(root);

    printf("\n\n");
	return 0;
}