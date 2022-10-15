import java.util.Scanner;
/**
 * Sol
 */
public class Sol {

    public static Scanner sc = new Scanner(System.in);
    public static StringBuilder sb = new StringBuilder();

    public static void main(String args[]) {        
        int tt = 1;
        // tt = sc.nextInt();
        for(int i = 0;i < tt;++i)solve();
        System.out.print(sb.toString());
        sc.close();
    }

    private static void solve(){
        int n = sc.nextInt(),q = sc.nextInt();
        int arr[] = new int[n];
        long sum = 0;
        for(int i = 0;i < n;++i){
            arr[i] = sc.nextInt();
            sum += arr[i];
        }
        long val = -1;
        int val_timer = 0;
        int arr_timer[] = new int[n];
        for(int i = 0;i < n;++i)arr_timer[i] = 0;
        for(int i = 0;i < q;++i){
            int typ = sc.nextInt();
            if(typ == 1){
                int idx = sc.nextInt() - 1,x = sc.nextInt();
                if(val_timer > arr_timer[idx]){
                    arr[idx] = (int)val;
                }
                sum += x - arr[idx];
                arr[idx] = x;
                arr_timer[idx] = i + 1;
            }
            else{
                long x = sc.nextLong();
                val = x;
                sum = (long)n * x;
                val_timer = i + 1;
            }
            sb.append(sum + "\n");
        }
    }

    
}