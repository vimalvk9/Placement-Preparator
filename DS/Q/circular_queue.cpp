#include <iostream>
#include <malloc.h>

using namespace std;

#define MAX 10

class queue
{
	private:	
		int arr[MAX];
		int front, rear; 
	public:
		queue();
		void add(int);
		int del();
		void display();
};

queue :: queue()
{
	int i;
	for(i=0;i<MAX;i++)	arr[i] = 0;
		front = rear = -1;
}

void queue :: add(int num)
{
	if((rear == MAX-1 && front == 0) || (rear+1 == front))
	{
		cout << "C_Queue full\n";
		return;
	}

	if(rear == MAX-1)
		rear = 0;
	else
		rear++;
	arr[rear] = num;
	if(front == -1)
		front = 0;
} 

int queue :: del()
{
	if(front == -1)
	{
		cout << "C_Queue empty\n";
		return NULL;
	}

	int item = arr[front];
	arr[front] = 0;

	if(front == rear)
		front = rear = -1;
	else
		front++;
	return item;
}

void queue :: display()
{
	int i;
	for(i=0;i<MAX;i++)
	{
		if(arr[i]!=0)
			cout << arr[i] << " ";
	}
	cout << "\n";
}

int main()
{
	queue q;
	q.add(1);
	q.add(2);
	q.add(3);
	q.add(4);
	q.add(4);
	q.add(4);
	q.display();

	q.del();
	q.del();

	q.display();
	return 0;
}