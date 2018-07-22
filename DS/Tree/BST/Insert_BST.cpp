#include <iostream>
#include <malloc.h>

using namespace std;

struct node
{
	int data;
	struct node *left,*right;
};

void inorder(struct node *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

void insert(struct node **root,int num)
{

	if(*root == NULL)
	{
		*root = (struct node*)malloc(sizeof(struct node));
		(*root)->data = num;
		(*root)->left = (*root)->right = NULL;
		return;
	}
	else
	{
		if(num < (*root)->data)
			insert(&((*root)->left),num);
		else
			insert(&((*root)->right),num);
	}
}

int main()
{
	struct node *tree = NULL;
	
	insert(&tree,10);
	insert(&tree,5);
	insert(&tree,25);
	insert(&tree,30);
	insert(&tree,12);
	insert(&tree,1);

	inorder(tree);
	cout << "\n";
	return 0;
}