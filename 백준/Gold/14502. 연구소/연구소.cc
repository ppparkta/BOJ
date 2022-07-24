#include    <iostream>
#include    <algorithm>
#include    <queue>
using namespace std;

int n, m, answ;
int graph[8][8];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(void)
{
    int graph_copy[8][8] = { 0, };
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            graph_copy[i][j] = graph[i][j];
            if (graph[i][j] == 2)
            {
                q.push({ i,j });
            }
        }
    }
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (((nx >= 0 && nx < m) && (ny >= 0 && ny < n)) && graph_copy[ny][nx] == 0)
            {
                graph_copy[ny][nx] = 2;
                q.push({ ny,nx });
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph_copy[i][j] == 0)
                cnt++;
        }
    }
    answ = max(answ, cnt);
    return;
}

void wall(int num)
{
    if (num == 3)
    {
        bfs();
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 0)
            {
                graph[i][j] = 1;
                wall(num + 1);
                graph[i][j] = 0;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> graph[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 0)
            {
                graph[i][j] = 1;
                wall(1);
                graph[i][j] = 0;
            }
        }
    }
    cout << answ;
}