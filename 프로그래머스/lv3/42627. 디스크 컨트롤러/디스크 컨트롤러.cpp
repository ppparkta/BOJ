#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class compare{
    public:
        bool operator() (pair<int,int> a, pair<int,int> b){
            return a.second>b.second;
        }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    int j=0;
    sort(jobs.begin(),jobs.end());
    priority_queue<pair<int,int>, vector<pair<int,int>>, compare>pq;
    while(j<jobs.size()||!pq.empty()){
        if(j<jobs.size()&&jobs[j][0]<=time)
        {
            pq.push({jobs[j][0],jobs[j++][1]});
            continue;
        }
        if(!pq.empty()){
            time+=pq.top().second;
            answer+=time-pq.top().first;
             pq.pop();
        }
        else
            time=jobs[j][0];
    }
    return answer/jobs.size();
}