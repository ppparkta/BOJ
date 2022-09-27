#include <iostream>
#include <algorithm>
using namespace std;

int n, ans;
int arr[11];
int graph[11][11];

int main()
{
    ans=1e9;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
        arr[i] = i + 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }
    do
    {
        bool check = true;
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (graph[arr[i]][arr[i + 1]] == 0)
                check = false;
            else
                sum += graph[arr[i]][arr[i + 1]];
        }
        if (check && graph[arr[n - 1]][arr[0]] != 0)
        {
            sum += graph[arr[n - 1]][arr[0]];
            ans = min(ans, sum);
        }
    } while (next_permutation(arr, arr + n));
    cout<<ans<<'\n';
}