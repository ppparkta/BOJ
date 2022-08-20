#include    <iostream>
#include    <algorithm>
using namespace std;

int n,ans;
int graph[501][501];
int dp[501][501];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cin>>graph[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+graph[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(dp[i][j]>ans)
                ans=dp[i][j];
        }
    }
    cout<<ans<<endl;
}