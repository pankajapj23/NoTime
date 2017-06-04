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

int checkSumEqualToNumber(int givenNumber, int *a, int index)
{
	int temp=0,i=0;
	for(i=0; i<index; i++)
		temp=temp+a[i];
	if(temp==givenNumber) return 1;
	else return 0;
}

int rootToLeafPath(struct node *root, int givenNumber, int *a, int index)
{
	if(!root) return 0;
	//Add the node in array
	a[index]= root->data;
	index++;
	if(!root->left && !root->right)
	{
		if(checkSumEqualToNumber(givenNumber, a, index)) 
		{
			printf("\nGiven Number IS EQUAL to sum of node in root to leaf path\n\n");	
			exit(1); //terminate the program when sum is equal to given number
		}
		else 
			return 0;
	}
	else
	{
       rootToLeafPath(root->left, givenNumber, a, index);
	   rootToLeafPath(root->right, givenNumber, a, index);
	}
}


int main()
{
	struct node *root = addNode(10);
	root->left = addNode(20);
	root->right = addNode(30);
	root->left->left = addNode(40);
	root->left->right = addNode(50);
	root->right->left = addNode(60);
	root->right->right = addNode(70);
    root->left->left->left = addNode(80);
    root->left->left->right = addNode(90);
	
    printf("Binary Tree: ");
	inorder(root);

	int A[100];
	if(!rootToLeafPath(root,160,A,0))
		printf("\nGiven Number is NOT equal to sum of node in root to leaf path");

    printf("\n\n");
	return 0;
}