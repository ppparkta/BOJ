//  하노이 탑 이동 순서

import java.util.*;
import java.lang.*;
import java.io.*;

class Main {

    public static StringBuilder SB = new StringBuilder();
    public static int ans = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        move(1, 3, n);
        System.out.println(ans);
        System.out.println(SB.toString());
    }

    private static void move(int start, int end, int n) {
        // n-1개 원판을 start에서 6-start-end로 이동한다
        if (n == 1) {
            SB.append(start + " " + end + "\n");
            ans++;
            return;
        }
        move(start, 6 - start - end, n - 1);
        // n번째 원판을 start->end로 이동한다
        SB.append(start + " " + end + "\n");
        ans++;
        // n-1개 원판을 6-start-end에서 end로 이동한다
        move(6 - start - end, end, n - 1);
    }
}
