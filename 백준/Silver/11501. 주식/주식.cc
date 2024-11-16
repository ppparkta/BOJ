#include <iostream>
using namespace std;

int t, n;

int arr[1000001];

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;

		for (int j = 0; j < n; j++)
		{
			cin >> arr[j];
		}
		long tmp = 0;
		long ans = 0;
		for (int j = n - 1; j >= 0; j--)
		{
			if (arr[j] > tmp)
			{
				tmp = arr[j];
			}
			else
				ans += tmp - arr[j];
		}
		cout << ans << endl;
	}
	return 0;
}