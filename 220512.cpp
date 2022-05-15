#include	<iostream>
#include	<algorithm>
using namespace std;

int main() {
	int n, min, max, tmp;

	cin >> n;
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		arr[i] = tmp;
	}
	sort(arr, arr + n);
	min = arr[0];
	max = arr[n - 1];
	cout << min << " " << max << endl;
	free(arr);
	return 0;
}