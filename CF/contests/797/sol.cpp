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

/*

    2 1 4 5 3

    1 2 3 4 5

    1 2 5 3 4

    2 1 4 5 3

    1 2 3 4 5    
    

*/

using ll = long long;

ll lcm(ll a,ll b){
    return (a * b) / gcd(a,b);
}

void solve(){
    int n;
    std :: cin >> n;
    std :: string s;
    std :: cin >> s;
    std :: vector<int> p(n + 1);
    for(int i = 1;i <= n;++i)std :: cin >> p[i];
    std :: vector<bool> vis(n + 1);
    ll ans = 1;
    for(int k = 1;k <= n;++k){
        if(!vis[k]){
            std :: vector<std :: vector<int>> cycle(26);
            std :: set<char> se;
            int u = k,cyc = 0;
            while(!vis[u]){
                vis[u] = 1;
                cycle[s[u - 1] - 'a'].push_back(cyc);
                se.insert(s[u - 1]);
                u = p[u];
                ++cyc;
            }
            // dbg(se);
            if(se.size() > 1){
                for(int i = 0;i < 26;++i){
                    if(cycle[i].size() > 0){
                        // dbg(i,cycle[i],cyc);
                        cycle[i].push_back(cyc - 1);
                        int dif = cycle[i][1] - cycle[i][0] + 1;
                        for(int j = 2;j < len(cycle[i]);++j){
                            if(dif != cycle[i][j] - cycle[i][j - 1] + 1){
                                ans = lcm(ans,cyc);
                                break;
                            }
                        }
                        ans = lcm(ans,dif);
                    }
                }
            }
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
