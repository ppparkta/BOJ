import java.io.*;
import java.util.*;

// 경사로 
// https://www.acmicpc.net/problem/14890
public class Main {
    static int N, L;
    static int[][] arr;

    // 경사로는 겹치면 안 된다
    // 높이는 +-1만 달라질 수 있다
    // 올라갈 때는 여태까지 건너온 동일한 칸이 l 이상이어야 한다
    // 내려갈 때는 앞으로 건널 동일한 칸이 l 이상이어야 한다
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());
        arr = new int[N][N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int answer = 0;
        // 가로
        for (int i = 0; i < N; i++) {
            int[] line = new int[N];
            for (int j = 0; j < N; j++) {
                line[j] = arr[i][j];
            }
            if (canBuild(line, L)) {
                answer++;
            }
        }
        // 세로
        for (int j = 0; j < N; j++) {
            int[] line = new int[N];
            for (int i = 0; i < N; i++) {
                line[i] = arr[i][j];
            }
            if (canBuild(line, L)) {
                answer++;
            }
        }
        System.out.println(answer);
    }

    // 한 줄(line)에 경사로를 놓아 통과 가능한지 판단
    static boolean canBuild(int[] a, int L) {
        boolean[] used = new boolean[N]; // 경사로가 설치된 칸(mark) → 겹침 금지
        for (int i = 0; i < N - 1; i++) {
            int cur = a[i], nxt = a[i + 1];
            if (cur == nxt) {
                continue;
            }
            // 올라감: nxt = cur + 1
            // 직전 L칸이 cur로 연속 & 미사용이어야 함
            if (nxt == cur + 1) {
                // i-L+1 .. i 가 모두 cur
                if (i - L + 1 < 0) {
                    return false;
                }
                for (int k = i - L + 1; k <= i; k++) {
                    if (a[k] != cur || used[k]) {
                        return false;
                    }
                }
                for (int k = i - L + 1; k <= i; k++) {
                    used[k] = true;
                }
            }
            // 내려감: nxt = cur - 1
            // 앞으로 L칸(i+1 .. i+L)이 nxt로 연속 & 미사용이어야 함
            else if (nxt == cur - 1) {
                if (i + L >= N) {
                    return false;
                }
                for (int k = i + 1; k <= i + L; k++) {
                    if (a[k] != nxt || used[k]) {
                        return false;
                    }
                }
                for (int k = i + 1; k <= i + L; k++) {
                    used[k] = true;
                }
            }
            // 차이가 1 초과 → 불가
            else {
                return false;
            }
        }
        return true;
    }
}
