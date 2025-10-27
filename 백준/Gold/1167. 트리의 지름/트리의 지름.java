//  트리의 지름

import java.util.*;
import java.lang.*;
import java.io.*;

// 트리의 성질
// 트리는 무방향 & 거리는 가중치로 표시한다. 따라서 양 노드 간 거리가 항상 같다.
// 트리는 항상 연결되어 있다.
// 따라서 임의의 노드에서 가장 먼 노드를 찾고 그 노드와 가장 먼 노드를 구하면 트리의 노드 간 최대 거리를 구할 수 있다.
class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        List<List<Pair>> arr = new ArrayList<>(n + 1);
        for (int i = 0; i <= n; i++) {
            arr.add(new ArrayList<>());
        }

        // 트리를 그린다
        for (int i = 1; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int o = Integer.parseInt(st.nextToken());
            while (st.hasMoreTokens()) {
                int token = Integer.parseInt(st.nextToken());
                if (token == -1) {
                    break;
                }
                int value = Integer.parseInt(st.nextToken());
                arr.get(o).add(new Pair(token, value));
            }
        }

        // 트리의 아무 정점에서 가장 먼 정점을 찾는다
        // 내 임의의 정점-> 임의로 1로 설정
        Deque<Integer> dq = new ArrayDeque<>();
        dq.offer(1);

        int firstAnswer[] = new int[n + 1];
        boolean visited[] = new boolean[n + 1];

        firstAnswer[1] = 0;
        visited[1] = true;

        while (!dq.isEmpty()) {
            int now = dq.poll();
            List<Pair> pairs = arr.get(now);
            for (int i = 0; i < pairs.size(); i++) {
                if (visited[pairs.get(i).getN()] == true) {
                    continue;
                }
                dq.offer(pairs.get(i).getN());
                visited[pairs.get(i).getN()] = true;
                firstAnswer[pairs.get(i).getN()] = firstAnswer[now] + pairs.get(i).getV();
            }
        }
        int maxN = -1;
        int idx = 1;
        for (int i = 1; i <= n; i++) {
            if (maxN < firstAnswer[i]) {
                idx = i;
                maxN = firstAnswer[i];
            }
        }

        // 가장 먼 정점으로부터 가장 먼 정점 사이의 거리를 구한다 -> 거리가 정답!
        dq = new ArrayDeque<>();
        dq.offer(idx);

        int answer[] = new int[n + 1];
        visited = new boolean[n + 1];

        answer[idx] = 0;
        visited[idx] = true;

        while (!dq.isEmpty()) {
            int now = dq.poll();
            List<Pair> pairs = arr.get(now);
            for (int i = 0; i < pairs.size(); i++) {
                if (visited[pairs.get(i).getN()] == true) {
                    continue;
                }
                dq.offer(pairs.get(i).getN());
                visited[pairs.get(i).getN()] = true;
                answer[pairs.get(i).getN()] = answer[now] + pairs.get(i).getV();
            }
        }

        int answerValue = -1;
        for (int i = 1; i <= n; i++) {
            answerValue = Math.max(answerValue, answer[i]);
        }
        System.out.println(answerValue);
    }

    public static class Pair {
        public int n;
        public int v;

        public Pair(int n, int v) {
            this.n = n;
            this.v = v;
        }

        public int getN() {
            return n;
        }

        public int getV() {
            return v;
        }
    }
}
