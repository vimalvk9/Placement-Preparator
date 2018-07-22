#include <bits/stdc++.h>
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

int maximum(int arr[])
{
	return arr[1];
}

int extract_maximum(int arr[],int n)
{
 	if(n == 0)
 		return -1;

 	int m = arr[1];
 	arr[1] = arr[n];
 	n = n-1;
 	max_heapify(arr,1,n);
 	return m; 
}

void increase_val(int arr[],int i,int val)
{
	if(val < arr[i])
		return;

	arr[i] = val;

	while(i > 1 && arr[i/2] < arr[i])
	{
		swap(arr[i/2],arr[i]);
		i /= 2;
	}
}

int insert(int arr[],int val,int n)
{
	n += 1;
	arr[n] = -1;
	increase_val(arr,val,n);
}


int main()
{
	int arr[6] = {1000000,4,8,1,7,3};
	build_maxheap(arr,5);

	cout << maximum(arr) << "\n";
	extract_maximum(arr,5);
	cout << maximum(arr) << "\n";
}	