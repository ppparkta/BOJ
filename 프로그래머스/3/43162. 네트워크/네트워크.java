import java.util.*;

class Solution {
    
    public static boolean visited[];
    public static int answer = 0;
    
    public int solution(int n, int[][] computers) {
        visited = new boolean[n];
        for(int i =0;i<n;i++){
            search(i, computers);
        }
        return answer;
    }
    
    private void search(int cur, int[][] computers){
        if(visited[cur] == true) {
            return;
        }
        answer++;
        Deque<Integer> dq = new ArrayDeque<>();
        dq.offer(cur);
        while(!dq.isEmpty()) {
            int now = dq.poll();
            for(int i=0; i<computers[now].length; i++) {
                if (i == now || visited[i] == true) {
                    continue;
                }
                if (computers[now][i] == 0) {
                    continue;
                }
                visited[i] = true;
                dq.offer(i);
            }
        }
    }
}