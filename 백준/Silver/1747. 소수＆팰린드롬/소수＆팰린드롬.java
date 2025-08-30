import java.util.*;
import java.lang.*;
import java.io.*;

// 소수&팰린드롬
// https://www.acmicpc.net/problem/1747
class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int arr[] = new int[10_000_000 + 1];
        int answer = 0;

        arr[0] = 0;
        arr[1] = 0;
        for (int i = 2; i <= 10_000_000; i++) {
            arr[i] = i;
        }
        int sqrt = (int) Math.sqrt(10_000_000);
        for (int i = 2; i <= sqrt; i++) {
            if (arr[i] == 0) {
                continue;
            }
            for (int j = i + i; j <= 10_000_000; j += i) {
                arr[j] = 0;
            }
        }
        int idx = n;
        while (true) {
            if (arr[idx] == 0) {
                idx++;
                continue;
            }
            if (isPal(arr[idx])) {
                System.out.println(arr[idx]);
                break;
            }
            idx++;
        }
    }

    public static boolean isPal(int n) {
        String str = n + "";
        StringBuilder sb = new StringBuilder();
        for (int j = str.length() - 1; j >= 0; j--) {
            sb.append(str.charAt(j));
        }
        int reverseInt = Integer.parseInt(sb.toString());
        if (n == reverseInt) {
            return true;
        }
        return false;
    }
}
