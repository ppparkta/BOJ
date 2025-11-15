//  1로 만들기

import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        Deque<int[]> dq = new ArrayDeque<>();
        dq.offer(new int[]{n, 0});
        while (!dq.isEmpty()) {
            int poll[] = dq.poll();
            int cur = poll[0];
            int sum = poll[1];
            if (cur == 1) {
                System.out.println(sum);
                break;
            }
            if (cur < 1) {
                continue;
            }
            if (cur % 3 == 0) {
                dq.offer(new int[]{cur / 3, sum + 1});
            }
            if (cur % 2 == 0) {
                dq.offer(new int[]{cur / 2, sum + 1});
            }
            dq.offer(new int[]{cur - 1, sum + 1});
        }
    }
}
