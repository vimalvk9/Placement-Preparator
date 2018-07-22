#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[],int size)
{
	int i,hole,value;

	for(i=1;i<size;i++)
	{
		value = arr[i];
		hole = i;

		while(hole > 0 && arr[hole-1] < value)
		{
			arr[hole] = arr[hole-1];
			hole = hole-1;
		} 
		arr[hole] = value;
	}

}

int main()
{
	int n,i;
	cin >> n;
	int arr[n];

	for(i=0;i<n;i++)
		cin >> arr[i];

	insertion_sort(arr,n);
	cout << "After sorting : ";
	for(i=0;i<n;i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}