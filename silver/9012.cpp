#include	<iostream>
#include	<string>
#include	<vector>
using namespace std;

int main()
{
	int n;
	int sw = 0;
	string s;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		vector<char>v;
		for (int k = 0; k < s.length(); k++)
		{
			if (s[k] == '(')
				v.push_back(s[k]);
			else if(s[k]==')')
			{
				if (v.empty())
					sw = 1;
				else
					v.pop_back();
			}
		}
		if (!(v.empty()) || sw == 1)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
		sw = 0;
		v.clear();
	}
	return 0;
}