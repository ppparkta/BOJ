#include	<iostream>
#include	<algorithm>
using namespace std;

int n;
bool check;
int arr[9];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		arr[i - 1] = i;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << '\n';
	while (next_permutation(arr, arr + n))
	{
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
	}
	return 0;
}