#include	<iostream>
using namespace std;

int main()
{
	int n, k, record, answer;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		record = answer = 0;
		cin >> s;
		k = 0;
		while (s[k])
		{
			if (s[k] == 'O')
				record += 1;
			else if (s[k] =='X')
				record = 0;
			answer += record;
			k++;
		}
		cout << answer << endl;
	}
	return 0;
}