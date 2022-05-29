#include	<iostream>
using namespace std;

int main()
{
	int x, y, xp, yp;
	int xlist[10];
	int ylist[10];
	for (int i = 0; i < 3; i++)
	{
		cin >> x >> y;
		xlist[i] = x;
		ylist[i] = y;
	}
	if (xlist[0] == xlist[1])
		cout << xlist[2] << " ";
	else if (xlist[0] == xlist[2])
		cout << xlist[1] << " ";
	else
		cout << xlist[0] << " ";
	if (ylist[0] == ylist[1])
		cout << ylist[2] << endl;
	else if (ylist[0] == ylist[2])
		cout << ylist[1] << endl;
	else
		cout << ylist[0] << endl;
	return 0;
}