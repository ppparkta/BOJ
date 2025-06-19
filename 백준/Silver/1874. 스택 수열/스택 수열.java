import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> arr = new ArrayList<>();
        List<String> result = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            arr.add(sc.nextInt());
        }

        List<Integer> newArr = new ArrayList<>();
        newArr.add(0);
        int current = 0;
        for (int i = 0; i < n; i++) {
            Integer n1 = arr.get(i);
            for (int cur = current + 1; cur <= n1; cur++) {
                newArr.add(cur);
                result.add("+");
                current++;
            }
            boolean flag = false;
            for (int cur = newArr.get(newArr.size() - 1); cur >= arr.get(i) && !flag; cur--) {
                int tmp = newArr.get(newArr.size() - 1);
                newArr.remove(newArr.size() - 1);
                result.add("-");
                if (tmp == arr.get(i)) {
                    flag = true;
                }
            }
            if (flag) {
                continue;
            } else {
                System.out.println("NO");
                return;
            }
        }
        for (int i = 0; i < result.size(); i++) {
            System.out.println(result.get(i));
        }
    }
}
