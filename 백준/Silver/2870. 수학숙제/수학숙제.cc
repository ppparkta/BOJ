#include	<iostream>
#include	<vector>
#include	<algorithm>
using namespace std;

bool com(string a, string b)
{
	if (a.size() < b.size())
		return true;
	else if (a.size() == b.size()) 
	{
		if (a < b) return true;
	}
	return false;
}

int main()
{
	int n;
	string s;
	vector<string> v;
	vector<string> ans;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		string sub;
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] >= '0' && s[j] <= '9')
				sub += s[j];
			else
			{
				if (sub.size() > 0)
					v.push_back(sub);
				sub.clear();
			}
		}
		v.push_back(sub);
	}
	for (int i = 0; i < v.size(); i++)
	{
		int flag = 0;
		string ansstr;
		if (v[i] == "") continue;
		for (int j = 0; j < v[i].size(); j++) {
			if (flag == 0) {
				if (v[i][j] == '0') {
					continue;
					continue;
				}
				else {
					flag = 1;
					ansstr += v[i][j];
				}
			}
			else {
				ansstr += v[i][j];
			}
		}
		if (flag == 0) {
			if (ansstr.size() == 0) {
				char ch = '0';
				ansstr += ch;
				ans.push_back(ansstr);
				continue;
			}
		}
		ans.push_back(ansstr);
	}
	sort(ans.begin(), ans.end(), com);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
	cout << endl;
}