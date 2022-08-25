#include<iostream>
#include<algorithm>
using namespace std;

int t;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> t;
	while (t--) 
    {
		int chicken, money, require, coupon;
		cin >> chicken >> money >> require >> coupon;
		int s = (money / chicken);
		int c = (money / chicken) * coupon;
		// 등비수열의 합 공식에 극한값 대입
		if (c >= require) 
        {
			c -= require;
			s += 1;
			s += c / (require - coupon);
		}
		int d = (money / chicken) + ((money / chicken) * coupon) / require;
		cout << s - d << '\n';
	}
	return 0;
}