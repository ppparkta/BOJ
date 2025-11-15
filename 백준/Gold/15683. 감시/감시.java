//  감시

import java.util.*;
import java.lang.*;
import java.io.*;

class Main {

    public static int arr[][];
    public static List<int[]> point = new ArrayList<>();
    public static Map<String, Boolean> visited = new HashMap<>();
    public static int n, m, ans = 0, totalZero = 0;
    // 0상 1하 2좌 3우
    public static int dy[] = {1, -1, 0, 0};
    public static int dx[] = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        // 그래프 그리기
        arr = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                int val = Integer.parseInt(st.nextToken());
                arr[i][j] = val;
                if (val != 0 && val != 6) {
                    point.add(new int[]{i, j, val});
                }
                if (val == 0) {
                    totalZero++;
                }
            }
        }
        // 탐색 시작
        // 깊이, 방문여부, 이동한 값
        dfs(0, new boolean[n][m], 0);
        System.out.println(totalZero - ans);
    }

    private static void dfs(int d, boolean v[][], int sum) {
        if (d == point.size()) {
            ans = Math.max(ans, sum);
            return;
        }
        int y = point.get(d)[0];
        int x = point.get(d)[1];
        int val = point.get(d)[2];
        int dist[][];

        if (val == 1) {
            dist = new int[][]{{0}, {1}, {2}, {3}};
        } else if (val == 2) {
            dist = new int[][]{{0, 1}, {2, 3}};
        } else if (val == 3) {
            dist = new int[][]{{0, 3}, {3, 1}, {1, 2}, {2, 0}};
        } else if (val == 4) {
            dist = new int[][]{{0, 3, 1}, {3, 1, 2}, {1, 2, 0}, {2, 0, 3}};
        } else {
            dist = new int[][]{{0, 1, 2, 3}};
        }

        boolean nv[][] = new boolean[n][m];

        for (int i = 0; i < dist.length; i++) {
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < m; c++) {
                    nv[r][c] = v[r][c];
                }
            }
            int tmp = sum;
            for (int j = 0; j < dist[i].length; j++) {
                int ny = y + dy[dist[i][j]];
                int nx = x + dx[dist[i][j]];
                while (ny >= 0 && ny < n && nx >= 0 && nx < m) {
                    if (arr[ny][nx] == 6) {
                        break;
                    }
                    if (nv[ny][nx] != true && arr[ny][nx] == 0) {
                        nv[ny][nx] = true;
                        tmp++;
                    }
                    ny = ny + dy[dist[i][j]];
                    nx = nx + dx[dist[i][j]];
                }
            }
            dfs(d + 1, nv, tmp);
        }
    }
}
