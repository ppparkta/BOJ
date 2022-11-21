#include <iostream>
#include <algorithm>
using namespace std;
int n, tmp, ans = 10000;
int arr[11][11];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool visited[11][11];

void first_state(int y,int x) {
	visited[y][x] = false;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		visited[ny][nx] = false;
	}
	return;
}

int flower_sum(int y, int x) {
	int sum = arr[y][x];
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		sum += arr[ny][nx];
		visited[ny][nx] = true;
	}
	return sum;
}

bool use_check(int y, int x)
{
	if (visited[y][x])
		return false;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (visited[ny][nx])
			return false;
	}
	return true;
}

void dfs(int depth, int sum) {
	if (depth == 3) {
		ans = min(ans, sum);
		return;
	}
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			if (use_check(i,j)) {
				tmp = flower_sum(i, j);
				dfs(depth + 1, sum + tmp);
				first_state(i, j);
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	dfs(0, 0);
	cout << ans;
}