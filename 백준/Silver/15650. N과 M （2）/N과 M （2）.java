import java.util.*;
import java.lang.*;
import java.io.*;

// N과 M (2)
// https://www.acmicpc.net/problem/15650
class Main {

    static int m;
    static int n;
    static boolean visited[];
    static int answer[];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        visited = new boolean[n + 1];

        for (int i = 1; i <= n; i++) {
            answer = new int[m];
            visited[i] = true;
            answer[0] = i;
            dfs(i, 1);
            visited[i] = false;
        }
    }

    private static void dfs(int node, int depth) {
        if (depth == m) {
            for (int i = 0; i < m; i++) {
                System.out.print(answer[i] + " ");
            }
            System.out.println();
            return;
        }
        for (int i = node + 1; i <= n; i++) {
            if (visited[i] == true) {
                continue;
            }
            visited[i] = true;
            answer[depth] = i;
            dfs(i, depth + 1);
            visited[i] = false;
        }
    }
}
