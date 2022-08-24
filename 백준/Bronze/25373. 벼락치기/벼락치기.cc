#include	<iostream>
#include	<algorithm>
using namespace std;

long long n, ans;

int main()
{
	cin >> n;
	long long l = 0;
	long long r = 10e17;
	while (l <= r)
	{
		ans = 0;
		long long m = (l + r) / 2;
		for (long long i = 0; i < 7; i++)
		{
			if (m - i > 0)
				ans += m - i;
		}
		if (ans >= n)
			r = m - 1;
		else
			l = m + 1;
	}
	cout << l << endl;
}