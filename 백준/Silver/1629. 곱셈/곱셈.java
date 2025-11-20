//  곱셈

import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        System.out.println(calc(a, b, c));
    }

    private static long calc(long a, long b, long c) {
        if (b == 1) {
            return a % c;
        }
        long r = calc(a, b / 2, c);
        if (b % 2 == 0) {
            return (r * r) % c;
        }
        return ((r * r) % c * a) % c;
    }
}
