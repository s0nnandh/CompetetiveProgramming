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
    int n;
    std :: cin >> n;
    bool dp[n][10][3];
    for(int i = 0;i < n;++i){
        for(int j = 0;j < 10;++j)for(int k = 0;k < 3;++k)dp[i][j][k] = 0;
    }
    for(int i = 0;i < n;++i){
        int x;
        std :: cin >> x;
        x %= 10;
        if(i == 0){
            dp[i][x][0] = 1;
        }
        else{
            dp[i][x][0] = 1;
            for(int j = 0;j < 10;++j){
                dp[i][(x + j) % 10][1] = dp[i - 1][j][0];
                dp[i][(x + j) % 10][2] = dp[i - 1][j][1];
            }
            for(int j = 0;j < 10;++j){
                for(int k = 0;k < 3;++k){
                    dp[i][j][k] |= dp[i - 1][j][k];
                }
            }
        }
    }
    bool ans = 0;
    for(int i = 0;i < n;++i)ans |= dp[i][3][2];
    std :: cout << (ans ? "YES" : "NO") << '\n';
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
