#include	iostream
#include	vector
#include	algorithm
using namespace std;

bool bstrcmp(string n, string m)
{
	if (n.length() == m.length())
		return n  m;
	return n.length()  m.length();
}

int main()
{
	int n;
	string s;
	vectorstring vec;

	cin  n;
	for (int i = 0; i  n; i++)
	{
		cin  s;
		if (find(vec.begin(), vec.end(), s) == vec.end())
			vec.push_back(s);
	}
	sort(vec.begin(), vec.end(), bstrcmp);
	for (int i = 0; i  vec.size(); i++)
	{
		cout  vec[i]  'n';
	}
	return 0;
}