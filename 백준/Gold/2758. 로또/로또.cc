#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

long long t;
long long dp[11][20001];

long long ro(long long n, long long m);
void solve();

void solve()
{
    long long n, m;
    cin >> n >> m;
    cout << ro(n, m) << '\n';
}

long long ro(long long x, long long y)
{
    if (y <= 0)
        return 0;
    long long &sum = dp[x][y];
    if (sum != -1)
        return sum;
    sum = 0;
    sum += ro(x - 1, y / 2);
    sum += ro(x, y - 1);
    return sum;
}

int main()
{
    cin >> t;
    memset(dp, -1, sizeof(dp));
    for (long long i = 1; i <= 2000; i++)
        dp[1][i] = i;
    while (t--)
    {
        solve();
    }
}