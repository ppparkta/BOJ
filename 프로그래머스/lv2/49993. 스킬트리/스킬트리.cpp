#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
bool visits[27];

void setVisits(){
    for(int i=0;i<27;i++)
        visits[i]=false;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0, tmp_index;
    unordered_map<char,int> map;
    
    for(int i=0;i<skill.length();i++){
        map[skill[i]]=1;
    }
    
    for(int i=0;i<skill_trees.size();i++){
        setVisits();
        bool swc=true;
        for(int j=0;j<skill_trees[i].length();j++){
            char s=skill_trees[i][j];
            if(map.end()==map.find(s))
                continue;
            else{
                for(int k=0;k<skill.length();k++){
                    if(skill[k]==s){
                        tmp_index=k;
                        break;
                    }
                }
                visits[tmp_index]=true;
                for(int k=0;k<tmp_index;k++){
                    if(!visits[k]){
                        swc=false;
                    }
                }
            }
        }
        if(swc)
            answer++;
    }
    
    return answer;
}