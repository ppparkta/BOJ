import java.util.*;

class Solution {
    
    public boolean[] sosue = new boolean[10_000_000];
    public boolean[] visited;
    public boolean[] numVisited = new boolean[10_000_000];
    public int answer = 0;
    
    public int solution(String numbers) {
        getSosue();
        for(int i=0;i<numbers.length();i++){
            visited = new boolean[numbers.length()];
            visited[i] = true;
            dfs(1, String.valueOf(numbers.charAt(i)), numbers);
        }
        return answer;
    }
    
    private void dfs(int depth, String ans, String numbers) {
        int num = Integer.parseInt(ans);
        if (sosue[num] == true && numVisited[num] == false) {
            numVisited[num] = true;
            answer++;
        }
        for(int i=0;i<numbers.length();i++) {
            if (visited[i] == true) {
                continue;
            }
            visited[i] = true;
            dfs(depth+1, ans + String.valueOf(numbers.charAt(i)), numbers);
            visited[i] = false;
        }
    }
    
    // 에라토스테네스의 체~
    private void getSosue(){
        for(int i=0;i<10_000_000;i++){
            sosue[i] = true;
        }
        sosue[0] = false;
        sosue[1] = false;
        for(int i=2;i*i<10_000_000; i++) {
            if (sosue[i] == false) {
                continue;
            }
            for(int j=i*i; j<10_000_000; j+=i) {
                sosue[j] = false;
            }
        }
    }
}


