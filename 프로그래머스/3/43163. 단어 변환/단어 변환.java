import java.util.*;

class Solution {
    
    public static boolean used[];
    
    public int solution(String begin, String target, String[] words) {
        used = new boolean[words.length];
        
        Deque<Pair> dq = new ArrayDeque<>();
        dq.offer(new Pair(begin, 0));
        
        while(!dq.isEmpty()) {
            Pair p = dq.poll();
            String t = p.value;
            int d = p.dist;
            if (t.equals(target)) {
                return d;
            }
            for(int i =0; i< words.length;i++) {
                if (used[i] == true) {
                    continue;
                }
                if (comp(t, words[i]) == true) {
                    used[i] = true;
                    dq.offer(new Pair(words[i], d+1));
                }
            }
        }
        
        int answer = 0;
        return answer;
    }
    
    private boolean comp(String a, String b){
        int cnt = 0;
        for(int i=0;i<a.length();i++){
            if (a.charAt(i) != b.charAt(i)) {
                cnt++;
            }
        }
        return cnt <= 1;
    }
    
    static class Pair {
        public String value;
        public int dist;
        
        public Pair(String v, int d) {
            this.value = v;
            this.dist = d;
        }
    }
}