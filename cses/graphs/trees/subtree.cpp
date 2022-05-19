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
const int nx = 2e5 + 5;
vector<int> adj[nx];
vector<int> t;
ll v[nx];
int sz[nx];
int idx[nx];
void dfs1(int u,int par){
    t.pb(u);
    for(auto x : adj[u]){
        if(x == par)continue;
        dfs1(x,u);
        sz[u] += sz[x];
    }
}

struct Fenwick{   // 1 - indexed Fenwick tree
    int n;
    vector<ll> bit;  

    Fenwick(int nn){
        this -> n = nn;
        bit.resize(nn + 1);
    }
    void add(ll x,int i){
        while(i <= n){
            bit[i] += x;
            i += i & (-i);
        }
    }
    ll get(int i){
        ll sum = 0;
        while(i > 0){
            sum += bit[i];
            i -= i & (-i);
        }  
        return sum; 
    }
    ll query(int l,int r){
        return get(r) - get(l-1);
    }
};

void solve(){

    int n,q;
    cin >> n >> q;
    rep(i,1,n + 1){
        cin >> v[i];
        sz[i] = 1;
    }
    rep(i,0,n-1){
        int a,b;
        cin >> a >> b;
        // --a;--b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    t.pb(0);
    dfs1(1,-1);
    // rep(i,0,n + 1)cout << t[i] << " " << sz[i] <<  " ";
    // ln;
    rep(i,1,n + 1)idx[t[i]] = i;
    Fenwick f(n);
    rep(i,1,n + 1){
        f.add(v[i],idx[i]);
        // dbg(v[i],idx[i]);
    }
    // for(auto x : f.bit)cout << x << " ";
    // ln;
    rep(i,0,q){
        int typ;
        cin >> typ;
        if(typ == 1){
            int s,x;
            cin >> s >> x;
            f.add(x - v[s],idx[s]);
            v[s] = x;
        }
        else{
            int s;
            cin >> s;
            // for(auto x : f.bit)cout << x << " ";
            // ln;
            // dbg(idx[s],sz[s],idx[s] + sz[s] - 1);
            cout << f.query(idx[s],idx[s] + sz[s] - 1);ln;
        }
    }
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