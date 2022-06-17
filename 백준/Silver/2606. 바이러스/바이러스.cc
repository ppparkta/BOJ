#include	<iostream>
#include	<vector>
#include	<queue>
using namespace std;

vector<int> node[101];
int visit[101];
int cnt = -1;

void bfs(int n)
{
	queue<int> b;
	b.push(n);
	visit[n] = 1;
	while (!b.empty())
	{
		int x = b.front();
		b.pop();
		cnt++;
		for (int i = 0; i < node[x].size(); i++)
		{
			int y = node[x][i];
			if (visit[y] == 0)
			{
				b.push(y);
				visit[y] = 1;
			}
		}
	}
}

int main()
{
	int n, e;
	cin >> n >> e;
	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	bfs(1);
	cout << cnt << endl;
	return 0;
}