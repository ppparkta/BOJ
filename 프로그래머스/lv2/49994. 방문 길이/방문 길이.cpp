#include <string>
#include <iostream>
using namespace std;
bool visits[10001][10001];

int solution(string dirs) {
    int answer = 0, dir, x=500,y=500;
    string direction="UDRL";
    visits[y][x]=true;
    int dx[4]={0,0,1,-1,};
    int dy[4]={1,-1,0,0,};
    for(int i=0;i<dirs.length();i++){
        for(int j=0;j<4;j++){
            if(direction[j]==dirs[i])
            {
                dir=j;
                break;
            }
        }
        x+=dx[dir];
        y+=dy[dir];
        if((x>510||x<490)||(y>510||y<490))
        {
            x-=dx[dir];
            y-=dy[dir];
            continue;
        }
        if(visits[y][x]==true){
            x+=dx[dir];
            y+=dy[dir];
            visits[x][y]=true;
            cout<<"x좌표:"<<x<<" y좌표:"<<y<<'\n';
            continue;
        }
        else{
            answer++;
            visits[y][x]=true;
            x+=dx[dir];
            y+=dy[dir];
            visits[y][x]=true;
            cout<<"x좌표:"<<x<<" y좌표:"<<y<<'\n';
            cout<<"add answer"<<'\n';
        }
    }
    return answer;
}