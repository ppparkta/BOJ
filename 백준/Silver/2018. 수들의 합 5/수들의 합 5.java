//  수들의 합 5

import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int answer = 0;
        int arr[] = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            arr[i] = i;
        }
        int sum = 0;
        for (int start = 1; start <= n; start++) {
            for (int end = start; end <= n; end++) {
                sum += arr[end];
                if (sum == n) {
                    answer++;
                }
                if (sum >= n) {
                    sum = 0;
                    break;
                }
            }
        }
        System.out.println(answer);
    }
}
