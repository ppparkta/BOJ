#include	<iostream>
using namespace std;

int arr[51][51];
int visit[51][51];
int dh[8] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dw[8] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int w, h, ans;

void set_visit()
{
	for(int i=0;i<51;i++)
		for (int j = 0; j < 51; j++)
		{
			visit[i][j] = 0;
			arr[i][j] = 0;
		}
}

void	dfs(int hn, int wn)
{
	for (int i = 0; i < 8; i++)
	{
		int sh = hn + dh[i];
		int sw = wn + dw[i];
		if ((sh >= 0 || sh < h) && (sw >= 0 || sw < w))
		{
			if ((arr[sh][sw] == 1) && (visit[sh][sw] == 0))
			{
				visit[sh][sw] = 1;
				dfs(sh, sw);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		cin >> w >> h;
		ans = 0;
		if (w == 0 && h == 0)
			return (0);
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (arr[i][j] == 1 && visit[i][j] == 0)
				{
					visit[i][j] = 1;
					ans++;
					dfs(i, j);
				}
			}
		}
		cout << ans << "\n";
		set_visit();
	}
}