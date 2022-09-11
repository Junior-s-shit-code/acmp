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
        for (int curN = n - 1; curN >= 0; curN--) {
            int maxIndex = 0;
            for (int i = 0; i <= curN; i++) {
                if (a[i] > a[maxIndex]) {
                    maxIndex = i;
                }
            }

            int tmp = a[maxIndex];
            a[maxIndex] = a[curN];
            a[curN] = tmp;

            out.printf("%d ", maxIndex);
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
