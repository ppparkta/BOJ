#include	<iostream>
#include	<string>
#include	<algorithm>
using namespace std;

long long n;
int arr[11];

bool abc(int a, int b)
{
	if (a <= b)
		return false;
	else
		return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin >> n;
	int i = 0;

	while (n)
	{
		arr[i++] = n % 10;
		n /= 10;
	}
	sort(arr, arr + i, abc);
	for (int k = 0; k < i; k++)
		cout << arr[k];
	cout << '\n';
}