#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int c[1001];
vector<int> a[1001];

void insert_edge(int i, int j) {
	a[i].push_back(j);
	a[j].push_back(i);
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	c[start] = true;

	while (!q.empty()) {
		int w = q.front();
		q.pop();
		cout << w << ' ';
		for (int i = 0; i < a[w].size(); i++) {
			int y = a[w][i];
			if (!c[y]) {
				q.push(y);
				c[y] = true;
			}
		}
	}
}

void dfs(int n) {
	if (c[n]) return;

	cout << n << ' ';
	c[n] = true;
	for (int i = 0; i < a[n].size(); i++) {
		int y = a[n][i];
		if (!c[y])
			dfs(y);
	}
}

int main(void) {
	int N, M, V, x, y;
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		insert_edge(x, y);
	}

	for (int i = 1; i <= N; i++) {
		sort(a[i].begin(), a[i].end());
	}

	dfs(V);
	cout << endl;
	memset(c, 0, sizeof(c));
	bfs(V);
	cout << endl;
}