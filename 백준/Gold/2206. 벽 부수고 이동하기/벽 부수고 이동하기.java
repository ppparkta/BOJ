//  벽 부수고 이동하기

import java.util.*;
import java.lang.*;
import java.io.*;

class Main {

    public static int dx[] = {0, 0, 1, -1};
    public static int dy[] = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int arr[][] = new int[n][m];

        // 1차원 0: 벽을 뚫지 않았을 때, 1: 벽을 뚫었을 때
        int answer[][][] = new int[n][m][2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                answer[i][j][0] = Integer.MAX_VALUE;
                answer[i][j][1] = Integer.MAX_VALUE;
            }
        }
        answer[0][0][0] = 1;
        boolean visited[][][] = new boolean[n][m][2];

        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = s.charAt(j) - '0';
            }
        }

        Deque<int[]> dq = new ArrayDeque<>();
        dq.offer(new int[]{0, 0, 0});
        while (!dq.isEmpty()) {
            int[] poll = dq.poll();
            int cy = poll[0];
            int cx = poll[1];
            int broken = poll[2];
            if (cy == n - 1 && cx == m - 1) {
                System.out.println(answer[n - 1][m - 1][broken]);
                return;
            }
            for (int i = 0; i < 4; i++) {
                int ny = cy + dy[i];
                int nx = cx + dx[i];
                // 범위를 벗어난 경우
                if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                    continue;
                }
                if (arr[ny][nx] == 1) {
                    if (broken == 1) {
                        continue;
                    }
                    if (visited[ny][nx][1] == true) {
                        continue;
                    }
                    visited[ny][nx][1] = true;
                    answer[ny][nx][1] = answer[cy][cx][0] + 1;
                    dq.offer(new int[]{ny, nx, 1});
                    continue;
                }
                if (arr[ny][nx] == 0) {
                    if (visited[ny][nx][broken] == true) {
                        continue;
                    }
                    visited[ny][nx][broken] = true;
                    answer[ny][nx][broken] = answer[cy][cx][broken] + 1;
                    dq.offer(new int[]{ny, nx, broken});
                }
            }
        }
        System.out.println(-1);
    }
}
