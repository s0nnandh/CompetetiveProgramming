import java.util.Scanner;

public class D {
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
        String s = sc.next();
        Integer p = sc.nextInt();
        int cnt[] = new int[26];
        Integer sum = 0;
        for(int i = 0;i < s.length();++i){
            cnt[s.charAt(i) - 'a']++;
            sum += s.charAt(i) - 'a' + 1;
        }
        for(int i = 25;i >= 0;) { 
            if(sum <= p)break;
            if(cnt[i] == 0){
                --i;
                continue;
            }
            sum -= i + 1;
            cnt[i]--;    
        }
        StringBuilder msb = new StringBuilder();
        for(int i = 0;i < s.length();++i){
            if(cnt[s.charAt(i) - 'a'] > 0){
                msb.append(s.charAt(i));
                cnt[s.charAt(i) - 'a']--;
            }
        }
        sb.append(msb.toString() + "\n");
    }

}
