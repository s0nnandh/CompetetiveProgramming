import java.util.Scanner;
/**
 * Sol
 */
public class Sol {

    public static Scanner sc = new Scanner(System.in);
    public static StringBuilder sb = new StringBuilder();

    public static void main(String args[]) {        
        int tt = sc.nextInt();
        for(int i = 0;i < tt;++i)solve();
        System.out.print(sb.toString());
        sc.close();
    }

    private static void solve(){
        int n = sc.nextInt();
        int arr[] = new int[n];
        for(int i = 0;i < n;++i)arr[i] = sc.nextInt();
        int ev = 0;
        for(int i = 0;i < n;++i){
            ev += arr[i] % 2 == 0 ? 1 : 0;
        }
        sb.append(Math.min(ev, n - ev) + "\n");
    }

    
}