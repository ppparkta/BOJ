import java.util.*;

class Solution {
    
    public Map<String, PriorityQueue<String>> pq = new HashMap<>();
    public Deque<String> dq = new ArrayDeque<>();
    
    public String[] solution(String[][] tickets) {
        for(String[] t : tickets){
            PriorityQueue<String> s = pq.computeIfAbsent(t[0], k-> new PriorityQueue<>());
            s.offer(t[1]);
        }
        dfs("ICN");
        String[] arr = new String[dq.size()];
        for(int i=0; i<arr.length; i++){
            arr[i] = dq.poll();
        }
        return arr;
    }
    
    private void dfs(String s) {
        while(pq.containsKey(s) && !pq.get(s).isEmpty()){
            String nextS = pq.get(s).poll();
            dfs(nextS);
        }
        dq.push(s);
    }
}