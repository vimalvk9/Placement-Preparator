#include <bits/stdc++.h>
using namespace std;


void permuteHelper(string s,string chosen)
{
	// Base Case
	if(s.empty())
		cout << chosen << "\n";
	else
	{
		for(int i=0;i<s.size();i++)
		{
			char c = s[i];
			chosen += c;
			s.erase(i,1);

			permuteHelper(s,chosen);

			s.insert(i,1,c);
			chosen.erase(chosen.size()-1,1);
		}
	}
}

void permute(string s)
{
	string chosen = "";
	permuteHelper(s,chosen);
}

int main()
{
	int t;
	string s;

	cin >> t;
	while(t--)
	{
		cin >> s;
		sort(s.begin(),s.end());
		permute(s);
	}
}