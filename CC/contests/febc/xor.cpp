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
#define dbg(...) cerr << "[ ]" << endl
#endif

const ll mod  = 998244353;
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
	
	const ll FACTORIAL_SIZE = 2.1e5;
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
	vector<vector<ll>> cnt(30,vector<ll> (n+1));
	rep(i,0,n){
		int k;
		cin >> k;
		rep(j,0,30){
			if(k&(1LL<<j))cnt[j][i+1] = 1;
		}
	}
	rep(i,0,30){
		rep(j,1,n+1){
			cnt[i][j]+=cnt[i][j-1];
		}
	}
	vector<ll> power(30,0);
    power[0] = 1;
    rep(i,1,30){
        power[i] = mmul(power[i-1],2);
    }
	//rep()
	// rep(i,0,3){
	// 	rep(j,1,n+1){
	// 		cout << cnt[i][j] << " ";
	// 	}
	// 	ln;
	// }
	vector<ll> ans(n+1);
	// rep(i,0,30){
	// 	rep(j,1,n+1){
			
	// 		int ev = (cnt[i][j] - cnt[i][j-1] == 1)?0:1;
	// 		int one = cnt[i][n] - cnt[i][j];
	// 		while(ev <= one){
	// 			int z = n - j - one;
	// 			while(z >= 0){
	// 				ans[z+ev+1] = madd(ans[z+ev+1],mmul(power[i],mmul(nck(one,ev),nck(n-j-one,z))));
	// 				--z;
	// 			}
	// 			ev+=2;
	// 		}			
	// 	}
	// }
	// repeat over all pos of bits and calculate for each length possible given by i	
	rep(i,0,30){
		rep(j,1,n+1){
			int one = cnt[i][n];int z = n-one,t1 = one;
			if(one != 0 && one%2 == 0)--one;
			int p = 0;
			while(one){
				if(z >= j-one)ans[j] = madd(ans[j],mmul(power[i],mmul(nck(t1,one),nck(z,j-one)))); 
				one-=2;
			}
		}
	}
	rep(i,1,n+1){
		ans[i] = madd(ans[i],ans[i-1]);
	}
	int q;
	cin >> q;
	rep(i,0,q){
		int m;
		cin >> m;
		cout << ans[m];ln;
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    gen_factorial(1000);    
    int test=1;
    //cin>>test;   
    while(test--)
        solve();
    return 0;
}

