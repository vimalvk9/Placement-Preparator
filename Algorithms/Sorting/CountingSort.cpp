#include <bits/stdc++.h>
using namespace std;

void counting_sort(int arr[],int n)
{
	int ma = -1;
	int i;

	for(i=0;i<n;i++)
		ma = max(ma,arr[i]);

	int aux[ma+1]; 

	for(i=0;i<=ma;i++)
		aux[i]=0;

	for(i=0;i<n;i++)
		aux[arr[i]]++;

	int j = 0;
	for(i=0;i<=ma;i++)
	{
		int t = aux[i];
		while(t--)
		{
			arr[j] = i;
			j++;
		}
	}
}	

int main()
{
	int arr[5] = {12032,323,323,21,1};
	counting_sort(arr,5);

	cout << "After sorting :";
	int i;
	for(i=0;i<5;i++)
		cout << arr[i] << " ";
	cout << "\n";
}