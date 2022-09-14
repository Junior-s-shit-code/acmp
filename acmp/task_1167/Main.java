import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main {

    Scanner in;

    PrintWriter out;

    int findSeparateIndex(String s, int left, int right) {
        int count = 0;
        int index = -1;
        for (int i = left; i <= right; i++) {
            if (s.charAt(i) == '(') {
                count++;
            } else if (s.charAt(i) == ')') {
                count--;
            } else if (s.charAt(i) == ',' && count == 1) {
                index = i;
                break;
            }
        }
        return index;
    }

    int getValue(String s, int left, int right) {
        if (s.charAt(left) == 'M') {
            int iSep = findSeparateIndex(s, left, right);
            return max(
                    getValue(s, left + 2, iSep - 1),
                    getValue(s, iSep + 1, right - 1)
            );
        } else if (s.charAt(left) == 'm') {
            int iSep = findSeparateIndex(s, left, right);
            return min(
                    getValue(s, left + 2, iSep - 1),
                    getValue(s, iSep + 1, right - 1)
            );
        } else {
            return s.charAt(left) - '0';
        }
    }

    private void solve() {
        String s = in.next();
        out.println(getValue(s, 0, s.length() - 1));
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