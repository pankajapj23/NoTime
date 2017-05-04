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

int findIdentical(struct node *root1, struct node *root2)
{
	if(!root1 && !root2) //If both trees are NULL
		return 1;
	else if(root1 && root2) //If both trees are not empty
	{ 
		if (root1->data != root2->data)
			return 0;
		else //root1 and root2 data are equal
			return (findIdentical(root1->left, root2->left) && findIdentical(root1->right,root2->right));
	}
	else
		return 0;	
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
	//Tree 1
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

	//Tree 2
	struct node *root1 = addNode(1);
	root1->left = addNode(2);
	root1->right = addNode(3);
	root1->left->left = addNode(4);
	root1->left->left->right = addNode(5);
	root1->right->right = addNode(6);	
	root1->right->right->right = addNode(8);
	root1->right->right->right->right = addNode(9);
	printf("\nBinary Tree: ");
	inorderTraversal(root1);

    //Check if Tree1 and Tree2 are identical
	(findIdentical(root, root1))?
		printf("\n\tResult - Both Trees are Identical!!!\n"):
		printf("\n\tResult - Trees are NOT Identical!!!\n");
	return 0;
}