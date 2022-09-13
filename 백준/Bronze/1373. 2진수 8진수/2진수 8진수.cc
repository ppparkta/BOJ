#include	<iostream>
#include	<string>
#include	<cmath>
using namespace std;

string s, s2;

int main()
{
	cin >> s;
	while (s.length() % 3 != 0)
	{
		s = '0' + s;
	}
	for (int i = 0; i < s.length(); i += 3)
	{
		int tmp = 0;
		for (int j = i; j < i + 3; j++)
		{
			tmp += (s[j] - '0') * pow(2, 2 - (j % 3));
		}
		s2 += tmp + '0';
	}
	cout << s2 << endl;
}