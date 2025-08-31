import java.util.*;
import java.lang.*;
import java.io.*;

// 제곱 ㄴㄴ 수
// https://www.acmicpc.net/problem/1016
class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long m = Long.parseLong(st.nextToken());
        long n = Long.parseLong(st.nextToken());

        boolean[] check = new boolean[(int) (n - m + 1)];
        int answer = 0;

        for (long i = 2; i * i <= n; i++) {
            long pow = i * i;
            long startIdx = m / pow;
            if (m % pow != 0) {
                startIdx++;
            }
            for (long j = startIdx; pow * j <= n; j++) {
                check[(int) ((j * pow) - m)] = true;
            }
        }
        for (int i = 0; i <= n - m; i++) {
            if (!check[i]) {
                answer++;
            }
        }
        System.out.println(answer);
    }
}
