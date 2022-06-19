#include	<iostream>
#include	<vector>
using namespace std;

vector<int> node[1001];
int visit[1001];
int n, m;

bool dfs(int num)
{
	if (visit[num] == 0)
	{
		visit[num] = 1;
		for (int i = 0; i < node[num].size(); i++)
			dfs(node[num][i]);
		return true;
	}
	return false;
}

int main()
{
	int from, to, cnt;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> from >> to;
		node[from].push_back(to);
		node[to].push_back(from);
	}
	cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dfs(i))
			cnt++;
	}
	cout << cnt << "\n";
	return 0;
}