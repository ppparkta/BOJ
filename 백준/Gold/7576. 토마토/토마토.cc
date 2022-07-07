#include	<iostream>
#include	<deque>
using namespace std;

int n, m;
int graph[1001][1001];
int xs[4] = { 0,0,1,-1 };
int ys[4] = { 1,-1,0,0 };
deque<pair<int, int>> q;

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + xs[i];
			int ny = y + ys[i];
			if (nx >= 1 && ny >= 1 && nx <= n && ny <= m)
			{
				if (graph[nx][ny] == 0)
				{
					graph[nx][ny] = graph[x][y] + 1;
					q.push_back({ nx,ny });
				}	
			}
		}
	}
}

int main()
{
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 1)
				q.push_back({ i,j });
		}
	}
	bfs();
	int max = 0;
	bool emp = false;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) 
		{
			if (graph[i][j] == 0)
			{
				emp = true;
			}
			if (max < graph[i][j])
				max = graph[i][j];
		}
	}
	if (emp == false)
		cout << max - 1 << endl;
	else
		cout << "-1" << endl;
	return 0;
}