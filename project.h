#include<stdio.h>
#include<stdlib.h>
 
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
	int nodeheight;
}node;
 
node *insert(node *tree,int element);
node *Delete(node *tree,int element);
int search(node *tree,int element);
void preorder(node *tree);
void inorder(node *tree);
int height(node *tree);
node *rotateright(node *tree);
node *rotateleft(node *tree);
node *R(node *tree);
node *L(node *tree);
node *LR(node *tree);
node *RL(node *tree);
int balancefactor(node *tree);
