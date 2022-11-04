#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	unordered_map<int,int> map;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		map[a]++;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		cout << map[a] << " ";
	}
}