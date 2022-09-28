#include	<iostream>
#include	<algorithm>
using namespace std;

int n;
int arr[14];
int depth[7];
bool check[50];

void rec(int idx, int number)
{
	if (idx == 6)
	{
		for (int i = 0; i < 6; i++)
			cout << depth[i] << " ";
		cout << '\n';
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		int tmp = arr[i];
		if (check[tmp] == true)
			continue;
		if (depth[idx - 1] > tmp)
			continue;
		check[tmp] = true;
		depth[idx] = tmp;
		rec(idx + 1, number + 1);
		check[tmp] = false;
	}
}

int main()
{
	n = -1;
	while (1)
	{
		cin >> n;
		if (n == 0)
			return 0;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr + n);
		rec(0, 0);
		cout << '\n';
	}
}