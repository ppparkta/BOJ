#include	<iostream>
#include	<cmath>
using namespace std;

int main()
{
	int n, cnt, result;
	while (1) {
		cnt = 0;
		cin >> n;
		if (n == 0)
			break;
		for (int i = n + 1; i <= n * 2; i++)
		{
			result = sqrt(i);
			if (result == 1 && i != 1)
			{
				cnt++;
				continue;
			}
			if (i % 2 != 0)
			{
				for (int j = 2; j <= result; j++)
				{
					if (i % j == 0)
						break;
					if (j == result)
						cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}