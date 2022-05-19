#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define DEBUG(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)
using namespace std;
//const int m = 1e9 + 7;
bool isPrime(ll n) 
{ 
    
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (ll i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 
void solve(){
    ll n;
    cin >> n;
     ll cnt = 1;
    int b = 1e6;
    // if(n == 2){
    //     cout << n << " " << 2*n << " ";
    // }
    // else{
    //     cout << n << " " << 2*n << " " << 3*n << " ";
    //     cnt = 3;
    // }
    // //cout << n << " ";
    // ll i = 2;
   
    // //fast_sieve();
    // ll a = 3,b = 1000000000;
    // for (i = a; (i <= b) && (cnt < n); i = i + 2) {
        
    //     bool flag = 1;
    //     if (i % 2 == 0 || i % 3 == 0) 
    //             flag = 0;
    //     ll j;
    //     for (j = 5; j * j <= i; j = j+6) {
    //         if (i % j == 0 || i % (j+2) == 0 ){
    //             flag = 0;
    //             break;
    //         }
    //     }
 
       
    //     if (flag == 1){
    //         cout << n * i << " ";
    //         ++cnt;
    //     }
        
    // }
    bool prime[b+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=b; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=b; i += p) 
                prime[i] = false; 
        } 
    } 
    cout << n << " ";
    for (ll p=2; (p<=b) && (cnt < n); p++) {
       if (prime[p]) {
          cout << n * p << " "; 
          ++cnt;
       }
    }
 

    // while(true){
    //     if(cnt >= n)break;
        
    //     if(isPrime(i)){
    //         cout << n*i << " ";
    //         ++cnt;
    //     }
    //     ++i;
    // }
    ln;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int test=1;
    //cin>>test;   
    while(test--)
        solve();
    return 0;
}
