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
#define all(x) x.begin(),x.end()

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
vector<vector<int>> adj;
vector<vector<int>> tree;
vector<bool> c;

void dfs(int u,int par,bool color){
    for(auto x : tree[u]){
        if(x == par)continue;
        c[u] = color;
        dfs(x,u,!color);    
    }
}

int inf = 1e9;
void solve(){

    int n,m;
    cin >> n >> m;
    adj.resize(n);
    UF uf(n);
    rep(i,0,m){
        int a,b;
        cin >> a >> b;
        --a;--b;
        uf.unite(a,b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bool ok = *max_element(uf.sz.begin(),uf.sz.end()) == n;
    if(!ok){
        cout << "NO";ln;
        return;
    }
    priority_queue<int,vector<int>,greater<int>> q;
    vector<bool> mst(n);  
    vector<int> p(n);
    q.push(0);
    while(!q.empty()){
        int u = q.top();       
        q.pop();
        if(mst[u])continue;
        mst[u] = 1;
        for(auto x : adj[u]){
            if(!mst[x]){
                q.push(x);
                p[x] = u;
                q.push(x);
            }
        }
    }
    tree.resize(n);
    rep(i,0,n){
        tree[i].pb(p[i]);
        tree[p[i]].pb(i);
    }
    c.resize(n);
    dfs(0,-1,0);
    vector<int> ans;
    rep(i,0,n)if(!c[i])ans.pb(i);
    cout << "YES";ln;
    cout << ans.size();ln;
    for(auto x : ans)cout << x + 1 << " ";
    ln;
    rep(i,0,n){
        adj[i].clear();
        tree[i].clear();
    }
    adj.clear();
    tree.clear();
    c.clear();
}	

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    // gen_factorial(1e6);  	
    int test=1;
	cin>>test;   
    while(test--)
        solve();
    return 0;
}
