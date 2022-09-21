#include <iostream>
#include <algorithm>
using namespace std;

int x, y, n, ans;
int arr[501][501];

int form1(int nx, int ny)
{
    int tmp = 0;
    if (nx + 3 < x)
    {
        tmp = arr[ny][nx] + arr[ny][nx + 1] + arr[ny][nx + 2] + arr[ny][nx + 3];
    }
    if (ny + 3 < y)
    {
        tmp = max(tmp, arr[ny][nx] + arr[ny + 1][nx] + arr[ny + 2][nx] + arr[ny + 3][nx]);
    }
    //cout<<"form1's return is "<<tmp<<endl;
    return tmp;
}

int form2(int nx, int ny)
{
    int tmp = 0;
    if (nx + 1 < x && ny + 1 < y)
    {
        tmp = arr[ny][nx] + arr[ny][nx + 1] + arr[ny + 1][nx] + arr[ny + 1][nx + 1];
    }
    //cout<<"form2's return is "<<tmp<<endl;
    return tmp;
}

int form3(int nx, int ny)
{
    int tmp = 0;
    if (nx + 1 < x && ny + 2 < y)
    {
        tmp = arr[ny][nx] + arr[ny + 1][nx] + arr[ny + 2][nx] + arr[ny + 2][nx + 1];
    }
    if (nx - 1 >= 0 && ny + 2 < y)
    {
        tmp = max(tmp, arr[ny][nx] + arr[ny + 1][nx] + arr[ny + 2][nx] + arr[ny + 2][nx - 1]);
    }
    if (nx + 1 < x && ny - 2 >= 0)
    {
        tmp = max(tmp, arr[ny][nx] + arr[ny - 1][nx] + arr[ny - 2][nx] + arr[ny - 2][nx + 1]);
    }
    if (nx - 1 >= 0 && ny - 2 >= 0)
    {
        tmp = max(tmp, arr[ny][nx] + arr[ny - 1][nx] + arr[ny - 2][nx] + arr[ny - 2][nx - 1]);
    }
    if (nx + 2 < x && ny - 1 >= 0)
    {
        tmp = max(tmp, arr[ny][nx] + arr[ny][nx + 1] + arr[ny][nx + 2] + arr[ny - 1][nx + 2]);
    }
    if (nx - 2 >= 0 & ny - 1 >= 0)
    {
        tmp = max(tmp, arr[ny][nx] + arr[ny][nx - 1] + arr[ny][nx - 2] + arr[ny - 1][nx - 2]);
    }
    if (nx + 2 < x & ny + 1 < y)
    {
        tmp = max(tmp, arr[ny][nx] + arr[ny][nx + 1] + arr[ny][nx + 2] + arr[ny + 1][nx + 2]);
    }
    if (nx - 2 >= 0 & ny + 1 < y)
    {
        tmp = max(tmp, arr[ny][nx] + arr[ny][nx - 1] + arr[ny][nx - 2] + arr[ny + 1][nx - 2]);
    }
    //cout<<"form3's return is "<<tmp<<endl;
    return tmp;
}

int form4(int nx, int ny)
{
    int tmp = 0;
    if (nx - 1 >= 0 && ny + 1 < y && ny - 1 >= 0)
    {
        tmp = arr[ny][nx] + arr[ny][nx - 1] + arr[ny - 1][nx - 1] + arr[ny + 1][nx];
    }
    if (nx + 1 < x && ny + 1 < y && ny - 1 >= 0)
    {
        tmp = max(tmp, arr[ny][nx] + arr[ny][nx + 1] + arr[ny + 1][nx] + arr[ny - 1][nx + 1]);
    }
    if (nx + 1 < x && nx - 1 >= 0 && ny - 1 >= 0)
    {
        tmp = max(tmp, arr[ny][nx] + arr[ny][nx - 1] + arr[ny - 1][nx + 1] + arr[ny - 1][nx]);
    }
    if (nx + 1 < x && nx - 1 >= 0 && ny - 1 >= 0)
    {
        tmp = max(tmp, arr[ny][nx] + arr[ny][nx + 1] + arr[ny - 1][nx - 1] + arr[ny - 1][nx]);
    }
    //cout<<"form4's return is "<<tmp<<endl;
    return tmp;
}

int form5(int nx, int ny)
{
    int tmp = 0;
    if (nx + 2 < x && ny - 1 >= 0)
    {
        tmp = arr[ny][nx] + arr[ny][nx + 1] + arr[ny][nx + 2] + arr[ny - 1][nx + 1];
    }
    if (nx + 2 < x && ny + 1 < y)
    {
        tmp = max(tmp, arr[ny][nx] + arr[ny][nx + 1] + arr[ny][nx + 2] + arr[ny + 1][nx + 1]);
    }
    if (nx - 1 >= 0 && ny + 2 < y)
    {
        tmp = max(tmp, arr[ny][nx] + arr[ny + 1][nx] + arr[ny + 2][nx] + arr[ny + 1][nx - 1]);
    }
    if (nx + 1 < x && ny + 2 < y)
    {
        tmp = max(tmp, arr[ny][nx] + arr[ny + 1][nx] + arr[ny + 2][nx] + arr[ny + 1][nx + 1]);
    }
    //cout<<"form5's return is "<<tmp<<endl;
    return tmp;
}

int main()
{
    cin >> y >> x;
    ans = 0;
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            ans = max(ans, max(form1(j, i), max(form2(j, i), max(form3(j, i), max(form4(j, i), form5(j, i))))));
        }
    }
    cout << ans << '\n';
    return 0;
}