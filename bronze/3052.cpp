#include	<iostream>
using namespace std;

int main()
{
	int n, cnt;
	int arr[43];
	
	for (int i = 0; i < 43; i++)
		arr[i] = 0;
	for (int i = 0; i < 10; i++)
	{
		cin >> n;
		n %= 42;
		arr[n]++;
	}
	cnt = 0;
	for (int i = 0; i < 43; i++)
	{
		if (arr[i] != 0)
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}