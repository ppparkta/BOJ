
import java.util.*;
import java.lang.*;
import java.io.*;

// N-Queen
// https://www.acmicpc.net/problem/9663
// 문제 이해하기: N*N 크기의 체스판에 퀸을 N개 넣어야 한다. 고로 depth를 N으로 잡아야 함! (같은 행/열/대각 제외시키기, 시작지점은 항상 첫번째 열부터임)
class Main {

    static int n;
    static int arr[];
    static int answer = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        arr = new int[n];

        fillOut(0);
        System.out.println(answer);
    }

    private static void fillOut(int r) {
        if (r == n) {
            answer++;
            return;
        }
        for (int i = 0; i < n; i++) {
            arr[r] = i;
            if (check(r)) {
                fillOut(r + 1);
            }
        }
    }

    private static boolean check(int r) {
        for (int i = 0; i < r; i++) {
            if (arr[i] == arr[r]) {
                return false;
            }
            if (Math.abs(r - i) == Math.abs(arr[r] - arr[i])) {
                return false;
            }
        }
        return true;
    }
}
