//  미로 탐색

import java.util.*;
import java.lang.*;
import java.io.*;

class Main {

    public static int dx[] = {0, 0, -1, 1};
    public static int dy[] = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        // n개의 줄
        int n = Integer.parseInt(st.nextToken());
        // m개의 정수
        int m = Integer.parseInt(st.nextToken());

        int arr[][] = new int[n][m];

        // 그래프 채우기
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(String.valueOf(s.charAt(j)));
            }
        }

        // 반복하며 이동하기
        boolean visited[][] = new boolean[n][m];
        int dist[][] = new int[n][m];
        Deque<Pair> deque = new ArrayDeque<>();
        // x, y 순서로 삽입
        deque.offer(new Pair(0, 0));
        visited[0][0] = true;
        dist[0][0] = 1;
        while (!deque.isEmpty()) {
            Pair removed = deque.poll();
            int x = removed.getX();
            int y = removed.getY();
            if (x == m - 1 && y == n - 1) {
                System.out.println(dist[y][x]);
                break;
            }
            for (int i = 0; i < 4; i++) {
                int sx = dx[i];
                int sy = dy[i];
                int nx = sx + x;
                int ny = sy + y;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                    continue;
                }
                if (arr[ny][nx] == 0 || visited[ny][nx] == true) {
                    continue;
                }
                visited[ny][nx] = true;
                dist[ny][nx] = dist[y][x] + 1;
                deque.offer(new Pair(nx, ny));
            }
        }
    }

    static class Pair {
        public int x;
        public int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }
    }
}
