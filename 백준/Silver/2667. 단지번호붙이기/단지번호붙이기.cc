#include	<iostream>
#include	<deque>
#include	<algorithm>
using namespace std;

int graph[26][26];
bool visit[26][26];
int n;
int now = 0;
int dong[25 * 25 + 1];
int xs[4] = { 0,0,1,-1 };
int ys[4] = { 1,-1,0,0 };

void bfs(int x, int y)
{
	deque<pair<int, int>>q;
	q.push_back({ x,y });
	visit[x][y] = true;
	dong[now]++;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + xs[i];
			int ny = y + ys[i];
			if (nx > 0 && nx <= n && ny > 0 && ny <= n)
			{
				if (visit[nx][ny] == false && graph[nx][ny] == 1)
				{
					visit[nx][ny] = true;
					dong[now]++;
					q.push_back({nx, ny});
				}
			}
		}
	}

}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			graph[i][j + 1] = s[j] - '0';
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visit[i + 1][j + 1] == false && graph[i + 1][j + 1] == 1)
			{
				now++;
				bfs(i + 1, j + 1);
			}
		}
	}
	sort(dong + 1, dong + now + 1);
	cout << now << '\n';
	for (int i = 1; i <= now; i++)
	{
		cout << dong[i] << '\n';
	}
}