#include <iostream>
using namespace std;
int t, k, n;
string s[35];
bool alive[11];
int rsp[4];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        alive[i] = true;
    }
    k = s[1].size();
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            rsp[j] = 0;
        }
        for (int j = 1; j <= n; j++)
        {
            if (!alive[j])
                continue;
            if (s[j][i] == 'R')
                rsp[0] = 1;
            else if (s[j][i] == 'S')
                rsp[1] = 1;
            else if (s[j][i] == 'P')
                rsp[2] = 1;
        }
        if (rsp[0] + rsp[1] + rsp[2] == 2)
        {
            char lose_char;
            if (rsp[0] == 0)
                lose_char = 'P';
            else if (rsp[1] == 0)
                lose_char = 'R';
            else if (rsp[2] == 0)
                lose_char = 'S';
            for (int j = 1; j <= n; j++)
            {
                if (s[j][i] == lose_char)
                    alive[j] = false;
            }
        }
    }
    int cnt = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (alive[i])
        {
            cnt++;
            ans = i;
        }
    }
    if (cnt != 1)
        ans = 0;
    cout << ans << '\n';
}

int main()
{
    cin >> t;
    while (t--)
        solve();
    return 0;
}