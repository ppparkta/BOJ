#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m, now, start, ans;
bool arr[10];

int check(int c)
{
    int num = 0;
    if (c == 0)
    {
        if (arr[0])
            return 0;
        else
            return 1;
    }
    while (c > 0)
    {
        if (arr[c % 10])
            return 0;
        c /= 10;
        num++;
    }
    return num;
}

int main()
{
    now = 100;
    ans = 1000000;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        arr[k] = true;
    }
    ans = min(ans, abs(now-n));
    for (int i = 0; i < 1000000; i++)
    {
        if (check(i))
        {
            int tmp;
            start = check(i);
            tmp = abs(n - i) + start;
            ans = min(ans, tmp);
        }
    }
    cout << ans << endl;
}