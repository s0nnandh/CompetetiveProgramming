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

void solve(){
    int q;
    std :: cin >> q;
    std :: set<pi> s;
    for(int i = 0;i < q;++i){
        int typ;
        std :: cin >> typ;
        if(typ == 1){
            int x;
            std :: cin >> x;
            auto ptr = s.lower_bound({x,0});
            if(ptr == s.end() || (*ptr).fr != x){
                s.insert({x,1});
            }
            else{
                int cnt = (*ptr).second;
                ++cnt;
                s.erase(ptr);
                s.insert({x,cnt});
            }
        }
        else if(typ == 2){
            int x,c;
            std :: cin >> x >> c;
            auto ptr = s.lower_bound({x,0});
            if(ptr == s.end() || (*ptr).fr != x)continue;
            int cnt = (*ptr).second;
            cnt-=c;
            s.erase(ptr);
            if(cnt > 0)s.insert({x,cnt});
        }
        else{
            auto f = s.begin(),l = s.end();
            --l;
            std :: cout << (*l).fr - (*f).fr << '\n';
        }
    }
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
