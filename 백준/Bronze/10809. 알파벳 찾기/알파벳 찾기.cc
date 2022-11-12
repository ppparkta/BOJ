#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string s;
    cin >> s;
    unordered_map<char, int> map;
    for (char i = 'a';i <= 'z'; i++) {
        map[i] = -1;
    }
    for (int i = 0; i < s.length(); i++) {
        char tmp = s[i];
        if (map[tmp] == -1) {
            map[tmp] = i;
        }
    }
    for (char i = 'a'; i <= 'z'; i++) {
        cout << map[i] << " ";
    }
    return 0;
}