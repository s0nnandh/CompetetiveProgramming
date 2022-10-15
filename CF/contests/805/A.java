import java.util.Scanner;

/**
 * A
 */
public class A {

    final static Scanner sc = new Scanner(System.in);

    final static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) {
        
        int tt = sc.nextInt();
        for (int i = 0; i < tt; i++) {
            solve();
        }
        System.out.print(sb.toString());
    }

    public static void solve() {
        String s = sc.next();
        int ans = (int)Math.pow(10, s.length() - 1);
        sb.append(Integer.valueOf(s) - ans);
        sb.append('\n');
    }
    
}