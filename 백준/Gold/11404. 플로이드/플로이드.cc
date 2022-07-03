#include	<iostream>
#define INF 1e9
using namespace std;

int graph[101][101];
int n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			graph[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, value;
		cin >> a >> b >> value;
		if (graph[a][b] > value)
			graph[a][b] = value;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < 101; j++)
		{
			for (int k = 1; k < 101; k++)
			{
				graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (graph[i][j] == INF || i == j)
				cout << "0" << ' ';
			else
				cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}
}