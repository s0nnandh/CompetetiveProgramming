#include<bits/stdc++.h>
#include<stdio.h>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
using namespace std;
//#define dbg(x) cout<<#x<<" = "<<x<<" "
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define pc(x) __builtin_popcount(x)
void DBG() {
	cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
    //cerr << '[' << endl;
	cerr << to_string(h);
	if(sizeof...(t))
		cerr << ", ";
	DBG(t...);
}
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) cerr << "" << endl
#endif

#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back
#define gcd(a,b) __gcd(a,b)


ll mod = 1e9 + 7;
namespace modop {
	ll madd(ll a, ll b) {
	  return (a + b) % mod;
	}
	ll msub(ll a, ll b) {
	  return (((a - b) % mod) + mod) % mod;
	}
	ll mmul(ll a, ll b) {
	  return ((a % mod) * (b % mod)) % mod;
	}
	ll mpow(ll base, ll exp) {
	  ll res = 1;
	  while (exp) {
		if (exp % 2 == 1){
			res = (res * base) % mod;
		}
		exp >>= 1;
		base = (base * base) % mod;
	  }
	  return res;
	}
	ll minv(ll base) {
	  return mpow(base, mod - 2);
	}
	ll mdiv(ll a, ll b) {
	  return mmul(a, minv(b));
	}
	
	const ll FACTORIAL_SIZE = 1.1e6;
	ll fact[FACTORIAL_SIZE], ifact[FACTORIAL_SIZE];
	void gen_factorial(ll n) {
		fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
		
		for (ll i = 2; i <= n; i++) {
			fact[i] = (i * fact[i - 1]) % mod;
            //dbg(fact[i]);
		}
		ifact[n] = minv(fact[n]);
		for (ll i = n - 1; i >= 2; i--) {
			ifact[i] = ((i + 1) * ifact[i + 1]) % mod;
		}
	}
	ll nck(ll n, ll k) {
		ll den = (ifact[k] * ifact[n - k]) % mod;
        //dbg(ifact[k],ifact[n - k]);
		return (den * fact[n]) % mod;
	}
}
 
using namespace modop;

void solve(){
    
	int n;
	cin >> n;
	vector<ll> c(n);
	for(auto& i : c)cin >> i;
	vector<string> v(n),r(n);
	rep(i,0,n){
		cin >> v[i];
		r[i] = v[i];
		reverse(r[i].begin(),r[i].end());
	}
	vector<vector<ll>> dp(n+1,vector<ll> (2,1e16));
	rep(i,1,n+1){
		rep(j,0,2){
			if(i == 1){
				dp[i][0] = 0;
				dp[i][1] = c[i-1];
			}
			else{
				if(v[i-1] >= v[i-2]){
					dp[i][0] = dp[i-1][0];
				}
				else{
					dp[i][0] = 1e16;
				}
				if(r[i-1] >= v[i-2]){
					dp[i][1] = dp[i-1][0] + c[i-1];
				}
				else{
					dp[i][1] = 1e16;
				}
				if(v[i-1] >= r[i-2]){
					dp[i][0] = min(dp[i][0],dp[i-1][1]);
				}
				else{
					dp[i][0] = min(dp[i][0],(ll)1e16);
				}
				if(r[i-1] >= r[i-2]){
					dp[i][1] = min(dp[i][1],dp[i-1][1] + c[i-1]);
				}
				else{
					dp[i][1] = min(dp[i][1],(ll)1e16);
				}

			}
		}
	}

	cout << (min(dp[n][1],dp[n][0]) >= 1e16?-1:min(dp[n][1],dp[n][0]));ln;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    //gen_factorial(1e6);   
    int test=1;
    // cin>>test;   
    while(test--)
        solve();
    return 0;
}