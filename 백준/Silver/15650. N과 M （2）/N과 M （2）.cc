#include	<iostream>
using namespace std;

int n, m;
int arr[9];
bool visit[9];

void dfs(int k, int idx)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = idx; i <= n; i++)
	{
		if (visit[i] == false)
		{
			arr[k] = i;
			visit[i] = true;
			dfs(k + 1,i+1);
			visit[i] = false;
		}
	}
}

int main()
{
	cin >> n >> m;
	dfs(0,1);
	return 0;
}