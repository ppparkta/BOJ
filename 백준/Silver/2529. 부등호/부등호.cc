#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int k;
char updown[10];
bool check[10];
vector<string> ans;

bool ok(int pre, int now, char x)
{
    if (x == '<')
    {
        if (pre < now)
            return true;
    }
    if (x == '>')
        if (pre > now)
            return true;
    return false;
}

void go(int index, string s)
{
    if (index == k + 1)
    {
        ans.push_back(s);
        return;
    }
    for (int i = 0; i <= 9; i++)
    {
        if (check[i] == true)
            continue;
        if (index == 0 || ok(s[index - 1], i + '0', updown[index - 1]) == true)
        {
            check[i] = true;
            go(index + 1, s + to_string(i));
            check[i] = false;
        }
    }
}

int main()
{
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> updown[i];
    }
    go(0, "");
    sort(ans.begin(), ans.end());
    cout << ans.back() << '\n';
    cout << ans.front() << '\n';
    return 0;
}