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
#define int long long
int inf = 1e18;
int n;
vector<vector<int>> adj;
vector<int> color;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v) {
    color[v] = 1;
    for (int u : adj[v]) {
        dbg(u,color[u]);
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u))
                return true;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

vi find_cycle() {
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;
    vector<bool> incyc(n,0);
    for (int v = 0; v < n; v++) {
        if (color[v] == 0 && dfs(v)){
            dbg(v);
            if(cycle_start != - 1){
                vector<int> cycle;
                cycle.push_back(cycle_start);
                for (int vv = cycle_end; vv != cycle_start; vv = parent[vv])
                    cycle.push_back(vv);
                cycle.push_back(cycle_start);                        
                // for(int x : cycle)incyc[x] = 1;
            }
            cycle_start = -1;
        }            
    }
    vector<int> ans(n);
    // reachable
    queue<int> q;
    vector<bool> can(n);
    q.push(0);
    ans[0] = 1;   
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(ans[u] == 1){
            ans[u] = 2;
            continue;
        }
        for(auto x : adj[u]){
            if(ans[x] != 2){
                ans[x] = 1;
                q.push(x);
            }
        }
    } 
    rep(i,0,n){
        if(incyc[i])ans[i] = -1;
    }
    return ans;
}
void solve(){
    int m;
    cin >> n >> m;
    adj.resize(n);
    rep(i,0,m){
        int a,b;
        cin >> a >> b;
        --a;--b;
        adj[a].pb(b);
    }
    vi ans = find_cycle();
    for(auto x : ans)cout << x << " ";
    ln;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);     
    int test=1;
    cin>>test;   
    while(test--)
        solve();
    return 0;
}
