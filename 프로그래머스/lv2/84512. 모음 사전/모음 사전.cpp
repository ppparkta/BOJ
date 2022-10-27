#include <string>
#include <vector>

using namespace std;
int answer, cnt;
char words[5]={'A','E','I','O','U'};

void wordcnt(string now, string ans){
    if(now==ans)
        answer=cnt;
    if(now.length()>5)
        return;
    cnt++;
    for(int i=0;i<5;i++)
        wordcnt(now+words[i],ans);
}

int solution(string word) {
    wordcnt("",word);
    return answer;
}