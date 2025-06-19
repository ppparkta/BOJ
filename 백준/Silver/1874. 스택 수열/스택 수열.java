import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        Stack<Integer> stack = new Stack<>();
        stack.push(0);
        int current = 0;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            Integer n1 = arr[i];
            for (int cur = current + 1; cur <= n1; cur++) {
                stack.push(cur);
                sb.append("+\n");
                current++;
            }
            for (int cur = stack.get(stack.size() - 1); cur >= arr[i]; cur--) {
                int tmp = stack.get(stack.size() - 1);
                stack.pop();
                sb.append("-\n");
                if (tmp != arr[i]) {
                    System.out.println("NO");
                    return;
                }
            }
        }
        System.out.println(sb);
    }
}
