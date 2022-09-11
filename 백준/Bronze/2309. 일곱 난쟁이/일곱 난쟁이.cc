#include	<iostream>
#include	<algorithm>
using namespace std;

int add, arr[9];

int main()
{
	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		add += arr[i];
	}
	sort(arr, arr + 9);
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (add - (arr[i] + arr[j]) == 100)
			{
				for (int k = 0; k < 9; k++)
				{
					if (k != i && k != j)
					{
						cout << arr[k] << '\n';
					}
				}
				return 0;
			}
		}
	}
}