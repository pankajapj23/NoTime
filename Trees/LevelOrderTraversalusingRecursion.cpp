#include <stdio.h>
#include <stdlib.h>

#define max(a,b) ((a>b)?a:b)

struct node 
{
	int data;
	struct node *left, *right;
};

struct node* addNode(int data)
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = data; newnode->left=NULL; newnode->right =NULL;
	return newnode;
}

//Assumption height of an empty tree is 0
int height(struct node *root)
{
	if(root==NULL) return 0;
	int a = height(root->left);
	int b = height(root->right);
	return max(a,b)+1;
}

void printAtGivenLevel(struct node *root, int level)
{
	if(!root) return;
	if(level==1) 
		printf(" %d ",root->data);
	else //if level is greater than 1
	{
		printAtGivenLevel(root->left, level-1);
		printAtGivenLevel(root->right, level-1);
	}
}


void levelOrderRecursive(struct node  *root)
{
	int i=1;
	while(i<=height(root))
		printAtGivenLevel(root, i++);
}

int main()
{
	struct node *root=NULL;
	root = addNode(1);
	root->left = addNode(2);
	root->right = addNode(3);
	root->left->left = addNode(4);
	root->left->right = addNode(5);
	root->right->left = addNode(6);
	root->right->right = addNode(7);
	root->right->right->left = addNode(8);
	printf("\nLevel Order Traversal using recursion: ");
	levelOrderRecursive(root);	
	printf("\n");
	return 0;
}
