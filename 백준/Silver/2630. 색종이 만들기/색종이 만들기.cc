#include	<iostream>
using namespace std;

int arr[129][129];
int n;
int b = 0;
int w = 0;

void dfs(int x, int y, int leng)
{
	bool blue, white;
	blue = white = true;
	if (leng == 1)
	{
		if (arr[x][y] == 1)
			b++;
		else
			w++;
		return;
	}
	for (int i = x; i < x + leng; i++)
	{
		for (int j = y; j < y + leng; j++)
		{
			if (arr[i][j] == 1)
				white = false;
			if (arr[i][j] == 0)
				blue = false;
		}
	}
	if (white == true)
	{
		w++;
		//cout << "하얀색이 추가됨" << endl;
		return;
	}
	if (blue == true)
	{
		b++;
		//cout << "파란색이 추가됨" << endl;
		return;
	}
	int i = leng / 2;
	dfs(x, y, i);
	dfs(x, y + i, i);
	dfs(x + i, y, i);
	dfs(x + i, y + i, i);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}
	dfs(0, 0, n);
	cout << w << "\n" << b << "\n";
	return 0;
}