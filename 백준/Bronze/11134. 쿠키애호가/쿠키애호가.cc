#include	<iostream>
using namespace std;

int main()
{
	int t, n, c, cnt;
	cin >> t;
	while (t--)
	{
		cin >> n >> c;
		if (n % c == 0)
			cnt = n / c;
		else
			cnt = n / c + 1;
		cout << cnt << endl;
	}
}