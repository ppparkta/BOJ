#include <iostream>
#include <algorithm>
using namespace std;

int l,n,n_min=0,n_max=1001,ans=0;
int arr[51];

int main(){
    cin>>l;
    for(int i=0;i<l;i++){
        cin>>arr[i];
    }
    sort(arr,arr+l);
    cin>>n;
    for(int i=0;i<l;i++){
        if(arr[i]==n)
        {
            cout<<ans;
            return 0;
        }
        if(n>arr[i]&&arr[i]>n_min){
            n_min=arr[i];
        }
        if(n<arr[i]&&arr[i]<n_max){
            n_max=arr[i];
        }
    }
    for(int i=n_min+1;i<=n;i++){
        for(int j=n;j<n_max;j++){
            if(i==j)
                continue;
            ans++;
        }
    }
    cout<<ans;
}