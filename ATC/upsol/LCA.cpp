#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ln cout<<"\n"
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define pc(x) __builtin_popcount(x)
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
void __dbg(int x) {cerr << x;}
void __dbg(long long x) {cerr << x;}
void __dbg(float x) {cerr << x;}
void __dbg(double x) {cerr << x;}
void __dbg(long double x) {cerr << x;}
void __dbg(char x) {cerr << '\'' << x << '\'';}
void __dbg(const char *x) {cerr << '\"' << x << '\"';}
void __dbg(const string &x) {cerr << '\"' << x << '\"';}
void __dbg(bool x) {cerr << (x ? "true" : "false");} 
template<class T,class V>void __dbg(const pair<T, V> &x) {cerr << "{ "; __dbg(x.first); cerr << ','; __dbg(x.second); cerr << "}";}
template<class T>void __dbg(const T &x) {int f = 0; cerr << "{ "; for (auto &i: x) cerr << (f++ ? "," : ""), __dbg(i); cerr << "}";}
void _dbg() {cerr << " ]" << endl;}
template <class T, class... V>void _dbg(T t, V... v) {__dbg(t); if (sizeof...(v)) cerr << ", "; _dbg(v...);} 
#ifdef _DEBUG
#define dbg(x...) cerr << "[" << #x << "] = [ "; _dbg(x)
#else
#define dbg(x...)
#endif   

struct LCA{
    int n;
    int root;
    vector<vector<int>> g;
    vector<vector<int>> up; 
    vector<int> depth;  
    int LOG;
    LCA(){

    }
    LCA(vector<vector<int>> &adj,int r = 0){ // 0 indexed based LCA 
        g = adj; 
        n = adj.size();
        root = r;
        preprocess();   
    }
    void preprocess(){
        LOG = 17; // change log if required(17 if 1e5 20 if 1e6)
        up.assign(n,vector<int> (LOG));
        depth.assign(n,0);
        for(int i = 0;i < LOG;++i)up[root][i] = root;
        dfs(root,-1);
    }
    void dfs(int u,int par){
        if(par == -1){
            depth[u] = 0;
        }
        else{
            depth[u] = 1 + depth[par];
        }
        for(auto x : g[u]){
            if(x == par)continue;
            up[x][0] = u;
            for(int j = 1;j < LOG;++j){
                up[x][j] = up[up[x][j - 1]][j - 1]; // powers of 2 2 ^ 3 = 2 ^ 2 + 2 ^ 2
            }
            dfs(x,u);
        }
    }
    int kth_anc(int u,int k){
        for(int j = LOG - 1;j >= 0;--j){
            if(k&(1 << j))u = up[u][j];
        }
        return u;
    }
    int lca(int a,int b){
        // d b > d a
        if(depth[a] > depth[b]){
            swap(a,b);
        }
        // make them bit h at same depth
        int k = depth[b] - depth[a];
        b = kth_anc(b,k);
        if(a == b){
            return a;
        }
        // start from higher powers
        for(int j = LOG - 1;j >= 0;--j){
            if(up[a][j] != up[b][j]){
                a = up[a][j];
                b = up[b][j];
            }
        }
        return up[a][0];
    }
    int dis(int a,int b){
        int x = lca(a,b);
        return depth[a] + depth[b] - 2 * depth[x];
    }
};

void solve(){
    int n,q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    rep(i,0,n - 1){
        int a,b;
        cin >> a >> b;
        --a;--b;
        g[a].pb(b);
        g[b].pb(a);
    }
    LCA L(g);
    rep(i,0,q){
        int c,d;
        cin >> c >> d;
        --c;--d;
        cout << (L.dis(c,d)&1 ? "Road" : "Town");ln;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);     
    int test=1;
    // cin>>test;   
    while(test--)
        solve();
    return 0;
}
