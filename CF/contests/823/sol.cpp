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

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> x(n), t(n);
    for(int &i : x)std :: cin >> i;
    for(int &i : t)std :: cin >> i;
    map<int, int> mp;
    std :: vector<pi> v;
    for(int i = 0;i < n;++i)v.push_back({2 * x[i], t[i]});
    sort(all(v));
    for(int i = 0;i < n - 1;++i)v.push_back({(v[i].first + v[i + 1].first) / 2, -1});
    sort(all(v));
    int me = 0, prev = v[0].first;
    for(int i = 0;i < (int)v.size();++i) {
        me = max(me + v[i].first - prev, v[i].second);
        mp[v[i].first] = me;
        prev = v[i].first;
    }
    reverse(all(v));
    me = 0;prev = v[0].first;
    for(int i = 0;i < (int)v.size();++i) {
        me = max(me + prev - v[i].first, v[i].second);
        mp[v[i].first] = std :: max(me, mp[v[i].first]);
        prev = v[i].first;
    }
    int mx = 1e9, idx = 0;
    for(auto X : mp) {
        if(mx > X.second) {
            mx = X.second;
            idx = X.first;
        }
    }
    std :: cout << (double)idx / 2 << '\n';
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
