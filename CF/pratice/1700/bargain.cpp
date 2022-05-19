#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define DEBUG(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)
using namespace std;
const int mod = 1000000007;
void solve(){
    string s;
    cin>>s;
    ll n = s.length();
    vector<ll> power(n);
    power[0] = 1;
    rep(i,1,n){
        power[i] = (power[i-1]*10)%mod;
    }
    //rep(i,0,n)cout<<power[i]<<" ";ln;
    vector<ll> right(n+1);
    right[0] = 0;
    rep(i,1,n+1){
        right[i] = (((i)*power[i-1])%mod + right[i-1])%mod;
    }
    //rep(i,0,n+1)cout<<right[i]<<" ";ln;
    ll ans = 0;
    for(ll i = n-1;i>=0;--i){
        ll t = s[i] - '0';
        //dbg(t);ln;
        ans=(ans + (right[n-1-i]*t)%mod)%mod;
        //dbg(ans);
        ans=(ans + (t*(power[n-1-i]*(((i*(i+1))/2)%mod))%mod)%mod)%mod;
        //dbg(ans);
    }
    cout<<ans;
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

// PROBLEM CAN BE SOLVED BY CONTRIBUTION TECHNIQUE BY FINDING HOW MUCH EACH
// DIGIT CONTRIBUTES TO THE ANSWER

// digit = t
//  n*(n+1)/2 * power10(after digit) + t * 54321