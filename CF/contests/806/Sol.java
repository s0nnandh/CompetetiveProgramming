import java.util.HashMap;
import java.util.Map;
import java.util.Optional;
import java.util.Scanner;

public class Sol {
    

    final static Scanner sc = new Scanner(System.in);

    final static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) {
        int tt = sc.nextInt();
        for (int i = 0; i < tt; i++) {
            solve();
        }
        System.out.print(sb.toString());
    }

    static void change(Map<String, Integer> mp, String a, String b, Boolean restore) {
        if(mp.containsKey(a))mp.put(a, mp.get(a) - ( restore ? -1 : 1));
        if(mp.containsKey(b))mp.put(b, mp.get(b) - ( restore ? -1 : 1));
    }

    public static void solve() {
        int n = sc.nextInt();
        Map<String, Integer> mp = new HashMap<>();
        String[] v = new String[n];
        for(int i = 0;i < n;++i) {
            String s = sc.next();
            v[i] = s;
            mp.put(s, mp.containsKey(s) ? mp.get(s) + 1 : 1);
        }
        int[] ans = new int[n];
        for(int i = 0;i < n;++i) {
            for(int j = 1;j < n;++j) {
                final String a = v[i].substring(0, j), b = v[i].substring(j);
                change(mp, a, b, false);
                ans[i] = 1;
                if(!mp.containsKey(a) || mp.get(a) < 0)ans[i] = 0;
                if(!mp.containsKey(b) || mp.get(b) < 0)ans[i] = 0;  
                change(mp, a, b, true);
            }
        }
        for(int i = 0;i < n;++i)sb.append(ans[i]);
        sb.append("\n");
    }        
}
