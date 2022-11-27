#include <iostream>
#include <queue>
using namespace std;
bool visits[51][51];
int n, m, ans;
char arr[51][51];
int dx[2] = {1, -1};
int dy[2] = {1, -1};

void bfs(int y, int x)
{
    char tmp;
    tmp=arr[y][x];
    queue<pair<int, int>> q;
    q.push({y, x});
    while(!q.empty()){
        int ny=q.front().first;
        int nx=q.front().second;
        tmp=arr[ny][nx];
        q.pop();
        for(int i=0;i<2;i++){
            int sy,sx;
            if(tmp=='|'){
                sy=ny+dy[i];
                sx=nx;
            }
            else if(tmp=='-'){
                sx=nx+dx[i];
                sy=ny;
            }
            if(sy<0||sy>=n||sx<0||sx>=m)
                continue;
            if(visits[sy][sx]==true)
                continue;
            if(arr[sy][sx]!=tmp)
                continue;
            visits[sy][sx]=true;
            q.push({sy,sx});
        }
    }
    return;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visits[i][j] == false){
                bfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}