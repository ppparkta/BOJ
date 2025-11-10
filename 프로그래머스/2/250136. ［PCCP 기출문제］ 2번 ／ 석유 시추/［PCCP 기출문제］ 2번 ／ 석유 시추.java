import java.util.*;

class Solution {
    
    public static boolean[][] visited;
    public static int dx[] = {0,0,1,-1}; 
    public static int dy[] = {1,-1,0,0};
    public static int[][] arr;
    public static int[][] oil;
    public static int r, c;
    
    public int solution(int[][] land) {
        arr = land;
        r = land.length;
        c = land[0].length;
        visited = new boolean[r][c];
        oil = new int[r][c];

        Map<Integer, Integer> oilSize = new HashMap<>();
        int id = 1;
        
        for (int y = 0; y < r; y++) {
            for (int x = 0; x < c; x++) {
                if (land[y][x] == 1 && !visited[y][x]) {
                    Set<Integer> cols = new HashSet<>();
                    int size = bfs(y, x, id, cols);
                    oilSize.put(id, size);
                    id++;
                }
            }
        }
        
        int answer = 0;
        for (int x = 0; x < c; x++) {
            Set<Integer> s = new HashSet<>();
            int cnt = 0;
            for (int y = 0; y < r; y++) {
                int curId = oil[y][x];
                if (curId != 0 && !s.contains(curId)) {
                    s.add(curId);
                    cnt += oilSize.get(curId);
                }
            }
            answer = Math.max(answer, cnt);
        }

        return answer;
    }
    
    private int bfs(int sy, int sx, int id, Set<Integer> cols) {
        Queue<int[]> q = new ArrayDeque<>();
        q.offer(new int[]{sy, sx});
        visited[sy][sx] = true;
        oil[sy][sx] = id;
        cols.add(sx);

        int cnt = 0;
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            cnt++;
            int y = cur[0], x = cur[1];
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
                if (visited[ny][nx] || arr[ny][nx] == 0) continue;
                visited[ny][nx] = true;
                oil[ny][nx] = id;
                cols.add(nx);
                q.offer(new int[]{ny, nx});
            }
        }
        return cnt;
    }
}
