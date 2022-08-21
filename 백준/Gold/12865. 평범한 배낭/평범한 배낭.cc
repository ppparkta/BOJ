#include    <iostream>
#include    <algorithm>
using namespace std;

int n,k,ans;
int w[101];
int v[101];
int dp[101][100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i]>>v[i];
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(w[j]<=i)
                dp[j][i]=max(dp[j-1][i],dp[j-1][i-w[j]]+v[j]);
            else
                dp[j][i]=dp[j-1][i];
        }
    }
    cout<<dp[n][k];
}