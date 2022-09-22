#include	<iostream>
using namespace std;

int n, m;
int arr[8];

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
		arr[idx] = i;
		rec(idx + 1, n, m);
	}
}

int main()
{
	cin >> n >> m;
	rec(0, n, m);
}