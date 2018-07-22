#include <iostream>
using namespace std;

struct stack
{
	int data;
	struct stack *link;
};

void del(struct stack **s)
{
	if(*s == NULL)
		return;
	struct stack *st;

	while(*s != NULL)
	{
		st = *s;
		free(st);
		*s = (*s)->link;
	}
}

void push(struct stack **s,int num)
{
	struct stack *t = (struct stack *)malloc(sizeof(struct stack));
	
	if(t == NULL)
	{
		cout << "Stack Full\n";
		return;
	}

	t->data = num;
	t->link = *s;
	*s = t;
}

int pop(struct stack **s)
{
	if(*s == NULL)
	{
		cout << "Stack Empty\n";
		return NULL;
	}

	struct stack *t = *s;
	*s = (*s)->link;
	int item = t->data;
	free(t);
	return item;
}



int main()
{
	struct stack *st;
	st = NULL;
	int i;

	push(&st,14);
	push(&st,-3);
	push(&st,18);
	push(&st,29);
	push(&st,31);
	push(&st,16);
	
	i = pop(&st);
	if( i != NULL )
		cout << "Item poped is " << i << "\n";	
	i = pop(&st);
	if( i != NULL )
		cout << "Item poped is " << i << "\n";	
	i = pop(&st);
	if( i != NULL )
		cout << "Item poped is " << i << "\n";	

	del(&st);
	return 0;
}