#include<bits/stdc++.h>
// #define ll long long
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

void solve(){
    using namespace std;
    int n, m;
    std :: cin >> n >> m;
    vector<vector<pi>> g(n);
    map<pair<int,int>, bool> mp;
    for(int i = 0;i < m;++i) {
        int a,b;
        std :: cin >> a >> b;
        --a;--b;
        if(a > b)swap(a, b);
        g[a].push_back({b, 0});
        g[b].push_back({a, 0});
        mp[{a, b}] = true;
    }    
    for(int i = 0;i < n;++i) {
        if(i && !mp[{i - 1, i}]) {
            g[i - 1].push_back({i, -1});
            g[i].push_back({i - 1, -1});
        }
        if(i + 1 < n && !mp[{i, i + 1}]) {
            g[i].push_back({i + 1, -1});
            g[i + 1].push_back({i, -1});
        }
    }
    const int INF = 1e9;
    vector<int> distance(n, INF);
    priority_queue<pi> q;
    vector<bool> processed(n);
    distance[0] = 0;
    q.push({0,0});
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : g[a]) {
            int b = u.first, w = u.second;
            if (distance[a]+w < distance[b]) {
                distance[b] = distance[a]+w;
                q.push({-distance[b],b});
            }
        }
    }
    std :: cout << -distance[n - 1] << '\n';
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
