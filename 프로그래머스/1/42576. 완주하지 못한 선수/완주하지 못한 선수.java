import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        Map<String, Integer> s = new HashMap<>();
        for(String p : participant) {
            s.put(p, s.getOrDefault(p, 0) + 1);
        }
        for(String c : completion) {
            if (s.containsKey(c)) {
                s.put(c, s.get(c) - 1);
            }
        }
        for(String key : s.keySet()) {
            if (s.get(key) != 0){
                return key;
            }
        }
        String answer = "";
        return answer;
    }
}