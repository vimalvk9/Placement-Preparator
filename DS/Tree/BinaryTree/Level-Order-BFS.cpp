#include <iostream>
#include <malloc.h>
#include <queue>
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

void bfs(struct node *root)
{
	queue <struct node *> q;
	q.push(root);

	while(!q.empty())
	{
		struct node *x = q.front();
		int u = (q.front())->data;
		cout << u << " ";
		q.pop();

		if(x->left)
			q.push(x->left);
		if(x->right)
			q.push(x->right);	
	}
}

int main()
{
	struct node *tree = NULL;
	tree = getnode(1);
	tree->left = getnode(2);
	tree->right = getnode(4);
	tree->left->left = getnode(3); 
	tree->left->right = getnode(5);

	bfs(tree);
	cout << "\n";
	return 0;
}