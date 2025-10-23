//  미로 탐색

import java.util.*;
import java.lang.*;
import java.io.*;

class Main {

    public static int dx[] = {0, 0, 1, -1};
    public static int dy[] = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        //y
        int n = Integer.parseInt(st.nextToken());
        // x
        int m = Integer.parseInt(st.nextToken());

        int arr[][] = new int[n][m];

        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = s.charAt(j) - '0';
            }
        }

        Deque<int[]> dq = new ArrayDeque<>();
        boolean visited[][] = new boolean[n][m];
        int dist[][] = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dist[i][j] = Integer.MAX_VALUE;
            }
        }

        dq.offer(new int[]{0, 0});
        visited[0][0] = true;
        dist[0][0] = 1;

        while (!dq.isEmpty()) {
            int[] poll = dq.poll();
            int y = poll[0];
            int x = poll[1];
//            System.out.println("y: " + y + ", x: " + x);
            if (y == n - 1 && x == m - 1) {
                System.out.println(dist[y][x]);
                break;
            }
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                    continue;
                }
                if (visited[ny][nx] == true || arr[ny][nx] == 0) {
                    continue;
                }
                visited[ny][nx] = true;
                dist[ny][nx] = Math.min(dist[ny][nx], dist[y][x] + 1);
                dq.offer(new int[]{ny, nx});
            }
        }

    }
}
