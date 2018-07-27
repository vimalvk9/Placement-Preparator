#include <bits/stdc++.h>
using namespace std;

int EggDrop(int floors,int eggs)
{
	int floorEgg[floors+1][eggs+1];
	int res;
	int i,j,x;

	for(i=1;i<=floors;i++){
		floorEgg[i][0] = 0;
		floorEgg[i][1] = i;
	}

	for(j=1;j<=eggs;j++)
		floorEgg[1][j] = 1;

	for(i=2;i<=floors;i++)
	{
		for(j=2;j<=eggs;j++)
		{
			floorEgg[i][j] = INT_MAX;
			for(x=1;x<=i;x++)
			{
				res = 1+max(floorEgg[i-x][j],floorEgg[x-1][j-1]);
				if (res < floorEgg[i][j])
					floorEgg[i][j] = res; 
			}
		}
	}

	return floorEgg[floors][eggs];
}

int main()
{
	int n,k;
	n = 10;
	k = 2;

	cout << EggDrop(n,k) << "\n";
	return 0;
}