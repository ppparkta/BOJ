#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool sosu(int num)
{
    if (num < 2)
        return false;
    int a = (int)sqrt(num);
    for (int i = 2; i <= a; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n, m, ans = 0;
    vector<int> v;
    cin >> n >> m;
    for (int i = n; i <= m; i++)
    {
        if (sosu(i))
        {
            v.push_back(i);
            ans += i;
        }
    }
    sort(v.begin(), v.end());
    if(v.empty()){
        cout<<-1;
        return 0;
    }
    cout << ans << '\n';
    cout << v[0];
}
