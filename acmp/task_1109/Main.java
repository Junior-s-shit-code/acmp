import java.io.*;
import java.util.*;

public class Main {

    Scanner in;

    PrintWriter out;

    private void solve() {
        int value = in.nextInt();
        out.printf("The next number for the number %d is %d.\n", value, value + 1);
        out.printf("The previous number for the number %d is %d.", value, value - 1);
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
