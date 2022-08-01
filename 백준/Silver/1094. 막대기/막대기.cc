#include	<iostream>
using namespace std;

int main()
{
	int x, cnt;
	cnt = 0;
	cin >> x;
	while (x)
	{
		if (x % 2 == 1)
			cnt++;
		x /= 2;
	}
	cout << cnt << endl;
}