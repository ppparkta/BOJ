#include	<iostream>
#include	<algorithm>
#include	<vector>
using namespace std;

int main()
{
	int n, sub, m;
	double answer;
	vector<int> s;
	cin >> n;
	answer = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> sub;
		s.push_back(sub);
	}
	sort(s.begin(), s.end());
	m = s[n-1];
	for (int i = 0; i < n; i++)
	{
		answer += (double)s[i] / (double)m * (double)100;
	}
	answer /= n;
	cout << answer << endl;
	return 0;
}