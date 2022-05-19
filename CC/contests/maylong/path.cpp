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

const ll mod  = 1e9 + 7;
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

vector<vector<int>> adj;

vector<ll> dp,inbw;

vector<bool> v;

void dfs(int u,int par){
    v[u] = 1;
    for(auto x : adj[u]){
        if(!v[x]){
            dfs(x,u);
            // dbg(x,dp[x]);
            dp[u] = madd(dp[u],mmul(2,(dp[x] - 1)));
        }
    }    
    dp[u] += 2;
    if(adj[u].size() > 1){
        ll s = 0,ss = 0;
        for(auto x : adj[u]){
            if(x != par){
                ll t = msub(dp[x],1);
                s = madd(s,t);
                ss = madd(ss,mmul(t,t));
            }
        }  
        s = mmul(s,s);
        inbw[u] = msub(s,ss);
    } 
}

void solve(){
    
    int n;
    cin >> n;
    adj.resize(n);
    dp.resize(n);
    inbw.resize(n);
    v.resize(n);
    rep(i,0,n-1){
        int a,b;
        cin >> a >> b;
        --a;--b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0,-1);
    // dbg(dp[0]);
    dp[0] = msub(dp[0],1);
    // dp[0] -= 1;
    for(auto x : inbw){
        // dbg(x);
        dp[0] = madd(dp[0],x);
    }

    cout << dp[0];ln;
    for(auto &x : adj)x.clear();
    adj.clear();
    dp.clear();
    v.clear();
    inbw.clear();
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