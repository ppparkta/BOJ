#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string n;
int ans;
int number[10];

int main() {
	cin >> n;
	for (int i = 0; i < n.length(); i++) {
		number[n[i] - '0']++;
	}
	for (int i = 0; i < 10; i++) {
		if (i != 9 && i != 6) {
			ans = max(ans, number[i]);
		}
	}
	ans = max(ans, (number[6] + number[9] + 1) / 2);
	cout << ans;
}