#include <iostream>
#include <malloc.h>

using namespace std;

struct node
{
	int data;
	struct node *link;
};

struct queue
{
	struct node *f;
	struct node *r;
};

struct node* get()
{
	struct node *t = (struct node *)malloc(sizeof(struct node));
	return t;
}

void init(struct queue *q)
{
	q->f = q->r = NULL;
}

void add(struct queue *q,int num)
{
	struct node *t = get();

	if(t == NULL)
	{
		cout << "Queue full\n";
		return;
	}

	t->data = num;
	t->link = NULL;

	if(q->f == NULL)
	{
		q->f = q->r = t;
		return;
	}

	q->r->link = t;
	q->r = q->r->link;

}

int del(struct queue *q)
{
	
	if(q->f == NULL)
	{
		cout << "Queue empty\n";
		return NULL;
	}

	int item = q->f->data;
	struct node *t = q->f;

	q->f = q->f->link;
	free(t);
	return item; 
}

void del_que(struct queue *q)
{
	struct node *t;
	
	if(q->f == NULL)
		return;
	while(q->f != NULL)
	{
		t = q->f;
		q->f = q->f->link;		
		free(t);

	}
}

int main()
{
	struct queue q;
	int i;

	init(&q);

	add(&q,1);
	add(&q,2);
	add(&q,3);
	add(&q,4);

	i = del(&q);
	if(i != NULL)
		cout << i << "\n";

	i = del(&q);
	if(i != NULL)
		cout << i << "\n";

    i = del(&q);
	if(i != NULL)
		cout << i << "\n";
	
	i = del(&q);
	if(i != NULL)
		cout << i << "\n";
	return 0;
}
