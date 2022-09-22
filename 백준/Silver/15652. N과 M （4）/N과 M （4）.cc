#include	<iostream>
using namespace std;

int arr[9];
int n, m;

void rec(int idx, int n, int m)
{
	if (idx == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (i < arr[idx - 1])
			continue;
		arr[idx] = i;
		rec(idx + 1, n, m);
	}
}

int main()
{
	cin >> n >> m;
	rec(0, n, m);
}