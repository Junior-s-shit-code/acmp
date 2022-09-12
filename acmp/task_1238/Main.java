import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main {

    Scanner in;

    PrintWriter out;

    int[][] readMatrix(int sizeI, int sizeJ) {
        int[][] m = new int[sizeI][sizeJ];
        for (int i = 0; i < sizeI; i++) {
            for (int j = 0; j < sizeJ; j++) {
                m[i][j] = in.nextInt();
            }
        }
        return m;
    }

    private void solve() {
        int sizeI = in.nextInt();
        int sizeJ = in.nextInt();
        int sizeK = in.nextInt();
        int[][] a = readMatrix(sizeI, sizeJ);
        int[][] b = readMatrix(sizeJ, sizeK);

        int[][] ans = new int[sizeI][sizeK];
        for (int i = 0; i < sizeI; i++) {
            for (int j = 0; j < sizeJ; j++) {
                for (int k = 0; k < sizeK; k++) {
                    ans[i][k] += a[i][j] * b[j][k];
                }
            }
        }
        for (int i = 0; i < sizeI; i++) {
            for (int k = 0; k < sizeK; k++) {
                out.print(ans[i][k]);
                out.print(" ");
            }
            out.println();
        }
    }

    public void run() {
        try {
            Locale.setDefault(Locale.US);
            in = new Scanner(new File("input.txt"));
            out = new PrintWriter("output.txt");

            solve();

            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Main().run();
    }
}