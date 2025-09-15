
import java.util.*;
import java.lang.*;
import java.io.*;

//  돌 게임
// https://www.acmicpc.net/problem/9655
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        boolean isSK = true;
        while (n > 0) {
            if (n == 1) {
                if (isSK) {
                    System.out.println("SK");
                } else {
                    System.out.println("CY");
                }
                return;
            }
            if (n - 3 >= 2) {
                n -= 3;
            } else {
                n--;
            }
            isSK = isSK == true ? false : true;
        }
    }
}
