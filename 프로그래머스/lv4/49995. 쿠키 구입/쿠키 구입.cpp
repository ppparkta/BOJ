#include <string>
#include <vector>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    int n=cookie.size();
    for(int i=0;i<n;i++){
        int l_index=i;
        int r_index=i+1;
        int left_sum=cookie[i];
        int right_sum=cookie[i+1];
        while(l_index>=0&&r_index<n){ 
            if(left_sum>right_sum){
                if(++r_index<n)
                    right_sum+=cookie[r_index];
            }
            else if(left_sum<right_sum){
                if(--l_index>=0)
                    left_sum+=cookie[l_index];
            }
            else{
                if(left_sum>answer)
                    answer=left_sum;
                if(++r_index<n)
                    right_sum+=cookie[r_index];
                if(--l_index>=0)
                    left_sum+=cookie[l_index];
            }
        }
    }
    return answer;
}