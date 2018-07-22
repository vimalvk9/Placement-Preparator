#include <bits/stdc++.h>
using namespace std;

int root(int arr[],int i)
{
	while(arr[i] != i)
	{
		arr[i] = arr[arr[i]];
		i = arr[i];
	}	

	return i;
}

void Find(int arr[],int a,int b)
{
	return (root(arr,a) == root(arr,b));
}

void Union(int arr[],int a,int b)
{
	int r_a = root(arr,a);
	int r_b = root(arr,b);

	if(size[r_a] < size[r_b])
	{
		r_a = r_b;
		size[r_b] += size[r_a];
	}	
	else
	{
		r_b = r_a;
		size[r_a] += size[r_b];
	}
}

int main()
{
	return 0;
}