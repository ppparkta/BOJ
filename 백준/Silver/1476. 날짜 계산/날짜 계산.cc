#include <iostream>
using namespace std;

int e, s, m, e1, s1, m1, ans;

int main()
{
    cin >> e >> s >> m;
    ans = 0;
    while (1)
    {
        ans++;
        if (e1 < 15)
            e1++;
        else
            e1 = 1;
        if (s1 < 28)
            s1++;
        else
            s1 = 1;
        if (m1 < 19)
            m1++;
        else
            m1 = 1;
        if (e1 == e && s1 == s && m1 == m)
        {
            cout << ans << '\n';
            return 0;
        }
    }
}