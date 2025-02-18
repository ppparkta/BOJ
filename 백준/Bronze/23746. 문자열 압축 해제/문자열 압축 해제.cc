#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, s, e;
    string example;
    string word[27], press[27];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> word[i] >> press[i];
    }

    cin >> example;

    string result = ""; 
    int i = 0;

    while (i < example.length()) {
        bool replaced = false;

        for (int j = 0; j < n; j++) {
            if (example.substr(i, press[j].length()) == press[j]) {
                result += word[j]; 
                i += press[j].length(); 
                replaced = true;
                break;  
            }
        }

        if (!replaced) {  
            result += example[i];  
            i++;
        }
    }

    cin >> s >> e;
    for (int i = s - 1; i < e; i++) {
        cout << result[i];
    }

    return 0;
}
