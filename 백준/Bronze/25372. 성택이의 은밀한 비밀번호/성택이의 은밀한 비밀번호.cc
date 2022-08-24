#include	<iostream>
using namespace std;

int n;
string s;

int length_s(string s)
{
	int i=0;
	for(int j=0;j<s.length();j++)
	{
		i++;
	}
	return (i);
}

int main()
{
	cin>>n;
	while(n--)
	{
		cin>>s;
		if(length_s(s)>=6&&length_s(s)<=9)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return(0);
}