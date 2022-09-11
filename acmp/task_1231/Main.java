import java.io.*;
import java.util.*;

public class Main {

    Scanner in;

    PrintWriter out;

    private void solve() {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        int count = 0;
        for (int i = 0; i + 1 < n; i++) {
            for (int j = 0; j + 1 < n; j++) {
                if (a[j] > a[j + 1]) {
                    count++;
                    int tmp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = tmp;
                }
            }
        }
        out.println(count);
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
