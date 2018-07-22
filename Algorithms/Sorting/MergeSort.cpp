#include <bits/stdc++.h>
using namespace std;

void merge(int arr[],int l,int m,int r)
{
	int n1 = m-l+1;
	int n2 = r-m;
	int i,j,k;

	int L[n1],R[n2];

	for(i=0;i<n1;i++)
		L[i] = arr[i+l];

	for(j=0;j<n2;j++)
		R[j] = arr[m+j+1];

	i = j = 0;
	k = l;

	while(i<n1 && j<n2)
	{
		if(L[i] <= R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}

	while(i<n1) arr[k++] = L[i++];
	while(j<n2) arr[k++] = R[j++];

}

void merge_sort(int arr[],int l,int r)
{
	if(l < r)
	{
		int m = (l+r)/2;
		merge_sort(arr,l,m);
		merge_sort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}

int main()
{
	int arr[6] = {1,5,2,43,3234324,4343};
	merge_sort(arr,0,5);
	int i;

	for(i=0;i<6;i++)
		cout << arr[i] << " ";
	cout << "\n";
	return 0;
}
