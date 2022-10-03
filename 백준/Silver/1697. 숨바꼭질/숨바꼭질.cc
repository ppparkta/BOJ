#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k, cnt;
int ans[200001];
bool visits[200001];

void bfs()
{
    queue<int> q;
    ans[n] = 0;
    visits[n]=true;
    q.push(n);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (visits[k] == true)
        {
            cout << ans[k] << '\n';
            break;
        }
        if (x - 1 >= 0 && visits[x - 1] == false)
        {
            ans[x - 1] = ans[x] + 1;
            q.push(x - 1);
            visits[x-1]=true;
        }
        if (x + 1 > 0 && x+1 <= 100001 && visits[x + 1] == false)
        {
            ans[x + 1] = ans[x] + 1;
            q.push(x + 1);
            visits[x+1]=true;
        }
        if (x * 2 <= 200001 && visits[x * 2] == false)
        {
            ans[x * 2] = ans[x] + 1;
            q.push(x * 2);
            visits[x*2]=true;
        }
    }
}

int main()
{
    cin >> n >> k;
    memset(ans, -1, sizeof(ans));
    bfs();
}