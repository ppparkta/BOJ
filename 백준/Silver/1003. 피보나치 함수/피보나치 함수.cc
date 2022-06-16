#include	<iostream>
using namespace std;

int dp_zero[41];
int dp_one[41];

int main()
{
	dp_zero[0] = 1;
	dp_one[0] = 0;
	dp_zero[1] = 0;
	dp_one[1] = 1;
	int t, n;
	cin >> t;
	for (int i = 2; i <= 40; i++)
	{
		dp_zero[i] = dp_zero[i - 1] + dp_zero[i - 2];
		dp_one[i] = dp_one[i - 1] + dp_one[i - 2];
	}
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cout << dp_zero[n] << " " << dp_one[n] << "\n";
	}
	return 0;
}