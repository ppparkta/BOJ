#include	<iostream>
#include	<cmath>
#include	<algorithm>
using namespace std;

int arr[3];

int main()
{
	while (1)
	{
		cin >> arr[0] >> arr[1] >> arr[2];
		if (arr[0] == 0)
			return 0;
		sort(arr, arr + 3);
		if (pow(arr[0], 2) + pow(arr[1], 2) == pow(arr[2], 2))
			cout << "right" << '\n';
		else
			cout << "wrong" << '\n';
	}
	return (0);
}