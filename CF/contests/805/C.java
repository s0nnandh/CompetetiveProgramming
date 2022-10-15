import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class C {

    final static Scanner sc = new Scanner(System.in);

    final static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) {
        Integer tt = sc.nextInt();
        for(int i = 0;i < tt;++i){
            solve();
        }
        System.out.print(sb.toString());
    }

    private static void solve() {
        Integer n = sc.nextInt(), k = sc.nextInt();
        ArrayList<Integer> arr = new ArrayList<Integer>();  
        for(int i = 0;i < n;++i)arr.add(sc.nextInt());
        Map<Integer, Integer> L = new HashMap<Integer, Integer>(), 
                R = new HashMap<Integer, Integer>();
        for(int i = 0;i < n;++i) {
            R.put(arr.get(i), i + 1);
        }
        for(int i = n - 1;i >= 0;--i) { 
            L.put(arr.get(i), i + 1);
        }
        for(int i = 0;i < k;++i){
            Integer a = sc.nextInt(), b = sc.nextInt();
            sb.append(R.containsKey(a) && R.containsKey(b) &&  R.get(b) >= L.get(a) ? "YES\n" : "NO\n");
        }
    }

}
