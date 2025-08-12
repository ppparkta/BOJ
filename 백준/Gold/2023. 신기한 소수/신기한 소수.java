//  신기한 소수

import java.util.*;
import java.lang.*;
import java.io.*;

class Main {

    static int n;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        dfs(2, 1);
        dfs(3, 1);
        dfs(5, 1);
        dfs(7, 1);
        System.out.println(sb.toString());
    }

    public static void dfs(int number, int depth) {
        if (depth == n) {
            if (isSosue(number)) {
                sb.append(number + "\n");
            }
            return;
        }
        for (int i = 1; i < 10; i++) {
            if (i % 2 == 0) {
                continue;
            }
            if (isSosue(number * 10 + i)) {
                dfs(number * 10 + i, depth + 1);
            }
        }
    }

    public static boolean isSosue(int number) {
        for (int i = 2; i <= number / 2; i++) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }
}