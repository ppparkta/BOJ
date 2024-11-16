#include <iostream>
using namespace std;

int r, c, k, ans;
string map[6];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool visited[6][6] = {false};

void go(int x, int y, int dist)
{
	if (x == c - 1 && y == 0 && dist == k)
	{
		ans++;
		return;
	}
	if (dist >= k)
	{
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int sx = x + dx[i];
		int sy = y + dy[i];
		if (sx < 0 || sx >= c || sy < 0 || sy >= r)
			continue;
		if (map[sy][sx] == 'T' || visited[sy][sx])
			continue;
		visited[sy][sx] = true;
		go(sx, sy, dist + 1);
		visited[sy][sx] = false;
	}
}

int main()
{
	cin >> r >> c >> k;
	for (int i = 0; i < r; i++)
	{
		cin >> map[i];
	}
	visited[r - 1][0] = true;
	go(0, r - 1, 1);
	cout << ans << endl;
	return 0;
}