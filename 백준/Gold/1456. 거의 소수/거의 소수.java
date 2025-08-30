import java.util.*;
import java.lang.*;
import java.io.*;

// 거의 소수
// https://www.acmicpc.net/problem/1456
class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long m = Long.parseLong(st.nextToken());
        long n = Long.parseLong(st.nextToken());

        int answer = 0;
        long sosue[] = new long[(int) Math.sqrt(n) + 1];
        for (int i = 1; i <= (int) Math.sqrt(n); i++) {
            sosue[i] = i;
        }
        for (int i = 2; i <= (int) Math.sqrt(n); i++) {
            if (sosue[i] == 0) {
                continue;
            }
            int idx = 2;
            double pow = Math.pow(i, idx);
            while (pow <= n) {
                pow = Math.pow(i, idx);
                if ((long) pow >= m && (long) pow <= n) {
                    answer++;
                }
                idx++;
            }
            for (int j = i + i; j <= (int) Math.sqrt(n); j += i) {
                sosue[j] = 0;
            }
        }
        System.out.println(answer);
    }
}
