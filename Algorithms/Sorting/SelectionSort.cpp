#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[],int size)
{
	int i,j;
	for(i=0;i<size-1;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(arr[i]<arr[j])
				swap(arr[i],arr[j]);
		}
	}	
}

int main()
{
	int n,i;
	cin >> n;
	int arr[n];

	for(i=0;i<n;i++)
		cin >> arr[i];

	selection_sort(arr,n);

	cout << "After sorting : ";

	for(i=0;i<n;i++)
		cout << arr[i] << " ";
	cout << "\n";
	return 0;
}