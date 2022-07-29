#include    <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    if(n==1)
    {
        cout<<"1"<<endl;
    }
    else if(n==2)
    {
        cout<<min(4,(m+1)/2)<<endl;
    }
    else if(m<7)
    {
        cout<<min(m,4)<<endl;
    }
    else
    {
        cout<<m-2<<endl;
    }
    return 0;
}
