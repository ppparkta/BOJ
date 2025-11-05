class Solution {
    
    public static boolean visited[];
    public static int answer = 0;
    
    public int solution(int n, int[][] computers) {
        visited = new boolean[n];
        for (int i=0; i<n; i++){
            if (visited[i] == false){
                answer++;
                search(i, computers);
            }
        }
        return answer;
    }
    
    private void search(int cur, int[][] computers) {
        visited[cur] = true;
        for(int i=0; i<computers[cur].length; i++) {
            if (visited[i] == false && computers[cur][i] == 1) {
                search(i, computers);
            }
        }
    }
}