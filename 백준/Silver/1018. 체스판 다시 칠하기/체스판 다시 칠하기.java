import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        List<Integer> arr = Arrays.stream(s.split(" "))
                .map(Integer::parseInt)
                .collect(Collectors.toList());

        String board[] = new String[51];

        for (int x = 0; x < arr.get(0); x++) {
            String line = sc.nextLine();
            board[x] = line;
        }

        int min = 10000000;
        int idx = 0;
        for (int y = idx; y <= arr.get(0) - 8; y++) {
            for (int x = 0; x <= arr.get(1) - 8; x++) {
                min = Math.min(min, checkRange(x, y, board));
            }
        }
        System.out.println(min);
    }

    private static int checkRange(int x, int y, String[] board) {
        int visit = 0;
        char start = board[y].charAt(x);
        visit = countVisit(x, y, board, start, visit);
        start = start == 'B' ? 'W' : 'B';
        visit = Math.min(visit, countVisit(x, y, board, start, 0));
        return visit;
    }

    private static int countVisit(int x, int y, String[] board, char start, int visit) {
        for (int ny = y; ny < y + 8; ny++) {
            for (int nx = x; nx < x + 8; nx++) {
                if (ny % 2 == 0) {
                    if (nx % 2 == 0) {
                        if (board[ny].charAt(nx) != start) {
                            visit++;
                        }
                    } else {
                        if (board[ny].charAt(nx) == start) {
                            visit++;
                        }
                    }
                } else {
                    if (nx % 2 == 0) {
                        if (board[ny].charAt(nx) == start) {
                            visit++;
                        }
                    } else {
                        if (board[ny].charAt(nx) != start) {
                            visit++;
                        }
                    }
                }
            }
        }
        return visit;
    }
}
