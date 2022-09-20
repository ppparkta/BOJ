#include    <iostream>
#include    <algorithm>
using namespace std;

int n, max_e, ans;
char arr[51][51];

void search()
{
    for(int i=0;i<n;i++)
    {
        char c=arr[i][0];
        int cnt=1;
        for(int j=1;j<n;j++)
        {
            if(arr[i][j]==c)
                cnt++;
            else
                cnt=1;
             c=arr[i][j];
            if(max_e<cnt)
                max_e=cnt;
        }
    }
    for(int i=0;i<n;i++)
    {
        char c=arr[0][i];
        int cnt=1;
        for(int j=1;j<n;j++)
        {
            if(arr[j][i]==c)
                cnt++;
            else
                cnt=1;
            c=arr[j][i];
            if(max_e<cnt)
                max_e=cnt;
        }
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            swap(arr[i][j],arr[i][j+1]);
            search();
            swap(arr[i][j],arr[i][j+1]);
            if(ans<max_e)
                ans=max_e;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            swap(arr[j][i],arr[j+1][i]);
            search();
            swap(arr[j][i],arr[j+1][i]);
            if(ans<max_e)
                ans=max_e;
        }
    }
    cout<<ans<<'\n';
}
