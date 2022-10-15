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
    int n, q;
    std :: cin >> n >> q;
    std :: vector<int> v(n), pos(n + 1);
    for(int i = 0;i < n;++i){
        std :: cin >> v[i];
        pos[v[i]] = i;
    }
    std :: vector<int> ans(n);
    int mx = v[0], nx = 0;
    for(int i = 1;i < n;++i){
        if(mx < v[i]) {
            ans[pos[mx]] = i - pos[mx] - 1 + (nx ? 1 : 0);
            mx = v[i];
            nx = 1;
        }
    }
    for(int I = 0;I < q;++I) {
        int i, k;
        std :: cin >> i >> k;
        --i;
        if(i && k < i){
            std :: cout << 0 << '\n';
        }
        else{
            if(v[i] == n){
                std :: cout << k - std :: max(0, pos[n] - 1) << '\n';
            }
            else{
                std :: cout << std :: min(k - std :: max(0, pos[v[i]] - 1), ans[i]) << '\n';
            }
        }
    }
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
