#include <stdio.h>
#include <stdlib.h>

#define max(a,b) ((a>b)?a:b)

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

//A tree is height balanced tree if Left subtree or right subtree height difference is not
//greater than 1
int findHeightBalanceBT(struct node *root)
{
	if(!root) return 0;
	int left=0, right=0;

	if(root->left) left = findHeightBalanceBT(root->left);
	if(root->right) right = findHeightBalanceBT(root->right);
	
	if(left == -99 || right == -99)
		return -99;
	else if(abs(left-right) > 1) //to check if height balanced tree
		return -99;
	else return max(left, right)+1;
}

int main()
{
	int i=1;
	struct node *root = addNode(i++);
	root->left = addNode(i++);
	root->right = addNode(i++);
	root->left->left = addNode(i++);
	root->left->right = addNode(i++);
	root->left->left->left = addNode(i++);
	root->left->right->right = addNode(i++);
	root->right->right = addNode(i++);
	//root->left->right->right->right = addNode(i++);
	//root->right->right->right = addNode(i++);
	//root->right->right->right->right = addNode(i++);
	//root->right->right->right->right->right = addNode(i++);

	printf("Binary Tree: ");
	inorder(root);

	(findHeightBalanceBT(root) == -99)?
		printf("\n\nTree is not Height Balanced!!!"):
		printf("\n\nTree is Height Balanced!!!");

    printf("\n\n");
	return 0;
}