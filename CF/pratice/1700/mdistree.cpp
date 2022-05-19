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
ll mod = 1e9 + 7;   
inline ll add(ll a,ll b){
    return (a + b) % mod;
}
inline ll mul(ll a,ll b){
    return ( (a % mod) * (b % mod) ) % mod;
}
void solve(){
    int n;
    cin >> n;
    vector<vi> g;
    vi cnt;
    g.resize(n);
    cnt.resize(n,1);  
    rep(i,0,n - 1){
        int a,b;
        cin >> a >> b;
        --a;--b;
        g[a].pb(b);
        g[b].pb(a);
    }
    priority_queue<ll> q;    
    function<void(int,int)> dfs = [&](int u,int par){
        for(auto x : g[u]){
            if(x == par)continue;
            dfs(x,u);
            cnt[u] += cnt[x];
        } 
        for(auto x : g[u]){
            if(x == par)continue;  
            // dbg(cnt[u],cnt[x],u,x);          
            q.push((ll)(n - cnt[x]) * cnt[x]);
        } 
    };
    dfs(0,-1);
    // dbg((int)q.size());
    assert(len(q) == n - 1);
    int m;
    cin >> m;
    vl p(m);
    for(auto &i : p)cin >> i;
    sort(all(p),greater<ll>());
    ll ans = 0;
    if(m <= n - 1){
        int ptr = 0;
        while(!q.empty()){            
            ll val = (ptr < m ? p[ptr] : 1);
            // dbg(q.top(),val);
            ans = add(ans,mul(val,q.top()));
            q.pop();
            ++ptr;
        }
    }
    else{
        int ptr = 0;
        // dbg(n,m);
        int e =  n - 1;
        ll M = 1;
        while(ptr < m - e + 1){
            M = mul(M,p[ptr++]);
        }
        ans = add(ans,mul(M,q.top()));
        q.pop();
        while(!q.empty()){
            // dbg(ptr);
            ans = add(ans,mul(q.top(),p[ptr++]));
            q.pop();
        }
    }
    cout << ans;ln;
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
