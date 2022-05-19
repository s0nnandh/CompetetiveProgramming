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
void _dbg() {cerr << " ]" << endl ;}
template <class T, class... V>void _dbg(T t, V... v) {__dbg(t); if (sizeof...(v)) cerr << ", "; _dbg(v...);} 
#ifdef _DEBUG
#define dbg(x...) cerr << "[" << #x << "] = [ "; _dbg(x)
#else
#define dbg(x...)

#endif

void solve(){
    int n,k;
    cin >> n >> k;
    vector<bool> imp(n),rmv(n);
    int x,y;
    cin >> x >> y;
    --x;--y;
    imp[x] = imp[y] = true;
    for(int i = 0;i < k;++i){
        int a;
        cin >> a;
        --a;
        imp[a] = true;
    }
    vector<int> deg(n);
    vector<vector<int>> g(n);
    for(int i = 0;i < n - 1;++i){
        int a,b;
        cin >> a >> b;
        --a;--b;
        deg[a]++;
        deg[b]++;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> par(n);
    par[x] = x;
    function<void(int,int)> dfs = [&](int u,int p){
        if(p != -1)par[u] = p;
        for(auto x1 : g[u]){
            if(x1 == p)continue;
            dfs(x1,u);
        }
    };
    dfs(x,-1);
    queue<int> q;
    for(int i = 0;i < n;++i)if(deg[i] == 1 && !imp[i])q.push(i);
    int nodes = n;
    while(!q.empty()){
        int me = q.front();
        q.pop();
        if(deg[me] == 0)continue;
        assert(deg[me] == 1);
        int pr = par[me];        
        rmv[me] = 1;
        deg[pr]--;
        --nodes;        
        if(!imp[pr] && deg[pr] == 1){
            q.push(pr);
        }
    }
    int depth = 0;
    function<void(int,int,int)> dfs2 = [&](int u,int p,int d){
        if(u == y)depth = d;
        for(auto x1 : g[u]){
            if(x1 == p)continue;
            if(!rmv[x1])dfs2(x1,u,d + 1);
        }
    };
    dfs2(x,-1,1);
    cout << 2 * nodes - 1 - depth << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    int test=1;
    cin>>test;  
    while(test--)
        solve();
    return 0;
}