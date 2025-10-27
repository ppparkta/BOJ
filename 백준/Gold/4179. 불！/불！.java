//  불!

import java.util.*;
import java.lang.*;
import java.io.*;

// 불과 지훈이를 동시에 queue에 넣고 시간을 흘려보낸다.
// 지훈이가 이동하는 방향은 기록하지 않고 현재 좌표만 움직이며 확인한다.
class Main {

    public static int r, c, jy, jx;
    public static char arr[][];
    public static int answer[][];
    public static boolean visited[][];
    public static int firedTime[][];
    public static int dx[] = {0, 0, 1, -1};
    public static int dy[] = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());

        arr = new char[r][c];
        answer = new int[r][c];
        firedTime = new int[r][c];
        visited = new boolean[r][c];

        for (int i = 0; i < r; i++) {
            Arrays.fill(firedTime[i], Integer.MAX_VALUE);
        }

        // 같은 큐에 visited를 다르게 표기한다.
        // 중간에 검사한다??
        Deque<int[]> dq = new ArrayDeque<>();

        for (int i = 0; i < r; i++) {
            String s = br.readLine();
            for (int j = 0; j < c; j++) {
                answer[i][j] = -1;
                arr[i][j] = s.charAt(j);
                if (s.charAt(j) == 'J') {
                    jy = i;
                    jx = j;
                    answer[jy][jx] = 1;
                }
                if (s.charAt(j) == 'F') {
                    firedTime[i][j] = 0;
                    visited[i][j] = true;
                    dq.offer(new int[]{i, j});
                }
            }
        }

        // 일단 불이 언제 타는지 계산해보자
        while (!dq.isEmpty()) {
            int[] poll = dq.poll();
            int cy = poll[0];
            int cx = poll[1];
            for (int i = 0; i < 4; i++) {
                int ny = dy[i] + cy;
                int nx = dx[i] + cx;
                if (ny < 0 || ny >= r || nx < 0 || nx >= c) {
                    continue;
                }
                if (visited[ny][nx] == true || arr[ny][nx] == '#') {
                    continue;
                }
                firedTime[ny][nx] = firedTime[cy][cx] + 1;
                visited[ny][nx] = true;
                dq.offer(new int[]{ny, nx});
            }
        }
        dq.clear();
//        for (int i = 0; i < c; i++) {
//            for (int j = 0; j < r; j++) {
//                System.out.print(firedTime[i][j]);
//            }
//            System.out.println();
//        }

        // 그 다음에 지훈이가 지나갈 수 있는 시간대 + 길을 계산하자.
        visited = new boolean[r][c];
        visited[jy][jx] = true;
        dq.offer(new int[]{jy, jx});
        while (!dq.isEmpty()) {
            int[] poll = dq.poll();
            int cy = poll[0];
            int cx = poll[1];
            for (int i = 0; i < 4; i++) {
                int ny = dy[i] + cy;
                int nx = dx[i] + cx;
                if (ny < 0 || ny >= r || nx < 0 || nx >= c) {
                    continue;
                }
                if (visited[ny][nx] == true || (arr[ny][nx] == '#')) {
                    continue;
                }
                if (firedTime[ny][nx] < answer[cy][cx] + 1) {
                    continue;
                }
                visited[ny][nx] = true;
                answer[ny][nx] = answer[cy][cx] + 1;
                dq.offer(new int[]{ny, nx});
            }
        }

//        for (int i = 0; i < c; i++) {
//            for (int j = 0; j < r; j++) {
//                System.out.print(answer[i][j]);
//            }
//            System.out.println();
//        }

        int max = findMax();
        if (max == -1) {
            System.out.println("IMPOSSIBLE");
        } else {
            System.out.println(max);
        }
    }

    private static int findMax() {
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (i == 0 || i == r - 1 || j == 0 || j == c - 1) {
                    if (answer[i][j] != -1) {
                        ans = Math.min(ans, answer[i][j]);
                    }
                }
            }
        }
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}
