#include<stdio.h>
#include<stdlib.h>
#include "project.h"

node *insert(node *tree,int element)
{
	if(tree==NULL)
	{
		tree=(node*)malloc(sizeof(node));
		tree->data=element;
		tree->left=NULL;
		tree->right=NULL;
	}
	else
		if(element > tree->data)		
		{
			tree->right=insert(tree->right,element);
			if(balancefactor(tree)==-2)
				if(element>tree->right->data)
					tree=R(tree);
				else
					tree=RL(tree);
		}
		else
			if(element<tree->data)
			{
				tree->left=insert(tree->left,element);
				if(balancefactor(tree)==2)
					if(element < tree->left->data)
						tree=L(tree);
					else
						tree=LR(tree);
			}
		
		tree->nodeheight=height(tree);
		return tree;
}
 
node * Delete(node *tree,int element)
{
	node *p;
	
	if(tree==NULL)
	{
		return NULL;
	}
	else
		if(element > tree->data)		
		{
			tree->right=Delete(tree->right,element);
			if(balancefactor(tree)==2)
				if(balancefactor(tree->left)>=0)
					tree=L(tree);
				else
					tree=LR(tree);
		}
		else
			if(element<tree->data)
			{
				tree->left=Delete(tree->left,element);
				if(balancefactor(tree)==-2)	
					if(balancefactor(tree->right)<=0)
						tree=R(tree);
					else
						tree=RL(tree);
			}
			else
			{
				
				if(tree->right!=NULL)
				{	
					p=tree->right;
					
					while(p->left!= NULL)
						p=p->left;
					
					tree->data=p->data;
					tree->right=Delete(tree->right,p->data);
					
					if(balancefactor(tree)==2)
						if(balancefactor(tree->left)>=0)
							tree=L(tree);
						else
							tree=LR(tree);
				}
				else
					return tree->left;
			}
	tree->nodeheight=height(tree);
	return tree;
}

int search(node *tree,int element)
{
	if(tree!=NULL)
	{	
		if(tree->data==element)
		{
			return 1;
		}
		else if(tree->data <element)
		{
			return search(tree->right,element);
		}
		else if(tree->data >element)
		{
			return search(tree->left,element);
		}
	}	
	else
	{
		return -1;
	}
}

int height(node *tree)
{
	int leftheight,rightheight;
	if(tree==NULL)
		return 0;
	
	if(tree->left==NULL)
		leftheight=0;
	else
		leftheight=1+tree->left->nodeheight;
		
	if(tree->right==NULL)
		rightheight=0;
	else
		rightheight=1+tree->right->nodeheight;
	
	if(leftheight>rightheight)
		return leftheight;
	
	return rightheight;
}
 
node * rotateright(node *x)
{
	node *temp;
	temp=x->left;
	x->left=temp->right;
	temp->right=x;
	x->nodeheight=height(x);
	temp->nodeheight=height(temp);
	return temp;
}
 
node * rotateleft(node *x)
{
	node *temp;
	temp=x->right;
	x->right=temp->left;
	temp->left=x;
	x->nodeheight=height(x);
	temp->nodeheight=height(temp);
	return temp;
}
 
node * R(node *tree)
{
	tree=rotateleft(tree);
	return tree;
}
 
node * L(node *tree)
{
	tree=rotateright(tree);
	return tree;
}
 
node * LR(node *tree)
{
	tree->left=rotateleft(tree->left);
	tree=rotateright(tree);
	return tree;
}
 
node * RL(node *tree)
{
	tree->right=rotateright(tree->right);
	tree=rotateleft(tree);
	return tree;
}
 
int balancefactor(node *tree)
{
	int leftheight,rightheight;
	if(tree==NULL)
		return 0;
 
	if(tree->left==NULL)
		leftheight=0;
	else
		leftheight=1+tree->left->nodeheight;
 
	if(tree->right==NULL)
		rightheight=0;
	else
		rightheight=1+tree->right->nodeheight;
 
	return leftheight-rightheight;
}
 
void preorder(node *tree)
{
	if(tree!=NULL)
	{
		printf("%d ",tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}
}
 
void inorder(node *tree)
{
	if(tree!=NULL)
	{
		inorder(tree->left);
		printf("%d ",tree->data);
		inorder(tree->right);
	}
}
