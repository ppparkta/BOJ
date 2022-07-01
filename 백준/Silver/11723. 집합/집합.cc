#include	<iostream>
using namespace std;

int bit[21];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s == "add")
		{
			int x;
			cin >> x;
			if (bit[x] == 0)
				bit[x]++;
		}
		if (s == "remove")
		{
			int x;
			cin >> x;
			if (bit[x] == 1)
				bit[x]--;
		}
		if (s == "check")
		{
			int x;
			cin >> x;
			if (bit[x] == 1)
				cout << "1" << "\n";
			else
				cout << "0" << "\n";
		}
		if (s == "toggle")
		{
			int x;
			cin >> x;
			if (bit[x] == 1)
				bit[x] = 0;
			else
				bit[x] = 1;
		}
		if (s == "all")
		{
			for (int j = 0; j < 21; j++)
			{
				bit[j] = 1;
			}
		}
		if (s == "empty")
		{
			for (int j = 0; j < 21; j++)
			{
				bit[j] = 0;
			}
		}
	}
}