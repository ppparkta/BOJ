#include <iostream>
using namespace std;

int n, ans;
int arr[16];
// time
int t[16];
// price
int p[16];

void go(int day, int sum)
{
    if (day == n)
    {
        ans = max(ans, sum);
        return;
    }
    if (day > n)
        return ;
    go(day + t[day], sum + p[day]);
    go(day + 1, sum);
    return ;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i] >> p[i];
    }
    go(0, 0);
    cout << ans << '\n';
    return 0;
}