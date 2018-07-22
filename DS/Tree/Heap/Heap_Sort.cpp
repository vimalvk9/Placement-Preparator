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



void min_heapify(int arr[],int i,int N)
{
	int smallest = i;
	int left = 2*i;
	int right = 2*i + 1;

	if(left <= N && arr[left] < arr[i])
		smallest = left;
	else
		smallest = i;

	if(right <= N && arr[right] < arr[smallest])
		smallest = right;

	if(smallest != i)
	{
		swap(arr[i],arr[smallest]);
		min_heapify(arr,smallest,N);
	}
}

void build_minheap(int arr[],int N)
{
	int i;
	for(i=N/2;i>=1;i--)
		min_heapify(arr,i,N);
}

void Aheapsort(int arr[],int N)
{
	int heap_size = N;
	build_maxheap(arr,N);

	int i;
	for(i=N;i>=2;i--)
	{
		swap(arr[1],arr[i]);
		heap_size = heap_size - 1;
		max_heapify(arr,1,heap_size);
	}
}

void Dheapsort(int arr[],int N)
{
	int heap_size = N;
	build_minheap(arr,N);

	int i;
	for(i=N;i>=2;i--)
	{
		swap(arr[1],arr[i]);
		heap_size = heap_size - 1;
		min_heapify(arr,1,heap_size);
	}
}	

int main()
{
	int arr[8] = {100000,4,3,7,1,8,5,9};
	int i;
	// Descending
	  Dheapsort(arr,7);

	  
	  for(i=1;i<8;i++)
		cout << arr[i] << " ";
	  cout << endl;

	// Ascending
	  Aheapsort(arr,7);

	  for(i=1;i<8;i++)
	   	 cout << arr[i] << " ";
	  cout << endl; 

	  return 0;
}
