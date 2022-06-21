#include	<iostream>
#include	<string>
using namespace std;

int main()
{
	int a, b, c, d, e;
	string y;
	cin >> a >> b;
	y = to_string(b);
	c = y[2] - '0';
	d = y[1] - '0';
	e = y[0] - '0';
	cout << a * c << "\n";
	cout << a * d << "\n";
	cout << a * e << "\n";
	cout << a * b << "\n";
	return 0;
}