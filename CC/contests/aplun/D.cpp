// https://www.codechef.com/problems/SPTREE

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

vector<vector<int>> adj;
vector<int> spl;
vector<bool> f;
vector<pi> ans;

void calc(int u,int p){
    // dbg(u,p);
    // exit(0);
    for(auto x : adj[u]){
        if(x == p)continue;
        calc(x,u);
    }
    for(auto x : adj[u]){
        if(x == p)continue;
        if(spl[x] != -1)spl[u] = spl[x];
    }
    if(f[u])spl[u] = u;
}



void dfs(int u,int p,int mx,int d,int node){   
    // dbg(u,p);
    mx += spl[u] != -1 ? 1 : 0;
    node = spl[u] != -1 ? spl[u] : node;
    ans[u].fr = 2*mx - d;
    ans[u].sc = node;
    for(auto x : adj[u]){
        if(x == p)continue;
        dfs(x,u,mx,d+1,node);
    }
}

void solve(){
    
    int n,k,a;
    cin >> n >> k >> a;
    adj.resize(n);
    spl.resize(n,-1);
    f.resize(n);
    ans.resize(n);
    --a;
   rep(i,0,k){
       int c;
       cin >> c;
       --c;
       f[c] = 1;
   }
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        --u;--v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    calc(a,-1);
    dfs(a,-1,-1,0,spl[a]);
    for(auto x : ans)cout << x.fr << " ";
    ln;
    for(auto x : ans)cout << x.sc + 1 << " ";
    ln;
    for(auto &x : adj)x.clear();
    adj.clear();
    spl.clear();
    ans.clear();
    f.clear();
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