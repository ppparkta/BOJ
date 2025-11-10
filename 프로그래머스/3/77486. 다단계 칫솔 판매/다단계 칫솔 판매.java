import java.util.*;

class Solution {
    public int[] solution(
        String[] enroll, 
        String[] referral,
        String[] seller, 
        int[] amount
    ) {
        Map<String, String> parent = new HashMap<>();
        Map<String, Integer> ans = new HashMap<>();
        for(int i=0;i<enroll.length;i++) {
            parent.put(
                enroll[i], 
                referral[i].equals("-")?null:referral[i]
            );
            ans.put(enroll[i], 0);
        }
        
        for(int i=0;i<seller.length;i++){
            String s = seller[i];
            int price = amount[i] * 100;
            
            while(parent.get(s) != null&&price>0){
                int nxt = price / 10;
                ans.put(s, ans.get(s) + price - nxt);
                price = nxt;
                s = parent.get(s);
            }
            ans.put(s, ans.get(s) + price - (price/10));
        }
        
        int[] answer = new int[enroll.length];
        int idx=0;
        for(String en:enroll) {
            answer[idx++] = ans.get(en);
        }
        return answer;
    }
}