#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, m, number;
    cin >> n >> m;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    cout << "<";
    while (q.size() > 1)
    {
        for (int i = 0; i < m - 1; i++)
        {
            number = q.front();
            q.pop();
            q.push(number);
        }
        number = q.front();
        cout << number << ", ";
        q.pop();
    }
    number = q.front();
    cout << number << ">\n";
    return 0;
}