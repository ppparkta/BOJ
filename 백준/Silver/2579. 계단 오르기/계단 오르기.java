//  계단 오르기

import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n + 1];
        int dp[] = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            arr[i] = sc.nextInt();
            dp[i] = 0;
        }
        dp[1] = arr[1];
        if (n >= 2) {
            dp[2] = dp[1] + arr[2];
        }
        if (n >= 3) {
            dp[3] = Math.max(arr[2] + arr[3], dp[1] + arr[3]);
        }
        if (n >= 4) {
            for (int i = 4; i <= n; i++) {
                dp[i] = Math.max(dp[i - 2] + arr[i], (arr[i - 1] + arr[i] + dp[i - 3]));
            }
        }
        System.out.println(dp[n]);
    }
}
