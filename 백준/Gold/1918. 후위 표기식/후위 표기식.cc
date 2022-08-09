/*
백준 1918번
오늘 해야되는 것: 
-switch문 정리하기		         	
-이 코드의 스택이 어떻게 작동하는지 가시화하기
-
*/

#include<iostream>
#include<stack>
using namespace std;

int main() {
	string a;
	cin >> a;
	string result;
	stack<char>s;
	for (int i = 0; i < a.size(); i++) {
		if ('A' <= a[i] && 'Z' >= a[i]) {
			result += a[i];
		}
		else {
			switch (a[i]) {
			case'(':
				s.push(a[i]);
				break;
			case'*':
			case'/':
				while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
					result += s.top();
					s.pop();
				}
				s.push(a[i]);
				break;
			case'+':
			case'-':
				while (!s.empty() && s.top()!='(') {
					result += s.top();
					s.pop();
				}
				s.push(a[i]);
				break;
			case')':
				while (!s.empty() && s.top() != '(') {
					result += s.top();
					s.pop();

				}
				s.pop();
				break;
			}
		}
	}
	while (!s.empty()) {
		result += s.top();
		s.pop();
	}

	cout << result << endl;
}