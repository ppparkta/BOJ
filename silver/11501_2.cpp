#include	<iostream>
#include	<vector>
using namespace std;

int main()
{
	long long int T, N, current, max;
	vector<int>v;
	cin >> T;
	while (T--)
	{
		cin >> N;
		current = 0;
		for (int i = 0; i < N; i++)
		{
			int n;
			cin >> n;
			v.push_back(n);
		}
		max = -1;
		for (int i = N - 1; i >= 0; i--)
		{
			if (max < v[i])
				max = v[i];
			current += max - v[i];
		}
		v.clear();
		cout << current << '\n';
	}
	return 0;
}
