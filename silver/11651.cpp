#include	<iostream>
#include	<vector>
#include	<algorithm>
using namespace std;

class a {
public:
	int x;
	int y;
	a(int ax,int ay) {
		x = ax;
		y = ay;
	}
};

bool new_sort(a x, a y)
{
	if (x.y < y.y)
		return true;
	else if (x.y == y.y)
	{
		if (x.x < y.x)
			return true;
		else
			return false;
	}
	else
		return false;
}

int main()
{
	int n, x, y;
	vector<a> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		v.push_back(a(x,y));
	}
	sort(v.begin(), v.end(),new_sort);
	for (int i = 0; i < n; i++)
	{
		cout << v[i].x << " " << v[i].y << "\n";
	}
	return 0;
}