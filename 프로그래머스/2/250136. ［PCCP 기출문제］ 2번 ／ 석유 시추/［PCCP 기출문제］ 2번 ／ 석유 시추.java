import java.util.*;

class Solution {
    
    public static boolean[][] visited;
    public static int dx[] = {0,0,1,-1}; 
    public static int dy[] = {1,-1,0,0};
    public static int[][] arr;
    public static int[][] oil;
    public static int r, c;
    
    // 시간초과 문제 -> bfs 단순탐색말거 캐싱
    public int solution(int[][] land) {
        arr = land;
        r = land.length;
        c = land[0].length;
        visited = new boolean[r][c];
        oil = new int[r][c];

        // 오일 덩어리 크기, 덩어리마다 포함된 좌표 
        Map<Integer, Integer> oilSize = new HashMap<>();
        Map<Integer, Set<Integer>> oilCols = new HashMap<>();
        int id = 1;
        
        // 덩어리별로 다 돌ㄹ아버려
        // 다 도는거? dfs임
        for (int y = 0; y < r; y++) {
            for (int x = 0; x < c; x++) {
                if (land[y][x] == 1 && !visited[y][x]) {
                    Set<Integer> cols = new HashSet<>();
                    int size = dfs(y, x, id, cols);
                    oilSize.put(id, size);
                    oilCols.put(id, cols);
                    id++;
                }
            }
        }
        
        // 덩어리 걸치는 구간 화긴
        // gkTlqkf
        int answer = 0;
        for (int x = 0; x < c; x++) {
            Set<Integer> seen = new HashSet<>();
            int total = 0;
            for (int y = 0; y < r; y++) {
                int curId = oil[y][x];
                if (curId != 0 && !seen.contains(curId)) {
                    seen.add(curId);
                    total += oilSize.get(curId);
                }
            }
            answer = Math.max(answer, total);
        }

        return answer;
    }
    
    private int dfs(int y, int x, int id, Set<Integer> cols) {
        visited[y][x] = true;
        oil[y][x] = id;
        cols.add(x);
        int cnt = 1;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= r || nx >= c) {
                continue;
            }
            if (visited[ny][nx] || arr[ny][nx] == 0) {
                continue;
            }
            cnt += dfs(ny, nx, id, cols);
        }
        return cnt;
    }
}
