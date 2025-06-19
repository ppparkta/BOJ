import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine().trim();
        int result = 0;
        if (str.length() >= 1 && str.charAt(0) != ' ') {
            result++;
        }
        for (int i = 1; i < str.length() - 1; i++) {
            if (str.charAt(i) == ' ') {
                result++;
            }
        }
        System.out.println(result);
    }
}
