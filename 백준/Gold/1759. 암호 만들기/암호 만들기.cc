#include <iostream>
#include <algorithm>
using namespace std;

int l, c, a, temp;
char depth[15];
char arr[15];
bool check[15];

void go(int idx)
{
    if (idx == c)
    {
        if (temp >= 1 && c - temp >= 2)
        {
            for (int i = 0; i < c; i++)
                cout << depth[i];
            cout << '\n';
        }
        return;
    }
    for (int i = 0; i < l; i++)
    {
        if (check[i] == true)
            continue;
        if (depth[idx - 1] > arr[i])
            continue;
        if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
            temp++;
        check[i] = true;
        depth[idx] = arr[i];
        go(idx + 1);
        check[i] = false;
        if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
            temp--;
    }
}

int main()
{
    cin >> c >> l;
    for (int i = 0; i < l; i++)
        cin >> arr[i];
    sort(arr, arr + l);
    go(0);
}