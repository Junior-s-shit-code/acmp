import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main {
    Scanner in;

    PrintWriter out;

    private long getSum(long right) {
        return right * (right + 1) / 2;
    }

    long ask() {
        int n = in.nextInt();
        out.printf("? %d\n", n);
        out.flush();

        return n;
    }

    private void binSearch() {
        long left = 0;
        long right = ask();

        long totalNeed = getSum(right) - in.nextLong();

        right = (totalNeed + 2) / 3;
        while (left + 1 < right) {
            long mid = (left + right) >> 1;
            out.printf("? %d\n", mid);
            out.flush();

            long curNeed = getSum(mid) - in.nextLong();

            if (curNeed == 0) {
                left = mid;
            } else {
                right = mid;
            }
        }
        long coin1 = right;

        totalNeed -= coin1;
        long end2 = (totalNeed - 1) / 2;
        out.printf("? %d\n", end2);
        out.flush();

        long need12 = getSum(end2) - in.nextLong();

        long coin2 = need12 - coin1;
        long coin3 = totalNeed - coin2;

        out.printf("! %d %d %d", coin1, coin2, coin3);
    }

    private void solve() {
        binSearch();
    }

    public void run() {
        try {
            Locale.setDefault(Locale.US);
            in = new Scanner(System.in);
            out = new PrintWriter(System.out);

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