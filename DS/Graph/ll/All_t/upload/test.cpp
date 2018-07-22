#include <bits/stdc++.h>
using namespace std;

int main()
{
	FILE *fp , *fpp; 
	string s;

   	fp = fopen("out04.txt","w");

	cin >> s;
	
	int i = 0 , ct = 0;
	for(i=0;i<s.length();i++)
	{
		if(isdigit(s[i]))
			ct += s[i]-'0';
	} 
	cout << ct << endl;
	
   	
	fprintf(fp,"%d\n",ct);

	fclose(fp);

}