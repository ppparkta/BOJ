#include    <iostream>
#include    <cmath>
using namespace std;

int main()
{
    int n, cnt;
    double k, i;
    
    cnt = 0;
    cin>>n>>k>>i;
    while (k != i)
    {
        k = ceil(k / 2);
        i = ceil(i / 2);
        cnt++;
    }
    cout<<cnt;
    return 0;
}