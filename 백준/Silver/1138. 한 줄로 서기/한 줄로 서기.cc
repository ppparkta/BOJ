#include <iostream>
#include <algorithm>
using namespace std;
int n;
pair<int,int> arr[11];
pair<int, int> depth[11];
bool visits[11];

int check_height(int n, int d) {
	int ans = 0;
	for (int i = 0; i < d; i++) {
		if (depth[i] > arr[n])
			ans++;
	}
	return ans;
}

void dfs(int d) {
	if (d == n) {
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visits[i] == true)
			continue;
		if (check_height(i, d) != arr[i].second)
			continue;
		visits[i] = true;
		depth[d] = arr[i];
		dfs(d + 1);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		arr[i].first = i + 1;
	}
	for (int i = 0; i < n; i++) {
		cin >> arr[i].second;
	}
	dfs(0);
	for (int i = 0; i < n; i++) {
		cout << depth[i].first << " ";
	}
}