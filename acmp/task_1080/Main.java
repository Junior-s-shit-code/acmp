import java.io.*;
import java.util.*;

import static java.lang.Math.min;

public class Main {

    Scanner in;

    PrintWriter out;

    private void solve() {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        int nQ = in.nextInt();
        for (int q = 0; q < nQ; q++) {
            String cmd = in.next();
            switch (cmd) {
                case "get" -> out.println(a[in.nextInt() - 1]);
                case "update" -> {
                    int left = in.nextInt() - 1;
                    int right = in.nextInt() - 1;
                    int value = in.nextInt();
                    for (int i = left; i <= right; i++) {
                        a[i] = value;
                    }
                }
                case "add" -> {
                    int left = in.nextInt() - 1;
                    int right = in.nextInt() - 1;
                    int value = in.nextInt();
                    for (int i = left; i <= right; i++) {
                        a[i] += value;
                    }
                }
                case "rsq" -> {
                    int left = in.nextInt() - 1;
                    int right = in.nextInt() - 1;
                    int sum = 0;
                    for (int i = left; i <= right; i++) {
                        sum += a[i];
                    }
                    out.println(sum);
                }
                case "rmq" -> {
                    int left = in.nextInt() - 1;
                    int right = in.nextInt() - 1;
                    int minValue = 1000 * 1000 * 10;
                    for (int i = left; i <= right; i++) {
                        minValue = min(minValue, a[i]);
                    }
                    out.println(minValue);
                }
                default -> System.out.println("undefined case value");
            }
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
            System.out.println(e);
        }
    }

    public static void main(String[] args) {
        new Main().run();
    }
}
