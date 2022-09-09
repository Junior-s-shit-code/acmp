import java.io.*;
import java.util.*;

public class Main {

    private static class Scanner implements AutoCloseable {
        private final InputStream in;
        private final byte[] buf = new byte[1 << 16];
        private int curChar;
        private int numChars;

        public Scanner(File file) throws FileNotFoundException {
            this.in = new FileInputStream(file);
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = in.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            int readCharacter = buf[curChar];
            curChar++;
            return readCharacter;
        }

        public int nextInt() {
            int c = read();
            while (isWhitespace(c)) {
                c = read();
            }
            int sign = 1;
            if (c == '-') {
                sign = -1;
                c = read();
            }
            int res = 0;
            do {
                if (!Character.isDigit(c)) {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isWhitespace(c));
            return res * sign;
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        @Override
        public void close() throws IOException {
            in.close();
        }
    }

    Scanner in;

    PrintWriter out;

    private void solve() {

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
