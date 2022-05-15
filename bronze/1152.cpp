#include	<iostream>
#include	<string>
using namespace std;

int main() {
	string input;
	int cnt = 0;
	int i = 0;
	cin.ignore();
	getline(cin, input);
	if (input[i] != ' ')
		cnt++;
	i++;
	while (input[i]) {
		if (input[i - 1] == ' ')
			cnt++;
		i++;
	}
	cout << cnt << endl;
	return 0;
}
