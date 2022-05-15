#include	<iostream>
#include	<cmath>
using namespace std;

int main()
{
	long long n, number, answer;
	cin >> n >> number;
	
	answer = 0;
	for (long long i = 1; i < n; i++)
	{
		if (number % 10 == 0)
		{
			number /= 10;
		}
		else
		{
			answer += number % 10;
			number /= 10;
		}
	}
	if (number % 10 != 0)
		answer += number % 10;
	cout << answer << endl;
	return 0;
}