#include	<iostream>
#include	<cmath>
#include	<queue>
using namespace std;

int n, x;
priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> q;

int main()
{
	cin >> n;
	while (n--)
	{
		cin >> x;
		if (x == 0)
		{
			if (!q.empty())
			{
				cout << q.top().second << "\n";
				q.pop();
			}
			else
				cout << 0 << "\n";
		}
		else
		{
			q.push({ abs(x),x });
		}
	}
}