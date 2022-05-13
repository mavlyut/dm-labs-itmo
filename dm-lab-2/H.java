import java.math.BigDecimal;
import java.math.RoundingMode;
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
        int[] pref = new int[n + 1];
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + in.nextInt();
        }
        String s = in.next();

        BigDecimal p = BigDecimal.ZERO;
        for (int i = 0; i < s.length(); i++) {
            p = p.multiply(BigDecimal.valueOf(2)).add(s.charAt(i) == '0' ? BigDecimal.ZERO : BigDecimal.ONE);
        }

        int m = pref[n];
        int pre = 500;
        RoundingMode tr = RoundingMode.DOWN;
        p = p.divide(BigDecimal.valueOf(2).pow(s.length()), pre, tr);
        //System.out.println(p);

        BigDecimal l = BigDecimal.ZERO;
        BigDecimal r = BigDecimal.ONE;
        for (int i = 0; i < m; i++) {
            int ind = 0;
            BigDecimal m_ = r.subtract(l);
            while (ind < n && (
                    l.add(BigDecimal.valueOf(pref[ind]).multiply(m_).divide(BigDecimal.valueOf(m), pre, tr)).compareTo(p) > 0
                    || l.add(BigDecimal.valueOf(pref[ind + 1]).multiply(m_).divide(BigDecimal.valueOf(m), pre, tr)).compareTo(p) <= 0
            )) {
                ind++;
            }
            r = l.add(BigDecimal.valueOf(pref[ind + 1]).multiply(m_).divide(BigDecimal.valueOf(m), pre, tr));
            l = l.add(BigDecimal.valueOf(pref[ind]).multiply(m_).divide(BigDecimal.valueOf(m), pre, tr));
            //System.out.println((char)(ind + 'a') + " " + l + " " + r);
            System.out.print((char)(ind + 'a'));
        }

        System.out.println();
    }
}