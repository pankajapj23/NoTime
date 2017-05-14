#include <stdio.h>
#include <stdlib.h>
 
struct node{
    int data;
    struct node* left, *right;
};

int childSum(struct node *root)
{
	if(!root) return 0;
	else if (!root->left && !root->right) return 1;
	else if (root->left && !root->right)
	{
		if(root->data == root->left->data)
		{
		    int temp = childSum(root->left);
			return temp;
		}
		else
			return 0;
	}
	else if(!root->left && root->right)
	{
		if(root->data == root->right->data)
		{
			int temp = childSum(root->right);
			return temp;
		}
		else
			return 0;
	}
	else //both child are not NULL
	{
		if(root->data == root->left->data + root->right->data)
		{
			int temp1 = childSum(root->left);
			int temp2 = childSum(root->right);
			return temp1&&temp2;
		}
		else
			return 0;
	}
}

struct node* newNode(int data){
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;  node->left = NULL;  node->right = NULL; 
  return node;
}

int main()
{
  struct node *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5); 
  root->left->right->left = newNode(4);
  root->left->right->right = newNode(1);
  root->right->left = newNode(2);
  root->right->right= newNode(0);

  if((!root->left && !root->right) && (root->data == 0))
    printf("InMain() - Children sum is equal to root data\n");
  else if((!root->left && !root->right) && (root->data != 0))
	printf("In Main() - Children sum is NOT equal to root data\n");	 
  else	  
  {
	int temp = childSum(root);
	(temp ?printf("Children sum is equal to root data\n"):
	  printf("Children sum is NOT equal to root data\n"));
  }
  
  printf("\n");
  return 0;
}