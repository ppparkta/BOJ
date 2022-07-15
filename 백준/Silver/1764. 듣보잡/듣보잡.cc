#include <iostream>
#include <algorithm>
#include <vector>
#include <string> 

using namespace std;

int main() {
	int N, M = 0;
	char temp[1][20];
	vector<string> listen;
	vector<string> who;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> temp[0];
		listen.push_back(temp[0]);
	}
	for (int i = 0; i < M; i++) {
		cin >> temp[0];
		listen.push_back(temp[0]);
	}
	sort(listen.begin(), listen.end());

	for (int i = 0; i < M + N; i++) {
		if (listen[i] == listen[i + 1]) {
			who.push_back(listen[i]);
			i++;
		}
	}
	cout << who.size() << endl;
	for (int i = 0; i < who.size(); i++) {
		cout << who.at(i) << endl;
	}

	return 0;
}