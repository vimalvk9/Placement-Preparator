#include <iostream>
#include <string.h>

using namespace std;

#define MAX 5

struct data
{
	char job[MAX];
	int pr_n;
	int or_n;
};

class priority_queue
{
	private:
		struct data d[MAX];
		int front , rear;

	public:
		priority_queue()
		{
			front = rear = -1;
			int i;
			for(i=0;i<MAX;i++)
			{
				strcpy(d[i].job,"");
				d[i].pr_n = d[i].or_n = 0;
			}
		}
        void add(data dt)
        {
        	if(rear == MAX-1)
        		{
        			cout << "Queue is full\n";
        			return;
        		}
        	rear++;
        	d[rear] = dt;

        	if(front == -1)
        		front = 0;

        	int i , j;
        	data t;
        	
        	for(i=front;i<=rear;i++)
        	{
        		for(j=i+1;j<=rear;j++)
        		{
        			if(d[i].pr_n > d[j].pr_n){
        				swap(d[i],d[j]);
        			}
        			else
        			{
        				if(d[i].pr_n == d[j].pr_n)
        				{
        					if(d[i].or_n > d[i].or_n)
        						{
        							swap(d[i],d[j]);
        						}
        				}
        			}
        		
        			
        		}
        	}

        }

        data del()
        {
        	data t , x;
        	strcpy(t.job,"");
        	t.pr_n = 0;
        	t.or_n = 0;

        	if(front == -1)
        	{
        		cout << "Priority_queue is empty\n";
        		return x;
        	}
        	
        	x = d[front];
        	d[front] = t;
            
            if(front == rear)
            	front = rear = -1;
            else
            	front++;

        	return x;
        }	

};

int main()
{
	priority_queue q;
	data dt;

	cout << "Enter job name and priority" << endl;
	cout << "Lower the priority number,higher the priority" << endl;
	cout << "Job    Priority" << endl;

	int i , j = 0;
	for(i=0;i<MAX;i++)
	{
		cin >> dt.job >> dt.pr_n;
		dt.or_n = j++;
		q.add(dt);
	}
	cout << endl;

	cout << "Process jobs priority wise" << endl;
	cout << "Job    Priority" << endl;

	for(i=0;i<MAX;i++)
	{
		data temp = q.del();
		cout << temp.job << "    " << temp.pr_n << "\n";
	}	
	cout << endl;
	return 0;
}