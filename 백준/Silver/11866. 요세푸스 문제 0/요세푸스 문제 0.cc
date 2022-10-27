#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k;
	queue<int>q;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		q.push(i);
	cout << "<";
	while (!q.empty()) {
		for (int i = 1; i < k; i++) {
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		cout << q.front();
		q.pop();
		if (!q.empty())
			cout << ", ";
		else
			cout << ">";
	}
}