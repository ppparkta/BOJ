//코드 참조해서 다시 짰음. 다시 풀기
#include	<iostream>
#include	<string>
using namespace std;

int main()
{
	int n, m, cnt;
	cin >> n;
	m = 666;
	string t = "666";
	cnt = 0;
	while (1)
	{
		string s = to_string(m);
		for (int i = 0; i < s.size() - 2; i++)
		{
			if (s[i] == '6' && s[i + 1] == '6' && s[i + 2] == '6')
			{
				cnt++;
				if (cnt == n)
				{
					cout << m << endl;
					return 0;
				}
				break;
			}
		}
		m++;
	}
}