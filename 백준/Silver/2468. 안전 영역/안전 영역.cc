#include	<iostream>
#include	<cstring>
#include	<algorithm>
#include	<queue>
using namespace std;

int n, maxe, cnt, ans;
int graph[101][101];
bool visit[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(int x, int y, int d)
{
	visit[x][y] = true;
	queue<pair<int, int>>q;
	q.push({ x,y });
	while (!q.empty())
	{
		int sx = q.front().first;
		int sy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = sx + dx[i];
			int ny = sy + dy[i];
			if ((nx >= 0 && nx < n) && (ny >= 0 && ny < n) && visit[nx][ny] == false && graph[nx][ny] > d)
			{
				visit[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
			if (maxe < graph[i][j])
				maxe = graph[i][j];
		}
	}
	for (int i = 0; i < maxe; i++)
	{
		memset(visit, false, sizeof(visit));
		cnt = 0;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (graph[j][k] > i && visit[j][k] == false)
				{
					cnt++;
					bfs(j, k, i);
				}
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
}