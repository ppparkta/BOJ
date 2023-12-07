#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    bool flag = false;
    int dp[101][101];
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++)
            dp[i][j]=9999999;
    }
    
    for(int i=0; i<targets.size(); i++) {
        int idx = 0;
        int cnt = 0;
        for(int s=0;s<targets[i].size();s++){
            for(int j =0; j<keymap.size(); j++) {
                cnt=0;
                for(int k =0; k<keymap[j].length(); k++){
                    cnt++;
                    if (keymap[j][k] == targets[i][s]) {
                        dp[i][s] = min(dp[i][s], cnt);
                        //cout<<"dp"<<i<<"/"<<s<<"의 값: "<<dp[i][s]<<endl;
                    }
                }
            }
        }
    }
    
    for(int i =0;i<targets.size();i++){
        int ans = 0;
        for(int j =0; j<targets[i].size(); j++){
            if (dp[i][j] != 9999999){
                ans += dp[i][j];
            }
        }
        if (ans == 0)
            answer.push_back(-1);
        else
            answer.push_back(ans);
    }
    
    return answer;
}
