#include	<iostream>
#include	<algorithm>
#include	<queue>
using namespace std;

int n, m, k, ans, temp;
int graph[102][102];
bool visit[102][102];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int bfs(int y, int x)
{
	int cnt = 0;
	visit[y][x] = true;
	queue<pair<int, int>>q;
	q.push({ y,x });
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if ((nx >= 1 && nx <= m) && (ny >= 1 && ny <= n) && visit[ny][nx] == false && graph[ny][nx] == 1)
			{
				visit[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
	}
	return (cnt);
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (graph[i][j] == 1 && visit[i][j] == false)
			{
				temp = bfs(i, j);
				ans = max(ans, temp);
			}
		}
	}
	cout << ans << endl;
}