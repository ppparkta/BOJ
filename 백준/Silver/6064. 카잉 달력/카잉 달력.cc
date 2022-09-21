#include <iostream>
using namespace std;

int t, m, n, x, y;
bool ok;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> m >> n >> x >> y;
        x -= 1;
        y -= 1;
        ok = false;
        for (int i = y; i < (m * n); i += n)
        {
            if (i % m == x)
            {
                cout << i + 1 << '\n';
                ok = true;
                break;
            }
        }
        if (ok == false)
            cout << -1 << '\n';
    }
}