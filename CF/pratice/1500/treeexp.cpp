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

int start = -1;

void dfs(vector<bool> &v,vector<vector<int>> &adj,vector<ll> &ans,int u,ll cost,int d,vector<int> &deg,map<int,int> &mp){
    if(!v[u]){
        v[u] = 1;
        if(adj[u].size() == 1){
            ans[u] = cost;
            mp[u] = d;
            return;
        }
        int de = deg[u];
        if(u != start)--de;
        for(auto x : adj[u]){
            dfs(v,adj,ans,x,cost * de,d + 1,deg,mp);
        }
    }
}

void solve(){

    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> deg(n);
    vector<bool> vis(n);
    vector<ll> ans(n);
    rep(i,0,n-1){
        int a,b;
        cin >> a >> b;
        --a;--b;
        if(start == -1)start = a;
        deg[a]++;
        deg[b]++;
        adj[a].pb(b);adj[b].pb(a);
    }
    start = 1;
    map<int,int> mp;
    dfs(vis,adj,ans,0,1,0,deg,mp);
    ll tot = 0,sum = 0;
    rep(i,0,n){
        tot += ans[i] * mp[i];
        sum += ans[i];
    }
    cout << setprecision(15) << fixed;
    long double final = tot / sum;

    cout << final;ln;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    gen_factorial(1e6);   
    int test=1;
    // cin>>test;   
    while(test--)
        solve();
    return 0;
}