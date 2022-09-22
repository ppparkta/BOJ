#include	<iostream>
using namespace std;

int n, m;
bool check[9];
int arr[9];

void rec(int idx, int n, int m)
{
	if (idx == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << '\n';
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (check[i] == true)
			continue;
		check[i] = true;
		arr[idx] = i;
		rec(idx + 1, n, m);
		check[i] = false;
	}
}

int main()
{
	cin >> n >> m;
	rec(0, n, m);
}