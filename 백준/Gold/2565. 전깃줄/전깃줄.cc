#include    <iostream>
#include    <vector>
#include    <algorithm>
using namespace std;

int n,a,b,tmp;
int dp[101];
vector<pair<int,int>> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    dp[0]=1;
	for(int i=0;i<n;i++)
	{
		tmp=0;
		for(int j=0;j<i;j++)
		{
			if(v[j].second<v[i].second&&tmp<dp[j])
                tmp=dp[j];
		}
		dp[i]=tmp+1;
	}
	sort(dp,dp+n,greater<>());
	cout<<n-dp[0];
}