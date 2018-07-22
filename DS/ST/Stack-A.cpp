#include <iostream>
using namespace std;

#define MAX 10

struct stack
{
	int arr[MAX];
	int	top;
};

void init(struct stack *s);
void push(struct stack *s,int num);
int pop(struct stack *s);


int main()
{
	struct stack s;
	int i;

	init(&s);

	push(&s,11);
	push(&s,23);
	push(&s,-8);
	push(&s,16);
	push(&s,27);
	push(&s,14);
	push(&s,20);
	push(&s,39);
	push(&s,2);
	push(&s,15);
	push(&s,7);

	i=pop(&s);

	if( i != NULL )
	{
		cout << "Item poped " << i << "\n";
	}

	i=pop(&s);

	if( i != NULL )
	{
		cout << "Item poped " << i << "\n";
	}

	i=pop(&s);

	if( i != NULL )
	{
		cout << "Item poped " << i << "\n";
	}

	return 0;
}

void init(struct stack *s)
{
	s->top = -1;
}

void push(struct stack *s,int num)
{
	if(s->top == MAX-1)
	{
		cout << "Stack Full\n";
		return;
	}

	(s->top)++;
	(s->arr[s->top]) = num;
}

int pop(struct stack *s)
{
	if(s->top == -1)
	{
		cout << "Stack Empty\n";
		return NULL;
	}

	int item = (s->arr[s->top]);
	--(s->top);
	return item;
}