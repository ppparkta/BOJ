#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    long long t, a, b, tmp_ans;
    string ans;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        if (b % 4 == 0)
            b = 4;
        else
            b %= 4;
        tmp_ans = pow(a, b);
        if (tmp_ans % 10 == 0)
            tmp_ans = 10;
        else
            tmp_ans %= 10;
        cout << tmp_ans << '\n';
    }
    return 0;
}