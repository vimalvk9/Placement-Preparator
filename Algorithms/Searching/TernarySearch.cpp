#include <bits/stdc++.h>
using namespace std;

int ternary_search(int arr[],int l,int r,int x)
{
	if(r >= l)
	{	
		int mid1 = l + (r-l)/3;
		int mid2 = r - (r-l)/3;

		if(x == arr[mid1])
			return mid1;

		if(x == arr[mid2])
			return mid2;

		if(x < arr[mid1])
			return ternary_search(arr,l,mid1-1,x);
		else
		{
			if(x > arr[mid2])
				return ternary_search(arr,mid2+1,r,x);
			else
				return ternary_search(arr,mid1+1,mid2-1,x);	 
		}			 
	}

	return -1;
}

int main() 
{
	int arr[5] = {1,2,3,4,5};
	int ans = ternary_search(arr,0,4,15);

	if(ans != -1)
		cout << "Found at " << ans << " \n";
	else
		cout << "Not found\n";
}