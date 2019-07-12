#include<stdio.h>
#include<stdlib.h>
#include "project.h"

int main()
{
	node *root=NULL;
	int element,n,choice;
	
	do
	{
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: scanf("%d",&n);
				root=NULL;
				for(int i=0;i<n;i++)
				{
					scanf("%d",&element);
					root=insert(root,element);
				}
				break;
				
					
			case 2: scanf("%d",&element);
				root=Delete(root,element);
				break;
			
			case 3: preorder(root);
				printf("\n");
				inorder(root);
				printf("\n\n");
				break;	
			case 4: scanf("%d",&element);
				int s=search(root,element);
				printf("%d",s);
				printf("\n\n");
				break;
		}		
		
	}while(choice!=5);
	
	return 0;
}
