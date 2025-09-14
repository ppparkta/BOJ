import java.io.*;
import java.util.*;

class Solution {
    public int[] solution(String today, String[] terms, String[] privacies) {
        // 오늘 날짜를 저장한다
        String[] date = today.split("[.]", 3);
        int year = Integer.parseInt(date[0]);
        int month = Integer.parseInt(date[1]);
        int day = Integer.parseInt(date[2]);
        
        // terms를 나눠서 MAP으로 저장한다
        Map<String, Integer> t = new HashMap<>();
        for(String term : terms){
            String tt[] = term.split(" ", 2);
            t.put(tt[0], Integer.parseInt(tt[1]));
        }
        
        int todayDateValue = toDate(year, month, day);
        
        // 오늘 날짜를 기준으로 연/달/일을 계산하여 terms 기간이 지났는지 확인한다
        List<Integer> answer = new ArrayList<>();
        int i = 1;
        for(String p : privacies){
            String pp[] = p.split(" ", 2);
            int m = t.getOrDefault(pp[1], 0);
            
            String pDate[] = pp[0].split("[.]", 3);
            int pYear =  Integer.parseInt(pDate[0]);
            int pMonth =  Integer.parseInt(pDate[1]);
            int pDay =  Integer.parseInt(pDate[2]);
            int pDateValue = toDate(pYear, pMonth, pDay);
            
            if (todayDateValue >= pDateValue + (m * 28)){
                answer.add(i);
            }
            i++;
        }
        
        int awr[] = new int[answer.size()];
        for(int x=0; x<answer.size(); x++){
            awr[x] = answer.get(x);
        }
        return awr;
    }
    
    private int toDate(int y, int m, int d){
        return y * 12 * 28 + m * 28 + d;
    }
}