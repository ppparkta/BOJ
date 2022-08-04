#include    <iostream>
#include    <queue>
using namespace std;

int n, rb, rgb;
char graph[101][101];
int visit_rb[101][101];
int visit_rgb[101][101];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void bfs_rb(int x, int y)
{
    queue<pair<int,int>>q;
    char cmp=graph[x][y];
    q.push({x,y});
    visit_rb[x][y]=1;
    while(!q.empty())
    {
        int nx=q.front().first;
        int ny=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xx=nx+dx[i];
            int yy=ny+dy[i];
            char ncmp=graph[xx][yy];
            if((xx>=0&&xx<n)&&(yy>=0&&yy<n))//가능한 범위 내
            {
                if(visit_rb[xx][yy]==0)//방문한 적 없고 같은 구역
                {
                    if(((cmp=='R'||cmp=='G')&&(ncmp=='R'||ncmp=='G'))||cmp==ncmp)
                    {   
                        q.push({xx,yy});
                        visit_rb[xx][yy]=1;
                    }
                }
            }
        }
    }
}

void bfs_rgb(int x, int y)
{
    queue<pair<int,int>>q;
    q.push({x,y});
    visit_rgb[x][y]=1;
    while(!q.empty())
    {
        int nx=q.front().first;
        int ny=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xx=nx+dx[i];
            int yy=ny+dy[i];
            if((xx>=0&&xx<n)&&(yy>=0&&yy<n))//가능한 범위 내
            {
                if(visit_rgb[xx][yy]==0)//방문한 적 없고 같은 구역
                {
                    if(graph[x][y]==graph[xx][yy])
                    {   
                        q.push({xx,yy});
                        visit_rgb[xx][yy]=1;
                    }
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>graph[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(visit_rb[i][j]==0)
            {
                rb++;
                bfs_rb(i,j);
            }
            if(visit_rgb[i][j]==0)
            {
                rgb++;
                bfs_rgb(i,j);
            }
        }
    }
    cout<<rgb<<" "<<rb<<endl;
}