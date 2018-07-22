#include <iostream>
#include <malloc.h>

using namespace std;

#define MAX 11

struct  queue
{
	int arr[MAX];
	int front, rear;
};		

void init(struct queue *q)
{
	q->front = q->rear = -1;
	int i;
	for(i=0;i<MAX;i++) q->arr[i] = 0;
}

void add(struct queue *q,int num)
{
	if(q->rear == MAX-1)
	{
		cout << "Queue Full\n";
		return;
	}
	

	if(q->front == -1)
	{
		q->front = q->rear = 0;
		q->arr[q->rear] = num;
		return;
	}

	++(q->rear);
	q->arr[q->rear] = num;
}

int del(struct queue *q)
{
	if(q->front == -1)
	{
		cout << "Queue is Empty\n";
		return NULL;
	}
	int data = (q->arr[q->front]);
	q->arr[q->front] = 0;
	
	if(q->front == q->rear)
		q->front = q->rear = -1;
	else
	++(q->front);

	return data;
}

void display(struct queue *q)
{
	int i;
	for(i=0;i<MAX;i++){
		if(q->arr[i] != 0)
		cout << q->arr[i] << " ";
	}
	cout << "\n";
}

int main()
{
	struct queue q;
	init(&q);
	add(&q,1);
	add(&q,2);
	add(&q,3);
	add(&q,4);
	display(&q);

	del(&q);
	del(&q);
	del(&q);
	del(&q);
	del(&q);
		
	display(&q);
	return 0;	
}