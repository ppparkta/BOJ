#include	<iostream>
#include	<cstdlib>
using namespace std;

int l;
bool visits[10];

void no()
{
	cout << "NO" << endl;
	exit(0);
}

int main()
{
	cin >> l;
	int prev = 0, cur = 0;
	while (l--)
	{
		prev = cur;
		cin >> cur;
		if (visits[cur] == true)
			no();
		visits[cur] = true;
		if (prev == 0)
			continue;
		if (visits[2] == false)
			if (cur + prev == 4)
				no();
		if (visits[4] == false)
			if ((cur == 1 && prev == 7) || (cur == 7 && prev == 1))
				no();
		if (visits[5] == false)
			if (cur + prev == 10)
				no();
		if(visits[6]==false)
			if((cur == 3 && prev == 9)||(cur == 9 && prev == 3))
				no();
		if (visits[8] == false)
			if ((cur == 7 && prev == 9) || (cur == 9 && prev == 7))
				no();
	}
	cout << "YES" << endl;
	return 0;
}