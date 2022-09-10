import java.io.*;
import java.util.*;

public class Main {

    Scanner in;

    PrintWriter out;

    private void solve() {
        final int INF = (int) 2e9;
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        for (int curN = n; curN > 0; curN--) {
            int maxValue = -INF;
            int maxIndex = -INF;
            for (int i = 0; i < curN; i++) {
                if (a[i] > maxValue) {
                    maxValue = a[i];
                    maxIndex = i;
                }
            }

            int tmp = a[maxIndex];
            a[maxIndex] = a[curN - 1];
            a[curN - 1] = tmp;

            out.print(maxIndex);
            out.print(" ");
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
