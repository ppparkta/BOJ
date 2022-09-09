#include	<iostream>
using namespace std;

int n, a, ans;
int arr[1001];
int dp[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for(int j=0;j<i;j++)
		{
			if (arr[j] < arr[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		if (dp[i] > ans)
			ans = dp[i];
	}
	cout << ans << endl;
}