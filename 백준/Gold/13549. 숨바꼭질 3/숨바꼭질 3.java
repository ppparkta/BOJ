//  숨바꼭질 3

import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();

        // 1초 후 +1/-1, 0초 후 x*2
        // 즉, 0초 후일 때에는 값을 안 더하면 되는거 아닌가?
        int arr[] = new int[100001];
        boolean visited[] = new boolean[100001];
        for (int i = 0; i <= 100000; i++) {
            arr[i] = Integer.MAX_VALUE;
        }
        arr[n] = 0;
        visited[n] = true;
        Deque<Integer> dq = new ArrayDeque<>();
        dq.offer(n);
        while (!dq.isEmpty()) {
            int cur = dq.poll();
            if (cur == k) {
                System.out.println(arr[k]);
            }
            for (int i : new int[]{cur * 2, cur - 1, cur + 1}) {
                if (i < 0 || i > 100000) {
                    continue;
                }
                if (visited[i] == true) {
                    continue;
                }
                visited[i] = true;
                if (i == cur * 2) {
                    arr[i] = arr[cur];
                } else {
                    arr[i] = arr[cur] + 1;
                }
                dq.offer(i);
            }
        }
    }
}
