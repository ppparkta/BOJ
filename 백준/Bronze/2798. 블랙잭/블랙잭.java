import java.util.Scanner;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[100001];
        int sum = 0;
        int n = sc.nextInt();
        int m = sc.nextInt();
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            int comp_sum = 0;
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (i == j || j == k || i==k){
                        continue;
                    }
                    comp_sum = arr[i] + arr[j] + arr[k];
                    if (comp_sum <= m && sum < comp_sum){
                        sum = comp_sum;
                    }
                }
            }
        }
        System.out.println(sum);
    }
}