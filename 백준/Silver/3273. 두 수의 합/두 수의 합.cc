#include	<iostream>
#include	<algorithm>
using namespace std;

int arr[100001];

int main()
{
	int n, x, cnt, left, right;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	cin >> x;
	cnt = 0;
	left = 0;
	right = n - 1;
	while (left < right)
	{
		if (arr[left] + arr[right] == x)
		{
			cnt++;
			right--;
		}
		else if (arr[left] + arr[right] > x)
			right--;
		else
			left++;
	}
	cout << cnt << "\n";
	return 0;
}