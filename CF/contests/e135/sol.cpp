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
    std :: vector<int> v, ok(n + 1);
    if(n % 3 == 0){
        ok[n] = 1;
        int x = n - 1;
        v.push_back(n); 
        if(x % 2){
            v.push_back(x / 2 + 1);
            v.push_back(x / 2);
            ok[x / 2] = 1;
            ok[x / 2 + 1] = 1;
        }       
        else{
            v.push_back(x / 2 + 1);
            v.push_back(x / 2 - 1);
            ok[x / 2 + 1] = 1;
            ok[x / 2 - 1] = 1;
        }
        for(int i = n;i > 0;--i)if(!ok[i])v.push_back(i);
    }
    else if(n % 3 == 1){
        v.push_back(n);
        v.push_back(n - 1);
        v.push_back(n - 3);
        v.push_back(n - 2);
        for(int i = n - 4;i > 0;--i)v.push_back(i);
    }
    else{
        for(int i = n;i > 0;--i)v.push_back(i);
    }
    std :: reverse(all(v));
    for(int x : v)std :: cout << x << " ";
    std :: cout << '\n';
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
