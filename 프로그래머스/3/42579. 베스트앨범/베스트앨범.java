import java.util.*;

class Solution {
    
    public int[] solution(String[] genres, int[] plays) {
        // 장르 별로 분리
        // 0: idx, 1: count
        Map<String, List<int[]>> pl = new HashMap<>();
        Map<String, Integer> sum = new HashMap<>();
        
        for(int i=0;i<genres.length;i++){
            pl.computeIfAbsent(genres[i], k->new ArrayList<>()).add(new int[]{i, plays[i]});
            sum.put(genres[i], sum.getOrDefault(genres[i], 0) + plays[i]);
        }
        
        // 전체합 기준 정렬 
        // 막힌 부분: 커스텀 정렬을 사용할줄 모름
        List<String> plG = new ArrayList<>(sum.keySet());
        plG.sort((a,b)-> sum.get(b) - sum.get(a));
        
        // 플레이 내림차순->인덱스 오름차순
        for(String g : plG) {
            List<int[]> list = pl.get(g);
            list.sort((a,b)-> {
                if (b[1] == a[1]) return a[0] - b[0];
                return b[1] - a[1];
            });
        }
        
        List<Integer> result = new ArrayList<>();
        for (String g : plG) {
            List<int[]> list = pl.get(g);
            result.add(list.get(0)[0]); 
            // 최대 두개씩 저장해야 함
            if (list.size() > 1) {
                result.add(list.get(1)[0]);
            }
        }
        
        int answer[] = new int[result.size()];
        for(int i=0;i<answer.length;i++){
            answer[i] = result.get(i);
        }
        return answer;
    }
}