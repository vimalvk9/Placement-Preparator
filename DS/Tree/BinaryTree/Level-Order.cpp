#include <iostream>
#include <malloc.h>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* getnode(int num)
{
	struct node* t = (struct node *)malloc(sizeof(struct node));
	t->data = num;
	t->left = NULL;
	t->right = NULL; 
	return t;
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

void printLevel(struct node *root,int level)
{
	if(root == NULL)
		return;
	if(level == 1)
		cout << root->data << " ";
	else
	{
		printLevel(root->left,level-1);
		printLevel(root->right,level-1);
	}			
}

void LevelOrder(struct node *root)
{
	int h = height(root);
	int i;
	for(i=1;i<=h;i++)
		printLevel(root,i);
}


int main()
{
	struct node *tree = NULL;
	tree = getnode(1);
	tree->left = getnode(2);
	tree->right = getnode(4);
	tree->left->left = getnode(3); 
	tree->left->right = getnode(5);

	 LevelOrder(tree);
	 cout << "\n";
	return 0;
}