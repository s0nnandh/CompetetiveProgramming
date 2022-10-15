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

std :: string s;

struct state{
    int i,a,b,c,d;
    state(){

    }
    state(int I,int A,int B,int C,int D){
        i = I;
        a = A;
        b = B;
        c = C;
        d = D;
    }
    friend bool operator< (const state &x,const state &y){
        if(x.i == y.i){
            if(x.a == y.a){
                if(x.b == y.b){
                    if(x.c == y.c){
                        return x.d < y.d;
                    }
                    return x.c < y.c;
                }
                return x.b < y.b;
            }
            return x.a < y.a;
        }
        return x.i < y.i;
    }
};

std :: map<state,int> mp;

int go(int i,int a,int b,int c,int d){
    state me = state(i,a,b,c,d);
    if(i >= 0 && (a < 0 || b < 0 || c < 0 || d < 0))return mp[me] = -1;
    if(i < 0 && a == 0 && b == 0 && c == 0 && d == 0)return mp[me] = 1;
    if(i < 0 && (a || b || c || d))return mp[me] = -1;
    if(mp[me])return mp[me];
    int ans = -1;
    if(s[i] == 'A'){
        if(go(i - 1,a - 1,b,c,d) == 1)return mp[me] = 1;
        if(i && s[i - 1] == 'B' && go(i - 2,a,b,c,d - 1) == 1)return mp[me] = 1;
    }
    else if(s[i] == 'B'){
        if(go(i - 1,a,b - 1,c,d) == 1)return mp[me] = 1;
        if(i && s[i - 1] == 'A' && go(i - 2,a,b,c - 1,d) == 1)return mp[me] = 1;
    }
    return mp[me] = ans;
}

void solve(){
    int a,b,c,d;
    std :: cin >> a >> b >> c >> d;
    std :: cin >> s;
    int n = s.size();
    mp.clear();
    std :: cout << (go(n - 1,a,b,c,d) == 1 ? "YES" : "NO") << '\n';
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
