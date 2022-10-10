#include	<iostream>
#include	<cstring>
using namespace std;

char friends[10001][5];
int n, i, piece1, piece2, piece3, result, rest;

int main()
{
	cin >> n;

	for (i = 0; i < n; i++)
		cin >> friends[i];
	for (i = 0; i < n; i++)
	{
		if (strcmp(friends[i], "1/4") == 0)
			piece1++;
		else if (strcmp(friends[i], "1/2") == 0)
			piece2++;
		else
			piece3++;
	}
	//1/2조각 처리
	if (piece2 % 2 == 0)
		result += piece2 / 2;
	else
	{
		result += piece2 / 2;
		rest += 2;
	}
	//1/4조각, 3/4조각 처리
	if (piece1 == piece3)
		result += piece1;
	else if (piece1 > piece3)
	{
		result += piece3;
		rest += piece1 - piece3;
	}
	else if (piece1 < piece3)
	{
		result += piece1 + (piece3 - piece1);
	}
	//나머지 피자조각 처리
	if (result % 4 == 0)
		result += rest / 4;
	else
		result += rest / 4 + 1;

	cout << result << '\n';
	return 0;
}