#include	<iostream>
using namespace std;

int main()
{
	int arr[9];
	int n, max, idx;
	max = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> n;
		arr[i] = n;
		if (max < arr[i])
		{
			max = arr[i];
			idx = i;
		}
	}
	cout << max << endl << idx + 1 << endl;
}