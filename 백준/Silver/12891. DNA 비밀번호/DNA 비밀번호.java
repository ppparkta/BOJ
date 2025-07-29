import java.util.*;
import java.lang.*;
import java.io.*;

// DNA 비밀번호
// https://www.acmicpc.net/problem/12891
class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        String s = br.readLine();

        int arr[] = new int[4];
        int newArr[] = new int[4];

        // A C G T
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 4; i++) {
            int c = Integer.parseInt(st.nextToken());
            arr[i] = c;
        }

        // 첫번째 구간에 대해 윈도우 크기만큼의 로직 추가
        for (int i = 0; i < k; i++) {
            char c = s.charAt(i);
            if (c == 'A') {
                newArr[0]++;
            }
            if (c == 'C') {
                newArr[1]++;
            }
            if (c == 'G') {
                newArr[2]++;
            }
            if (c == 'T') {
                newArr[3]++;
            }
        }
        int cnt = 0;
        if (isAnswer(arr, newArr)) {
            cnt++;
        }
        // 그 이후 구간부터 윈도우 좌/우 빼고 더하며 cnt 계산
        for (int i = 1; i <= n - k; i++) {
            if (s.charAt(i - 1) == 'A') {
                newArr[0]--;
            } else if (s.charAt(i - 1) == 'C') {
                newArr[1]--;
            } else if (s.charAt(i - 1) == 'G') {
                newArr[2]--;
            } else if (s.charAt(i - 1) == 'T') {
                newArr[3]--;
            }
            if (s.charAt(i + k - 1) == 'A') {
                newArr[0]++;
            } else if (s.charAt(i + k - 1) == 'C') {
                newArr[1]++;
            } else if (s.charAt(i + k - 1) == 'G') {
                newArr[2]++;
            } else if (s.charAt(i + k - 1) == 'T') {
                newArr[3]++;
            }
            if (isAnswer(arr, newArr)) {
                cnt++;
            }
        }
        System.out.println(cnt);
    }

    public static boolean isAnswer(int arr[], int comparedArr[]) {
        for (int i = 0; i < 4; i++) {
            if (arr[i] > comparedArr[i]) {
                return false;
            }
        }
        return true;
    }
}
