#include <iostream>
using namespace std;

int dp[11];

int main(){
    int n,k,ans;
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=10;i++){
        dp[i]=dp[i-1]*i;
    }
    cin>>n>>k;
    ans=dp[n]/(dp[k]*dp[n-k]);
    cout<<ans<<'\n';
}