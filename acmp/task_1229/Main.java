import java.io.*;
import java.util.*;

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

        int distTo(Point p2) {
            int dx = x - p2.x;
            int dy = y - p2.y;
            return dx * dx + dy * dy;
        }
    }

    private void solve() {
        final int SIZE = 3;
        Point[] p = new Point[SIZE];
        for (int i = 0; i < SIZE; i++) {
            p[i] = Point.read();
        }
        int[] line = new int[SIZE];
        for (int i = 0; i < SIZE; i++) {
            line[i] = p[i].distTo(p[(i + 1) % SIZE]);
        }
        Arrays.sort(line);
        out.print(line[0] + line[1] == line[2] ? "Yes" : "No");
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