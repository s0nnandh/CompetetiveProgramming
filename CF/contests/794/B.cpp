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

template <typename T> 
struct Fenwick{   // 1 - indexed Fenwick tree
    int n;
    std :: vector<T> bit;  

    Fenwick(int nn){
        this -> n = nn;
        bit.resize(nn + 1);
    }
    void add(T x,int i){
        while(i <= n){
            bit[i] += x;
            i += i & (-i);
        }
    }
    T get(int i){
        T sum = 0;
        while(i > 0){
            sum += bit[i];
            i -= i & (-i);
        }  
        return sum;
    }
    T query(int l,int r){
        return get(r) - get(l-1);
    }
};

void solve(){
    int n;
    std :: cin >> n;
    Fenwick<int> tree(n);
    std :: vector<int> v(n);
    for(int &i : v)std :: cin >> i;
    int ans = 0,sum = 0;
    std :: stack<int> rev;
    for(int i = n - 1;i >= 0;--i){
        sum += tree.get(v[i]);
        if(sum > 0){
            ++ans;
            sum = 0;
            while(!rev.empty()){
                tree.add(-1,rev.top());
                rev.pop();
            }
        }
        else{
            tree.add(1,v[i]);
            rev.push(v[i]);
        }
    }
    std :: cout << ans << '\n';
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
