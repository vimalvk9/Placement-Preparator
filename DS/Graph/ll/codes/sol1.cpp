#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int i = 0 , ct = 0;
	for(i=0;i<s.size();i++)
	{
		if(isdigit(s[i]))
			ct += s[i]-'0';
	} 
	cout << ct << endl;
}