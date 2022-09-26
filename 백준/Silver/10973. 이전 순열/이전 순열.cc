#include	<iostream>
#include	<algorithm>
using namespace std;
int n;
int arr[10001];
bool check;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	check = prev_permutation(arr, arr + n);
	if (check == false)
	{
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}