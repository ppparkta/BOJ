import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        for (int idx = 0; idx < n; idx++) {
            String cmd = br.readLine();
            int size = Integer.parseInt(br.readLine());
            Deque<Integer> deque = parseDeque(br);
            boolean reversed = false;
            boolean error = false;
            for (int i = 0; i < cmd.length(); i++) {
                if (cmd.charAt(i) == 'R') {
                    reversed = !reversed;
                } else {
                    if (deque.isEmpty()) {
                        error = true;
                        break;
                    } else {
                        if (reversed) {
                            deque.removeLast();
                        } else {
                            deque.removeFirst();
                        }
                    }
                }
            }
            if (error) {
                System.out.print("error\n");
                continue;
            }
            StringBuilder sb = new StringBuilder();
            sb.append("[");
            while (!deque.isEmpty()) {
                sb.append(reversed ? deque.removeLast() : deque.removeFirst());
                if (!deque.isEmpty()) {
                    sb.append(",");
                }
            }
            sb.append("]\n");
            System.out.print(sb);

        }
    }

    private static Deque<Integer> parseDeque(BufferedReader br) throws IOException {
        String s = br.readLine();
        Deque<Integer> deque = new ArrayDeque<>();
        s = s.substring(1, s.length() - 1);
        if (s.isEmpty()) {
            return deque;
        }
        for (String numStr : s.split(",")) {
            deque.add(Integer.parseInt(numStr));
        }
        return deque;
    }
}
