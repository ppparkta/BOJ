#include <iostream>
using namespace std;
int n, m, tmp, ans;

int main()
{
    cin >> n;
    if (n == 0)
    {
        cout << 1 << '\n';
        return 0;
    }
    while (n != tmp)
    {
        if (ans == 0)
            tmp = n;
        if (tmp > 9)
            m = (tmp / 10) + (tmp % 10);
        else
            m = tmp;
        tmp = ((tmp % 10) * 10) + (m % 10);
        ans++;
    }
    cout << ans << '\n';
    return 0;
}