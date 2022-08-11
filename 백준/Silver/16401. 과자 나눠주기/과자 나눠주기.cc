#include	<iostream>
#include	<algorithm>
using namespace std;

const int maxe = 1e9;
int arr[1000001];
int	n, m, l, r, ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	l = 1;
	r = maxe;
	while (l <= r)
	{
		int cnt = 0;
		int mid = (l + r) / 2;
		for (int i = 0; i < n; i++)
		{
			int temp = arr[i];
			while (temp >= mid)
			{
				cnt++;
				temp -= mid;
			}
		}
		if (cnt >= m)
		{
			ans = max(ans, mid);
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	cout << ans << endl;
}