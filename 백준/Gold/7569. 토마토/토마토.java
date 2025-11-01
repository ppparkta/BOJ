//  토마토

import java.util.*;
import java.lang.*;
import java.io.*;

class Main {

    public static int dy[]={1,-1,0,0,0,0};
    public static int dz[]={0,0,1,-1,0,0};
    public static int dx[]={0,0,0,0,1,-1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        // x
        int m=Integer.parseInt(st.nextToken());
        // y
        int n=Integer.parseInt(st.nextToken());
        // z
        int h=Integer.parseInt(st.nextToken());

        int arr[][][] = new int[h][n][m];
        int answer[][][] = new int[h][n][m];
        boolean visited[][][] = new boolean[h][n][m];

        Deque<int[]> dq = new ArrayDeque<>();
        for(int z=0;z<h;z++){
            for(int i=0;i<n;i++){
                st = new StringTokenizer(br.readLine());
                for(int j=0;j<m;j++){
                    arr[z][i][j] = Integer.parseInt(st.nextToken());
                    if (arr[z][i][j] == 1) {
                        visited[z][i][j] = true;
                        dq.offer(new int[]{z, i, j});
                        answer[z][i][j] = 0;
                    }
                }
            }
        }

//        for(int z=0;z<h;z++){
//            for(int i=0;i<n;i++){
//                for(int j=0;j<m;j++) {
//                    System.out.print(arr[z][i][j] + " ");
//                }
//                System.out.println();
//            }
//            System.out.println();
//        }

        int maxAnswer = 0;
        while(!dq.isEmpty()) {
            int poll[] = dq.poll();
            int z = poll[0];
            int y = poll[1];
            int x = poll[2];
            for(int i=0; i<6; i++){
                int nz = dz[i] + z;
                int ny = dy[i] + y;
                int nx = dx[i] + x;
                if (nz < 0 || nz >= h || ny < 0 || ny >= n || nx < 0 || nx >= m) {
                    continue;
                }
                if (visited[nz][ny][nx] == true || arr[nz][ny][nx] != 0) {
                    continue;
                }
                visited[nz][ny][nx] = true;
                answer[nz][ny][nx] = answer[z][y][x] + 1;
                maxAnswer = answer[nz][ny][nx];
                dq.offer(new int[]{nz, ny, nx});
            }
        }

//        for(int z=0;z<h;z++){
//            for(int i=0;i<n;i++){
//                for(int j=0;j<m;j++) {
//                    System.out.print(answer[z][i][j] + " ");
//                }
//                System.out.println();
//            }
//            System.out.println();
//        }

        for(int i=0;i<h;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<m;k++){
                    if (arr[i][j][k] == 0 && visited[i][j][k] == false){
                        System.out.println("-1");
                        return;
                    }
                }
            }
        }
        System.out.println(maxAnswer);
    }
}
