#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node* left, *right;
};

void printArray(int *ints, int len)
{
  for (int i=0; i<len; i++) {
    printf("%d ", ints[i]);
  }
  printf("\n");
} 

void printPathsRecur(struct node* node, int path[], int pathLen) 
{
  if (node==NULL) return;
  path[pathLen] = node->data;
  pathLen++;
 
  if (node->left==NULL && node->right==NULL) 
  {
    printArray(path, pathLen);
  }
  else
  {
    printPathsRecur(node->left, path, pathLen);
    printPathsRecur(node->right, path, pathLen);
  }
}
 
struct node* newNode(int data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL; 
  return node;
}

void printPaths(struct node* node) 
{
  int path[100];
  printPathsRecur(node, path, 0);
}

int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
  root->left->right->left = newNode(6);
  root->left->right->right = newNode(7);
 
  /* Print all root-to-leaf paths of the input tree */
  printPaths(root);
  return 0;
}