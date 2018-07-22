#include <iostream>
#include <malloc.h>

using namespace std;

struct node
{
	char data;
	struct node *left , *right;
};

char a[]={'A','B','C','D','E','F','G','\0','\0','H','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};

struct node* build(int n)
{
	struct node *t = NULL;
	if(a[n] != '\0')
	{
		t = (struct node*)malloc(sizeof(struct node));
		t->left = build(2*n+1);
		t->data = a[n];
		t->right = build(2*n+2);
	}
	return t;

} 

void inorder(struct node *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}	
}

int main()
{
	struct node *root;
	
	root = build(0);
	inorder(root);
	cout << "\n";
	
	return 0;	
}