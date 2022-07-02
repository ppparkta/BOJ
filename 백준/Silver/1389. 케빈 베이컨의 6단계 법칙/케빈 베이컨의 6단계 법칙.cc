#include	<iostream>
using namespace std;
#define INF 1e9

int graph[101][101];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			graph[i][j] = INF;
			if (i == j)
				graph[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int a = 1; a < 101; a++)
		{
			for (int b = 1; b < 101; b++)
			{
				graph[a][b] = min(graph[a][b], graph[a][i] + graph[i][b]);
			}
		}
	}
	int sum, ans;
	int min = INF;
	for (int i = 1; i <= n; i++)
	{
		sum = 0;
		for (int j = 1; j <= n; j++)
			sum += graph[i][j];
		if (sum < min)
		{
			min = sum;
			ans = i;
		}
	}
	cout << ans << endl;
}