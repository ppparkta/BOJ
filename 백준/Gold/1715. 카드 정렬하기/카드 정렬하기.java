
import java.util.*;
import java.lang.*;
import java.io.*;

// 카드 정렬하기
// https://www.acmicpc.net/problem/1715
class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        PriorityQueue<Integer> q = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            q.add(Integer.parseInt(br.readLine()));
        }
        int answer = 0;
        while (q.size() != 1) {
            int a = q.remove();
            int b = q.remove();
            answer += a + b;
            q.add(a + b);
        }
        System.out.println(answer);
    }
}
