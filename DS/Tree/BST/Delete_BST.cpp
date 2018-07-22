#include <iostream>
#include <malloc.h>

using namespace std;

struct node
{
	int data;
	struct node *left , *right;
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

void search(struct node **root,int num,struct node **par,struct node **x,bool *found)
{
	struct node *q;
	q = *root;
	*found = false;
	*par = NULL;

	while(q != NULL)
	{
		if(q->data == num)
		{
			*found = true;
			*x = q;
			return;
		}

		*par = q;

		if(num < q->data)
			q = q->left;
		else
			q = q->right;
	}

}

void del(struct node **root,int num)
{
	bool found;
	struct node *par , *x , * xsucc;

	if( *root == NULL)
	{
		cout << "Tree is empty\n";
		return;
	}

	par = x = NULL;
	search(root,num,&par,&x,&found);

	if(found == false)
		{
			cout << "Data to be deleted not found\n";
			return;
		}	

	// Node with 2 children	

	if(x->left != NULL && x->right != NULL)
	{
		par = x;
		xsucc = x->right;

		while(xsucc->left != NULL)
		{
			par = xsucc;
			xsucc = xsucc->left;
		}

		x->data = xsucc->data;
		x = xsucc;
		// cout << "data :" <<  x->data << "\n";
		// cout << "left : " << (x->left) << "\n";
		// cout << "right : " << (x->right) << "\n";  
	}


	// Node with 0 children
	
	if(x->left == NULL && x->right == NULL)
	{
		if(par->right == x)
			 par->right = NULL;
		else
			par->left = NULL;
		free(x);
		return;		
	}	

	// Node with right child

	if(x->left == NULL && x->right != NULL)
	{
		if(par->left == x)
			par->left = x->right;
		else
			par->right = x->right;
			free(x);
			return;	 
	}

	// Node with left child
	if(x->left != NULL && x->right == NULL)
	{
		if(par->left == x)
			par->left = x->left;
		else
			par->right = x->left;
		free(x);
		return;
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


int main()
{
	struct node *tree;
	tree = NULL; 

	int n;
	char x;

	do
	{	
		scanf("%d%c",&n,&x);
		insert(&tree,n);

	}while(x != '\n');

	cout << "Before deletion\n";

	in(tree);
	cout << "\n";

	cout << "After deletion\n";
	del(&tree,8);
	in(tree);
	cout << "\n";

	// cout << "After deletion\n";
	// del(&tree,14);
	// in(tree);
	// cout << "\n";

	// cout << "After deletion\n";
	// del(&tree,8);
	// in(tree);
	// cout << "\n";

	cout << "After deletion\n";
	del(&tree,17);
	in(tree);
	cout << "\n";

}