#include	<iostream>
#include	<string>
using namespace std;

int main()
{
	string s;
	int i = 0;
	int k, idx, max, cnt;
	int alpha[256];

	while (i < 256)
	{
		alpha[i] = 0;
		i++;
	}
	i = 0;
	cin >> s;
	while (s[i] != 0)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] -= 32;
		}
		k = s[i];
		alpha[k]++;
		i++;
	}
	/*for (int j = 0; j < 256; j++)
	{
		if (alpha[j] != 0)
			cout << (char)j << " " << alpha[j] << endl;
	}*/
	idx = 0;
	max = 0;
	for (int j = 0; j < 256; j++)
	{
		if (max < alpha[j])
		{
			max = alpha[j];
			idx = j;
		}
	}
	cnt = 0;
	for (int j = 0; j < 256; j++)
	{
		if (max == alpha[j])
			cnt++;
	}
	if (cnt > 1)
		cout << "?" << endl;
	else
		cout << (char)idx << endl;
	return 0;
}