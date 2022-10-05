#include	<iostream>
using namespace std;

int n, m;
int arr[102];

void girl(int x)
{
	int l, r;
	l = x - 1;
	r = x + 1;
	while (l != 0 && r != n + 1)
	{
		if (arr[l] != arr[r])
			return;
		else
		{
			if (arr[l])
			{
				arr[l] = 0;
				arr[r] = 0;
			}
			else
			{
				arr[l] = 1;
				arr[r] = 1;
			}
		}
		l--;
		r++;
	}
	return;
}

void boy(int x)
{
	for (int i = 1; i <= n; i++)
	{
		if (i % x == 0)
		{
			if (arr[i] == 1)
				arr[i] = 0;
			else
				arr[i] = 1;
		}
	}
	return;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int sex, number;
		cin >> sex >> number;
		if (sex == 1)
			boy(number);
		else if (sex == 2)
		{
			girl(number);
			if (arr[number] == 1)
				arr[number] = 0;
			else
				arr[number] = 1;
		}
			
	}
	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] << " ";
		if(i % 20 == 0)
			cout << '\n';
	}
	return 0;
}