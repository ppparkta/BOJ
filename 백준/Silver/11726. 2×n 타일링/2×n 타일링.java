//  2×n 타일링

import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int dp[] = new int[n + 1];
        dp[0] = 0;

        dp[1] = 1;
        if (n >= 2) {
            dp[2] = 2;
        }
        if (n >= 3) {
            for (int i = 3; i <= n; i++) {
                // -> 한칸 적다면 마지막에 한줄만 추가하면 됨
                // -> 두칸 적다면 마지막에 두줄짜리 추가하면 됨
                dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
            }
        }
        System.out.println(dp[n]);
    }
}
