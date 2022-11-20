#include <iostream>
#include <string>
using namespace std;
string n, m;
int ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    getline(cin,n);
    getline(cin,m);
    for (int i = 0; i < n.length(); i++)
    {
        bool flag = true;
        for (int j = 0; j < m.length(); j++)
        {
            if (n[i + j] != m[j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            ans++;
            i += m.length() - 1;
        }
    }
    cout << ans;
}