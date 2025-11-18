//  1로 만들기 2

import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int arr[] = new int[1000001];
        int prev[] = new int[1000001];
        arr[1] = 0;
        for (int i = 2; i <= n; i++) {
            arr[i] = arr[i - 1] + 1;
            prev[i] = i - 1;
            if (i % 3 == 0 && (arr[i] > arr[i / 3] + 1)) {
                arr[i] = arr[i / 3] + 1;
                prev[i] = i / 3;
            }
            if (i % 2 == 0 && (arr[i] > arr[i / 2] + 1)) {
                arr[i] = arr[i / 2] + 1;
                prev[i] = i / 2;
            }
        }
        System.out.println(arr[n]);
        int tmp = n;
        while (true) {
            System.out.print(tmp + " ");
            if (tmp == 1) {
                break;
            }
            tmp = prev[tmp];
        }
    }
}
