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

void pre(struct node *t)
{
	if(t != NULL)
	{
		cout << t->data << " ";
		pre(t->left);
		pre(t->right);
	}
}

void post(struct node *t)
{
	if(t != NULL)
	{
		post(t->left);
		post(t->right);
		cout << t->data << " ";
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

	cout << "Inorder -> ";
	in(tree);
	cout << "\n";

	cout << "Preorder -> ";
	pre(tree);
	cout << "\n";
	
	cout << "Postder -> ";
	post(tree);
	cout << "\n";
	
	return 0;
}