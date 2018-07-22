#include <iostream>
#include <malloc.h>

using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right; 
};

struct node* getnode(int num)
{
	struct node *t = (struct node *)malloc(sizeof(struct node));
	t->data = num;
	t->left = t->right = NULL;
	return t; 
}

void in(struct node *t)
{	
	if(t != NULL)
	{
		in(t->left);
		cout << t->data << " ";
		in(t->right);
	}
}

int height(struct node *t)
{
	if(t == NULL)
		return 0;
	else
	{
		int l = height(t->left);
		int r = height(t->right);

		return max(l,r)+1;
	}
}




int main()
{

	struct node* tree;
	tree = NULL;

	tree = getnode(1);
	tree->left = getnode(2);
	tree->right = getnode(4);
	tree->left->left = getnode(3); 
	tree->left->right = getnode(5);
	tree->left->right->left = getnode(6);

	cout << "Inorder -> ";
	in(tree);
	cout << "\n";

	cout << "Height -> " << height(tree) << "\n";
}