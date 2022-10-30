#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int var=nums.size()/2;
    unordered_map<int,int> map;
    for(int i=0;i<nums.size();i++){
        int tmp=nums[i];
        if(map.end()==map.find(tmp))
            map.insert({tmp,1});
        else
            map[tmp]++;
    }
    if(map.size()>=var)
        answer=var;
    else if(map.size()<var)
        answer=map.size();
    return answer;
}