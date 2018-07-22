#include <bits/stdc++.h>
using namespace std;

int split(int arr[],int lower,int higher)
{
	int pivot = arr[higher];
	int i = lower-1;
	int j;

	for(j=lower; j<=higher-1; j++)
	{
		if(arr[j] >= pivot)
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[higher]);
	return i+1;
}

void qsort(int arr[],int lower,int higher)
{
	if(higher > lower)
	{
		int i = split(arr,lower,higher);
		qsort(arr,lower,i-1);
		qsort(arr,i+1,higher);
	}
}

int main()
{
	int t,n,i;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int arr[n];
		for(i=0;i<n;i++)
			cin >> arr[i];
		
		qsort(arr,0,n-1);

		for(i=0;i<n;i++)
			cout << arr[i] << " ";
		cout << endl;
	}
}