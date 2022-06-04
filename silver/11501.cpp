#include	<iostream>
#include	<algorithm>
#include	<vector>
using namespace std;

int main()
{
	long long  n, m, l, j, i, k, max, cnt, current;
	j = i = 0;
	vector<int>v;
	cin >> n;
	while (j < n)
	{
		v.clear();
		cnt = current = 0;
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> l;
			v.push_back(l);
		}
		max = *max_element(v.begin(), v.end());
		while (i < m)
		{
			if (v[i] == max)
			{
				if (cnt != 0)
				{
					current = (cnt * v[i]) + current;
					cnt = 0;
					if (i != m - 1)
						max = *max_element(v.begin() + i + 1, v.end());
				}
				else
				{
					if (i != m - 1)
						max = *max_element(v.begin() + i + 1, v.end());
					continue;
				}
			}
			else
			{
				current = current - v[i];
				cnt++;
			}
			i++;
		}
		cout << current << '\n';
		j++;
	}
	return 0;
}