import java.util.*;
import java.lang.*;
import java.io.*;

// 수 묶기
// https://www.acmicpc.net/problem/1744
class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Integer> positive = new ArrayList<>();
        List<Integer> negative = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int a = Integer.parseInt(br.readLine());
            if (a > 0) {
                positive.add(a);
            } else {
                negative.add(a);
            }
        }
        positive.sort(Collections.reverseOrder());
        Collections.sort(negative);
        int answer = 0;

        while (!positive.isEmpty()) {
            if (positive.get(0) == 1) {
                answer += positive.remove(0);
            } else if (positive.size() >= 2) {
                int a = positive.remove(0);
                int b = positive.remove(0);
                if (a > 1 && b > 1) {
                    answer += a * b;
                } else {
                    answer += a + b;
                }
            } else {
                answer += positive.remove(0);
            }
        }
        while (!negative.isEmpty()) {
            if (negative.size() >= 2) {
                answer += negative.remove(0) * negative.remove(0);
            } else {
                answer += (negative.remove(0));
            }
        }
        System.out.println(answer);
    }
}
