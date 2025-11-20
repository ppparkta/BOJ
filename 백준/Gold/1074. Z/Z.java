//  Z

import java.util.*;
import java.lang.*;
import java.io.*;

class Main {

    public static int depth = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int r = sc.nextInt();
        int c = sc.nextInt();
        int calcN = calcN(n);
        System.out.println(calc(calcN, r, c));
    }

    private static int calcN(int n) {
        int result = 1;
        while (n-- > 0) {
            result *= 2;
        }
        return result;
    }

    private static int calc(int n, int r, int c) {
        if (n == 1) {
            return 0;
        }
        int middle = n / 2;
        int block = middle * middle;
        if (r < middle && c < middle) {
            return calc(middle, r, c);
        }
        if (r < middle && c >= middle) {
            return block + calc(middle, r, c - middle);
        }
        if (r >= middle && c < middle) {
            return block * 2 + calc(middle, r - middle, c);
        }
        return block * 3 + calc(middle, r - middle, c - middle);
    }
}
