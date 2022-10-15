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

bool check(std :: vector<int> &v){
    bool ok = 1;
    int n = (int)v.size();
    for(int i = 0;i < n;++i){
        if(i == 0){
            ok &= (v[n - 1] > v[0] && v[1] > v[0]) || (v[n - 1] < v[0] && v[1] < v[0]); 
        }
        else if(i == n - 1){
            ok &= (v[n - 1] > v[n - 2] && v[n - 1] > v[0]) || (v[n - 2] > v[n - 1] && v[0] > v[n - 1]);
        }
        else ok&= (v[i - 1] > v[i] && v[i + 1] > v[i]) || (v[i] > v[i - 1] && v[i] > v[i + 1]);
    }
    return ok;
}

void solve(){
    int n;
    std :: cin >> n;
    std :: vector<int> v(n);
    for(int &i : v)std :: cin >> i;
    std :: vector<int> ans(n,-1);
    std :: sort(all(v));
    int i = 0,j = 0;
    for(;j < n;i++,j += 2)ans[j] = v[i];
    for(j = 1;j < n;j += 2,i++)ans[j] = v[i];
    // dbg(ans);
    if(check(ans)){
        std :: cout << "YES" << '\n';
        for(auto x : ans)std :: cout << x <<  ' ';
        std :: cout << '\n';
        return;
    }
    i = 0;j = 1;
    for(;j < n;i++,j += 2)ans[j] = v[i];
    for(j = 0;j < n;j += 2,i++)ans[j] = v[i];
    // dbg(ans);
    if(check(ans)){
        std :: cout << "YES" << '\n';
        for(auto x : ans)std :: cout << x <<  ' ';
        std :: cout << '\n';
        return;
    }
    std :: cout << "NO" << '\n';
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
