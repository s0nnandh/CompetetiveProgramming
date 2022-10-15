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
#define gcd(a,b) __gcd(a,b)
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

int length(long long x){
    int ans = 0;
    while(x){
        x /= 10;
        ++ans;
    }
    return ans;
}

void solve(){
	using ll = long long;
    int n;ll X;
    std :: cin >> n >> X;
    if(X == 1){
        std :: cout << ( n == 1 ? 0 : -1) << '\n';
        return;
    }
    std :: vector<int> ans(20,1e9);
    std :: map<ll,bool> mp;
    std :: priority_queue<std :: pair<int, ll>,std :: vector< std :: pair<int, ll>>,std :: greater<std :: pair<int, ll>>> q;
    q.push({0,X});
    while(!q.empty()){
        auto x = q.top();
        q.pop();
        ll t = x.second;
        if(length(x.second) == n){
            std :: cout << x.first << '\n';
            return;
        }
        while(t){
            ll d = t % 10;
            if(d > 1 && (double)d * x.second <= 4e18 && mp[d * x.second] == 0 && length(d * x.second) <= n){
                mp[d * x.second] = 1;
                q.push({x.first + 1,d * x.second});
            }
            t /= 10;
        }
    }
    std :: cout << -1 << '\n';
    // std :: cout << (ans[n] == 1e9 ? -1 : ans[n]) << '\n';
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);  	
    int test=1;
    // std :: cin>>test;   
    while(test--)
        solve();
    return 0;
}
