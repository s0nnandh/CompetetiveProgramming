import java.util.Scanner;

/**
 * Sol
 */
public class Sol {

    final static private Scanner sc = new Scanner(System.in);

    final static private StringBuilder sb = new StringBuilder();

    public static void main(String[] args) {
        int n = sc.nextInt(), mxN = sc.nextInt() + 1;
        long[] a = new long[mxN], b = new long[mxN], ans = new long[2 * mxN];
        for(int i = 0;i < n;++i) {
            int x = sc.nextInt(), y = sc.nextInt();
            a[x]++;
            b[y]++;
        }
        for(int i = 0;i < mxN;++i) {
            for(int j = 0;j < mxN;++j) {
                ans[i + j] += a[i] * a[j];
                ans[i + j + 1] -= b[i] * b[j];
            }
        }
        long tot = 0;
        for(int i = 0;i < 2*mxN - 1;++i) {
            tot += ans[i];
            System.out.println(tot);
        }
    }
    
}