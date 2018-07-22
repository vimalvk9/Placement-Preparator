#include <bits/stdc++.h>
using namespace std;

bool Find(int arr[],int a,int b)
{
	return (arr[a] == arr[b]);
}

void Union(int arr[],int n,int a,int b)
{
	int t = arr[a];
	int i;

	for(i=0;i<n;i++)
		if(arr[i] == t)
			arr[i] = arr[b];	
}

int main()
{
	int n;
	cin >> n;

	int i,arr[n];
	for(i=0;i<n;i++) arr[i]=i;	
}