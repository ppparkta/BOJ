#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int ans;
bool visits[9];

bool compare(vector<int> a, vector<int> b){
    if(a[0]>=b[0])
        return true;
    else
        return false;
}

void dfs(vector<vector<int>> dungeons, int k, int cnt){
    if(k<=0)
        return;
    ans=max(cnt,ans);
    cout<<ans<<'\n';
    for(int i=0;i<dungeons.size();i++){
        if(dungeons[i][0]>k||visits[i])
            continue;
        visits[i]=true;
        dfs(dungeons,k-dungeons[i][1],cnt+1);
        visits[i]=false;
    }
    return;
}

int solution(int k, vector<vector<int>> dungeons) {
    sort(dungeons.begin(),dungeons.end(),compare);
    dfs(dungeons, k, 0);
    return ans;
}