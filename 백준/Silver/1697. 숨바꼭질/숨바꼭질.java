//  숨바꼭질

import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        boolean visited[] = new boolean[100001];
        int answer[] = new int[100001];
        for (int i = 0; i < 100001; i++) {
            answer[i] = Integer.MAX_VALUE;
        }
        int n = sc.nextInt();
        int k = sc.nextInt();

        Deque<Integer> dq = new ArrayDeque<>();
        answer[n] = 0;
        dq.offer(n);
        visited[n] = true;
        while (!dq.isEmpty()) {
            int cur = dq.poll();
            if (cur == k) {
                System.out.println(answer[k]);
                return;
            }
            // 순간이동
            if (cur * 2 <= 100000) {
                if (visited[cur * 2] == false) {
                    answer[cur * 2] = Math.min(answer[cur] + 1, answer[cur * 2]);
                    visited[cur * 2] = true;
                    dq.offer(cur * 2);
                }
            }
            // 앞으로 1칸
            if (cur + 1 <= 100000) {
                if (visited[cur + 1] == false) {
                    answer[cur + 1] = Math.min(answer[cur] + 1, answer[cur + 1]);
                    visited[cur + 1] = true;
                    dq.offer(cur + 1);
                }
            }
            // 뒤로 1칸
            if (cur - 1 >= 0) {
                if (visited[cur - 1] == false) {
                    answer[cur - 1] = Math.min(answer[cur] + 1, answer[cur - 1]);
                    visited[cur - 1] = true;
                    dq.offer(cur - 1);
                }
            }
        }
    }
}
