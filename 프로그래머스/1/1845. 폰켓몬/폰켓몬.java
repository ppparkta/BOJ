import java.util.*;

class Solution {
    public int solution(int[] nums) {
        Map<Integer, Integer> m = new HashMap<>();
        for(int i : nums) {
            m.put(i, m.getOrDefault(i, 0) + 1);
        }
        int n = (int) (nums.length / 2);
        if ( m.size() < n){
            return m.size();
        } else {
           return n;
        }
    }
}