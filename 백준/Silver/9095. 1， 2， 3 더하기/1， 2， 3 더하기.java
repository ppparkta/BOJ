//  1, 2, 3 더하기

import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int arr[] = new int[11];
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;
        arr[3] = 4;
        for (int i = 4; i < 11; i++) {
            arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
        }
        for (int i = 0; i < n; i++) {
            int m = sc.nextInt();
            System.out.println(arr[m]);
        }
    }
}
