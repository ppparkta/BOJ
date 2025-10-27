//  그림

import java.util.*;
import java.lang.*;
import java.io.*;

class Main {

    public static int dx[] = {0, 0, 1, -1};
    public static int dy[] = {1, -1, 0, 0};
    public static boolean visited[][];
    public static int answer = 0;
    public static int maxSize = 0;
    public static int n, m, arr[][];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        arr = new int[n][m];

        // 캔버스 그리기
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        visited = new boolean[n][m];

        // 그림 순회하며 개수 찾기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] == true) {
                    continue;
                }
                if (arr[i][j] == 1) {
                    int size = dfs(i, j);
                    maxSize = maxSize < size ? size : maxSize;
                    answer++;
                }
            }
        }
        System.out.println(answer);
        System.out.println(maxSize);
    }

    // 지나간 곳 지우기
    private static void bfs(int y, int x) {
        Deque<int[]> dq = new ArrayDeque<>();
        dq.offer(new int[]{y, x});
        visited[y][x] = true;
        int buffer = 1;

        while (!dq.isEmpty()) {
            int[] poll = dq.poll();
            for (int i = 0; i < 4; i++) {
                int ny = poll[0] + dy[i];
                int nx = poll[1] + dx[i];
                if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                    continue;
                }
                if (visited[ny][nx] == true || arr[ny][nx] == 0) {
                    continue;
                }
                visited[ny][nx] = true;
                dq.offer(new int[]{ny, nx});
                buffer++;
            }
        }
        maxSize = maxSize < buffer ? buffer : maxSize;
    }

    private static int dfs(int y, int x) {
        visited[y][x] = true;
        int answer = 1;
        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                continue;
            }
            if (visited[ny][nx] == true || arr[ny][nx] == 0) {
                continue;
            }
            visited[ny][nx] = true;
            answer += dfs(ny, nx);
        }
        return answer;
    }
}
