//  우유 축제

import java.util.*;
import java.lang.*;
import java.io.*;

//맨 처음에는 딸기우유를 한 팩 마신다.
//딸기우유를 한 팩 마신 후에는 초코우유를 한 팩 마신다.
//초코우유를 한 팩 마신 후에는 바나나우유를 한 팩 마신다.
//바나나우유를 한 팩 마신 후에는 딸기우유를 한 팩 마신다.
class Main {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int need = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            if (x == need) {
                ans++;
                need = (need + 1) % 3;
            }
        }
        System.out.println(ans);
    }
}
