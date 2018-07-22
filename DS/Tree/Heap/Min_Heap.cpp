#include <iostream>
using namespace std;

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

void build_heap(int arr[],int N)
{
	int i;
	for(i=N/2;i>=1;i--)
		min_heapify(arr,i,N);
}

int main()
{
	int arr[9] = {-1,8,7,6,5,4,3,2,1}; 
	build_heap(arr,9);

	int i;
	for(i=1;i<9;i++)
		cout << arr[i] << " ";
	cout << "\n";
}