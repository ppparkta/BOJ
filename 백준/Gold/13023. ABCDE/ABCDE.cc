#include    <iostream>
#include    <cstring>
#include    <vector>
using namespace std;

int n,m;
vector<int>graph[2001];
bool visits[2001];
bool ans;

void set_vis()
{
    for(int i=0;i<2001;i++)
        visits[i]=false;
}

void dfs(int d, int n)
{
    if(d==4)
    {
        ans=true;
        return;
    }
    visits[n]=true;
    for(int i=0;i<graph[n].size();i++)
    {
        int new_ = graph[n][i];
        if(ans == true)
            return;
        if(visits[new_] == false)
            dfs(d+1, new_);
    }
    visits[n]=false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        memset(visits,false,sizeof(visits));
        dfs(0, i);
        if(ans==true)
            break;
    }
    if(ans==true)
        cout<<1<<endl;
    else
        cout<<0<<endl;
}