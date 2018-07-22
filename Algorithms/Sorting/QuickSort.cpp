#include <bits/stdc++.h>
using namespace std;

int split(int arr[],int lower,int higher)
{
	int p,q,pivot;
	int x = lower + rand()%(higher-lower);
	swap(arr[x],arr[lower]);
	pivot = arr[lower];

		p =	lower+1;
		q = higher;

	while(q >= p)
	{
		while( p <= higher && arr[p] < pivot )
			p++;
		
		while( q >= lower && arr[q] > pivot )
			q--;

		if(q > p)
			swap(arr[p],arr[q]);
	}		 
	swap(arr[lower],arr[q]);
	return q;
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