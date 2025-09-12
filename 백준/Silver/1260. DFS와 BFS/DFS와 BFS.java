
import java.util.*;
import java.lang.*;
import java.io.*;

//  DFS와 BFS
// https://www.acmicpc.net/problem/1260
class Main {
    static int n;
    static int m;
    static int k;
    static List<List<Integer>> arr;
    static boolean visitDfs[];
    static boolean visitBfs[];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        visitDfs = new boolean[n + 1];
        visitBfs = new boolean[n + 1];
        arr = new ArrayList<>(n + 1);
        for (int i = 0; i <= n; i++) {
            arr.add(new ArrayList<>());
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            arr.get(a).add(b);
            arr.get(b).add(a);
        }
        for (int i = 0; i <= n; i++) {
            Collections.sort(arr.get(i));
        }
        System.out.print(k + " ");
        visitDfs[k] = true;
        dfs(k, 0);
        bfs();
    }

    private static void dfs(int node, int depth) {
        if (depth == n) {
            return;
        }
        for (int i = 0; i < arr.get(node).size(); i++) {
            if (visitDfs[arr.get(node).get(i)] == true) {
                continue;
            }
            System.out.print(arr.get(node).get(i) + " ");
            visitDfs[arr.get(node).get(i)] = true;
            dfs(arr.get(node).get(i), depth + 1);
        }
    }

    private static void bfs() {
        Deque<Integer> queue = new ArrayDeque<>();
        StringBuilder sb = new StringBuilder();
        int node = k;
        sb.append("\n" + node + " ");
        queue.push(node);
        visitBfs[node] = true;
        while (!queue.isEmpty()) {
            node = queue.pop();
            for (int i = 0; i < arr.get(node).size(); i++) {
                if (visitBfs[arr.get(node).get(i)] == true) {
                    continue;
                }
                queue.offer(arr.get(node).get(i));
                sb.append(arr.get(node).get(i) + " ");
                visitBfs[arr.get(node).get(i)] = true;
            }
        }
        System.out.println(sb.toString());
    }
}
