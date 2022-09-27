#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, ans;
int arr[9];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    do
    {
        int temp = 0;
        for (int i = 1; i < n; i++)
            temp += abs(arr[i] - arr[i - 1]);
        ans = max(ans, temp);
    } while (next_permutation(arr, arr + n));
    cout << ans << '\n';
}