#include <iostream>
#include <malloc.h>
#include <stdio.h>

using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

void insert(struct node **root,int num)
{
	if(*root == NULL)
	{
		(*root) =(struct node *)malloc(sizeof(struct node));
		(*root)->left = (*root)->right = NULL;
		(*root)->data = num;
	}
	else
	{
		if(num < (*root)->data)
			insert(&((*root)->left),num);
		else
			if(num > (*root)->data)
			insert(&((*root)->right),num);	
	}
}

void in(struct node *root)
{
	if(root != NULL)
	{
		in(root->left);
		cout << root->data << " ";
		in(root->right);
	}
}

void pre(struct node *root)
{
	if(root != NULL)
	{
		cout << root->data << " ";
		pre(root->left);
		pre(root->right);
	}
}

void pos(struct node *root)
{
	if(root != NULL)
	{
		pos(root->left);
		pos(root->right);
		cout << root->data << " ";
	}
}

int main()
{
	struct node *tree = NULL;
	int x;
	char ch;

	cout <<	"Enter numbers for BST :\n";

	do
	{
		scanf("%d%c",&x,&ch);
		insert(&tree,x);

	}while(ch != '\n');

	cout << "\n";

	cout << "Inorder -> ";
		in(tree);
	cout << "\n";
	
	cout << "Preorder ->";
		pre(tree);
	cout << "\n";
	
	cout << "Postorder ->";
		pos(tree);
	cout << "\n";
	
	return 0;			
}