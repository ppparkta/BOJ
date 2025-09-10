import java.util.*;
import java.lang.*;
import java.io.*;

//  특정 거리의 도시 찾기
// https://www.acmicpc.net/problem/18352
class Main {

    static int answer[];
    static boolean visit[];
    static List<List<Integer>> arr = new ArrayList<>();
    static int n;
    static int m;
    static int k;
    static int x;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());

        answer = new int[n];
        visit = new boolean[n];
        for (int i = 0; i < n; i++) {
            answer[i] = 2_100_000_000;
            arr.add(new ArrayList<>());
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int prev = Integer.parseInt(st.nextToken());
            int next = Integer.parseInt(st.nextToken());
            arr.get(prev - 1).add(next - 1);
        }

        backtracking(x - 1, 0);

        int result = 0;
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i < n; i++) {
            if (answer[i] == k) {
                result++;
                sb.append(i + 1 + "\n");
            }
        }
        if (result == 0) {
            System.out.println("-1");
        } else {
            System.out.println(sb);
        }
    }

    private static void backtracking(int prev, int depth) {
        if (depth > k || answer[prev] <= depth) {
            return;
        }
        answer[prev] = Math.min(depth, answer[prev]);
        for (int i = 0; i < arr.get(prev).size(); i++) {
            if (visit[arr.get(prev).get(i)]) {
                continue;
            }
            visit[arr.get(prev).get(i)] = true;
            backtracking(arr.get(prev).get(i), depth + 1);
            visit[arr.get(prev).get(i)] = false;
        }
    }
}
