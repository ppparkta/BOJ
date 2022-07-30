#include    <iostream>
#include    <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int z, o;
    z = 0;
    o = 0;
    cin>>s;
    if(s[0]=='0')
        z++;
    else
        o++;
    for(int i=1;i<s.size();i++)
    {
        if(s[i-1]==s[i])
            continue;
        else if (s[i-1]!=s[i])
        {
            if(s[i]=='1')
                o++;
            else
                z++;
        }
    }
    if(o < z)
        cout<<o<<endl;
    else if (o > z)
        cout<<z<<endl;
    else if (o == z)
        cout<<o<<endl;
    else if ((o==1&&z==0)||(o==0&&z==1))
        cout<<0<<endl;
}