#include <bits/stdc++.h>
using namespace std;

// Finding root of an element
int root(int arr[],int i)
{
	while(arr[i] != i)
		i = arr[i];

	return i;
}

void Union(int arr[],int a,int b)
{
	int r_a = root(arr,a);
	int r_b = root(arr,b);

	arr[r_a] = r_b;
}

bool find(int arr[],int a,int b)
{
	return (root(arr,a) == root(arr,b));
}


int main()
{
	return 0;
}