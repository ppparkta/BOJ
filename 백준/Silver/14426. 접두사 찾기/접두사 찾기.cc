#include	<iostream>
#include	<algorithm>
#include	<vector>
#include	<string>
using namespace std;

int n, m, l, r, ans;
string s, ns;
vector<string>v;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++)
	{
		cin >> ns;
		l = 0;
		r = n - 1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (ns < v[mid])
				r = mid - 1;
			else if (ns > v[mid])
				l = mid + 1;
			if (v[mid].substr(0, ns.length()) == ns)
			{
				ans++;
				break;
			}
		}
	}
	cout << ans << endl;
}