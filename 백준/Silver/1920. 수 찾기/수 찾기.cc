#include	<iostream>
#include	<algorithm>
using namespace std;

int arr[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cin >> m;
	sort(arr, arr + n);
	for (int i = 0; i < m; i++)
	{
		int x;
		bool emp = false;
		cin >> x;
		int start, end;
		start = 0;
		end = n - 1;
		while (start <= end)
		{
			int mid = (start + end) / 2;
			if (x > arr[mid])
			{
				start = mid + 1;
				continue;
			}
			else if (x < arr[mid])
			{
				end = mid - 1;
				continue;
			}
			else if(x == arr[mid])
			{
				emp = true;
				break;
			}
		}
		cout << emp << '\n';
	}
}