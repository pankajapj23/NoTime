//Convert an arbitrary Binary Tree to a tree that holds Children Sum Property

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

int childSumUtil(struct node *root)
{
	int left=0, right=0, flag=0;

	if(root->left) left = root->left->data;
	if(root->right) right = root->right->data;

	int temp = root->data - (left+right);
	if(temp<1)
		root->data = root->data + abs(temp);
	else if(root->left)
	{
		flag =1; 
		root->left->data = root->left->data +temp;
	}
	else if(root->right)
	{
		flag =2; 
		root->right->data = root->right->data +temp;
	}
	return flag;
}
		   

void convertChildSumBT(struct node *root)
{
	if(!root) return;
    if(!root->left && !root->right) return;
    int flag=0;
	convertChildSumBT(root->left);
	convertChildSumBT(root->right);
	
	int left=0, right=0;
	if(root->left) left = root->left->data;
	if(root->right) right = root->right->data;

	//Update the tree when it does not hold childSum Property 
	if(root->data != left+right)
		flag = childSumUtil(root);

	//Again check the ChildSum property in left and right subtree flag value 1 means LEFT or
	//2 means RIGHT subtree need to be updated again to hold the child sum property
	if(flag==1) convertChildSumBT(root->left);	
	else if (flag==2) convertChildSumBT(root->right);
}


int main()
{
	struct node *root = addNode(50);
	root->left = addNode(7);
	root->right = addNode(2);
	root->left->left = addNode(3);
	root->left->right = addNode(5);
	root->right->left = addNode(1);
	root->right->right = addNode(30);

	root->left->left->left = addNode(2);
	root->left->left->right = addNode(5);
	
    printf("Binary Tree: ");
	inorder(root);

	convertChildSumBT(root);
	printf("\nBinary Tree after Child Sum Property: ");
	inorder(root);

    printf("\n\n");
	return 0;
}