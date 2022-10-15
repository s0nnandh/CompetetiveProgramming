import java.util.ArrayList;
import java.util.Scanner;

public class G1 {
    final static Scanner sc = new Scanner(System.in);

    final static StringBuilder sb = new StringBuilder();

    final int mxN = (int)2e5 + 3;

    static ArrayList<ArrayList<Integer>> g = new ArrayList<>();

    public static void main(String[] args) {
        int n = sc.nextInt();
        for(int i = 0;i < n;++i)g.add(new ArrayList<Integer>());
        for(int i = 0;i < n - 1;++i) { 
            int a = sc.nextInt(), b = sc.nextInt();
            --a;--b;
            g.get(a).add(b);
            g.get(b).add(a);
        }
        int q = sc.nextInt();
        for(int i = 0;i < q;++i){
            boolean[] arr = new boolean[n];
            int k = sc.nextInt();
            int me = 0;
            for(int j = 0;j < k;++j) {
                int id = sc.nextInt();
                --id;
                arr[id] = true;
                me = id;
            }
            int ans = dfs(me, -1, arr, me);
            sb.append(ans != -(int)1e9 && ans <= 2 ? "YES\n" : "NO\n");
        }
        System.out.println(sb.toString());
    }

    private static int dfs(int u, int par, boolean[] arr, int root) {
        int cnt = 0;
        for(int x : g.get(u)) {
            if(x == par)continue;
            cnt += dfs(x, u, arr, root);
        }
        if(cnt < 0)return -(int)1e9;
        if(cnt == 1)return 1;
        if(cnt > 1){
            return u == root ? cnt : -(int)1e9;
        }
        return arr[u] ? 1 : 0;
    }
}
