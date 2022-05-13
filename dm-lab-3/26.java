package lab;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class N26 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        while (n != 0 || k != 0) {
            ArrayList<ArrayList<Integer>> a = new ArrayList<>();
            in.nextLine();
            for (int i = 0; i < k; i++) {
                ArrayList<Integer> b = new ArrayList<>();
                Scanner in2 = new Scanner(in.nextLine());
                while (in2.hasNextInt()) {
                    b.add(in2.nextInt());
                }
                a.add(b);
            }
            cntAns(a, n);
            n = in.nextInt();
            k = in.nextInt();
        }
    }

    private static void cntAns(ArrayList<ArrayList<Integer>> a, int n) {
        ArrayList<Integer> used = new ArrayList<>();
        boolean isEnd = false;
        for (int i = a.size() - 1; i >= 0; i--) {
            if (!used.isEmpty() && Collections.max(used) > a.get(i).get(a.get(i).size() - 1)) {
                int m = f(used, a.get(i).get(a.get(i).size() - 1));
                a.get(i).add(m);
                Integer q = m;
                used.remove(q);
                break;
            }
            for (int j = a.get(i).size() - 1; j >= 0; j--) {
                if (!used.isEmpty() && j > 0 && Collections.max(used) > a.get(i).get(j)) {
                    int m = f(used, a.get(i).get(j));
                    int toAdd = a.get(i).get(j);
                    a.get(i).set(j, m);
                    Integer q = m;
                    used.remove(q);
                    used.add(toAdd);
                    isEnd = true;
                    break;
                } else {
                    used.add(a.get(i).get(a.get(i).size() - 1));
                    a.get(i).remove(a.get(i).size() - 1);
                    if (a.get(i).isEmpty()) {
                        a.remove(a.size() - 1);
                    }
                }
            }
            if (isEnd) {
                break;
            }
        }
        Collections.sort(used);
        for (int i : used) {
            ArrayList<Integer> c = new ArrayList<>();
            c.add(i);
            a.add(c);
        }
        System.out.println(n + " " + a.size());
        for (ArrayList<Integer> i : a) {
            for (int j : i) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    private static int f(ArrayList<Integer> a, int x) {
        int ans = 10000000;
        for (int i : a) {
            if (i > x) {
                ans = Math.min(ans, i);
            }
        }
        return ans;
    }
}
