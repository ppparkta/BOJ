#include <iostream>
using namespace std;

int N;
int cnt=0;

void dfs(int n)
{
	if(n==N)
	{
		cnt++;
		return;	
	}
	for(int i=1;i<=3;i++)
	{
		if(n+i<=N)
			dfs(n+i);	
	}	
}
		
int main()
{
	int number;
	cin>>number;
	for(int i=0;i<number;i++)
	{
		cin>>N;
		dfs(0);
		cout<<cnt<<"\n";
		cnt=0;
	}
	return 0;	
}