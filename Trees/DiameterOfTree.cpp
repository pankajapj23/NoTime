//The diameter of a tree T is the largest of the following quantities:
// - the diameter of T’s left subtree
// - the diameter of T’s right subtree
// - the longest path between leaves that goes through the root of T 

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

int height(struct node *root)
{
    if(!root) return 0;
	int left = height(root->left);
	int right = height(root->right);
	return max(left,right)+1;
}

int diameter_Opt(struct node *root, int *height)
{
	int leftHt=0, rightHt=0; 
	if(!root) return 0;

	int dL = diameter_Opt(root->left, &leftHt);
	int dR = diameter_Opt(root->right, &rightHt);
    *height = max(leftHt, rightHt)+1;
    return max(leftHt+rightHt+1, max(dL,dR));
}

int diameter(struct node *root)
{
	if(!root) return 0;
	
	int leftHt = height(root->left);
	int rightHt = height(root->right);
	
	int dL = diameter(root->left);
	int dR = diameter(root->right);
    
    return max(leftHt+rightHt+1, max(dL,dR));
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
	root->left->right->right->right = addNode(i++);
	root->right->right = addNode(i++);
	root->right->right->right = addNode(i++);
	root->right->right->right->right = addNode(i++);
	root->right->right->right->right->right = addNode(i++);

	printf("Binary Tree: ");
	inorder(root);
    int a=0;

	printf("\n\nHeight of above Binary Tree is %d", height(root));
	printf("\n\nDiameter of above Binary Tree is %d", diameter(root));
	printf("\n\nDiameter_OPT of above Binary Tree is %d", diameter_Opt(root, &a));

    printf("\n\n");
	return 0;
}








