import java.util.*;
import java.lang.*;
import java.io.*;

// 회의실 배정
// https://www.acmicpc.net/problem/1931
class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        List<Pair> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            arr.add(new Pair(start, end));
        }
        arr.sort((a, b) -> {
            if (a.getEnd() < b.getEnd()) {
                return -1;
            } else if (a.getEnd() == b.getEnd()) {
                if (a.getStart() < b.getStart()) {
                    return -1;
                } else {
                    return 1;
                }
            }
            return 1;
        });
        int end = 0;
        int answer = 0;

        for (Pair p : arr) {
//            System.out.println(p.getStart() + " " + p.getEnd());
            if (p.getStart() >= end) {
//                System.out.println(p.getStart() + "<- A, B ->" + p.getStart());
                answer++;
                end = p.getEnd();
            }
        }
        System.out.println(answer);
    }

    public static class Pair {
        int start;
        int end;

        public Pair(int start, int end) {
            this.start = start;
            this.end = end;
        }

        public int getStart() {
            return start;
        }

        public int getEnd() {
            return end;
        }
    }
}
