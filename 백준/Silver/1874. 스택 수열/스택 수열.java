import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[100001];
        List<String> result = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
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
