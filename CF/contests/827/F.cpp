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

void solve() {
    vector<int> cnt[2];
    cnt[0].resize(26, 0);
    cnt[1].resize(26, 0);
    cnt[0][0] = cnt[1][0] = 1;
    int q;
    cin >> q;
    vector<int> v(26);
    for(int ii = 0;ii < q;++ii) {
        int typ, k;
        string x;
        cin >> typ >> k >> x;
        for(char c : x)cnt[typ - 1][c - 'a'] += k;
        bool ok = 0;
        for(int i = 0;i < 26;++i)v[i] = cnt[0][i] - cnt[1][i];
        vector<int> a, b;
        for(int i = 0;i < 26;++i) {
            if(v[i] > 0)a.push_back(i);
            else if(v[i] < 0)b.push_back(i);
        }
        ok = (b.size() > 0 && a.size() == 0);
        if(a.size()) {
            for(int j = a.front() + 1;j < 26;++j) {
                ok |= cnt[1][j] > 0;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
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
