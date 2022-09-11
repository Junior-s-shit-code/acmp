import java.io.*;
import java.util.*;

public class Main {

    static Scanner in;

    PrintWriter out;

    static class Person {

        String surname;

        String name;

        String couple;

        String date;

        Person(
                String surname,
                String name,
                String couple,
                String date
        ) {
            this.surname = surname;
            this.name = name;
            this.couple = couple;
            this.date = date;
        }

        static Person read() {
            String surname = in.next();
            String name = in.next();
            String couple = in.next();
            String date = in.next();
            return new Person(surname, name, couple, date);
        }
    }

    private void solve() {
        int n = in.nextInt();
        Person[] a = new Person[n];
        for (int i = 0; i < n; i++) {
            a[i] = Person.read();
        }
        Arrays.sort(a, (left, right) -> {
            int cLen = Integer.compare(left.couple.length(), right.couple.length());
            int couple = left.couple.compareTo(right.couple);
            int surname = left.surname.compareTo(right.surname);
            if (cLen != 0) {
                return cLen;
            } else if (couple != 0) {
                return couple;
            }
            return surname;
        });
        for (Person p : a) {
            out.printf("%s %s %s %s\n", p.couple, p.surname, p.name, p.date);
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
