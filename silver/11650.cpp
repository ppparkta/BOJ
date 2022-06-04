#include	<iostream>
#include	<utility>
#include	<vector>
#include	<algorithm>
using namespace std;

int main()
{
	int N,a,b;
	cin >> N;
	vector<pair<int, int>>v;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back(pair<int, int>(a, b));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++)
	{
		cout << v[i].first << " " << v[i].second << "\n";
	}
	return 0;
}