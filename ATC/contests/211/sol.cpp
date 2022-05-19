#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
#define ln cout<<endl
#else
#define dbg(x...)
#define ln cout<<"\n"
#endif   
ll mod = 1e9 + 7;
ll inf = 1e18;
void solve(){
    int n,m;
    cin >> n >> m;
    vector<vi> g(n);
    rep(i,0,m){
        int a,b;
        cin >> a >> b;
        --a;--b;
        g[a].pb(b);
        g[b].pb(a);
    }
    queue<int> q;
    vector<ll> d(n,inf),dp(n);
    q.push(0);
    d[0] = 0;
    dp[0] = 1;
    vector<bool> v(n);
    v[0] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto x : g[u]){
            if(!v[x]){
                v[x] = 1;
                q.push(x);
            }
            if(d[x] > 1 + d[u]){
                d[x] = 1 + d[u];
                dp[x] = dp[u];
            }
            else if(d[x] == 1 + d[u]){
                dp[x] = (dp[x] + dp[u]) % mod;
            }
        }
    }
    cout << dp.back();ln;
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
