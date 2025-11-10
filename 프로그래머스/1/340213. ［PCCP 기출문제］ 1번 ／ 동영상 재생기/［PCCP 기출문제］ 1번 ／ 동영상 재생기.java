class Solution {
    
    // prev -> 10전, next->10후, 그런데 오프닝 구간은 무조건 op_end로 이동
    public String solution(
        String video_len, 
        String pos, 
        String op_start,
        String op_end, 
        String[] commands
    ) {
        // 분->초 환산
        String[] leng = video_len.split(":");
        int time = Integer.parseInt(leng[0]) * 60 + Integer.parseInt(leng[1]);
        
        String[] post=pos.split(":");
        int pos_time = Integer.parseInt(post[0]) * 60 + Integer.parseInt(post[1]);
        
        String[] start = op_start.split(":");
        int start_time =  Integer.parseInt(start[0]) * 60 + Integer.parseInt(start[1]);
        
        String[] end = op_end.split(":");
        int end_time =  Integer.parseInt(end[0]) *60 + Integer.parseInt(end[1]);
       
        // 연산
        if (pos_time >= start_time && pos_time < end_time) {
            pos_time = end_time;
        }
        for(String cmd:commands) {
            if(cmd.equals("prev")) {
                if (pos_time - 10 < 0) {
                    pos_time = 0;
                } else {
                    pos_time-=10;
                }
            }
            else {
                if (pos_time + 10 > time){
                    pos_time = time;
                } else {
                    pos_time+=10;
                }
            }
            
            if (pos_time >= start_time && pos_time < end_time) {
                pos_time = end_time;
            }
        }
        
        // 정답 변환
        int m = pos_time / 60;
        int s = pos_time % 60;
        StringBuilder sb=new StringBuilder();
        if(m<10) {
            sb.append("0");
        }
        sb.append(m);
        sb.append(":");
        if(s<10) {
            sb.append("0");
        }
        sb.append(s);
        
        String answer = sb.toString();
        return answer;
    }
}