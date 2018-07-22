#include <iostream>
using namespace std;

void max_heapify(int arr[],int i,int N)
{
	int largest = i;
	int left 	= 2*i;
	int right 	= 2*i + 1;

	if(left <= N && arr[left] > arr[i])
		largest = left;
	else
		largest = i;

	if(right <= N && arr[right] > arr[largest])
		largest = right;

	if(largest != i)
	{
		swap(arr[i],arr[largest]);
		max_heapify(arr,largest,N);
	}		 
}

void build_maxheap(int arr[],int N)
{
	int i;
	for(i=N/2;i>=1;i--)
		max_heapify(arr,i,N);
}

int main()
{
	int arr[8] = {100000,1,4,3,7,8,9,10};
	build_maxheap(arr,8);

	int i;
	for(i=1;i<8;i++)
		cout << arr[i] << " ";
	cout << endl;		
}