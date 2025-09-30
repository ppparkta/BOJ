import java.util.*;

class Solution {
    public String[] solution(String[] record) {
        
        Map<String, String> users = new HashMap<>();
        List<Pair> records = new ArrayList<>();
        for(String re : record) {
            String arr[] = re.split(" ", 3);
            if (arr[0].equals("Enter") || arr[0].equals("Change")){
                users.put(arr[1], arr[2]);
            }
            records.add(new Pair(arr[1], arr[0]));
        }
        List<String> answer = new ArrayList<>();
        for(Pair pair:records){
            String name = users.get(pair.getA());
            String c = pair.getB();
            StringBuilder sb = new StringBuilder();
            if(c.equals("Enter")){
                sb.append(name);
                sb.append("님이 들어왔습니다.");
                answer.add(sb.toString());
            }
            if (c.equals("Leave")){
                sb.append(name);
                sb.append("님이 나갔습니다.");
                answer.add(sb.toString());
            }
        }
        String awr[] = new String[answer.size()];
        int idx = 0;
        for(String a:answer){
            awr[idx++] = a;
        }
        return awr;
    }
    
    public static class Pair{
        private String a;
        private String b;
        
        public Pair(String a, String b){
            this.a=a;
            this.b=b;
        }
        
        public String getA(){
            return this.a;
        }
        
        public String getB(){
            return this.b;
        }
    }
}
