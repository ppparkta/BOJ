//  수 고르기

import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(arr);

        int right = 0;

        int ans = Integer.MAX_VALUE;
        for (int left = 0; left < n; left++) {
            while (right < n && (arr[right] - arr[left]) < m) {
                right++;
            }
            if (right == n) {
                break;
            }
            ans = Math.min(ans, arr[right] - arr[left]);
        }
        System.out.println(ans);
    }
}
