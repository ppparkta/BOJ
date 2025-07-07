import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Deque<Integer> deque = new ArrayDeque<>();
        for (int i = n; i > 0; i--) {
            deque.push(i);
        }
        while (!deque.isEmpty()) {
            System.out.print(deque.pop() + " ");
            if (!deque.isEmpty()) {
                int swap = deque.pop();
                deque.addLast(swap);
            }
        }
    }
}
