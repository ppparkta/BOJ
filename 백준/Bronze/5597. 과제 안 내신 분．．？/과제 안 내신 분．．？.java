import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.*;
import java.io.*;

// https://www.acmicpc.net/problem/5597
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean hi[] = new boolean[31];
        for (int i = 0; i < 28; i++) {
            int n = Integer.parseInt(br.readLine());
            hi[n] = true;
        }
        for (int i = 1; i <= 30; i++) {
            if (!hi[i]) {
                System.out.println(i);
            }
        }
    }
}