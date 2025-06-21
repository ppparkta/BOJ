import java.util.*;

public class Main {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        int devN = (n / 4);
        for(int i=0;i<devN;i++) {
            System.out.print("long ");
        }
        System.out.print("int\n");
    }
}