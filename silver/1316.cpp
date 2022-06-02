#include	<iostream>
using namespace std;

int main()
{
	int n, k, check, cnt;
	int arr[256];
	cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		k = 0;
		check = 0;
		while (k < 256)
		{
			arr[k] = 0;
			k++;
		}
		string s;
		cin >> s;
		arr[s[0]] = 1;
		for (int j = 1; j < s.size(); j++)
		{
			if (s[j - 1] == s[j])
				continue;
			else
			{
				if (arr[s[j]] == 0)
					arr[s[j]] = 1;
				else
				{
					check = 1;
					break;
				}
			}
		}
		if (check == 0)
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}