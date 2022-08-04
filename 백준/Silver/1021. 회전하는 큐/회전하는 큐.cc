#include    <iostream>
#include    <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    static int n,m,cnt;
    
    cin>>n>>m;
    deque<int> d;
    for(int i=1;i<=n;i++)
    {
        d.push_back(i);
    }
    for(int i=0;i<m;i++)
    {
        int a, idx;
        cin>>a;
        for(int j=0;j<d.size();j++)
        {
            if(d[j]==a)
            {
                idx=j;
                break;
            }
        }
        if(idx<d.size()-idx)
        {
            while(true)
            {
                if(a==d.front())
                {
                    d.pop_front();
                    break;
                }
                else
                {
                    cnt++;
                    d.push_back(d.front());
                    d.pop_front();
                }
            }   
        }
        else
        {
            while(true)
            {
                if(a==d.front())
                {
                    d.pop_front();
                    break;
                }
                else
                {
                    cnt++;
                    d.push_front(d.back());
                    d.pop_back();
                }
            }
        }
    }
    cout<<cnt<<endl;
}