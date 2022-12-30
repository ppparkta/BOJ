#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, a, b, c;
vector<pair<int, int>> v[5001];

long long dfs(int n, int prev)
{
    long long tmp = 0;
    for (int i = 0; i < v[n].size(); i++)
    {
        if (v[n][i].first == prev)
            continue;
        tmp = max(tmp, dfs(v[n][i].first, n) + v[n][i].second);
    }
    return tmp;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    cout << dfs(1, -1) << endl;
}