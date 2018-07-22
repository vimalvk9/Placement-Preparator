#include <bits/stdc++.h>
using namespace std;

int bub_sort(int arr[],int n)
{
	int i,j;

	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(arr[j] < arr[j+1])
				swap(arr[j],arr[j+1]);
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

	bub_sort(arr,n);
	
	cout << "After sorting:";
	for(i=0;i<n;i++)
		cout << arr[i] << " ";
	cout << endl;			
}