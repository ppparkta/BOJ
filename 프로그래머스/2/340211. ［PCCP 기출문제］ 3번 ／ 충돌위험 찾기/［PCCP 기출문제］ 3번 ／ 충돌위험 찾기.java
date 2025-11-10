import java.util.*;

class Solution {
    
    public static int dy[] = {1, -1, 0, 0};
    public static int dx[] = {0, 0, 1, -1};
    
    public int solution(int[][] points, int[][] routes) {
        // ㅆㅃㅆㅃㅆㅃㅆㅃ
        // 좌표 - <시간 개수>
        Map<String, Map<Integer, Integer>> visit = new HashMap<>();
        
        // 각 로봇이 지나간 최단시간 계산
        // 아 뇌정지가 왓음
        for (int n = 0; n < routes.length; n++) {
            // 시작지점 기록
            int[] start = points[routes[n][0] - 1];
            int cy = start[0];
            int cx = start[1];
            int cur = 0;
            record(visit, cy, cx, cur); 
            // 지나야하는 포인트 순회
            for (int i = 1; i < routes[n].length; i++) {
                int[] next = points[routes[n][i] - 1];
                int ty = next[0];
                int tx = next[1];

                // y축 먼저 이동
                while (cy != ty) {
                    cur++;
                    cy += (cy < ty ? 1 : -1);
                    record(visit, cy, cx, cur);
                }
                // x축 이동
                while (cx != tx) {
                    cur++;
                    cx += (cx < tx ? 1 : -1);
                    record(visit, cy, cx, cur);
                }
            }
        }
         
        // 각 로봇의 좌표와 현재시간 비교하여 위험상황 판단
        int ans = 0;
        for (Map<Integer, Integer> m : visit.values()) {
            for (int count : m.values()) {
                if (count >= 2) ans++;
            }
        }
        // int ans = 0;
        // for(int y=0; y<101; y++){
        //     for(int x=0; x<101; x++){
        //         Map<Integer, Integer> m = new HashMap<>();
        //         for(int n=0; n<routes.length; n++){
        //             if(time[n][y][x] == Integer.MAX_VALUE) {
        //                 continue;
        //             }
        //             int t = time[n][y][x];
        //             m.put(t, m.getOrDefault(t, 0) + 1);
        //         }
        //         for(int count : m.values()){
        //             if(count >= 2) {
        //                 ans++;
        //             }
        //         }
        //     }
        // }
        
        return ans;
    }
    
    private void record(
        Map<String, 
        Map<Integer, Integer>> visit, 
        int y,
        int x,
        int t
    ) {
        String key = y + "," + x;
        visit.putIfAbsent(key, new HashMap<>());
        Map<Integer, Integer> m = visit.get(key);
        m.put(t, m.getOrDefault(t, 0) + 1);
    }
}
