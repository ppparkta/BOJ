import java.util.*;
import java.lang.*;
import java.io.*;

//  에라토스테네스의 체
// https://www.acmicpc.net/problem/2960
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int count = 0;

        int arr[] = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            arr[i] = i;
        }
        for (int i = 2; i <= n; i++) {
            if (arr[i] == 0) {
                continue;
            }
            for (int j = i; j <= n; j += i) {
                if (arr[j] == 0) {
                    continue;
                }
                count++;
                arr[j] = 0;
                if (count == k) {
                    System.out.println(j);
                    return;
                }
            }
        }
    }
}
