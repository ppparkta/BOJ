
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String first = sc.nextLine();
        List<Integer> obj = Arrays.stream(first.split(" "))
                .map(Integer::parseInt).collect(Collectors.toList());

        Map<String, String> map = new HashMap<>();

        for (int i = 0; i < obj.get(0); i++) {
            String second = sc.nextLine();
            String[] split = second.split(" ");
            map.put(split[0], split[1]);
        }

        for (int i = 0; i < obj.get(obj.size() - 1); i++) {
            String third = sc.nextLine();
            System.out.println(map.get(third));
        }
    }
}