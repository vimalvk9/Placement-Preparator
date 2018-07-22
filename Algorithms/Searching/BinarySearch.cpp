#include <bits/stdc++.h>
using namespace std;

int bs(int arr[],int l,int r,int x)
{
	if(r >= l)
	{
		int m = l + (r-l)/2;

		if(x == arr[m])
			return m;

		if(x > arr[m])
			return bs(arr,m+1,r,x);
		else
			if(x < arr[m])
				return bs(arr,l,m-1,x); 
	}
	return -1;
}

int main()
{
	int arr[5] = {1,2,3,4,5};
	int ans = bs(arr,0,4,9);

	if(ans != -1)
		cout << "Element found at index " << ans+1 << "\n";
	else
		cout << "Element not found\n";
}
