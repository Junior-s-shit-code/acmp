import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main {

    static Scanner in;

    PrintWriter out;

    static final int UNDEF = -1;

    static class Person {

        String country;

        String fullName;

        double[] result;

        Person(String country,
               String fullName,
               double[] result
        ) {
            this.country = country;
            this.fullName = fullName;
            this.result = result;
        }

        static Person read() {
            final int size = 6;
            String country = in.next();
            String name = in.next() + " " + in.next();
            double[] rawResult = new double[size];
            for (int i = 0; i < size; i++) {
                String val = in.next();
                if (val.equals("x")) {
                    rawResult[i] = UNDEF;
                } else {
                    rawResult[i] = Double.parseDouble(val);
                }
            }
            double[] result = Arrays.stream(rawResult).boxed()
                    .sorted(Comparator.reverseOrder())
                    .mapToDouble(Double::doubleValue)
                    .toArray();
            return new Person(country, name, result);
        }
    }

    private void solve() {
        final double EPS = 1e-4;
        int n = in.nextInt();
        Person[] a = new Person[n];
        for (int i = 0; i < n; i++) {
            a[i] = Person.read();
        }
        Arrays.sort(a, (right, left) -> Arrays.compare(left.result, right.result));

        n = min(n, 3);
        for (int i = 0; i < n; i++) {
            if (abs(a[i].result[0] - UNDEF) < EPS) {
                if (i == 0) {
                    out.println("No results.");
                }
                break;
            }
            out.printf("%d) %s %s %.2f\n", i + 1, a[i].country, a[i].fullName, a[i].result[0]);
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
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Main().run();
    }
}