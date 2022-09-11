#include	<iostream>
#include	<algorithm>
using namespace std;

int add, arr[9], ans[7];
bool swc;

int main()
{
	swc = false;
	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + 9);
	for (int i = 0; i < 9; i++)
	{
		ans[0] = arr[i];
		for (int j = i + 1; j < 9; j++)
		{
			ans[1] = arr[j];
			for (int k = j + 1; k < 9; k++)
			{
				ans[2] = arr[k];
				for (int l = k + 1; l < 9; l++)
				{
					ans[3] = arr[l];
					for (int n = l + 1; n < 9; n++)
					{
						ans[4] = arr[n];
						for (int m = n + 1; m < 9; m++)
						{
							ans[5] = arr[m];
							for (int o = m + 1; o < 9; o++)
							{
								ans[6] = arr[o];
								add = arr[i] + arr[j] + arr[k] + arr[l] + arr[n] + arr[m] + arr[o];
								if (add == 100)
								{
									for (int nu = 0; nu < 7; nu++)
									{
										cout << ans[nu] << '\n';
									}
									swc = true;
									break;
								}
								if (swc == true)
									break;
							}
							if (swc == true)
								break;
						}
						if (swc == true)
							break;
					}
					if (swc == true)
						break;
				}
				if (swc == true)
					break;
			}
			if (swc == true)
				break;
		}
		if (swc == true)
			break;
	}
	return(0);
}