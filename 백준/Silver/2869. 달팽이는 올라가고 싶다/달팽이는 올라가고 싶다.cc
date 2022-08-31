#include	<iostream>
using namespace std;

int a, b, v, ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b >> v;

    ans = 1;
    ans += (v - a) / (a - b);
    if ((v - a) % (a - b) != 0)
        ans++;
    if (a >= v)
        cout << "1";
    else
        cout << ans;
    return 0;
}