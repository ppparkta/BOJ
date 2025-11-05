import java.util.*;

class Solution {
    
    public int solution(
        int[][] rectangle, 
        int characterX, 
        int characterY, 
        int itemX, 
        int itemY
    ) {
        // 최단거리니까 bfs를 쓰면 좋을거 같은데
        int [][] dist = {{0,1},{0,-1},{1,0},{-1,0}};
        
        // 모서리 경로를 구해보자.
        // 그래프 간선 위니까 테두리 구하려면 *2
        int[][] line = new int[101][101];
        boolean [][] visited = new boolean[101][101];
        
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                line[i][j] = 0;
            }
        }
        
        // 0은 불가능, 1은 가능한 경로
        for(int i=0;i<rectangle.length;i++){
            int[] r = rectangle[i];
            int minx = r[0] * 2;
            int miny = r[1] * 2;
            int maxx = r[2] * 2;
            int maxy = r[3] * 2;
            for(int j=miny; j<=maxy;j++){
                for(int k=minx; k<=maxx;k++){
                    line[j][k] = 1;
                }
            }    
        }
        for(int i=0;i<rectangle.length;i++){
            int[] r = rectangle[i];
            int minx = r[0] * 2;
            int miny = r[1] * 2;
            int maxx = r[2] * 2;
            int maxy = r[3] * 2;
            for(int j=miny + 1; j<=maxy - 1;j++){
                for(int k=minx+1; k<=maxx-1;k++){
                    line[j][k] = 0;
                }
            }            
        }
        
        // 그 다음에 캐릭터 경로를 모서리 경로에 맞게 이동시키자.
        Deque<int[]> dq = new ArrayDeque<>();
        dq.offer(new int[]{characterY*2,characterX*2,1});
        visited[characterY*2][characterX*2] = true;
        while(!dq.isEmpty()) {
            int[] poll = dq.poll();
            int y = poll[0];
            int x = poll[1];
            int d = poll[2];
            if ((y == itemY * 2) && (x == itemX * 2)) {
                return d / 2;
            }
            for(int[] dis : dist) {
                int ny = y+dis[0];
                int nx = x+dis[1];
                if(ny <0|| ny>100 || nx <0 || nx > 100){
                    continue;
                }
                if (line[ny][nx] != 1 || visited[ny][nx] == true){
                    continue;
                }
                // System.out.println(ny+" "+nx+" "+(d+1));
                visited[ny][nx] = true;
                dq.offer(new int []{ny, nx, d+1});
            }
        }
        
        int answer = 0;
        return answer;
    }
}