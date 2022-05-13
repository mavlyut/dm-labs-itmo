import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Scanner;

public class G_dm_lab {
    public static void main(String[] args) {
        new SolutionG().run();
    }
}

class SolutionG {
    public void run() {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        String s = in.next();
        int m = s.length();

        int[] cnt = new int[n];
        int[] pref = new int[n + 1];
        for (int i = 0; i < m; i++) {
            cnt[s.charAt(i) - 'a']++;
        }
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + cnt[i];
        }

        System.out.println(n);
        for (int i : cnt) {
            System.out.print(i + " ");
        }
        System.out.println();

        BigDecimal l = BigDecimal.ZERO;
        BigDecimal r = BigDecimal.ONE;

        RoundingMode round = RoundingMode.DOWN;
        int precision = 500;

        for (int i = 0; i < m; i++) {
            int w = s.charAt(i) - 'a';
            BigDecimal len = r.subtract(l).divide(BigDecimal.valueOf(m), precision, round);//(r - l) / m
            l = l.add(len.multiply(BigDecimal.valueOf(pref[w]))); //len * pref[w];
            r = l.add(len.multiply(BigDecimal.valueOf(cnt[w])));//l + len * cnt[w];
        }

        BigDecimal p = BigDecimal.ZERO;
        BigDecimal q = BigDecimal.ONE.add(BigDecimal.ONE);
        long cntr = 1;

        while (p.divide(q, precision, round).compareTo(l) < 0 || p.divide(q, precision, round).compareTo(r) >= 0) {
            p = l.multiply(q).setScale(0, round);
            while (p.divide(q, precision, round).compareTo(l) <= 0 && p.compareTo(q) < 0) {
                p = p.add(BigDecimal.ONE);
            }
            if (!(p.divide(q, precision, round).compareTo(l) < 0 || p.divide(q, precision, round).compareTo(r) >= 0)) {
                break;
            }
            q = q.multiply(BigDecimal.ONE.add(BigDecimal.ONE));
            cntr++;
            //System.out.println(p + " " + q + " " + cntr);
        }

        ArrayList<String> a = new ArrayList<>();
        BigInteger p_ = p.toBigInteger();

        for (int i = 0; i < cntr; i++) {
            a.add(p_.mod(BigInteger.TWO).toString());
            p_ = p_.divide(BigInteger.TWO);
        }

        Collections.reverse(a);
        for (String i : a) {
            System.out.print(i);
        }
        System.out.println();
    }
}