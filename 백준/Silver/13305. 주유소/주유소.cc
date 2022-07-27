#include	<iostream>
using namespace std;

int n;
long long minn, ans;
int maxnode = 1e9;
int arr[100001];
int path[100000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; i++)
		cin >> path[i];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	minn = maxnode;
	for (int i=0;i<n-1;i++)
	{
		if (arr[i] < minn)
			minn = arr[i];
		ans += minn * path[i];
	}
	cout << ans << endl;
	return (0);
}