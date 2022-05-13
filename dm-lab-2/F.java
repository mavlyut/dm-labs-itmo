import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class LZW_decode {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int oldCode, newCode;
        char chr;
        Map<Integer, String> dict = new HashMap<>();
        for (int i = 0; i < 26; i++) {
            dict.put(i + 1, (char)(i + 'a') + "");
        }
        int ind = 27;
        oldCode = in.nextInt() + 1;
        chr = dict.get(oldCode).charAt(0);
        String string;
        System.out.print(dict.get(oldCode));
        for (int i = 1; i < n; i++) {
            newCode = in.nextInt() + 1;
            if (!dict.containsKey(newCode)) {
                string = dict.get(oldCode) + chr;
            } else {
                string = dict.get(newCode);
            }
            System.out.print(string);
            chr = string.charAt(0);
            dict.put(ind++, dict.get(oldCode) + chr);
            oldCode = newCode;
        }
    }
}