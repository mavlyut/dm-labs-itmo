package lab;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;

public class N16 {
    public static void main(String[] args) throws FileNotFoundException {
        new Solution().run(new Scanner(
                //new FileReader("C:\\Users\\User\\IdeaProjects\\untitled12\\src\\lab\\input.txt")
                System.in
        ));
    }
}

class Solution {
    private int n;
    private int k;
    private int[] a;
    private long res;
    private long z = 0;
    private int[] p;
    private long[][] c;

    public void run(Scanner in) {
        readData(in);
        preCalc();
        //printC();
        gen(0, 1);
        System.out.println(res);
    }

    /*private void printC() {
        for (long[] i : c) {
            for (long j : i) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }*/

    private void gen(int size, int left) {
        if (size == k) {
            res = z;
            return;
        }
        for (int i = left; i <= n; i++) {
            if (size == 0 || p[size - 1] < i) {
                long t = C(n - i, k - size - 1);
                if (a[size] == i) {
                    p[size] = i;
                    gen(size + 1, i + 1);
                    return;
                }
                z += t;
            }
        }
    }

    private long C(int n, int k) {
        if (n < 0 || k < 0) {
            return 0;
        }
        return c[n][k];
    }

    private void preCalc() {
        c = new long[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            c[i][0] = 1L;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            }
        }
    }

    private void readData(Scanner in) {
        n = in.nextInt();
        k = in.nextInt();
        a = new int[k];
        p = new int[k];
        for (int i = 0; i < k; i++) {
            a[i] = in.nextInt();
        }
    }
}
