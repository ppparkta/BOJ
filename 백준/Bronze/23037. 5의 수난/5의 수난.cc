#include	<iostream>
#include	<cmath>
using namespace std;

int main()
{
	string n;
	int sum;
	cin >> n;
	sum = 0;
	for (int i = 0; i < 5; i++)
	{
		int x = n[i] - '0';
		sum += pow(x, 5);
	}
	cout << sum << endl;
}