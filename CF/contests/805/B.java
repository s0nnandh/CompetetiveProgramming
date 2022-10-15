import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * B
 */
public class B {

    final static Scanner sc = new Scanner(System.in);

    final static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) {
        Integer tt = sc.nextInt();
        for (int i = 0; i < tt; i++) {
            solve();
        }
        System.out.print(sb.toString());
    }

    private static void solve() {
        String s = sc.next();
        Set<Character> S = new HashSet<Character>();
        Integer n = s.length(), ans = 0;
        for(int i = 0;i < n;++i){
            if(S.size() == 3 && !S.contains(s.charAt(i))){
                ans++;
                S.clear();
            }
            S.add(s.charAt(i));
        }
        ans++;
        sb.append(ans + "\n");
    }
}