#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;
ll compute(ll n)  	 
{
	ll i,x;
	ll num,ct = 0;

	for(i=1;i<=n;i++)
	{
		num = i;
		x = num;

		// Forming the even-length palindrome
		while(x)
		{
			num = num*10 + x%10;
			x /= 10;  	
		}

		// Calculating digit sum
		x = num;
		while(x)
		{
			ct += x%10;
			x /= 10;
		}
		
	}
	return ct;
}

int main()
{

	FILE *fp , *fpp;
   	
   	fp = fopen("testcases.txt","w");
   	fpp = fopen("solutions.txt","w");

	ll l , r , i = 20;
	
	
    while(i--)
		{
			r = 1 + rand()%999999;
			l = 1 + rand()%r ;

			
			ll min_ = compute(l);
			ll max_ = compute(r);
			ll m  = max_ - min_ - 1;
   			ll MOD = min_ + rand()%m;
   			ll ans = (max_%MOD - min_%MOD + MOD)%MOD;

   			/*cout << "l -->"  << l << "\n";
   			cout << "r -->"  << r << "\n";
 			cout << "Modulus number  --> " << MOD << "\n";
			cout << "Answer --> " << (max_%MOD - min_%MOD + MOD)%MOD << "\n\n";*/

			fprintf (fp, "%lld %lld %lld\n\n",l,r,MOD);
			fprintf(fpp,"%lld\n",ans);
			

		}
		fclose(fp);
		fclose(fpp);
	
	return 0;
}
