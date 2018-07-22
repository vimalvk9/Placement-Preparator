#include <bits/stdc++.h>
using namespace std;

#include <stdio.h>
#include <malloc.h>
#define TRUE 1
#define FALSE 0
#define MAX 4

struct node
{
	int data;
	struct node *link;
};

int visited[MAX];

void dfs(int v,struct node **p)
{
	struct node *q;
	visited[v-1] = TRUE;

	cout << v << " ";
	q = *(p+v-1);

	while(q != NULL)
	{
		if(visited[q->data-1] == FALSE)
			dfs(q->data,p);
		else
			q = q->link;
	}
}

struct node * getnode_write(int value)
{
	struct node* n = (struct node *)malloc(sizeof(struct node));
	n->data = value;
	return n; 
} 

void del(struct node *n)
{
	struct node *temp;

	while(n != NULL)
	{
		temp = n->link;
		free(n);
		n = temp;
	}
}

int main()
{
	struct node * arr[MAX];
	struct node *v1, *v2, *v3, *v4;

	int i;
	
	v1 = getnode_write(2);
	arr[0] = v1;
	v1->link = v2 = getnode_write(3);
	v2->link = NULL;

	v1 = getnode_write(1);
	arr[1] = v1;
	v1->link = v2 = getnode_write(3);
	v2->link = v3 = getnode_write(4);
	v3->link = NULL;

	v1 = getnode_write(1);
	arr[2] = v1;
	v1->link = v2 = getnode_write(2);
	v2->link = NULL;

	v1 = getnode_write(2);
	arr[3] = v1;
	v1->link = NULL;


	dfs(4,arr);

	for(i=0;i<MAX;i++)
		del(arr[i]);

	return 0;	 
}

























