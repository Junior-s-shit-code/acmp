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

        Person(String surname,
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

        public String toString() {
            return couple + " " +
                    surname + " " +
                    name + " " +
                    date;
        }
    }

    private void solve() {
        int n = in.nextInt();
        Person[] a = new Person[n];
        for (int i = 0; i < n; i++) {
            a[i] = Person.read();
        }
        Arrays.sort(a, (left, right) -> {
            int res = Integer.compare(left.couple.length(), right.couple.length());
            if (res != 0) {
                return res;
            }
            res = left.couple.compareTo(right.couple);
            if (res != 0) {
                return res;
            }
            return left.surname.compareTo(right.surname);
        });
        for (Person p : a) {
            out.println(p.toString());
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
