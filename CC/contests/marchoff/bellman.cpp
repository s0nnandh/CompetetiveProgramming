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

const ll mod  = 998244353;
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

struct UF{
    vector<int> par, sz;
    UF() {}
    UF(int n):par(n), sz(n, 1){
        for(int i=0; i<n; i++) par[i]=i;
    }
    int find(int x){
        if(par[x]==x) return x;
        return par[x]=find(par[x]);
    }
    void unite(int x, int y){
        x=find(x); y=find(y);
        if(x==y) return;
        if(sz[x]>sz[y]) swap(x, y);
        par[x]=y;
        sz[y]+=sz[x];
    }
    bool same(int x, int y){
        return find(x)==find(y);
    }
    int size(int x){
        return sz[find(x)];
    }
};  

void solve(){
    int c,n,m;
    cin >> c >> n >> m;
    vector<pair<int,pi>> v; 
    rep(i,0,c){
        int x;
        cin >> x;
        rep(j,0,x){
            int l,r;
            cin >> l >> r;
            v.pb({l,{r,i}});
        }
    }
    sort(v.begin(),v.end());
    stack<pair<int,pi>> s;
    s.push(v[0]);
    //vector<bool> vis(c);
    UF uf(c);
    //vis[v[0].sc.sc] = 1;
    int prev_vertex = v[0].sc.sc;
    ll ans = v[0].fr - 1;
    rep(i,1,(int)v.size()){
        if(v[i].fr <= s.top().sc.fr){
            int l = s.top().fr;
            int r = max(s.top().sc.fr,v[i].sc.fr);
            s.pop();
            s.push({l,{r,-1}});
            uf.unite(prev_vertex,v[i].sc.sc);
            prev_vertex = v[i].sc.sc;
        }
        else{
            ans += v[i].fr - s.top().sc.fr - 1;
            s.push(v[i]);
            prev_vertex = v[i].sc.sc;
        }
    } 
    ans += n - s.top().sc.fr;
    rep(i,0,c)ans += (uf.par[i] == i);
    cout << mpow(m % mod,ans);
    ln;
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