// https://www.codechef.com/problems/MEXUM

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ln cout<<"\n"
using namespace std;
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
#define dbg(...) {}
#endif

#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back
#define gcd(a,b) __gcd(a,b)

const ll mod  = 998'244'353;
namespace modop {
	ll madd(ll a, ll b) {
        ll k = a + b;
        if(k < 0)return mod + k;
        if(k > mod)return k - mod;
        return k;

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
    vector<int> cnt(n+1),pre(n + 1),occ(n + 1,1);
    rep(i,0,n){
        int a;
        cin >> a;
        if(a <= n)cnt[a]++;
    }
    rep(i,1,n+1){
        pre[i] = cnt[i];
        pre[i] = madd(pre[i],pre[i-1]);
        occ[i] = msub(mpow(2,cnt[i]),1);
        occ[i] = mmul(occ[i],occ[i-1]);
    }
    // for(auto x : occ){
    //     cout << x << " ";
    // }
    // ln;
    ll ans = 0;
    rep(i,1,n + 1){     /// ans is i * (occ[i-1] * mpow(2,n - pre[i])
        ll k = mpow(2,n - pre[i]);
        ans = madd(ans,mmul(i,mmul(occ[i-1],k)));
        // dbg(ans);
        if(cnt[i] == 0)break;
    }   
    cout << ans;ln;
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    //gen_factorial(1e6);  

    int test=1;
    cin>>test;   
    while(test--)
        solve();
    return 0;
}