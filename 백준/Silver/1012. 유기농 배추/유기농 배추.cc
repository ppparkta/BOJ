#include	<iostream>
#include	<cstring>
#include	<queue>
using namespace std;

int t, m, n, k, x, y, cnt;
int graph[51][51];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool visit[51][51];

void bfs(int y, int x)
{
	queue<pair<int, int>>q;
	visit[y][x] = true;
	q.push({ x,y });
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if ((nx >= 0 && nx < m) && (ny >= 0 && ny < n) && graph[ny][nx] == 1 && visit[ny][nx] == false)
			{
				visit[ny][nx] = true;
				q.push({ nx,ny });
			}
		}
	}
}

int main()
{
	cin >> t;
	while (t--)
	{
		memset(graph, 0, sizeof(graph));
		memset(visit, false, sizeof(visit));
		cin >> m >> n >> k;
		cnt = 0;
		for (int i = 0; i < k; i++)
		{
			cin >> x >> y;
			graph[y][x] = 1;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (graph[i][j] == 1 && visit[i][j] == false)
				{
					bfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
}