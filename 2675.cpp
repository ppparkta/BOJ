#include	<iostream>
using namespace std;

int main()
{
	string s;
	int t, r, k;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> r >> s;
		k = 0;
		while (s[k])
		{
			for (int j = 0; j < r; j++)
			{
				cout << s[k];
			}
			k++;
		}
		cout << endl;
	}
	return 0;
}