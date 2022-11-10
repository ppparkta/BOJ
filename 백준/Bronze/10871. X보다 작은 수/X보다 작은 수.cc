#include <iostream>
using namespace std;

int main(){
    int n,x,y,j=0;
    int arr[10001];
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>y;
        if(y<x){
            cout<<y<<" ";
        }
    }
}