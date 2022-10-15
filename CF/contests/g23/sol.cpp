#include<bits/stdc++.h>
#define ll long long
#define ln cout<<"\n"
#define rep(i,s,n) for(ll i = (s);i<(n);++i)
#define pc(x) __builtin_popcount(x)
#define pi std::pair<int,int>
#define pl std::pair<ll,ll> 
#define fr first
#define sc second
#define pb push_back
#define gcd(a,b) std :: __gcd(a,b)
#define len(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define vi std::vector<int>
#define vl std::vector<ll>
void __dbg(int x) {std::cerr << x;}
void __dbg(long long x) {std::cerr << x;}
void __dbg(float x) {std::cerr << x;}
void __dbg(double x) {std::cerr << x;}
void __dbg(long double x) {std::cerr << x;}
void __dbg(char x) {std::cerr << '\'' << x << '\'';}
void __dbg(const char *x) {std::cerr << '\"' << x << '\"';}
void __dbg(const std::string &x) {std::cerr << '\"' << x << '\"';}
void __dbg(bool x) {std::cerr << (x ? "true" : "false");} 
template<class T,class V>void __dbg(const std::pair<T, V> &x) {std::cerr << "{ "; __dbg(x.first); std::cerr << ','; __dbg(x.second); std::cerr << "}";}
template<class T>void __dbg(const T &x) {int f = 0; std::cerr << "{ "; for (auto &i: x) std::cerr << (f++ ? "," : ""), __dbg(i); std::cerr << "}";}
void _dbg() {std::cerr << " ]" << std::endl;}
template <class T, class... V>void _dbg(T t, V... v) {__dbg(t); if (sizeof...(v)) std::cerr << ", "; _dbg(v...);} 
#ifdef _DEBUG
#define dbg(x...) std::cerr << "[" << #x << "] = [ "; _dbg(x)
#else
#define dbg(x...)
#endif

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vi> g(n);
    for(int i = 0;i < n - 1;++i) {
        int x;
        cin >> x;
        --x;
        g[x].push_back(i + 1);
    }
    vl s(n), sum(n), top(n);
    for(ll &i : s)cin >> i;
    top[0] = s[0];
    function<void(int)> pre_dfs = [&](int u) {
        int sz = g[u].size();
        if(sz == 0){
            sum[u] = s[u];
            return;
        }
        ll me = 0;
        for(int v : g[u]) {
            top[v] += top[u];
            pre_dfs(v);
            me = max(me, sum[v]);
        }
        sum[u] = me + s[u];
    };
    function<ll(int, ll me)> dfs = [&](int u, ll paths) {
        ll ans = paths * s[u];
        int sz = g[u].size();
        if(sz == 0)return ans;
        ll me = paths / sz;
        vl tv;
        for(int v: g[u]){
            tv.push_back(sum[v] + top[v] - s[v]);
            ans += dfs(v, me);
        }
        sort(all(tv), greater<ll>());
        for(int i = 0;i < paths % sz;++i)ans += tv[i];
        return ans;
    };
    pre_dfs(0);
    cout << dfs(0, (ll)k) << '\n';
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);  	
    int test=1;
    std :: cin>>test;   
    while(test--)
        solve();
    return 0;
}
