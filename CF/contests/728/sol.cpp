#include<bits/stdc++.h>
#define ll long long
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
#define dbg(...) cerr << "" << endl
#endif

#define pi pair<int,int>
#define pl pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back
#define gcd(a,b) __gcd(a,b)
#define len(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vl vector<ll>

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

ll inv = minv(2);

void solve(){
    
    int n;
    cin >> n;
    vi adj[n];
    vector<vi> d(n,vi(n));
    vector<vl> dp(n,vl(n));
    rep(i,0,n - 1){
        int a,b;
        cin >> a >> b;
        --a;--b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    function<void(int,int,int)> dfs = [&](int u,int par,int from){
        for(auto x : adj[u]){
            if(x == par)continue;
            d[from][x] = 1 + d[from][u];
            dfs(x,u,from);
        }
    };
    rep(i,0,n){
        dfs(i,-1,i);
    }
    // dp calculation 
    // dp[a][b] is probabilty that node with distance a is reached earlier than a node with dis b
    // dp[a][b] = .5 * (dp[a - 1][b] + dp[a][b - 1])
    rep(i,0,n){
        rep(j,0,n){
            if(i == 0){
                dp[i][j] = 1;
                // reaached our goal
            }
            else if(j == 0){
                dp[i][j] = 0;
                // impossiblee
            }   
            else{
                dp[i][j] = mmul(inv,madd(dp[i - 1][j],dp[i][j - 1]));
            }
        }
    }
    // now for each pair of inversion 
    ll ans = 0;
    for(int i = 0;i < n;++i){
        for(int j = i + 1;j < n;++j){
            // considering i j as invserion pair
            // j must come before i
            ll D = d[i][j];
            rep(k,0,n){ // start node
                // y + z = d[a][b]
                // x + y = d[k][a]
                // x + z = d[k][b];
                // y - z = d[k][a] - d[k][b]
                ll y = (D + d[k][i] - d[k][j]) / 2;
                ll z = (D - y);
                ans = madd(ans,dp[z][y]);
            }
        }
    }
    cout << mdiv(ans,n);ln;

}       

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    // gen_factorial(1e6);  	
    int test=1;
	// cin>>test;   
    while(test--)
        solve();
    return 0;
}
