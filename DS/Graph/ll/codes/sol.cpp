#include <iostream>
using namespace std;

typedef long long ll;

ll compute(ll n)
{
	ll i , ct = 0 , num , x;
	
	for(i=1;i<=n;i++)
	{
		num = x = i;
		
		// Forming Kanetkar number
		while(x)
		{
			num = num*10 + x%10;
			x /= 10; 
		}

		// Calculating digit sum
		while(num)
		{
			ct += num%10;
			num /= 10;
		}
	}

	return ct;
}

int main()
{
	ll l , r , c;
	cin >> l >> r >> c;

	ll a = compute(l);
	ll b = compute(r);

	/*cout << a%c << " " << b%c << "\n";*/
	cout << (b%c - a%c + c)%c << "\n";
	return 0;
}
