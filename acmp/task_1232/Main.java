import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main {

    Scanner in;

    PrintWriter out;

    private void solve() {
        int sizeI = in.nextInt();
        int sizeJ = in.nextInt();
        int[][] a = new int[sizeI][sizeJ];
        for (int i = 0; i < sizeI; i++) {
            for (int j = 0; j < sizeJ; j++) {
                a[i][j] = in.nextInt();
            }
        }

        int[] iSum = new int[sizeI];
        int[] jSum = new int[sizeJ];
        for (int i = 0; i < sizeI; i++) {
            for (int j = 0; j < sizeJ; j++) {
                iSum[i] += a[i][j];
                jSum[j] += a[i][j];
            }
        }
        for (int val : iSum) {
            out.printf("%d ", val);
        }
        out.println();
        for (int val : jSum) {
            out.printf("%d ", val);
        }
        out.println();
        out.println();
        for (int i = 0; i < sizeI; i++) {
            for (int j = 0; j < sizeJ; j++) {
                out.printf("%d ", a[i][j]);
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