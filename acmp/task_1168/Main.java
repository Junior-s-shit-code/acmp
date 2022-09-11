import java.io.*;
import java.util.*;

public class Main {

    static Scanner in;

    PrintWriter out;

    static class Applicant {

        String name;

        int score;

        Applicant(String name, int score) {
            this.name = name;
            this.score = score;
        }

        static Applicant read() {
            String name = in.next();
            int score = in.nextInt() + in.nextInt() + in.nextInt();
            return new Applicant(name, score);
        }
    }

    private void solve() {
        int n = in.nextInt();
        int iAns = in.nextInt() - 1;
        Applicant[] a = new Applicant[n];
        for (int i = 0; i < n; i++) {
            a[i] = Applicant.read();
        }
        Arrays.sort(a, (right, left) -> {
            int res = Integer.compare(left.score, right.score);
            if (res != 0) {
                return res;
            }
            return left.name.compareTo(right.name);
        });
        out.printf("%s %d", a[iAns].name, a[iAns].score);
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
