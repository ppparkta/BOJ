#include <iostream>
#include <unordered_map>
using namespace std;

char arr[5][5];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
unordered_map<string, int> ans;

void dfs(int y, int x, string s)
{
	s += arr[y][x];
	if (s.length() == 6)
	{
		ans[s] = 1;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if ((0 <= nx && nx < 5) && (0 <= ny && ny < 5))
			dfs(ny, nx, s);
	}
}

int main()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> arr[i][j];

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			dfs(i, j, "");
	cout << ans.size()<< endl;
}