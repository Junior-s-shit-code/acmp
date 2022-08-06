import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main {
    Scanner in;

    //PrintWriter out;

    private long getSum(int left, int right) {
        return 1L * (left + right) * (right - left + 1) / 2;
    }

    private void binSearch() {
        int INF = in.nextInt();

        int left = 0;
        int right = INF;
        System.out.printf("? %d\n", right);
        System.out.flush();

        long totalNeed = getSum(1, right) - in.nextLong();

        right = (int) ((totalNeed + 2) / 3);
        while (left + 1 < right) {
            int mid = (left + right) >> 1;
            System.out.printf("? %d\n", mid);
            System.out.flush();

            long curNeed = getSum(1, mid) - in.nextLong();

            if (curNeed == 0) {
                left = mid;
            } else {
                right = mid;
            }
        }
        int coin1 = right;

        totalNeed -= coin1;
        int end2 = (int) (totalNeed - 1) / 2 ;
        System.out.printf("? %d\n", end2);
        System.out.flush();

        long  need12 = getSum(1, end2) - in.nextLong();

        int coin2 = (int) (need12 - coin1);
        int coin3 = (int) (totalNeed - coin2);

        System.out.printf("! %d %d %d", coin1, coin2, coin3);
    }

    private void solve() {
        binSearch();
    }

    public void run() {
        try {
            Locale.setDefault(Locale.US);
            in = new Scanner(System.in);
            //out = new PrintWriter("output.txt");

            solve();

            //out.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public static void main(String[] args) {
        new Main().run();
    }
}