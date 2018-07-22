#include <bits/stdc++.h>
using namespace std;

void diceHelper(int dice,vector <int> &chosen)
{
	if(dice == 0)
	{
		// base case
		int i;
		for(i = 0;i < chosen.size();i++)
			cout << chosen[i];
		cout << endl;	 
	}
	else
	{
		for(int i = 1; i <= 6; i++)
		{
			chosen.push_back(i);
			diceHelper(dice-1,chosen);
			chosen.pop_back();
		}
	}
}

void diceRoll(int dice)
{
	vector <int> chosen;
	diceHelper(dice,chosen);
}

int main()
{
	diceRoll(2);
	return 0;
}

