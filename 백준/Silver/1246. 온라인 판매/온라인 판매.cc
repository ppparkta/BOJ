#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M; 
	cin >> N >> M;
	for (int i = 0; i < M; i++) 
		cin >> arr[i];
	sort(arr, arr + M);
	int ans = 0;
	int idx = 0;
	int k = min(N, M);
	for (int i = 1; i <= k; i++) 
	{
		if (ans <= i * arr[M - i])
		{
			ans = i * arr[M - i];
			idx = i;
		}
	}
	cout << arr[M - idx] << '\n' << ans;
}