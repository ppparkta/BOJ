#include	<iostream>
using namespace std;

int main()
{
	int n, answer;
	int nu[10];
	for (int i = 0; i < 10; i++)
		nu[i] = 0;
	answer = 1;
	for (int i = 0; i < 3; i++)
	{
		cin >> n;
		answer *= n;
	}
	while (answer > 9)
	{
		nu[answer % 10]++;
		answer /= 10;
	}
	nu[answer % 10]++;
	for (int i = 0; i < 10; i++)
	{
		cout << nu[i] << endl;
	}
	return 0;
}