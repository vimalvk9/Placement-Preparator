#include <iostream>
#include <malloc.h>

using namespace std;

#define MAX 10

class deque
{
	private:
		int	arr[MAX];
		int front , rear;
	public :
		 deque()
		{
			int i;
			for(i=0;i<MAX;i++)
				arr[i]=0;
			front = rear = -1;
		}
		
		void display()
		{
			int i;
			cout << "front ->";
			for(i=0;i<MAX;i++)
				cout << arr[i] << " ";
			cout << "<-rear" << "\n";
		}

		int count()
		{
			int i , ct = 0;
			for(i=0;i<MAX;i++)
			{
				if(arr[i])
					ct++;
			}
			return ct;
		}

		void addbeg(int item)
		{
			if(front == 0 && rear == MAX-1)
			{
				cout << "Deque Full\n";
				return ;
			}

			if(front == -1)
			{
				front = rear = 0;
				arr[front] = item;
				return; 
			}

			if(rear != MAX-1)
			{
				int c = count();
				int k = rear+1 , i;

				for(i=1;i<=c;i++)
				{
					arr[k] = arr[k-1];
					k--;
				}
				arr[k] = item;
				front = k;
				rear++;
			}
			else
			{
				front--;
				arr[front] = item;
			}
		}

		void addend(int item)
		{

			if(front == 0 && rear == MAX-1)
			{
				cout << "Deque Full\n";
				return ;
			}

			if(front == -1)
			{
				front = rear = 0;
				arr[front] = item;
				return; 
			}

			if(rear == MAX-1)
			{
				int k = front-1;
				int i;

				for(i=front-1;i<rear;i++)
				{
					k = i;
					if(k == MAX-1)
						arr[k] = 0;
					else
						arr[k] = arr[i+1];
				}
				rear--;
				front--;
			}
		rear++;
		arr[rear] = item;	
		}

		int delbeg()
		{
			if(front == -1)
			{
				cout << "Deque Empty\n";
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

		int delend()
		{
			if(front == -1)
			{
				cout << "Deque Empty\n";
				return NULL;
			}
			
			int item = arr[rear];
			arr[rear] = 0;
		
			if(front == rear)
				front = rear = -1;
			else
				rear--;

			return item;
		}

};

int main()
{
	deque d;

	d.addend(17);
	d.addbeg(10);
	d.addend(8);
	d.addbeg(-9);
	d.addend(13);
	d.addbeg(28);
	d.addend(14);
	d.addbeg(5);
	d.addend(25);
	d.addbeg(6);
	d.addend(21);
	d.addbeg(11);

	d.display();

	int n = d.count();
	cout << "Total elements -> " << n << "\n";

	int i = d.delbeg();
	cout << "\nItem extracted " << i << "\n";

	i = d.delbeg();
	cout << "\nItem extracted " << i << "\n";
	
	i = d.delbeg();
	cout << "\nItem extracted " << i << "\n";

	i = d.delbeg();
	cout << "\nItem extracted " << i << "\n";
	
    cout << "Elements in deque after deletion\n";
    d.display();

    d.addend(16);
    d.addend(7);


    cout << "Elements in deque after deletion\n";
    d.display();


    i = d.delend();
	cout << "\nItem extracted " << i << "\n";
	
    cout << "Elements in deque after deletion\n";
    d.display();

	 n = d.count();
	cout << "Total elements -> " << n << "\n";

	return 0;
}