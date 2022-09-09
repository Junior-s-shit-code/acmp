import java.io.*;
import java.util.*;

public class Main {
    FastScanner in;

    PrintWriter out;

    private void solve() throws IOException {

    }

    public void run() {
        try {
            Locale.setDefault(Locale.US);
            in = new FastScanner(new File("input.txt"));
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

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }
}