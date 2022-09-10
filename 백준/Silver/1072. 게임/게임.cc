#include    <iostream>
using namespace std;

long long x, y, z, mid, nz, ans;

int main()
{
    long long start=0;
    long long end=10e9;
    ans=-1;
    cin>>x>>y;
    z=(y*100)/x;
    if(z>=99)
    {
        cout<<ans<<endl;
        return 0;
    }
    while(start<=end)
    {
        mid=(start+end)/2;
        nz=((y+mid)*100)/(x+mid);
        if(nz>z)
            end=mid-1;
        else
            start=mid+1;
    }
    cout<<start<<endl;
}