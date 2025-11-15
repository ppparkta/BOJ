//  계단 오르기

import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n + 1];
        int dp[][] = new int[n + 1][3];
        for (int i = 1; i <= n; i++) {
            arr[i] = sc.nextInt();
        }
        dp[1][1] = arr[1];
        dp[1][2] = arr[0];
        if (n >= 2) {
            dp[2][1] = arr[2];
            dp[2][2] = arr[1] + arr[2];
        }
        if (n >= 3) {
            dp[3][1] = Math.max(dp[1][1], dp[1][2]) + arr[3];
            dp[3][2] = dp[2][1] + arr[3];
        }
        if (n >= 4) {
            for (int i = 4; i <= n; i++) {
                dp[i][1] = Math.max(dp[i - 2][1], dp[i - 2][2]) + arr[i];
                dp[i][2] = dp[i - 1][1] + arr[i];
            }
        }
        System.out.println(Math.max(dp[n][1], dp[n][2]));
    }
}
