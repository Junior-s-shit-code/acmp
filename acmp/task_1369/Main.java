import java.io.*;
import java.util.*;

import static java.lang.Math.min;
import static java.lang.Math.max;

public class Main {

    private static Scanner in;

    private static PrintWriter out;

    private void solve() {
        // input
        int n = in.nextInt();
        int[][] minDist = new int[n][n];
        int[][] g = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = in.nextInt();
                minDist[i][j] = g[i][j];
            }
        }
        // calc minDist in graph
        for (int vMid = 0; vMid < n; vMid++) {
            for (int v1 = 0; v1 < n; v1++) {
                for (int v2 = 0; v2 < n; v2++) {
                    if (v1 == v2) { continue; }
                    minDist[v1][v2] = min(minDist[v1][v2], minDist[v1][vMid] + minDist[vMid][v2]);
                }
            }
        }
        // find max Value in minDist
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, minDist[i][j]);
            }
        }
        //output
        out.println(ans);
    }

    public void run() {
        try {
            in = new Scanner(new File("input.txt"));
            out = new PrintWriter("output.txt");
            solve();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String args[]) {
        new Main().run();
    }
}