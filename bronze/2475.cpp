#include	<iostream>
using namespace std;

int main()
{
	int n, answer;
	answer = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> n;
		answer += n * n;
	}
	answer %= 10;
	cout << answer << endl;
	return 0;
}