import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main {
    static Scanner in;

    PrintWriter out;

    static class Point {

        int x;

        int y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        static Point read() {
            int x = in.nextInt();
            int y = in.nextInt();
            return new Point(x, y);
        }

        double distTo(Point p2) {
            int dx = x - p2.x;
            int dy = y - p2.y;
            return sqrt(dx * dx + dy * dy);
        }
    }

    private void solve() {
        final int SIZE = 3;
        Point[] p = new Point[SIZE];
        for (int i = 0; i < SIZE; i++) {
            p[i] = Point.read();
        }
        double[] line = new double[SIZE];
        for (int i = 0; i < SIZE; i++) {
            line[i] = p[i].distTo(p[(i + 1) % SIZE]);
        }
        Arrays.sort(line);
        final double EPS = (double) 1e-6;
        out.print(abs(line[0] * line[0] + line[1] * line[1] - line[2] * line[2]) < EPS ? "Yes" : "No");
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