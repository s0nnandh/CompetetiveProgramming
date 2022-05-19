#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ln cout<<"\n"
#define pc(x) __builtin_popcount(x)
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
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
template<class T,class V>void __dbg(const pair<T, V> &x) {cerr << "{ "; __dbg(x.first); cerr << ','; __dbg(x.second); cerr << "}";}
void __dbg(bool x) {cerr << (x ? "true" : "false");} 
template<class T>void __dbg(const T &x) {int f = 0; cerr << "{ "; for (auto &i: x) cerr << (f++ ? "," : ""), __dbg(i); cerr << "}";}
void _dbg() {cerr << " ]" << endl;}
template <class T, class... V>void _dbg(T t, V... v) {__dbg(t); if (sizeof...(v)) cerr << ", "; _dbg(v...);} 
#ifdef _DEBUG
#define dbg(x...) cerr << "[" << #x << "] = [ "; _dbg(x)
#else
#define dbg(x...)
#endif
vector<vector<int>> adj,rev;
vector<bool> vis;
vector<int> order;
vector<int> c;

void dfs1(int u){
    vis[u] = 1;

    for(auto x : adj[u]){
        if(!vis[x])dfs1(x);
    }
    order.push_back(u);
}

void dfs2(int u){
    vis[u] = 1;    
    c.push_back(u);

    for(auto x : rev[u]){
        if(!vis[x])dfs2(x);
    }

}
int mod = 1e9 + 7;
void solve(){
    int n;
    cin >> n;
    vector<int> cost(n);
    for(auto &i : cost)cin >> i;
    adj.resize(n);
    rev.resize(n);
    int m;
    cin >> m;
    for(int i = 0;i < m;++i){
        int a,b;
        cin >> a >> b;
        --a;--b;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }
    vis.assign(n,0);
    for(int i = 0;i < n;++i){
        if(!vis[i])dfs1(i);
    }
    reverse(all(order));
    vis.assign(n,0);
    ll ans = 0;
    ll ways = 1;
    for(auto x : order){
        if(!vis[x]){
            dfs2(x);
            // dbg(ways);
            int min_cost = 1e9,num = 0;
            for(auto y : c)min_cost = min(min_cost,cost[y]);
            for(auto y : c)num += cost[y] == min_cost;
            ways = (ways * num) % mod;
            ans += min_cost;
            c.clear();
        }
    }
    cout << ans << " " << ways << '\n';

}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    int test = 1;
    // cin >> test;
    while(test--)solve();
        // gen_factorial(1e6); 
    return 0;
}

