import java.io.*;
import java.util.*;

import static java.lang.Math.abs;

public class Main {

    Scanner in;

    PrintWriter out;

    class Point {
        int i;

        int j;

        void read() {
            String input = in.next();
            this.i = input.charAt(0) - 'A' + 1;
            this.j = input.charAt(1) - '0';
        }
    }

    private void solve() {
        Point a = new Point();
        Point b = new Point();
        a.read();
        b.read();

        Map<String, Boolean> isMove = new HashMap<>();

        int di = abs(b.i - a.i);
        int dj = abs(b.j - a.j);
        isMove.put("Pawn", di == 0 &&
                a.j > 1 && b.j > a.j && (dj == 1 || dj == 2 && a.j == 2)
        );
        isMove.put("King", di < 2 && dj < 2);
        isMove.put("Rook", di == 0 ^ dj == 0);
        isMove.put("Bishop", di == dj);
        isMove.put("Knight", di * di + dj * dj == 5);
        isMove.put("Queen", isMove.get("Bishop") || isMove.get("Rook"));

        boolean isEmpty = true;
        for (var entry : isMove.entrySet()) {
            if (entry.getValue()) {
                isEmpty = false;
                out.println(entry.getKey());
            }
        }

        if (isEmpty) {
            out.println("Nobody");
        }
    }

    public void run() {
        try {
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