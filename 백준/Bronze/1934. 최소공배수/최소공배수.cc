#include <iostream>
using namespace std;

int m(int a,int b){
    int tmp=a<b?a:b;
    
    for(int i=tmp;i>0;i--){
        if (a%i==0&&b%i==0){
            return (i);
        }
    }
}

int main(){
    int t,a,b;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b;
        cout<<a*b/m(a,b)<<endl;
    }
    return (0);
}