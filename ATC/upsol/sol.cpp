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
	int n;
    std :: cin >> n;
    std :: vector<int> a(n),b(n);
    for(int i = 0;i < n;++i)std :: cin >> a[i];
    for(int i = 0;i < n;++i)std :: cin >> b[i];
    // std :: swap(a,b);
    // std :: vector<pi> v(n);
    // for(int i = 0;i < n;++i)v[i] = {a[i], b[i]};
    // sort(all(v));
    // std :: vector<int> new_a(n),new_b(n);
    // for(int i = 0;i < n;++i){
    //     new_a[i] = v[i].first;
    //     new_b[i] = v[i].second;
    // }
    // // int A[3] = {1,2,3};
    // // std :: cout << std :: is_sorted(A,A+3) << std :: endl;
    // if(!std :: is_sorted(all(new_a)) || !std :: is_sorted(all(new_b))){
    //     std :: cout << "-1\n";
    //     return;
    // }
    std :: vector<pi> ans;
    for(int i = 0;i < n - 1;++i){
        int n_id = std :: min_element(a.begin() + i + 1,a.end()) - a.begin();
        assert(n_id < n);X
        if(a[n_id] < a[i]){
            ans.push_back({i,n_id});
            std :: swap(a[n_id],a[i]);
            std :: swap(b[n_id],b[i]);
        }
        else if(a[n_id] == a[i] && b[n_id] < b[i]){
            ans.push_back({i,n_id});
            std :: swap(a[n_id],a[i]);
            std :: swap(b[n_id],b[i]);
        }
    }
    for(int i = 0;i < n;++i){
        for(int j = i + 1;j < n;++j){
            if(a[i] <= a[j] && b[i] > b[j]){
                std :: cout << -1 << '\n';
                return;
            }
        }
    }
    // if(std :: is_sorted(all(a)) && std :: is_sorted(all(b))){
        std :: cout << ans.size() << '\n';
        for(auto x : ans)std :: cout << x.first + 1 << " " << x.second + 1 << '\n';
    // }
    // else std :: cout << -1 << '\n';
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
