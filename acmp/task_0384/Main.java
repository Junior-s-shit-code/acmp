import java.io.*;
import java.util.*;

public class Main {
    Scanner in;

    PrintWriter out;

    private int gcd(int a, int b) {
        while (b > 0) {
            int tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }

    private long findFib(int n) {
        final int MOD = (int) 1e9;
        int cur = 1;
        int prev = 1;
        for (int i = 2; i < n; i++) {
            int next = (cur + prev) % MOD;
            prev = cur;
            cur = next;
        }
        return cur;
    }
    private void solve() {
        int a = in.nextInt();
        int b = in.nextInt();
        int iToFind = gcd(a, b);
        out.println(findFib(iToFind));
    }

    public void run() {
        try {
            Locale.setDefault(Locale.US);
            in = new Scanner(new File("input.txt"));
            out = new PrintWriter("output.txt");

            solve();

            out.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public static void main(String[] args) {
        new Main().run();
    }
}