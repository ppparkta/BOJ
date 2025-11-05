import java.util.*;

class Solution {
    
    public static boolean visited[][];
    public static int answer[][];
    public static int dx[] = {0,0,1,-1};
    public static int dy[] = {1,-1,0,0};
    
    public int solution(int[][] maps) {
        int n = maps.length;
        int m = maps[0].length;
        visited = new boolean[n][m];
        answer = new int[n][m];
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                answer[i][j] = Integer.MAX_VALUE;
            }
        }
        
        Deque<int[]> dq = new ArrayDeque<>();
        dq.offer(new int[]{0,0});
        answer[0][0] = 1;
        
        while(!dq.isEmpty()){
            int[] poll = dq.poll();
            int y = poll[0];
            int x = poll[1];
            if (y == n-1 && x == m-1){
                return(answer[y][x]);
            }
            for(int i=0;i<4;i++){
                int ny = y+dy[i];
                int nx = x+dx[i];
                if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
                    continue;
                }
                if (visited[ny][nx] == true || maps[ny][nx] == 0){
                    continue;
                }
                visited[ny][nx] = true;
                answer[ny][nx] = answer[y][x] + 1;
                // System.out.println(ny+" "+nx +" :"+answer[ny][nx]);
                dq.offer(new int[]{ny, nx});
            }
        }
        return -1;
    }
}