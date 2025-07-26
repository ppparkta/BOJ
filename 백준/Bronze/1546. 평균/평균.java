//  평균
import java.util.*;
import java.lang.*;
import java.io.*;

class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        double arr[] = new double[n];
        int idx = 0;
        while (st.hasMoreTokens()) {
            arr[idx] = Double.parseDouble(st.nextToken());
            idx++;
        }
        Arrays.sort(arr);
        double max = arr[arr.length - 1];
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ((arr[i] / max) * 100);
        }
        System.out.println(sum / n);
    }
}