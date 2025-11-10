import java.util.*;

class Solution {
    
    public int solution(int[] bandage, int health, int[][] attacks) {
        // 회복시간
        int t = bandage[0];
        // 초당회복량
        int x = bandage[1];
        // 추가회복량
        int y = bandage[2];

        int ans = health;
        int prev = 1;
        int ht = 0;
        
        for(int[] attack : attacks) {
            int time = attack[0];
            int amount = attack[1];
            
            // 이전까지의 힐량 구하기
            ht = time - prev;
            ans = ans + ((ht * x) + (ht / t) * y);
            if (ans > health) {
                ans = health;
            }
            // System.out.println("prev: "+ans);
            ans -= amount;
            if (ans <= 0){
                return -1;
            }
            prev = time+1;
            // System.out.println("next: "+ans);
        }
        return ans;
    }
}