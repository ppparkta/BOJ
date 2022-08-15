#include	<iostream>
#include	<string>
using namespace std;

string arr[4] = { "`1234567890-=","QWERTYUIOP[]\\","ASDFGHJKL;\'","ZXCVBNM,./" };

int main()
{
	string s;
	while (getline(cin, s))
	{
		string ans = "";
		for (int i = 0; i < s.size(); i++)
		{
			bool swc = false;
			if (s[i] == ' ')
				cout << " ";
			else
			{
				for (int j = 0; j < 4; j++)
				{
					for (int k = 0; k < arr[j].size(); k++)
					{
						if (arr[j][k] == s[i])
						{
							cout << arr[j][k - 1];
							swc = true;
							break;
						}
					}
					if (swc)
						break;
				}
			}
		}
		cout << endl;
	}
}