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
    int n, k, r, c;
    std :: cin >> n >> k >> r >> c;
    std :: vector<std :: vector<char>> v(n, std :: vector<char> (n, '.'));
    std :: vector<int> col(n);
    std :: vector<int> row(n);
    std :: queue<pi> q; 
    std :: vector<pi> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    --r;--c;
    do{
        q.push({r, c});
        while(!q.empty()) {
            auto me = q.front();
            q.pop();
            int x = me.first, y = me.second;
            if(v[x][y] == 'X')continue;
            v[x][y] = 'X';
            col[y] = true;
            row[x] = true;
            for(int i = 0;i < 4;++i){
                int nx = x + k * d[i].first, ny = y + k * d[i].second;
                if(nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
                q.push({nx, ny});
            }
        }
        r = std :: find(row.begin(), row.end(), 0) - row.begin(), c = std :: find(col.begin(), col.end(), 0) - col.begin();
    }
    while(*std :: min_element(all(row)) == 0 || *std :: min_element(all(col)) == 0);
    for(auto x : v){
        for(auto y : x)std :: cout << y;
        std :: cout << '\n';
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
