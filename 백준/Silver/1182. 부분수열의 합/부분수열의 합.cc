#include    <iostream>
using namespace std;

int n,s, ans;
int arr[21];
bool check[21];

void rec(int sum, int index)
{
    if(index==n)
        return;
    if(sum+arr[index]==s)
        ans++;
    rec(sum+arr[index],index+1);
    rec(sum,index+1);
    return ;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    rec(0,0);
    cout<<ans<<'\n';
    return 0;
}