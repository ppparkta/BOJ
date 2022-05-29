#include	<iostream>
using namespace std;

int main()
{
	int n, m, count;
	double add, avg;
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		cin >> m;
		int v[1000];
		add = 0;
		for (int j = 0; j < m; j++)
		{
			cin >> v[j];
			add += v[j];
		}
		add /= (double)m;
		count = 0;
		for (int j = 0; j < m; j++)
		{
			if (v[j] > add)
				count++;
		}
		avg = (double)count / (double)m * 100;
		cout << fixed;
		cout.precision(3);
		cout << avg <<"%" << endl;
	}
	return 0;
}