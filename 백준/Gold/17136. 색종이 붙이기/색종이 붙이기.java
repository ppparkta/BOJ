import java.awt.print.Pageable;
import java.util.*;
import java.lang.*;
import java.io.*;

// 색종이 붙이기
// https://www.acmicpc.net/problem/17136
class Main {

    static int answer = 2_100_000_000;
    static int size[] = {0, 5, 5, 5, 5, 5};
    static int arr[][];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        arr = new int[10][10];
        for (int i = 0; i < 10; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 10; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        checkAndFillOut(0, 0);
        if (answer != 2_100_000_000) {
            System.out.println(answer);
        } else {
            System.out.println("-1");
        }
    }

    private static void checkAndFillOut(int xy, int used) {
        if (xy == 100) {
            answer = Math.min(answer, used);
            return;
        }
        if (answer < used) {
            return;
        }
        int sy = xy / 10;
        int sx = xy % 10;
        if (arr[sy][sx] == 1) {
            for (int i = 5; i > 0; i--) {
                if (size[i] > 0 && checkRange(sy, sx, i)) {
                    size[i]--;
                    fillOut(sy, sx, i, 0);
                    checkAndFillOut(xy + 1, used + 1);
                    fillOut(sy, sx, i, 1);
                    size[i]++;
                }
            }
        } else {
            checkAndFillOut(xy + 1, used);
        }
    }

    private static boolean checkRange(int y, int x, int s) {
        // 범위가 최대값을 넘어가면 안 됨
        if (y + s > 10 || x + s > 10) {
            return false;
        }
        for (int ny = y; ny < y + s; ny++) {
            for (int nx = x; nx < x + s; nx++) {
                if (arr[ny][nx] == 0) {
                    return false;
                }
            }
        }
        return true;
    }

    private static void fillOut(int y, int x, int s, int num) {
        for (int ny = y; ny < y + s; ny++) {
            for (int nx = x; nx < x + s; nx++) {
                arr[ny][nx] = num;
            }
        }
    }
}
