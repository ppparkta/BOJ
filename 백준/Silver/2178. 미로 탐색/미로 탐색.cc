#include	<iostream>
#include	<queue>
using namespace std;

int n, m, cnt, ans;
string temp[101];
int graph[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs(int x, int y)
{
	queue<pair<int, int>>q;
	q.push({ x,y });
	graph[x][y] = 1;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if ((nx >= 0 && nx < n) && (ny >= 0 && ny < m) && graph[nx][ny] == 0 && temp[nx][ny] == '1')
			{
				q.push({ nx,ny });
				graph[nx][ny] = graph[x][y] + 1;
			}
		}
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> temp[i];
	}
	bfs(0, 0);
	cout << graph[n - 1][m - 1];
}