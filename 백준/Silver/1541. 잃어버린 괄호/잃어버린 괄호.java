import java.util.*;
import java.lang.*;
import java.io.*;

//  잃어버린 괄호
// https://www.acmicpc.net/problem/1541
class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        List<Integer> nums = new ArrayList<>();
        List<Character> opers = new ArrayList<>();
        boolean flag = false;

        // 연산자, 피연산자 나누기
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != '-' && s.charAt(i) != '+') {
                sb.append(s.charAt(i));
                continue;
            } else {
                nums.add(Integer.parseInt(sb.toString()));
                opers.add(s.charAt(i));
                sb = new StringBuilder();
            }
        }
        nums.add(Integer.parseInt(sb.toString()));

        // 피연산자에 대해서
        int answer = nums.get(0);
        for (int i = 1; i < nums.size(); i++) {
            if (opers.get(i - 1) == '-') {
                flag = true;
                answer -= nums.get(i);
            } else {
                if (flag == true) {
                    answer -= nums.get(i);
                } else {
                    answer += nums.get(i);
                }
            }
        }
        System.out.println(answer);
    }
}
